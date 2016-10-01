/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "client3.h"
#include "client3Dlg.h"
#include "EWrapper.h"    // C:\JTS\SocketClient\include must be added to include path
#include "DlgOrder.h"
#include "DlgExtOrd.h"
#include "DlgAccount.h"
#include "DlgConnect.h"
#include "DlgMktDepth.h"
#include "DlgNewsBulletins.h"
#include "DlgLogConfig.h"
#include "RptFilterDlg.h"
#include "AcctUpdatesDlg.h"
#include "DlgFinancialAdvisor.h"
#include "DlgScanner.h"
#include "DlgAccountSummary.h"
#include "DlgGroups.h"

#include "Contract.h"
#include "Order.h"
#include "ScannerSubscription.h"

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"
#include "../ActiveX/ComPropAccessor.h"

#include "TwsHelpers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// consts
const int N = 5;
const CString CClient3Dlg::RETURN_NEWLINE("\r\n");
const CString CClient3Dlg::NEWLINE("\n");
const CString CClient3Dlg::RETURN("\r");
const CString CClient3Dlg::TAB("\t");
const CString CClient3Dlg::FOUR_SPACES("    ");
const int CClient3Dlg::NOT_AN_FA_ACCOUNT_ERROR = 321;

// statics
static CDlgAccount      s_accountDlg;
static int              s_maxOrderStatusStrSize;
static CDlgLogConfig    s_dlgLogConfig;

/////////////////////////////////////////////////////////////////////////////
// utility funcs
CString getField( TickType tickType) {
	switch( tickType)
	{
		case BID_SIZE:	                    return "bidSize";
		case BID:		                    return "bidPrice";
		case ASK:		                    return "askPrice";
		case ASK_SIZE:	                    return "askSize";
		case LAST:		                    return "lastPrice";
		case LAST_SIZE:	                    return "lastSize";
		case HIGH:		                    return "high";
		case LOW:		                    return "low";
		case VOLUME:	                    return "volume";
		case CLOSE:		                    return "close";
		case BID_OPTION_COMPUTATION:		return "bidOptComp";
		case ASK_OPTION_COMPUTATION:		return "askOptComp";
		case LAST_OPTION_COMPUTATION:		return "lastOptComp";
		case MODEL_OPTION:					return "optionModel";
        case OPEN:                          return "open";
        case LOW_13_WEEK:                   return "13WeekLow";
        case HIGH_13_WEEK:                  return "13WeekHigh";
        case LOW_26_WEEK:                   return "26WeekLow";
        case HIGH_26_WEEK:                  return "26WeekHigh";
        case LOW_52_WEEK:                   return "52WeekLow";
        case HIGH_52_WEEK:                  return "52WeekHigh";
        case AVG_VOLUME:                    return "AvgVolume";
        case OPEN_INTEREST:                 return "OpenInterest";
        case OPTION_HISTORICAL_VOL:         return "OptionHistoricalVolatility";
        case OPTION_IMPLIED_VOL:            return "OptionImpliedVolatility";
        case OPTION_BID_EXCH:               return "OptionBidExchStr";
        case OPTION_ASK_EXCH:               return "OptionAskExchStr";
        case OPTION_CALL_OPEN_INTEREST:     return "OptionCallOpenInterest";
        case OPTION_PUT_OPEN_INTEREST:      return "OptionPutOpenInterest";
        case OPTION_CALL_VOLUME:            return "OptionCallVolume";
        case OPTION_PUT_VOLUME:             return "OptionPutVolume";
        case INDEX_FUTURE_PREMIUM:          return "IndexFuturePremium";
        case BID_EXCH:                      return "bidExch";
        case ASK_EXCH:                      return "askExch";
        case AUCTION_VOLUME:                return "auctionVolume";
        case AUCTION_PRICE:                 return "auctionPrice";
        case AUCTION_IMBALANCE:             return "auctionImbalance";
        case MARK_PRICE:                    return "markPrice";
        case BID_EFP_COMPUTATION:           return "bidEFP";
        case ASK_EFP_COMPUTATION:           return "askEFP";
        case LAST_EFP_COMPUTATION:          return "lastEFP";
        case OPEN_EFP_COMPUTATION:          return "openEFP";
        case HIGH_EFP_COMPUTATION:          return "highEFP";
        case LOW_EFP_COMPUTATION:           return "lowEFP";
        case CLOSE_EFP_COMPUTATION:         return "closeEFP";
        case LAST_TIMESTAMP:                return "lastTimestamp";
        case SHORTABLE:                     return "shortable";
        case FUNDAMENTAL_RATIOS:            return "fundamentals";
        case RT_VOLUME:                     return "RTVolume";
        case HALTED:                        return "halted";
        case BID_YIELD:                     return "bidYield";
        case ASK_YIELD:                     return "askYield";
        case LAST_YIELD:                    return "lastYield";
        case CUST_OPTION_COMPUTATION:       return "custOptComp";
        case TRADE_COUNT:                   return "trades";
        case TRADE_RATE:                    return "trades/min";
        case VOLUME_RATE:                   return "volume/min";
        case LAST_RTH_TRADE:                return "lastRTHTrade";
        default:                            return "unknown";
	}
}

#define NUM_FA_ERROR_CODES 6
static int faErrorCodes[NUM_FA_ERROR_CODES] =
{ 503, 504, 505, 522, 1100, CClient3Dlg::NOT_AN_FA_ACCOUNT_ERROR } ;

/////////////////////////////////////////////////////////////////////////////
// Private helper templates

template<class ComInterface>
struct CClient3Dlg::PropPrintHelpers {

	typedef CComPropAccessor<ComInterface> Props;

	static int Print(CHScrollListBox& listBox, const char* name,
		ComInterface* obj, typename Props::bool_get get)
	{
		bool boolVal = false;
		Props::Get(boolVal, obj, get);
		CString str;
		str.Format("  %s=%i", name, boolVal);
		return listBox.AddString(str);
	}

	static int Print(CHScrollListBox& listBox, const char* name,
		ComInterface* obj, typename Props::long_get get)
	{
		long longVal = 0;
		Props::Get(longVal, obj, get);
		CString str;
		if (longVal == INT_MAX) {
			str.Format("  %s=", name);
		}
		else {
			str.Format("  %s=%i", name, longVal);
		}
		return listBox.AddString(str);
	}

	static int Print(CHScrollListBox& listBox, const char* name,
		ComInterface* obj, typename Props::dbl_get get)
	{
		double dblVal = 0;
		Props::Get(dblVal, obj, get);
		CString str;
		if (dblVal == DBL_MAX) {
			str.Format("  %s=", name);
		}
		else {
			str.Format("  %s=%f", name, dblVal);
		}
		return listBox.AddString(str);
	}

	static int Print(CHScrollListBox& listBox, const char* name,
		ComInterface* obj, typename Props::str_get get)
	{
		CString strVal;
		Props::Get(strVal, obj, get);
		CString str;
		str.Format("  %s=%s", name, strVal);
		return listBox.AddString(str);
	}
};

#define PRINT_PROP(Prop,Class,Obj) \
	PropPrintHelpers<Class>::Print(m_orderStatus, #Prop, Obj, &Class::get_##Prop);

#define PRINT_PROP_WPREF(Pref,Prop,Class,Obj) \
	PropPrintHelpers<Class>::Print(m_orderStatus, Pref #Prop, Obj, &Class::get_##Prop);

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient3Dlg dialog

CClient3Dlg::CClient3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClient3Dlg::IDD, pParent)
	, m_dlgOrder(new CDlgOrder(this))
	, m_dlgMktDepth(new CDlgMktDepth(this))
	, m_dlgGroups(new CDlgGroups(this))
{
	//{{AFX_DATA_INIT(CClient3Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    s_maxOrderStatusStrSize = 0;
    m_financialAdvisor = false;
}

CClient3Dlg::~CClient3Dlg()
{
}

void CClient3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClient3Dlg)
	DDX_Control(pDX, IDC_LIST1, m_errors);
	DDX_Control(pDX, IDC_LIST2, m_ticks);
	DDX_Control(pDX, IDC_LIST3, m_orderStatus);
	DDX_Control(pDX, IDC_TWSCTRL1, m_tws);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClient3Dlg, CDialog)
	//{{AFX_MSG_MAP(CClient3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_REQMKTDATA, OnReqMktData)
	ON_BN_CLICKED(IDC_CANMKTDATA, OnCanMktData)
	ON_BN_CLICKED(IDC_WHAT_IF, OnWhatIf)
	ON_BN_CLICKED(IDC_PLACEORDER, OnPlaceOrder)
	ON_BN_CLICKED(IDC_CANORDER, OnCanorder)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_EXTORD, OnSetExtOrdAttribs)
	ON_BN_CLICKED(IDC_REQ_OPEN_ORDERS, OnReqOpenOrders)
	ON_BN_CLICKED(IDC_REQ_ACCT_DATA, OnReqAcctData)
	ON_BN_CLICKED(IDC_REQ_IDS, OnReqIds)
	ON_BN_CLICKED(IDC_REQ_EXECUTIONS, OnReqExecutions)
	ON_BN_CLICKED(IDC_REQ_CONTRACT_DATA, OnReqContractDetails)
	ON_BN_CLICKED(IDC_CANCEL_MKT_DEPTH_DATA, OnCancelMktDepth)
	ON_BN_CLICKED(IDC_REQ_MKT_DEPTH, OnReqMktDepth)
	ON_BN_CLICKED(IDC_NEWS_BULLETINS, OnNewsBulletins)
	ON_BN_CLICKED(IDC_LOGGING, OnSetServerLogLevel)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_REQ_ACCTS, OnReqAccts)
	ON_BN_CLICKED(IDC_REQ_ALL_OPEN_ORDERS, OnReqAllOpenOrders)
	ON_BN_CLICKED(IDC_REQ_AUTO_OPEN_ORDERS, OnReqAutoOpenOrders)
	ON_BN_CLICKED(IDC_FINANCIAL_ADVISOR, OnFinancialAdvisor)
	ON_BN_CLICKED(IDC_HISTORICAL_DATA, OnReqHistoricalData)
	ON_BN_CLICKED(IDC_EXERCISE_OPTIONS, OnExerciseOptions)
	ON_BN_CLICKED(IDC_CANCEL_HIST_DATA, OnCancelHistData)
	ON_BN_CLICKED(IDC_REQ_REAL_TIME_BARS, OnReqRealTimeBars)
	ON_BN_CLICKED(IDC_CANCEL_REAL_TIME_BARS, OnCancelRealTimeBars)
	ON_BN_CLICKED(IDC_REQ_CURRENT_TIME, OnReqCurrentTime)
	ON_BN_CLICKED(IDC_MARKET_SCANNER, OnMarketScanner)
	ON_BN_CLICKED(IDC_CALC_IMPL_VOLAT, OnCalculateImpliedVolatility)
	ON_BN_CLICKED(IDC_CALC_OPTION_PRICE, OnCalculateOptionPrice)
	ON_BN_CLICKED(IDC_CANCEL_CALC_IMPL_VOLAT, OnCancelCalculateImpliedVolatility)
	ON_BN_CLICKED(IDC_CANCEL_CALC_OPTION_PRICE, OnCancelCalculateOptionPrice)
	ON_BN_CLICKED(IDC_REQ_GLOBAL_CANCEL, OnReqGlobalCancel)
	ON_BN_CLICKED(IDC_REQ_MARKET_DATA_TYPE, OnReqMarketDataType)
	ON_BN_CLICKED(IDC_REQUEST_POSITIONS, OnReqPositions)
	ON_BN_CLICKED(IDC_CANCEL_POSITIONS, OnCancelPositions)
	ON_BN_CLICKED(IDC_REQUEST_ACCOUNT_SUMMARY, OnReqAccountSummary)
	ON_BN_CLICKED(IDC_CANCEL_ACCOUNT_SUMMARY, OnCancelAccountSummary)
	ON_BN_CLICKED(IDC_BTN_GROUPS, OnGroups)
	ON_BN_CLICKED(IDC_FUNDAMENTAL_DATA, OnFundamentalData)
	ON_BN_CLICKED(IDC_CANCEL_FUNDAMENTAL_DATA, OnCancelFundamentalData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient3Dlg message handlers

BOOL CClient3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_dlgOrder->setCtrl( this, &m_tws);

	{
		CComPtr<IDispatch> dispExecFilter;
		dispExecFilter.Attach(m_tws.createExecutionFilter());
	
		m_execFilter = dispExecFilter;
	}

	{
		CComPtr<IDispatch> dispSubscription;
		dispSubscription.Attach(m_tws.createScannerSubscription());

		m_scannerSubscr = dispSubscription;

		typedef CComPropAccessor<IScannerSubscription> Props;

#define PUT_PROP(Prop, Value) \
		Props::Put(m_scannerSubscr, Value, &IScannerSubscription::put_##Prop);

		PUT_PROP(numberOfRows, 10);
		PUT_PROP(instrument, "STK");
		PUT_PROP(locations, "STK.US.MAJOR");
		PUT_PROP(scanCode, "TOP_PERC_GAIN");
		PUT_PROP(priceAbove, 3);
		PUT_PROP(marketCapAbove, 100000000);
		PUT_PROP(scannerSettingPairs, "Annual,true");

#undef PUT_PROP

	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClient3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClient3Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClient3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CClient3Dlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CClient3Dlg)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 1 /* tickPrice */, OntickPriceTwsctrl1, VTS_I4 VTS_I4 VTS_R8 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 2 /* tickSize */, OntickSizeTwsctrl1, VTS_I4 VTS_I4 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 3 /* connectionClosed */, OnconnectionClosedTwsctrl1, VTS_NONE)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 6 /* updateAccountTime */, OnupdateAccountTimeTwsctrl1, VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 7 /* updateAccountValue */, OnupdateAccountValueTwsctrl1, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 8 /* nextValidId */, OnnextValidIdTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 10 /* permId */, OnpermIdTwsctrl1, VTS_I4 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 11 /* errMsg */, OnerrMsgTwsctrl1, VTS_I4 VTS_I4 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 13 /* orderStatus */, OnorderStatusTwsctrl1, VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_R8 VTS_I4 VTS_I4 VTS_R8 VTS_I4 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 16 /* updateMktDepth */, OnupdateMktDepthTwsctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_R8 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 17 /* updateMktDepthL2 */, OnupdateMktDepthL2Twsctrl1, VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_R8 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 18 /* updateNewsBulletin */, OnupdateNewsBulletinTwsctrl1, VTS_I2 VTS_I2 VTS_BSTR VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 19 /* managedAccounts */, OnmanagedAccountsTwsctrl1, VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 21 /* receiveFA */, receiveFATwsctrl1, VTS_I4 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 22 /* historicalData */, OnhistoricalDataTwsctrl1, VTS_I4 VTS_BSTR VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_I4 VTS_R8 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 25 /* scannerParameters */, OnScannerParametersTwsctrl1, VTS_BSTR )
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 27 /* tickOptionComputation */, OntickOptionComputationTwsctrl1, VTS_I4 VTS_I4 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 28 /* tickGeneric */, OntickGenericTwsctrl1, VTS_I4 VTS_I4 VTS_R8)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 29 /* tickString */, OntickStringTwsctrl1, VTS_I4 VTS_I4 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 30 /* tickEFP */, OntickEFPTwsctrl1, VTS_I4 VTS_I4 VTS_R8 VTS_BSTR VTS_R8 VTS_I4 VTS_BSTR VTS_R8 VTS_R8)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 31 /* realtimeBar */, OnrealtimeBarTwsctrl1, VTS_I4 VTS_I4 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_R8 VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 32 /* currentTime */, OncurrentTimeTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 33 /* scannerDataEnd */, OnScannerDataEndTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 34 /* fundamentalData */, OnFundamentalDataTwsctrl1, VTS_I4 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 35 /* contractDetailsEnd */, OnContractDetailsEndTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 36 /* openOrderEnd */, OnOpenOrderEndTwsctrl1, VTS_NONE)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 37 /* accountDownloadEnd */, OnAccountDownloadEndTwsctrl1, VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 38 /* execDetailsEnd */, OnExecDetailsEndTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 39 /* deltaNeutralValidation */, OnDeltaNeutralValidationTwsctrl1, VTS_I4 VTS_DISPATCH)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 40 /* tickSnapshotEnd */, OnTickSnapshotEndTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 41 /* marketDataType */, OnMarketDataTypeTwsctrl1, VTS_I4 VTS_I4)

	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 100 /* contractDetailsEx */, OnContractDetailsExTwsctrl1, VTS_I4 VTS_DISPATCH)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 101 /* openOrderEx */, OnOpenOrderExTwsctrl1, VTS_I4 VTS_DISPATCH VTS_DISPATCH VTS_DISPATCH)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 102 /* execDetailsEx */, OnExecDetailsExTwsctrl1, VTS_I4 VTS_DISPATCH VTS_DISPATCH)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 103 /* updateProtfolioEx */, OnUpdatePortfolioExTwsctrl1, VTS_DISPATCH VTS_I4 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 104 /* scannerDataEx */, OnScannerDataExTwsctrl1, VTS_I4 VTS_I4 VTS_DISPATCH VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 105 /* commissionReport */, OnCommissionReportTwsctrl1, VTS_DISPATCH)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 106 /* position */, OnPositionTwsctrl1, VTS_BSTR VTS_DISPATCH VTS_I4 VTS_R8)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 107 /* positionEnd */, OnPositionEndTwsctrl1, VTS_NONE)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 108 /* accountSummary */, OnAccountSummaryTwsctrl1, VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 109 /* accountSummaryEnd */, OnAccountSummaryEndTwsctrl1, VTS_I4)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 110 /* verifyMessageAPI */, OnVerifyMessageAPITwsctrl1, VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 111 /* verifyCompleted */, OnVerifyCompletedTwsctrl1, VTS_BOOL VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 112 /* displayGroupList */, OnDisplayGroupListTwsctrl1, VTS_I4 VTS_BSTR)
	ON_EVENT(CClient3Dlg, IDC_TWSCTRL1, 113 /* displayGroupUpdated */, OnDisplayGroupUpdatedTwsctrl1, VTS_I4 VTS_BSTR)

	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CClient3Dlg::OnConnect() 
{
	// IMPORTANT: TWS must be running, and the "Enable Excel Integration" 
	// checkbox on the "Settings" menu must be checked!	

	// get connection parameters
	CDlgConnect dlg;
	if( dlg.DoModal() == IDCANCEL) {
		return;
	}

	// connect to TWS
	{
		CString displayString;
		displayString.Format( "Connecting to Tws using clientId %d ...", dlg.m_clientId);
		int i = m_orderStatus.AddString( displayString);
		m_orderStatus.SetTopIndex( i);
	}

	m_tws.connect( dlg.m_ipAddress, dlg.m_port, dlg.m_clientId, /* extraAuth */ false);

	if( m_tws.serverVersion() > 0) {
		CString displayString;
		displayString.Format( "Connected to Tws server version %d at %s.",
			m_tws.serverVersion(), m_tws.TwsConnectionTime());
		int i = m_orderStatus.AddString( displayString);
		m_orderStatus.SetTopIndex( i);
	}
}


void CClient3Dlg::OnReqMktData() 
{
	// run dlg box
    m_dlgOrder->init( "Request Market Data",
		CDlgOrder::REQ_MKT_DATA, m_managedAccounts, m_mktDataOptions);
	
	INT_PTR nRes = m_dlgOrder->DoModal();

	m_mktDataOptions = m_dlgOrder->getComOptions();

	if( nRes != IDOK) return;

	m_tws.reqMktDataEx(m_dlgOrder->m_id, m_dlgOrder->getComContract(),
		m_dlgOrder->m_genericTicks, m_dlgOrder->m_snapshotMktData, m_mktDataOptions);
}

void CClient3Dlg::OnCanMktData() 
{
    m_dlgOrder->init( "Cancel Market Data",
		CDlgOrder::CANCEL_MKT_DATA, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel market data
	m_tws.cancelMktData( m_dlgOrder->m_id);
}


void CClient3Dlg::OnWhatIf()
{
	placeOrder(/* whatIf */ true);
}

void CClient3Dlg::OnPlaceOrder()
{
	placeOrder(/* whatIf */ false);
}

void CClient3Dlg::placeOrder(bool whatIf)
{
	IOrder* order = m_dlgOrder->getComOrder();

	typedef CComPropAccessor<IOrder> Props;

	CComQIPtr<ITagValueList> miscOrderOptions;
	Props::GetQI(miscOrderOptions, order, &IOrder::get_orderMiscOptions);

	// run dlg
    m_dlgOrder->init( "Place Order",
		CDlgOrder::ORDER, m_managedAccounts, miscOrderOptions);

	INT_PTR nRes = m_dlgOrder->DoModal();

	miscOrderOptions = m_dlgOrder->getComOptions();
	Props::Put(order, miscOrderOptions, &IOrder::putref_orderMiscOptions);

	if( nRes != IDOK) return;

	bool savedWhatIf = false;

	Props::Get(savedWhatIf, order, &IOrder::get_whatIf);
	Props::Put(order, whatIf, &IOrder::put_whatIf);

	m_tws.placeOrderEx(m_dlgOrder->m_id, m_dlgOrder->getComContract(), order);

	Props::Put(order, savedWhatIf, &IOrder::put_whatIf);
}

void CClient3Dlg::OnCanorder() 
{
	// get order id
    m_dlgOrder->init( "Cancel Order",
		CDlgOrder::CANCEL_ORDER, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel order
	m_tws.cancelOrder( m_dlgOrder->m_id);
}

void CClient3Dlg::OnReqOpenOrders() 
{
	// request open orders
	m_tws.reqOpenOrders();
}

void CClient3Dlg::OnReqAcctData() 
{
    CAcctUpdatesDlg dlg;

    if ( dlg.DoModal() != IDOK) return;

	if (dlg.getSubscribe()) {
		s_accountDlg.accountDownloadBegin(dlg.getAcctCode());
	}

    m_tws.reqAccountUpdates(dlg.getSubscribe(), dlg.getAcctCode());

    // Show the account details dialog if we are subscribing.
    if ( dlg.getSubscribe() )
    {
	    s_accountDlg.DoModal();
    }
}

void CClient3Dlg::OnReqExecutions() 
{
    CRptFilterDlg dlg(m_execFilter);
    if ( dlg.DoModal() != IDOK) return;

	// request execution reports
	m_tws.reqExecutionsEx(dlg.reqId(), m_execFilter);
}

void CClient3Dlg::OnReqIds() 
{
	// request block of 20 ids
	m_tws.reqIds( 20);	
}

void CClient3Dlg::OnReqContractDetails() 
{
	// run dlg box
    m_dlgOrder->init( "Request Contract Details",
		CDlgOrder::REQ_CONTRACT_DETAILS, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;
	
	m_tws.reqContractDetailsEx(m_dlgOrder->m_id, m_dlgOrder->getComContract());
}

void CClient3Dlg::OnDisconnect() 
{
	// disconnect from TWS
	m_tws.disconnect();
}

void CClient3Dlg::OnClear() 
{
	// clear list boxes
	m_ticks.ResetContent();
	m_orderStatus.ResetContent();
	m_errors.ResetContent();
}

// modify extended order attributes
void CClient3Dlg::OnSetExtOrdAttribs() 
{
	CDlgExtOrd dlgExtOrd(m_dlgOrder->getComOrder(), this);
	if( dlgExtOrd.DoModal() != IDOK) return;
	// nothing to do here
}

void CClient3Dlg::OnCancelHistData()
{
    m_dlgOrder->init( "Cancel Historical Data",
		CDlgOrder::CANCEL_HISTORICAL_DATA, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	m_tws.cancelHistoricalData( m_dlgOrder->m_id);
}

void CClient3Dlg::OnReqCurrentTime()
{
	m_tws.reqCurrentTime();
}

void CClient3Dlg::OnMarketScanner()
{
	CDlgScanner dlgScanner(m_scannerSubscr, m_scannerSubscriptionOptions, &m_tws);

	dlgScanner.DoModal();

	m_scannerSubscriptionOptions = dlgScanner.getComScannerSubscriptionOptions();
}

void CClient3Dlg::OnExerciseOptions()
{
    m_dlgOrder->init( "Exercise Options",
		CDlgOrder::EXERCISE_OPTIONS, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	/* TODO: get account in a less convoluted way */
	CString account;
	typedef CComPropAccessor<IOrder> Props;
	Props::Get(account, m_dlgOrder->getComOrder(), &IOrder::get_account);

	m_tws.exerciseOptionsEx(
		m_dlgOrder->m_id,
		m_dlgOrder->getComContract(),
		m_dlgOrder->m_exerciseAction,
		m_dlgOrder->m_exerciseQuantity,
		account,
		m_dlgOrder->m_exerciseOverride);
}


void CClient3Dlg::OnReqHistoricalData() 
{
    m_dlgOrder->init( "Request Historical Data",
		CDlgOrder::REQ_HISTORICAL_DATA, m_managedAccounts, m_chartOptions);

	INT_PTR nRes = m_dlgOrder->DoModal();

	m_chartOptions = m_dlgOrder->getComOptions();

	if( nRes != IDOK) return;

	m_tws.reqHistoricalDataEx( 
		m_dlgOrder->m_id,
		m_dlgOrder->getComContract(),
		m_dlgOrder->m_backfillEndDateTime,
		m_dlgOrder->m_backfillDuration, 
		m_dlgOrder->m_barSizeSetting,
		m_dlgOrder->m_whatToShow,
		m_dlgOrder->m_useRTH,
		m_dlgOrder->m_formatDate,
		m_chartOptions);
}

void CClient3Dlg::OnFundamentalData()
{
	m_dlgOrder->init( "Request Fundamental Data",
		CDlgOrder::REQ_FUNDAMENTAL_DATA, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	m_tws.reqFundamentalData( m_dlgOrder->m_id, m_dlgOrder->getComContract(), m_dlgOrder->m_whatToShow);
}

void CClient3Dlg::OnCancelFundamentalData()
{
	m_dlgOrder->init( "Cancel Fundamental Data",
		CDlgOrder::CANCEL_FUNDAMENTAL_DATA, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	m_tws.cancelFundamentalData( m_dlgOrder->m_id);
}

void CClient3Dlg::OnReqRealTimeBars()
{
    m_dlgOrder->init( "Request Real Time Bars",
		CDlgOrder::REQ_REAL_TIME_BARS, m_managedAccounts, m_realTimeBarsOptions);

	INT_PTR nRes = m_dlgOrder->DoModal();

	m_realTimeBarsOptions = m_dlgOrder->getComOptions();

	if( nRes != IDOK) return;

	m_tws.reqRealTimeBarsEx(
		m_dlgOrder->m_id,
		m_dlgOrder->getComContract(),
		5 /* TODO: parse and use m_dlgOrder->m_barSizeSetting) */,
		m_dlgOrder->m_whatToShow,
		m_dlgOrder->m_useRTH > 0, m_realTimeBarsOptions);
}

void CClient3Dlg::OnCancelRealTimeBars()
{
    m_dlgOrder->init( "Cancel Real Time Bars",
		CDlgOrder::CANCEL_REAL_TIME_BARS, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	m_tws.cancelRealTimeBars( m_dlgOrder->m_id);
}

void CClient3Dlg::OnCalculateImpliedVolatility()
{
	// run dlg
	m_dlgOrder->init( "Calculate Implied Volatility",
		CDlgOrder::CALC_IMPL_VOL, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// request calculate implied volatility
	m_tws.calculateImpliedVolatility( m_dlgOrder->m_id, m_dlgOrder->getComContract(),
		m_dlgOrder->m_lmtPrice, m_dlgOrder->m_auxPrice);
}

void CClient3Dlg::OnCalculateOptionPrice()
{
	// run dlg
	m_dlgOrder->init( "Calculate Option Price",
		CDlgOrder::CALC_OPTION_PRICE, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// request calculate option price
	m_tws.calculateOptionPrice( m_dlgOrder->m_id, m_dlgOrder->getComContract(),
		m_dlgOrder->m_lmtPrice, m_dlgOrder->m_auxPrice);
}

void CClient3Dlg::OnCancelCalculateImpliedVolatility()
{
	// run dlg
	m_dlgOrder->init( "Cancel Calculate Implied Volatility",
		CDlgOrder::CANCEL_CALC_IMPL_VOL, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel calculate implied volatility
	m_tws.cancelCalculateImpliedVolatility( m_dlgOrder->m_id);
}

void CClient3Dlg::OnCancelCalculateOptionPrice()
{
	// run dlg
	m_dlgOrder->init( "Cancel Calculate Option Price",
		CDlgOrder::CANCEL_CALC_OPTION_PRICE, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel calculate option price
	m_tws.cancelCalculateOptionPrice( m_dlgOrder->m_id);
}

void CClient3Dlg::OnReqGlobalCancel()
{
	// request global cancel
	m_tws.reqGlobalCancel();
}

void CClient3Dlg::OnReqMarketDataType()
{
	// run dlg box
	m_dlgOrder->init( "Request Market Data Type",
		CDlgOrder::REQ_MARKET_DATA_TYPE, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// request market data type
	m_tws.reqMarketDataType( m_dlgOrder->m_marketDataType);
}

void CClient3Dlg::OnReqPositions()
{
	// request positions
	m_tws.reqPositions();
}

void CClient3Dlg::OnCancelPositions()
{
	// cancel positions
	m_tws.cancelPositions();
}

void CClient3Dlg::OnReqAccountSummary()
{
	CDlgAccountSummary dlg("Request Account Summary", CDlgAccountSummary::REQUEST_ACCOUNT_SUMMARY);

	if ( dlg.DoModal() != IDOK) return;

	// request account summary
	m_tws.reqAccountSummary(dlg.reqId(), dlg.groupName(), dlg.tags());
}

void CClient3Dlg::OnCancelAccountSummary()
{
	CDlgAccountSummary dlg("Cancel Account Summary", CDlgAccountSummary::CANCEL_ACCOUNT_SUMMARY);

	if ( dlg.DoModal() != IDOK) return;

	// cancel account summary
	m_tws.cancelAccountSummary(dlg.reqId());
}

void CClient3Dlg::OnGroups()
{
	m_dlgGroups->init(&m_tws);
	m_dlgGroups->DoModal();
}

///////////////////////////////////////////////////////////
// handle ActiveX events

void CClient3Dlg::OnScannerParametersTwsctrl1(LPCTSTR xml) {
	static CString myTitle("SCANNER PARAMETERS: ") ;
    DisplayMultiline(m_orderStatus, myTitle, xml);
}

void CClient3Dlg::DisplayMultiline(CHScrollListBox& box, const CString& title, const CString& data)
{
	int i = box.AddString(title);

	if (!data.IsEmpty()) {

		const char* const begin = (const char*)data;
		const char* const end   = begin + data.GetLength();

		const char* p = begin;

		for (;;) {

			ASSERT (p != end);

			const char* lineend = (const char*)memchr( p, '\n', end - p);
			if (!lineend)
				lineend = end;

			const char* e = lineend;
			if (e != p) {
				const char* c = e;
				if (*--c == '\r')
					e = c;
			}

			size_t len = e - p;
			bool cut = false;

			if (len > 1024) {
				len = 1024;
				cut = true;
			}

			CString line = data.Mid( p - begin, len);

			if (cut) {
				line += " ...";
			}

			CString expanded;
			CStringReplace( line, TAB, FOUR_SPACES, expanded);

			i = box.AddString( expanded);

			if (lineend >= end || ++lineend >= end)
				break;

			p = lineend;
		}
	}

	int top = i - N < 0 ? 0 : i - N;
	box.SetTopIndex( top);
}

void CClient3Dlg::OnScannerDataExTwsctrl1(long reqId, long rank, IDispatch* dispDetails,
		LPCTSTR distance, LPCTSTR benchmark, LPCTSTR projection, LPCTSTR legsStr)
{
	long    conId = 0;
	CString symbol;
	CString secType;
	CString expiry;
	double  strike = 0.0;
	CString right;
//	CString multiplier;
	CString exchange;
//	CString primaryExchange;
	CString currency;
	CString localSymbol;

	CString marketName;
	CString tradingClass;

	{
		CComQIPtr<IContractDetails> details(dispDetails);
		if (details) {

			IDispatch* dispContractPtr = 0;
			details->get_summary(&dispContractPtr);

			CComPtr<IDispatch> dispContract;
			dispContract.Attach(dispContractPtr);

			CComQIPtr<IContract> contract(dispContract);
			if (contract) {

				typedef CComPropAccessor<IContract> Props;

#define GET_CONTRACT_PROP(Prop) \
	Props::Get(Prop, contract, &IContract::get_##Prop);

				GET_CONTRACT_PROP(conId);
				GET_CONTRACT_PROP(symbol);
				GET_CONTRACT_PROP(secType);
				GET_CONTRACT_PROP(expiry);
				GET_CONTRACT_PROP(strike);
				GET_CONTRACT_PROP(right);
				//GET_CONTRACT_PROP(multiplier);
				GET_CONTRACT_PROP(exchange);
				//GET_CONTRACT_PROP(primaryExchange);
				GET_CONTRACT_PROP(currency);
				GET_CONTRACT_PROP(localSymbol);
				GET_CONTRACT_PROP(tradingClass);

#undef GET_CONTRACT_PROP
			}

			{
				typedef CComPropAccessor<IContractDetails> Props;

#define GET_CONTRACT_DETAILS_PROP(Prop) \
	Props::Get(Prop, details, &IContractDetails::get_##Prop);

				GET_CONTRACT_DETAILS_PROP(marketName);

#undef GET_CONTRACT_DETAILS_PROP
			}
		}
	}

	CString str;
	str.Format("id =%i rank=%i conId=%i symbol=%s secType=%s expiry=%s strike=%f right=%s exchange=%s currency=%s localSymbol=%s marketName=%s tradingClass=%s distance=%s benchmark=%s projection=%s legsStr=%s",
        reqId,
        rank,
		conId,
        symbol,
        secType,
        expiry,
        strike,
        right,
        exchange,
        currency,
        localSymbol,
        marketName,
        tradingClass,
        distance,
        benchmark,
        projection,
		legsStr);
    int i =  m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OnScannerDataEndTwsctrl1(long reqId)
{
	// create string
	CString str;
	str.Format("id =%i =============== end ===============", reqId);
    int i =  m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OnhistoricalDataTwsctrl1(long reqId, LPCTSTR date, double open, 
										 double high, double low, double close,
										 long volume, long barCount, double WAP, long hasGaps) 
{
    CString displayString;
	displayString.Format(
		"id=%i date=%s open=%f high=%f low=%f close=%f volume=%i barCount=%i WAP=%f hasGaps=%i",
		reqId, (const char *)date, open, high, low, close, volume, barCount, WAP, hasGaps);
    int i =  m_ticks.AddString(displayString);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OnrealtimeBarTwsctrl1(long tickerId, long time, double open,
										double high, double low, double close,
										long volume, double WAP, long count)
{
	CString displayString;
	displayString.Format(
		"id=%d time=%d open=%f high=%f low=%f close=%f volume=%d WAP=%f count = %d",
		tickerId, time, open, high, low, close, volume, WAP, count);
    int i =  m_ticks.AddString(displayString);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OnFundamentalDataTwsctrl1(LONG reqId, LPCTSTR data)
{
    CString title;
	title.Format( "fund data id=%d, len=%d", reqId, strlen(data));
	DisplayMultiline(m_ticks, title, data);
}

void CClient3Dlg::OncurrentTimeTwsctrl1(long millis)
{
	CString displayString;
	displayString.Format("current time = %d", millis);
    int i =  m_orderStatus.AddString(displayString);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex( top);
}

// VC++ 5.0 MFC does not have CString.Replace.  So, I use this:

void CClient3Dlg::CStringReplace(CString &pXml, const CString &cStr, const CString &rStr, CString &pDest)
{
	int rlen, len, clen, lenFound ;
	LPTSTR pFind, builtBuf, pBuiltBuf, pBuf ;

	len = pXml.GetLength() ;
	clen = strlen( cStr ) ;
	rlen = strlen( rStr ) ;
	pBuf = pXml.GetBuffer( len );
	// next allocation size will always be large enough!
	builtBuf = pBuiltBuf = (LPTSTR)calloc(1, len * rlen + 1) ; 

	do {
		pFind = strstr(pBuf, cStr) ;
		if (pFind == NULL)
			strcat(pBuiltBuf, pBuf) ;
		else {
			lenFound = pFind - pBuf ;
			memcpy(pBuiltBuf, pBuf, lenFound) ;
			memcpy(pBuiltBuf + lenFound, rStr, rlen) ;
			pBuiltBuf += lenFound + rlen ;
			pBuf += lenFound + clen ;
		}
		}
	while (pFind != NULL) ;
	pXml.ReleaseBuffer( );
	pDest = builtBuf ;
	free(builtBuf) ;
}

void CClient3Dlg::OntickPriceTwsctrl1(long id, long tickType, double price, int canAutoExecute) 
{
	// build string
	CString str;
	str.Format( "id=%i  %s=%f  canAutoExec=%d",
		id, (const char*)getField( (TickType)tickType), price, canAutoExecute);

	// add to listbox
	int i = m_ticks.AddString( str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OntickSizeTwsctrl1(long id, long tickType, long size) 
{
	// build string
	CString str;
	str.Format( "id=%i  %s=%i",
		id, (const char*)getField( (TickType)tickType), size);

	// add to listbox
	int i = m_ticks.AddString( str);
	
	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OntickEFPTwsctrl1(long tickerId, long tickType, double basisPoints, LPCTSTR formattedBasisPoints,
						  double totalDividends, long holdDays, LPCTSTR futureExpiry, double dividendImpact,
						  double dividendsToExpiry) 
{
	// build string
	CString str;
	str.Format( "id=%i  %s: basisPoints=%f / %s impliedFuture=%f holdDays=%i futureExpiry=%s dividendImpact=%f dividendsToExpiry=%f",
		tickerId, (const char*)getField( (TickType)tickType), basisPoints, formattedBasisPoints, totalDividends, holdDays, futureExpiry, dividendImpact, dividendsToExpiry);

	// add to listbox
	int i = m_ticks.AddString( str);
	
	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OntickGenericTwsctrl1(long id, long tickType, double value) 
{
	// build string
	CString str;
	str.Format( "id=%i  %s=%f",
		id, (const char*)getField( (TickType)tickType), value);

	// add to listbox
	int i = m_ticks.AddString( str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OntickStringTwsctrl1(long id, long tickType, LPCTSTR value) 
{
	// build string
	CString str;
	str.Format( "id=%i  %s=%s",
		id, (const char*)getField( (TickType)tickType), value);

	// add to listbox
	int i = m_ticks.AddString( str);
	
	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OntickOptionComputationTwsctrl1(long tickerId, long tickType, double impliedVol, double delta, double optPrice, double pvDividend,
	double gamma, double vega, double theta, double undPrice) 
{
	CString str, impliedVolStr("N/A"), deltaStr("N/A"), gammaStr("N/A"), vegaStr("N/A"), thetaStr("N/A"), 
		optPriceStr("N/A"), pvDividendStr("N/A"), undPriceStr("N/A");
	if (impliedVol != DBL_MAX) {
		impliedVolStr.Format("%f", impliedVol);
	}
	if (delta != DBL_MAX) {
		deltaStr.Format("%f", delta);
	}
	if (gamma != DBL_MAX) {
		gammaStr.Format("%f", gamma);
	}
	if (vega != DBL_MAX) {
		vegaStr.Format("%f", vega);
	}
	if (theta != DBL_MAX) {
		thetaStr.Format("%f", theta);
	}
	if (optPrice != DBL_MAX) {
		optPriceStr.Format("%f", optPrice);
	}
	if (pvDividend != DBL_MAX) {
		pvDividendStr.Format("%f", pvDividend);
	}
	if (undPrice != DBL_MAX) {
		undPriceStr.Format("%f", undPrice);
	}
	str.Format( "id=%i %s vol=%s delta=%s gamma=%s vega=%s theta=%s optPrice=%s pvDividend=%s undPrice=%s",
		tickerId, (const char*)getField( (TickType)tickType), impliedVolStr, deltaStr, gammaStr, vegaStr, thetaStr, 
		optPriceStr, pvDividendStr, undPriceStr);

	// add to listbox
	int i = m_ticks.AddString( str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient3Dlg::OnconnectionClosedTwsctrl1() 
{
	MessageBox( "Connection closed");	
}

void CClient3Dlg::OnupdateAccountTimeTwsctrl1(LPCTSTR timeStamp) 
{
	s_accountDlg.updateAccountTime(timeStamp);	
}

void CClient3Dlg::OnupdateAccountValueTwsctrl1(LPCTSTR key, LPCTSTR value, LPCTSTR curency, LPCTSTR accountName) 
{
	s_accountDlg.updateAccountValue( key, value, curency, accountName);	
}

void CClient3Dlg::OnnextValidIdTwsctrl1(long id) 
{
	m_dlgOrder->m_id = id;
}

void CClient3Dlg::OnpermIdTwsctrl1(long id, long permId) 
{
	// create string
	CString str;
	str.Format( "id=%i  permId=%i", id, permId);

	// add to listbox
	int i = m_orderStatus.AddString( str);
	
	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex( top);
}


void CClient3Dlg::OnerrMsgTwsctrl1(long id, long errorCode, LPCTSTR errorMsg) 
{
	CString errorStr("Id: ");

	char buf[20];
	_itoa(id, buf, 10);
	errorStr += CString(buf);
	errorStr += " | ";
	errorStr += "Error Code: ";
	_itoa(errorCode, buf, 10);
	errorStr += CString(buf);
	errorStr += " | ";
	errorStr += "Error Msg: ";
	errorStr += errorMsg;
    error( errorStr ) ;
	for (int ctr=0; ctr < NUM_FA_ERROR_CODES; ctr++) {
       faError |= (errorCode == faErrorCodes[ctr]) ;
	}
	if (errorCode == CDlgMktDepth::MKT_DEPTH_DATA_RESET) {
		m_dlgMktDepth->clear();
	}
}

void CClient3Dlg::error(CString &errorStr)
{
	int i = m_errors.AddString( errorStr);
	int top = i - N < 0 ? 0 : i - N;
	m_errors.SetTopIndex( top);
}

void CClient3Dlg::OnReqMktDepth() 
{
	// run dlg box
    m_dlgOrder->init( "Request Market Depth",
		CDlgOrder::REQ_MKT_DEPTH, m_managedAccounts, m_mktDepthOptions);

	INT_PTR nRes = m_dlgOrder->DoModal();

	m_mktDepthOptions = m_dlgOrder->getComOptions();

	if( nRes != IDOK) return;

	m_tws.reqMktDepthEx(m_dlgOrder->m_id, m_dlgOrder->getComContract(),
		m_dlgOrder->m_numRows, m_mktDepthOptions);

	m_dlgMktDepth->DoModal();

	m_tws.cancelMktDepth(m_dlgOrder->m_id);
}

void CClient3Dlg::OnCancelMktDepth() 
{
	// get ticker id
    m_dlgOrder->init( "Cancel Market Depth Data",
		CDlgOrder::CANCEL_MKT_DEPTH, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel market data
	m_tws.cancelMktDepth( m_dlgOrder->m_id);	
}

void CClient3Dlg::OnupdateMktDepthTwsctrl1(long id, long position, long operation, 
        long side, double price, long size) 
{
	m_dlgMktDepth->updateMktDepth(id, position, "", operation, side, price, size);	
}

void CClient3Dlg::OnupdateMktDepthL2Twsctrl1(long id, long position, 
        LPCTSTR marketMaker, long operation, long side, double price, long size) 
{
	m_dlgMktDepth->updateMktDepth(id, position, marketMaker, operation, side, price, size);	
}

void CClient3Dlg::OnNewsBulletins() 
{
	CDlgNewsBulletins dlg;

	if (dlg.DoModal() != IDOK) return;

    dlg.subscribe() 
        ? m_tws.reqNewsBulletins( dlg.allMsgs()) 
        : m_tws.cancelNewsBulletins();	
}

void CClient3Dlg::OnupdateNewsBulletinTwsctrl1(short msgId, short msgType, 
                                               LPCTSTR message, LPCTSTR origExchange) 
{
    CString displayString;
	displayString.Format(" MsgId=%d :: MsgType = %d :: Origin= %s :: Message= %s", 
            msgId, msgType, origExchange, message);

    MessageBox( displayString, "IB News Bulletin", MB_ICONINFORMATION);	
}
void CClient3Dlg::receiveFATwsctrl1(long pFaDataType, LPCTSTR cxml)
{
	switch (pFaDataType) {
        case GROUPS:
          faGroupsXML = cxml ;
          break ;
        case PROFILES:
          faProfilesXML = cxml ;
          break ;
        case ALIASES:
          faAliasesXML = cxml ;
          break ;
    }

	CString faStr("FA ");
	faStr += faDataTypeStr ( (faDataType)pFaDataType );
	faStr += ":";
	DisplayMultiline(m_orderStatus, faStr, cxml);

	if (!faError && faGroupsXML != "" && faProfilesXML != "" && faAliasesXML != "") {
		CDlgFinancialAdvisor dlg;
		dlg.receiveInitialXML(faGroupsXML, faProfilesXML, faAliasesXML);

		if (dlg.DoModal() != IDOK) return;

		dlg.extractXML(faGroupsXML, faProfilesXML, faAliasesXML);
		m_tws.replaceFA( GROUPS, faGroupsXML );
		m_tws.replaceFA( PROFILES, faProfilesXML );
		m_tws.replaceFA( ALIASES, faAliasesXML );

	}
}

void CClient3Dlg::OnFinancialAdvisor()
{
      faGroupsXML = faProfilesXML = faAliasesXML = "" ;
      faError = false ;
      m_tws.requestFA(GROUPS) ;
      m_tws.requestFA(PROFILES) ;
      m_tws.requestFA(ALIASES) ;
}

void CClient3Dlg::OnSetServerLogLevel() 
{
	if (s_dlgLogConfig.DoModal() != IDOK) return;

	// set the TWS log level for API requests/responses
    m_tws.setServerLogLevel( s_dlgLogConfig.serverLogLevel() );
}

void CClient3Dlg::OnmanagedAccountsTwsctrl1(LPCTSTR accountsList) 
{
    m_financialAdvisor = true;  // This event is only triggered for FA customers.
    m_managedAccounts = accountsList;

    CString displayString;
	displayString.Format("Connected : The list of managed accounts are : [%s]", accountsList);
    m_orderStatus.AddString( displayString);	
}

void CClient3Dlg::OnReqAccts() 
{
    m_tws.reqManagedAccts();
}

void CClient3Dlg::OnReqAllOpenOrders() 
{
    m_tws.reqAllOpenOrders();
}

void CClient3Dlg::OnReqAutoOpenOrders() 
{
	// request to automatically bind any newly entered TWS orders 
    // to this API client. NOTE: TWS orders can only be bound to
    // client's with clientId=0.
	m_tws.reqAutoOpenOrders( true);	
}

void CClient3Dlg::OnorderStatusTwsctrl1(long id, LPCTSTR status, long filled, long remaining, 
        double avgFillPrice, long permId, long parentId, double lastFillPrice, long clientId,
		LPCTSTR whyHeld) 
{
	// create string
	CString str;
	str.Format( "orderId=%i clientId=%i permId=%i status=%s  filled=%i  remaining=%i  avgFillPrice=%f lastFillPrice=%f parentId=%i whyHeld=%s",
		id, clientId, permId, (const char *)status, filled, remaining, avgFillPrice, lastFillPrice, parentId, (const char*)whyHeld);

	// Calculate the width of the text string and provide a horizontal scrollbar if required.
	// [This is needed to fix the MFC CListBox HSCROLL bug.
	CDC *pDC = GetDC();
	if ( pDC )
	{
		CSize size;
		CFont* pOldFont = pDC->SelectObject(GetFont());
		if ( pOldFont ) 
		{
			size = pDC->GetTextExtent(str, str.GetLength() );
			pDC->SelectObject(pOldFont);
            if ( size.cx > s_maxOrderStatusStrSize ) 
            {
                s_maxOrderStatusStrSize = size.cx + 5; // 5 pixel whitespace
			    m_orderStatus.SetHorizontalExtent(s_maxOrderStatusStrSize);
            }
		}
		ReleaseDC(pDC);
	}
		
	// add to listbox
	int i = m_orderStatus.AddString( str);
	
	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex( top);
	
}

void CClient3Dlg::OnContractDetailsExTwsctrl1(LONG reqId, IDispatch* dispContractDetails)
{
	// add to listbox
	CString str;
	str.Format("id =%i ===================================", reqId);
	m_orderStatus.AddString(str);

	int i =  m_orderStatus.AddString(" ---- Contract Details Ex begin ----");

	{
		CComQIPtr<IContractDetails> details(dispContractDetails);
		if (details) {

			CString secType;

			IDispatch* dispContractPtr = 0;
			details->get_summary(&dispContractPtr);

			CComPtr<IDispatch> dispContract;
			dispContract.Attach(dispContractPtr);

			CComQIPtr<IContract> contract(dispContract);

			if (contract) {

#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,IContract,contract)

				i = m_orderStatus.AddString("Contract:");

				typedef CComPropAccessor<IContract> Props;

				PRINT_CONTRACT_PROP(conId);
				PRINT_CONTRACT_PROP(symbol);
				PRINT_CONTRACT_PROP(secType);

				// store secType string for future use
				Props::Get(secType, contract, &IContract::get_secType);

				PRINT_CONTRACT_PROP(expiry);
				PRINT_CONTRACT_PROP(strike);
				PRINT_CONTRACT_PROP(right);
				PRINT_CONTRACT_PROP(multiplier);
				PRINT_CONTRACT_PROP(exchange);
				PRINT_CONTRACT_PROP(primaryExchange);
				PRINT_CONTRACT_PROP(currency);
				PRINT_CONTRACT_PROP(localSymbol);
				i = PRINT_CONTRACT_PROP(tradingClass);

#undef PRINT_CONTRACT_PROP
			}

#define PRINT_CONTRACT_DETAILS_PROP(Prop) \
	PRINT_PROP(Prop,IContractDetails,details)

			i = m_orderStatus.AddString("Details:");

			typedef CComPropAccessor<IContractDetails> Props;

			PRINT_CONTRACT_DETAILS_PROP(marketName);
			PRINT_CONTRACT_DETAILS_PROP(minTick);
			PRINT_CONTRACT_DETAILS_PROP(priceMagnifier);
			PRINT_CONTRACT_DETAILS_PROP(orderTypes);
			PRINT_CONTRACT_DETAILS_PROP(validExchanges);
			PRINT_CONTRACT_DETAILS_PROP(underConId);
			PRINT_CONTRACT_DETAILS_PROP(longName);

			if (secType != "BOND") {
				PRINT_CONTRACT_DETAILS_PROP(contractMonth);
				PRINT_CONTRACT_DETAILS_PROP(industry);
				PRINT_CONTRACT_DETAILS_PROP(category);
				PRINT_CONTRACT_DETAILS_PROP(subcategory);
				PRINT_CONTRACT_DETAILS_PROP(timeZoneId);
				PRINT_CONTRACT_DETAILS_PROP(tradingHours);
				PRINT_CONTRACT_DETAILS_PROP(liquidHours);
			}
			PRINT_CONTRACT_DETAILS_PROP(evRule);
			PRINT_CONTRACT_DETAILS_PROP(evMultiplier);

			if (secType == "BOND") {
				i = m_orderStatus.AddString("Bond Details:");
				PRINT_CONTRACT_DETAILS_PROP(cusip);
				PRINT_CONTRACT_DETAILS_PROP(ratings);
				PRINT_CONTRACT_DETAILS_PROP(descAppend);
				PRINT_CONTRACT_DETAILS_PROP(bondType);
				PRINT_CONTRACT_DETAILS_PROP(couponType);
				PRINT_CONTRACT_DETAILS_PROP(callable);
				PRINT_CONTRACT_DETAILS_PROP(putable);
				PRINT_CONTRACT_DETAILS_PROP(coupon);
				PRINT_CONTRACT_DETAILS_PROP(convertible);
				PRINT_CONTRACT_DETAILS_PROP(maturity);
				PRINT_CONTRACT_DETAILS_PROP(issueDate);
				PRINT_CONTRACT_DETAILS_PROP(nextOptionDate);
				PRINT_CONTRACT_DETAILS_PROP(nextOptionType);
				PRINT_CONTRACT_DETAILS_PROP(nextOptionPartial);
				PRINT_CONTRACT_DETAILS_PROP(notes);
			}

			m_orderStatus.AddString("  secIdList={");

			CComQIPtr<ITagValueList> secIdList;
			Props::GetQI(secIdList, details, &IContractDetails::get_secIdList);

			if( secIdList) {

				ITagValueList* secIdListPtr = secIdList;

				typedef CComPropAccessor<ITagValueList> Props;

				LONG secIdListCount = 0;
				Props::Get(secIdListCount, secIdListPtr, &ITagValueList::get_Count);

				if( secIdListCount > 0) {

					for( LONG i = 0; i < secIdListCount; ++i) {

						CComQIPtr<ITagValue> tagValue;
						Props::GetQI_P1(tagValue, secIdListPtr, &ITagValueList::get_Item, i);

						if (!tagValue)
							continue;

						TagValue param;
						CTwsHelpers::CopyTwsTagValue2TagValue(param, tagValue);

						CString str;
						str.Format("    %s=%s", param.tag, param.value);
						m_orderStatus.AddString(str);
					}
				}
			}
			i = m_orderStatus.AddString("  }");

#undef PRINT_CONTRACT_DETAILS_PROP
		}
	}

	i = m_orderStatus.AddString(" ---- Contract Details Ex end ------");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnContractDetailsEndTwsctrl1(LONG reqId)
{
	CString str;
	str.Format("id =%i =============== end ===============", reqId);

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnOpenOrderExTwsctrl1(LONG id,
	IDispatch* dispContract, IDispatch* dispOrder, IDispatch* dispOrderState)
{
	// create string
	CString str;
	str.Format("openOrderEx: orderId=%i", id);

	// add to listbox
	int i =  m_orderStatus.AddString(str);

	{
		CComQIPtr<IContract> contract(dispContract);
		CComQIPtr<IOrder> order(dispOrder);

		if (contract && order) {

#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,IContract,contract)

			i = m_orderStatus.AddString("Contract:");

			typedef CComPropAccessor<IContract> PropsContract;
			typedef CComPropAccessor<IOrder> PropsOrder;

			PRINT_CONTRACT_PROP(conId);
			PRINT_CONTRACT_PROP(symbol);
			PRINT_CONTRACT_PROP(secType);
			PRINT_CONTRACT_PROP(expiry);
			PRINT_CONTRACT_PROP(strike);
			PRINT_CONTRACT_PROP(right);
			PRINT_CONTRACT_PROP(multiplier);
			PRINT_CONTRACT_PROP(exchange);
			PRINT_CONTRACT_PROP(primaryExchange);
			PRINT_CONTRACT_PROP(currency);
			PRINT_CONTRACT_PROP(localSymbol);
			PRINT_CONTRACT_PROP(tradingClass);
			i = PRINT_CONTRACT_PROP(comboLegsDescrip);

#undef PRINT_CONTRACT_PROP

			m_orderStatus.AddString("  comboLegs={");

			CComQIPtr<IComboLegList> comboLegs;
			CComQIPtr<IOrderComboLegList> orderComboLegs;
			PropsContract::GetQI(comboLegs, contract, &IContract::get_comboLegs);
			PropsOrder::GetQI(orderComboLegs, order, &IOrder::get_orderComboLegs);

			if( comboLegs ) {
				IComboLegList* comboLegList = comboLegs;
				typedef CComPropAccessor<IComboLegList> PropsComboLegList;
				LONG comboLegsCount = 0;
				PropsComboLegList::Get(comboLegsCount, comboLegList, &IComboLegList::get_Count);

				IOrderComboLegList* orderComboLegList = orderComboLegs;
				typedef CComPropAccessor<IOrderComboLegList> PropsOrderComboLegList;
				LONG orderComboLegsCount = 0;

				if ( orderComboLegs ) {
					PropsOrderComboLegList::Get(orderComboLegsCount, orderComboLegList, &IOrderComboLegList::get_Count);
				}

				for( LONG i = 0; i < comboLegsCount; ++i) {

					CComQIPtr<IComboLeg> comboLeg;
					PropsComboLegList::GetQI_P1(comboLeg, comboLegList, &IComboLegList::get_Item, i);

					if (!comboLeg)
						continue;

					CString str;

					long conId;
					long ratio;
					CString action;
					CString exchange;
					long openClose;
					long shortSaleSlot;
					CString designatedLocation;
					int exemptCode;
					CString orderComboLegPriceStr("");

					typedef CComPropAccessor<IComboLeg> PropsComboLeg;

					PropsComboLeg::Get(conId, comboLeg, &IComboLeg::get_conId);
					PropsComboLeg::Get(ratio, comboLeg, &IComboLeg::get_ratio);
					PropsComboLeg::Get(action, comboLeg, &IComboLeg::get_action);
					PropsComboLeg::Get(exchange, comboLeg, &IComboLeg::get_exchange);
					PropsComboLeg::Get(openClose, comboLeg, &IComboLeg::get_openClose);
					PropsComboLeg::Get(shortSaleSlot, comboLeg, &IComboLeg::get_shortSaleSlot);
					PropsComboLeg::Get(designatedLocation, comboLeg, &IComboLeg::get_designatedLocation);
					PropsComboLeg::Get(exemptCode, comboLeg, &IComboLeg::get_exemptCode);


					if (comboLegsCount == orderComboLegsCount){

						CComQIPtr<IOrderComboLeg> orderComboLeg;
						PropsOrderComboLegList::GetQI_P1(orderComboLeg, orderComboLegList, &IOrderComboLegList::get_Item, i);
						
						if (!orderComboLeg)
							continue;
						
						double price;

						typedef CComPropAccessor<IOrderComboLeg> PropsOrderComboLeg;
						PropsOrderComboLeg::Get(price, orderComboLeg, &IOrderComboLeg::get_price);

						if (price != DBL_MAX) {
							orderComboLegPriceStr.Format("price=%f", price);
						}

					}
					str.Format( "    leg %i: conId=%i ratio=%i action=%s exchange=%s openClose=%i shortSaleSlot=%i designatedLocation=%s exemptCode=%i %s", 
					(i + 1), conId, ratio, action, exchange, openClose, shortSaleSlot, designatedLocation, exemptCode, 
					orderComboLegPriceStr);

					m_orderStatus.AddString(str);
				}
			}
			i = m_orderStatus.AddString("  }");


			CComQIPtr<IUnderComp> underComp;
			PropsContract::GetQI(underComp, contract, &IContract::get_underComp);

			if (underComp) {

#define PRINT_UNDER_COMP_PROP(Prop) \
		PRINT_PROP_WPREF("underComp.",Prop,IUnderComp,underComp)

				PRINT_UNDER_COMP_PROP(conId);
				PRINT_UNDER_COMP_PROP(delta);
				i = PRINT_UNDER_COMP_PROP(price);

#undef PRINT_UNDER_COMP_PROP
			}

#define PRINT_ORDER_PROP(Prop) \
	PRINT_PROP(Prop,IOrder,order)

			i = m_orderStatus.AddString("Order:");

			PRINT_ORDER_PROP(orderId);
			PRINT_ORDER_PROP(clientId);
			PRINT_ORDER_PROP(permId);
			PRINT_ORDER_PROP(action);
			PRINT_ORDER_PROP(totalQuantity);
			PRINT_ORDER_PROP(orderType);
			PRINT_ORDER_PROP(lmtPrice);
			PRINT_ORDER_PROP(auxPrice);

			i = m_orderStatus.AddString("Extended Attrs:");

			PRINT_ORDER_PROP(timeInForce);
			PRINT_ORDER_PROP(ocaGroup);
			PRINT_ORDER_PROP(ocaType);
			PRINT_ORDER_PROP(orderRef);
			PRINT_ORDER_PROP(transmit);
			PRINT_ORDER_PROP(parentId);
			PRINT_ORDER_PROP(blockOrder);
			PRINT_ORDER_PROP(sweepToFill);
			PRINT_ORDER_PROP(displaySize);
			PRINT_ORDER_PROP(triggerMethod);
			PRINT_ORDER_PROP(outsideRth);
			PRINT_ORDER_PROP(hidden);
			PRINT_ORDER_PROP(goodAfterTime);
			PRINT_ORDER_PROP(goodTillDate);
			PRINT_ORDER_PROP(overridePercentageConstraints);
			PRINT_ORDER_PROP(rule80A);
			PRINT_ORDER_PROP(allOrNone);
			PRINT_ORDER_PROP(minQty);
			PRINT_ORDER_PROP(percentOffset);
			PRINT_ORDER_PROP(trailStopPrice);
			PRINT_ORDER_PROP(trailingPercent);
			PRINT_ORDER_PROP(whatIf);
			PRINT_ORDER_PROP(notHeld);

			PRINT_ORDER_PROP(faGroup);
			PRINT_ORDER_PROP(faProfile);
			PRINT_ORDER_PROP(faMethod);
			PRINT_ORDER_PROP(faPercentage);

			PRINT_ORDER_PROP(account);
			PRINT_ORDER_PROP(settlingFirm);
			PRINT_ORDER_PROP(clearingAccount);
			PRINT_ORDER_PROP(clearingIntent);

			PRINT_ORDER_PROP(openClose);
			PRINT_ORDER_PROP(origin);
			PRINT_ORDER_PROP(shortSaleSlot);
			PRINT_ORDER_PROP(designatedLocation);
			PRINT_ORDER_PROP(exemptCode);

			PRINT_ORDER_PROP(discretionaryAmt);
			PRINT_ORDER_PROP(eTradeOnly);
			PRINT_ORDER_PROP(firmQuoteOnly);
			PRINT_ORDER_PROP(nbboPriceCap);
			PRINT_ORDER_PROP(optOutSmartRouting);

			PRINT_ORDER_PROP(auctionStrategy);

			PRINT_ORDER_PROP(startingPrice);
			PRINT_ORDER_PROP(stockRefPrice);
			PRINT_ORDER_PROP(delta);

			PRINT_ORDER_PROP(stockRangeLower);
			PRINT_ORDER_PROP(stockRangeUpper);

			PRINT_ORDER_PROP(volatility);
			PRINT_ORDER_PROP(volatilityType);
			PRINT_ORDER_PROP(continuousUpdate);
			PRINT_ORDER_PROP(referencePriceType);
			PRINT_ORDER_PROP(deltaNeutralOrderType);
			PRINT_ORDER_PROP(deltaNeutralAuxPrice);
			PRINT_ORDER_PROP(deltaNeutralConId);
			PRINT_ORDER_PROP(deltaNeutralSettlingFirm);
			PRINT_ORDER_PROP(deltaNeutralClearingAccount);
			PRINT_ORDER_PROP(deltaNeutralClearingIntent);
			PRINT_ORDER_PROP(deltaNeutralOpenClose);
			PRINT_ORDER_PROP(deltaNeutralShortSale);
			PRINT_ORDER_PROP(deltaNeutralShortSaleSlot);
			PRINT_ORDER_PROP(deltaNeutralDesignatedLocation);

			PRINT_ORDER_PROP(basisPoints);
			PRINT_ORDER_PROP(basisPointsType);
			m_orderStatus.AddString("  smartComboRoutingParams={");

			CComQIPtr<ITagValueList> smartComboRoutingParams;
			PropsOrder::GetQI(smartComboRoutingParams, order, &IOrder::get_smartComboRoutingParams);

			if( smartComboRoutingParams) {

				ITagValueList* smartComboRoutingParamsPtr = smartComboRoutingParams;

				typedef CComPropAccessor<ITagValueList> Props;

				LONG smartComboRoutingParamsCount = 0;
				Props::Get(smartComboRoutingParamsCount, smartComboRoutingParamsPtr, &ITagValueList::get_Count);

				if( smartComboRoutingParamsCount > 0) {

					for( LONG i = 0; i < smartComboRoutingParamsCount; ++i) {

						CComQIPtr<ITagValue> tagValue;
						Props::GetQI_P1(tagValue, smartComboRoutingParamsPtr, &ITagValueList::get_Item, i);

						if (!tagValue)
							continue;

						TagValue param;
						CTwsHelpers::CopyTwsTagValue2TagValue(param, tagValue);

						CString str;
						str.Format("    %s=%s", param.tag, param.value);
						m_orderStatus.AddString(str);
					}
				}
			}
			i = m_orderStatus.AddString("  }");

			PRINT_ORDER_PROP(scaleInitLevelSize);
			PRINT_ORDER_PROP(scaleSubsLevelSize);
			PRINT_ORDER_PROP(scalePriceIncrement);
			PRINT_ORDER_PROP(scalePriceAdjustValue);
			PRINT_ORDER_PROP(scalePriceAdjustInterval);
			PRINT_ORDER_PROP(scaleProfitOffset);
			PRINT_ORDER_PROP(scaleAutoReset);
			PRINT_ORDER_PROP(scaleInitPosition);
			PRINT_ORDER_PROP(scaleInitFillQty);
			PRINT_ORDER_PROP(scaleRandomPercent);

			PRINT_ORDER_PROP(hedgeType);
			i = PRINT_ORDER_PROP(hedgeParam);

			CString algoStrategy;
			PropsOrder::Get(algoStrategy, order, &IOrder::get_algoStrategy);

			if (!algoStrategy.IsEmpty()) {

				m_orderStatus.AddString(CString("  algoStrategy=")+algoStrategy);
				m_orderStatus.AddString("  algoParams={");

				CComQIPtr<ITagValueList> algoParams;
				PropsOrder::GetQI(algoParams, order, &IOrder::get_algoParams);

				if( algoParams) {

					ITagValueList* algoParamsPtr = algoParams;

					typedef CComPropAccessor<ITagValueList> Props;

					LONG algoParamsCount = 0;
					Props::Get(algoParamsCount, algoParamsPtr, &ITagValueList::get_Count);

					if( algoParamsCount > 0) {

						for( LONG i = 0; i < algoParamsCount; ++i) {

							CComQIPtr<ITagValue> tagValue;
							Props::GetQI_P1(tagValue, algoParamsPtr, &ITagValueList::get_Item, i);

							if (!tagValue)
								continue;

							TagValue param;
							CTwsHelpers::CopyTwsTagValue2TagValue(param, tagValue);

							CString str;
							str.Format("    %s=%s", param.tag, param.value);
							m_orderStatus.AddString(str);
						}
					}
				}
				i = m_orderStatus.AddString("  }");
			}

#undef PRINT_ORDER_PROP
		}
	}

	{
		CComQIPtr<IOrderState> orderState(dispOrderState);
		if (orderState) {

#define PRINT_ORDER_STATE_PROP(Prop) \
	PRINT_PROP(Prop,IOrderState,orderState)

			i = m_orderStatus.AddString("OrderState:");

			typedef CComPropAccessor<IOrderState> Props;

			PRINT_ORDER_STATE_PROP(status);
			PRINT_ORDER_STATE_PROP(initMargin);
			PRINT_ORDER_STATE_PROP(maintMargin);
			PRINT_ORDER_STATE_PROP(equityWithLoan);
			PRINT_ORDER_STATE_PROP(commission);
			PRINT_ORDER_STATE_PROP(minCommission);
			PRINT_ORDER_STATE_PROP(maxCommission);
			PRINT_ORDER_STATE_PROP(commissionCurrency);
			i = PRINT_ORDER_STATE_PROP(warningText);

#undef PRINT_ORDER_STATE_PROP
		}
	}

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnOpenOrderEndTwsctrl1()
{
	int i = m_orderStatus.AddString(" =============== end ===============");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}


void CClient3Dlg::OnExecDetailsExTwsctrl1(LONG reqId,
	IDispatch* dispContract, IDispatch* dispExecution)
{
	int i = m_orderStatus.AddString("---- Execution Details begin ----");

	// create string
	CString str;
	str.Format("execDetailsEx: reqId=%i", reqId);

	// add to listbox
	i =  m_orderStatus.AddString(str);

	{
		CComQIPtr<IContract> contract(dispContract);
		if (contract) {

#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,IContract,contract)

			i = m_orderStatus.AddString("Contract:");

			typedef CComPropAccessor<IContract> Props;

			PRINT_CONTRACT_PROP(conId);
			PRINT_CONTRACT_PROP(symbol);
			PRINT_CONTRACT_PROP(secType);
			PRINT_CONTRACT_PROP(expiry);
			PRINT_CONTRACT_PROP(strike);
			PRINT_CONTRACT_PROP(right);
			PRINT_CONTRACT_PROP(multiplier);
			PRINT_CONTRACT_PROP(exchange);
			PRINT_CONTRACT_PROP(primaryExchange);
			PRINT_CONTRACT_PROP(currency);
			PRINT_CONTRACT_PROP(localSymbol);
			PRINT_CONTRACT_PROP(tradingClass);

#undef PRINT_CONTRACT_PROP
		}
	}

	{
		CComQIPtr<IExecution> execution(dispExecution);
		if (execution) {

#define PRINT_EXECUTION_PROP(Prop) \
	PRINT_PROP(Prop,IExecution,execution)

			i = m_orderStatus.AddString("Execution:");

			typedef CComPropAccessor<IExecution> Props;

			PRINT_EXECUTION_PROP(execId);
			PRINT_EXECUTION_PROP(orderId);
			PRINT_EXECUTION_PROP(clientId);
			PRINT_EXECUTION_PROP(permId);
			PRINT_EXECUTION_PROP(time);
			PRINT_EXECUTION_PROP(acctNumber);
			PRINT_EXECUTION_PROP(exchange);
			PRINT_EXECUTION_PROP(side);
			PRINT_EXECUTION_PROP(shares);
			PRINT_EXECUTION_PROP(price);
			PRINT_EXECUTION_PROP(liquidation);
			PRINT_EXECUTION_PROP(cumQty);
			PRINT_EXECUTION_PROP(avgPrice);
			PRINT_EXECUTION_PROP(orderRef);
			PRINT_EXECUTION_PROP(evRule);
			PRINT_EXECUTION_PROP(evMultiplier);

#undef PRINT_EXECUTION_PROP
		}
	}

	i = m_orderStatus.AddString(" ---- Execution Details End ----");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}


void CClient3Dlg::OnExecDetailsEndTwsctrl1(LONG reqId) 
{	
	CString str;
	str.Format("reqId=%i =============== end ===============", reqId);

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnUpdatePortfolioExTwsctrl1(IDispatch* contract, long position, double marketPrice, 
        double marketValue, double averageCost, double unrealizedPNL, double realizedPNL, LPCTSTR accountName ) 
{	
	s_accountDlg.updatePortfolio(contract, position, marketPrice,
		marketValue, averageCost, unrealizedPNL, realizedPNL, accountName);
}

void CClient3Dlg::OnAccountDownloadEndTwsctrl1(LPCTSTR accountName) 
{	
	s_accountDlg.accountDownloadEnd(accountName);

	CString str;
	str.Format("Account Download End: %s", accountName);
	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnDeltaNeutralValidationTwsctrl1(LONG reqId, IDispatch* dispUnderComp)
{
		// create string
	CString str;
	str.Format("deltaNeutralValidation: reqId=%i", reqId);

	int i = m_orderStatus.AddString(str);

	{
		CComQIPtr<IUnderComp> underComp(dispUnderComp);
		if (underComp) {

#define PRINT_UNDER_COMP_PROP(Prop) \
	PRINT_PROP(Prop,IUnderComp,underComp)

			PRINT_UNDER_COMP_PROP(conId);
			PRINT_UNDER_COMP_PROP(delta);
			i = PRINT_UNDER_COMP_PROP(price);

#undef PRINT_UNDER_COMP_PROP
		}
	}

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnTickSnapshotEndTwsctrl1(LONG reqId) 
{	
	CString str;
	str.Format("id=%i =============== end ===============", reqId);

	int i = m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex(top);
}

void CClient3Dlg::OnMarketDataTypeTwsctrl1(long reqId, long marketDataType) 
{	
	CString str;
	switch (marketDataType){
		case REALTIME:
			str.Format("id=%i marketDataType=Real-Time", reqId);
			break;
		case FROZEN:
			str.Format("id=%i marketDataType=Frozen", reqId);
			break;
		default:
			str.Format("id=%i marketDataType=Unknown", reqId);
	}

	int i = m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex(top);
}

void CClient3Dlg::OnCommissionReportTwsctrl1(IDispatch* dispCommissionReport)
{
	int i = m_orderStatus.AddString("---- Commission Report ----");

	{
		CComQIPtr<ICommissionReport> commissionReport(dispCommissionReport);
		if (commissionReport) {

#define PRINT_COMMISSION_REPORT_PROP(Prop) \
	PRINT_PROP(Prop,ICommissionReport,commissionReport)

		typedef CComPropAccessor<ICommissionReport> Props;

		PRINT_COMMISSION_REPORT_PROP(execId);
		PRINT_COMMISSION_REPORT_PROP(commission);
		PRINT_COMMISSION_REPORT_PROP(currency);
		PRINT_COMMISSION_REPORT_PROP(realizedPNL);
		PRINT_COMMISSION_REPORT_PROP(yield);
		PRINT_COMMISSION_REPORT_PROP(yieldRedemptionDate);

#undef PRINT_COMMISSION_REPORT_PROP
		}
	}

	i = m_orderStatus.AddString(" ---- Commission Report End ----");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnPositionTwsctrl1(LPCTSTR account, IDispatch* dispContract, int position, double avgCost)
{
	int i = m_orderStatus.AddString("---- Position begin ----");

	// create string
	CString str;
	str.Format( "account=%s", (const char *)account);

	// add to listbox
	i = m_orderStatus.AddString( str);

	{
		CComQIPtr<IContract> contract(dispContract);
		if (contract) {

#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,IContract,contract)

		typedef CComPropAccessor<IContract> Props;

		i = m_orderStatus.AddString("Contract:");

		PRINT_CONTRACT_PROP(conId);
		PRINT_CONTRACT_PROP(symbol);
		PRINT_CONTRACT_PROP(secType);
		PRINT_CONTRACT_PROP(expiry);
		PRINT_CONTRACT_PROP(strike);
		PRINT_CONTRACT_PROP(right);
		PRINT_CONTRACT_PROP(multiplier);
		PRINT_CONTRACT_PROP(exchange);
		PRINT_CONTRACT_PROP(primaryExchange);
		PRINT_CONTRACT_PROP(currency);
		PRINT_CONTRACT_PROP(localSymbol);
		PRINT_CONTRACT_PROP(tradingClass);

#undef PRINT_CONTRACT_PROP
		}
	}

	// create string
	str.Format( "position=%i", position);

	// add to listbox
	i = m_orderStatus.AddString( str);

	// create string
	str.Format( "avgCost=%f", avgCost);

	// add to listbox
	i = m_orderStatus.AddString( str);

	i = m_orderStatus.AddString(" ---- Position End ----");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnPositionEndTwsctrl1()
{
	CString str;
	str.Format("=============== end ===============");

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnAccountSummaryTwsctrl1( long reqId, LPCTSTR account, LPCTSTR tag,
								 LPCTSTR value, LPCTSTR curency)
{
	int i = m_orderStatus.AddString("---- Account Summary begin ----");

	// create string
	CString str;
	str.Format("accountSummary: reqId=%i account=%s tag=%s value=%s currency=%s", reqId, 
		(const char *)account, (const char *)tag, (const char *)value, (const char *)curency);

	// add to listbox
	i = m_orderStatus.AddString(str);

	i = m_orderStatus.AddString(" ---- Account Summary End ----");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnAccountSummaryEndTwsctrl1( long reqId)
{
	CString str;
	str.Format("reqId=%i =============== end ===============", reqId);

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient3Dlg::OnVerifyMessageAPITwsctrl1( LPCTSTR apiData) {}

void CClient3Dlg::OnVerifyCompletedTwsctrl1( BOOL isSuccessful, LPCTSTR errorText) {}

void CClient3Dlg::OnDisplayGroupListTwsctrl1( long reqId, LPCTSTR groups) 
{
	m_dlgGroups->displayGroupList(reqId, (IBString&)groups);
}

void CClient3Dlg::OnDisplayGroupUpdatedTwsctrl1( long reqId, LPCTSTR contractInfo) 
{
	m_dlgGroups->displayGroupUpdated(reqId, (IBString&)contractInfo);
}

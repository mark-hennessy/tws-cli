/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "client2.h"
#include "client2Dlg.h"
#include "EClientSocket.h"   // C:\JTS\SocketClient\include must be added to include path
#include "TwsSocketClientErrors.h"   // C:\JTS\SocketClient\include must be added to include path
#include "DlgOrder.h"
#include "DlgExtOrd.h"
#include "DlgAccount.h"
#include "DlgConnect.h"
#include "DlgMktDepth.h"
#include "Contract.h"
#include "Execution.h"
#include "ScannerSubscription.h"
#include "DlgNewsBulletins.h"
#include "DlgLogConfig.h"
#include "RptFilterDlg.h"
#include "AcctUpdatesDlg.h"
#include "DlgFinancialAdvisor.h"
#include "DlgScanner.h"
#include "CommissionReport.h"
#include "DlgAccountSummary.h"
#include "DlgGroups.h"

#include "OrderState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// consts
const int TIMER = 0;
const int N = 5;
const CString CClient2Dlg::RETURN_NEWLINE("\r\n");
const CString CClient2Dlg::NEWLINE("\n");
const CString CClient2Dlg::RETURN("\r");
const CString CClient2Dlg::TAB("\t");
const CString CClient2Dlg::FOUR_SPACES("    ");

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
	{ 503, 504, 505, 522, 1100, NOT_AN_FA_ACCOUNT_ERROR } ;


struct CClient2Dlg::PropPrintHelpers {

	static int Print(CHScrollListBox& listBox, const char* name, bool boolVal)
	{
		CString str;
		str.Format("  %s=%i", name, boolVal);
		return listBox.AddString(str);
	}

	static int Print(CHScrollListBox& listBox, const char* name, int intVal)
	{
		CString str;
		if (intVal == INT_MAX) {
			str.Format("  %s=", name);
		}
		else {
			str.Format("  %s=%i", name, intVal);
		}
		return listBox.AddString(str);
	}

	static int Print(CHScrollListBox& listBox, const char* name, double dblVal)
	{
		CString str;
		if (dblVal == DBL_MAX) {
			str.Format("  %s=", name);
		}
		else {
			str.Format("  %s=%f", name, dblVal);
		}
		return listBox.AddString(str);
	}

	static int Print(CHScrollListBox& listBox, const char* name, const CString& strVal)
	{
		CString str;
		str.Format("  %s=%s", name, strVal);
		return listBox.AddString(str);
	}
};

#define PRINT_PROP(Prop,Value) \
	PropPrintHelpers::Print(m_orderStatus, #Prop, Value);

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
// CClient2Dlg dialog

CClient2Dlg::CClient2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClient2Dlg::IDD, pParent)
	, m_dlgOrder(new CDlgOrder(this))
	, m_dlgMktDepth(new CDlgMktDepth(this))
	, m_execFilter(new ExecutionFilter)
	, m_scannerSubscr(new ScannerSubscription)
	, m_dlgGroups(new CDlgGroups(this))
{

	//{{AFX_DATA_INIT(CClient2Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pClient = new EClientSocket( this);
	s_maxOrderStatusStrSize = 0;

	m_financialAdvisor = false;

	{
#define PUT_PROP(Prop, Value) \
		m_scannerSubscr->Prop = Value;

		PUT_PROP(numberOfRows, 10);
		PUT_PROP(instrument, "STK");
		PUT_PROP(locationCode, "STK.US.MAJOR");
		PUT_PROP(scanCode, "TOP_PERC_GAIN");
		PUT_PROP(abovePrice, 3);
		PUT_PROP(marketCapAbove, 100000000);
		PUT_PROP(scannerSettingPairs, "Annual,true");

#undef PUT_PROP

	}
}

CClient2Dlg::~CClient2Dlg()
{
	delete m_pClient;
}

void CClient2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClient2Dlg)
	DDX_Control(pDX, IDC_LIST3, m_orderStatus);
	DDX_Control(pDX, IDC_LIST2, m_ticks);
	DDX_Control(pDX, IDC_LIST1, m_errors);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClient2Dlg, CDialog)
	//{{AFX_MSG_MAP(CClient2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnConnect)
	ON_BN_CLICKED(IDC_BUTTON3, OnReqMktData)
	ON_BN_CLICKED(IDC_BUTTON4, OnCancelMktData)
	ON_BN_CLICKED(IDC_WHAT_IF, OnWhatIf)
	ON_BN_CLICKED(IDC_BUTTON5, OnPlaceOrder)
	ON_BN_CLICKED(IDC_BUTTON6, OnCancelOrder)
	ON_BN_CLICKED(IDC_BUTTON7, OnDisconnect)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_EXTORD, OnExtord)
	ON_BN_CLICKED(IDC_ReqOpenOrders, OnReqOpenOrders)
	ON_BN_CLICKED(IDC_ACCT_UPDATES, OnReqAccountUpdate)
	ON_BN_CLICKED(IDC_ReqExecutions, OnReqExecutions)
	ON_BN_CLICKED(IDC_ReqIds, OnReqIds)
	ON_BN_CLICKED(IDC_REQ_CONTRACT, OnReqContractDetails)
	ON_BN_CLICKED(IDC_REQ_MKT_DEPTH, OnReqMktDepth)
	ON_BN_CLICKED(IDC_CANCEL_MKT_DEPTH, OnCancelMktDepth)
	ON_BN_CLICKED(IDC_NEWS_BULLETINS, OnNewsBulletins)
	ON_BN_CLICKED(IDC_LOGGING, OnSetServerLogLevel)
	ON_BN_CLICKED(IDC_REQ_ALL_OPEN_ORDERS, OnReqAllOpenOrders)
	ON_BN_CLICKED(IDC_REQ_AUTO_OPEN_ORDERS, OnReqAutoOpenOrders)
	ON_BN_CLICKED(IDC_REQ_ACCTS, OnReqAccts)
	ON_BN_CLICKED(IDC_FINANCIAL_ADVISOR, OnFinancialAdvisor)
	ON_BN_CLICKED(IDC_HISTORICAL_DATA, OnReqHistoricalData)
	ON_BN_CLICKED(IDC_EXERCISE_OPTIONS, OnExerciseOptions)
	ON_BN_CLICKED(IDC_CANCEL_HIST_DATA, OnCancelHistData)
	ON_BN_CLICKED(IDC_REQ_REAL_TIME_BARS, OnReqRealTimeBars)
	ON_BN_CLICKED(IDC_CANCEL_REAL_TIME_BARS, OnCancelRealTimeBars)
	ON_BN_CLICKED(IDC_REQ_CURRENT_TIME, OnReqCurrentTime)
	ON_BN_CLICKED(IDC_MARKET_SCANNER, OnMarketScanner)
	ON_BN_CLICKED(IDC_CALC_IMPL_VOL, OnCalculateImpliedVolatility)
	ON_BN_CLICKED(IDC_CALC_OPTION_PRICE, OnCalculateOptionPrice)
	ON_BN_CLICKED(IDC_CANCEL_CALC_IMPL_VOL, OnCancelCalculateImpliedVolatility)
	ON_BN_CLICKED(IDC_CANCEL_CALC_OPTION_PRICE, OnCancelCalculateOptionPrice)
	ON_BN_CLICKED(IDC_REQ_GLOBAL_CANCEL, OnReqGlobalCancel)
	ON_BN_CLICKED(IDC_REQ_MARKET_DATA_TYPE, OnReqMarketDataType)
	ON_BN_CLICKED(IDC_REQUEST_POSITIONS, OnReqPositions)
	ON_BN_CLICKED(IDC_CANCEL_POSITIONS, OnCancelPositions)
	ON_BN_CLICKED(IDC_REQUEST_ACCOUNT_SUMMARY, OnReqAccountSummary)
	ON_BN_CLICKED(IDC_CANCEL_ACCOUNT_SUMMARY, OnCancelAccountSummary)
	ON_BN_CLICKED(IDC_BTN_GROUPS, OnQueryGroups)
	ON_BN_CLICKED(IDC_FUNDAMENTAL_DATA, OnFundamentalData)
	ON_BN_CLICKED(IDC_CANCEL_FUNDAMENTAL_DATA, OnCancelFundamentalData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient2Dlg message handlers

BOOL CClient2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX  &0xFFF0) == IDM_ABOUTBOX);
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

	m_orderStatus.ModifyStyle( 0, WM_HSCROLL, 0 );

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;
}

void CClient2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID  &0xFFF0) == IDM_ABOUTBOX)
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

void CClient2Dlg::OnPaint()
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
HCURSOR CClient2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



/////////////////////////////////////////////////////////////////////////////
// handle user events
void CClient2Dlg::OnConnect()
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

	m_pClient->eConnect( dlg.m_ipAddress, dlg.m_port, dlg.m_clientId, /* extraAuth */ false);

	if( m_pClient->serverVersion() > 0)	{
		CString displayString;
		displayString.Format( "Connected to Tws server version %d at %s.",
			m_pClient->serverVersion(), m_pClient->TwsConnectionTime());
		int i = m_orderStatus.AddString( displayString);
		m_orderStatus.SetTopIndex( i);
	}
}

// req mkt data
void CClient2Dlg::OnReqMktData()
{
	// run dlg box
	m_dlgOrder->init( this, "Request Market Data", CDlgOrder::REQ_MKT_DATA, m_managedAccounts, &m_mktDataOptions);

	if( m_dlgOrder->DoModal() != IDOK) return;

	// request ticker
	m_pClient->reqMktData( m_dlgOrder->m_id, m_dlgOrder->getContract(),
		m_dlgOrder->m_genericTicks, m_dlgOrder->m_snapshotMktData, m_mktDataOptions);
}

void CClient2Dlg::OnCancelMktData()
{
	// get ticker id
	m_dlgOrder->init( this, "Cancel Market Data", CDlgOrder::CANCEL_MKT_DATA, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel market data
	m_pClient->cancelMktData( m_dlgOrder->m_id);
}

void CClient2Dlg::OnCancelMktDepth()
{
	// get ticker id
	m_dlgOrder->init( this, "Cancel Market Depth", CDlgOrder::CANCEL_MKT_DEPTH, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel market data
	m_pClient->cancelMktDepth( m_dlgOrder->m_id);
}

void CClient2Dlg::cancelMktDepth(int tickerId)
{
	// cancel market data
	m_pClient->cancelMktDepth( tickerId);
}

void CClient2Dlg::OnWhatIf()
{
	placeOrder(/* whatIf */ true);
}

void CClient2Dlg::OnPlaceOrder()
{
	placeOrder(/* whatIf */ false);
}

void CClient2Dlg::placeOrder(bool whatIf)
{
	Order& order = m_dlgOrder->getOrder();

	// run order box
	m_dlgOrder->init(this, "Place Order", CDlgOrder::ORDER, m_managedAccounts, &order.orderMiscOptions);

	if( m_dlgOrder->DoModal() != IDOK) return;

	// save old and set new value of whatIf attribute
	bool savedWhatIf = order.whatIf;
	order.whatIf = whatIf;

	// place order
	m_pClient->placeOrder( m_dlgOrder->m_id, m_dlgOrder->getContract(), order);

	// restore whatIf attribute
	order.whatIf = savedWhatIf;
}

void CClient2Dlg::OnCancelOrder()
{
	// get order id
	m_dlgOrder->init( this, "Cancel Order", CDlgOrder::CANCEL_ORDER, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel order
	m_pClient->cancelOrder( m_dlgOrder->m_id);
}

void CClient2Dlg::OnReqOpenOrders()
{
	// request open orders
	m_pClient->reqOpenOrders();
}

void CClient2Dlg::OnReqAllOpenOrders()
{
	// request list of all open orders
	m_pClient->reqAllOpenOrders();
}

void CClient2Dlg::OnReqAutoOpenOrders()
{
	// request to automatically bind any newly entered TWS orders
	// to this API client. NOTE: TWS orders can only be bound to
	// client's with clientId=0.
	m_pClient->reqAutoOpenOrders( true);
}

void CClient2Dlg::OnReqAccountUpdate()
{
	CAcctUpdatesDlg dlg;

	if ( dlg.DoModal() != IDOK) return;

	if ( dlg.getSubscribe()) {
		s_accountDlg.accountDownloadBegin(dlg.getAcctCode());
	}

	m_pClient->reqAccountUpdates(dlg.getSubscribe(), dlg.getAcctCode());

	// Show the account details dialog if we are subscribing.
	if ( dlg.getSubscribe() ) {
		s_accountDlg.DoModal();
	}
}

void CClient2Dlg::OnReqExecutions()
{
	CRptFilterDlg dlg(m_execFilter.get());

	if ( dlg.DoModal() != IDOK) return;

	m_pClient->reqExecutions(dlg.reqId(), *m_execFilter);
}

void CClient2Dlg::OnReqContractDetails()
{
	// run dlg box
	m_dlgOrder->init( this, "Request Contract Details", CDlgOrder::REQ_CONTRACT_DETAILS, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// request contract details
	m_pClient->reqContractDetails( m_dlgOrder->m_id, m_dlgOrder->getContract());

}

void CClient2Dlg::OnReqIds()
{
	// request a block of 20 id's;
	// next id is returned via nextValidId()
	m_pClient->reqIds( 20);
}

void CClient2Dlg::OnDisconnect()
{
	// disconnect
	m_pClient->eDisconnect();
}

void CClient2Dlg::OnExtord()
{
	CDlgExtOrd dlgExtOrd(&m_dlgOrder->getOrder(), this);
	if( dlgExtOrd.DoModal() != IDOK) return;
	// nothing to do here
}

void CClient2Dlg::OnClear()
{
	// clear list boxes
	m_ticks.ResetContent();
	m_orderStatus.ResetContent();
	m_errors.ResetContent();
}

void CClient2Dlg::OnCancelHistData()
{
	m_dlgOrder->init( this, "Cancel Historical Data", CDlgOrder::CANCEL_HISTORICAL_DATA, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	m_pClient->cancelHistoricalData( m_dlgOrder->m_id);
}

void CClient2Dlg::OnReqCurrentTime()
{
	m_pClient->reqCurrentTime();
}

void CClient2Dlg::OnMarketScanner()
{
	CDlgScanner dlgScanner(m_scannerSubscr.get(), m_pClient, m_scannerSubscriptionOptions);

	dlgScanner.DoModal();
}

void CClient2Dlg::OnExerciseOptions()
{
	m_dlgOrder->init( this, "Exercise Options", CDlgOrder::EXERCISE_OPTIONS, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	/* TODO: get account in a less convoluted way */
	m_pClient->exerciseOptions(
		m_dlgOrder->m_id,
		m_dlgOrder->getContract(),
		m_dlgOrder->m_exerciseAction,
		m_dlgOrder->m_exerciseQuantity,
		m_dlgOrder->getOrder().account,
		m_dlgOrder->m_exerciseOverride);
}

void CClient2Dlg::OnReqHistoricalData()
{
	m_dlgOrder->init( this, "Request Historical Data", CDlgOrder::REQ_HISTORICAL_DATA, m_managedAccounts, &m_chartOptions);

	if( m_dlgOrder->DoModal() != IDOK) return;

	m_pClient->reqHistoricalData( m_dlgOrder->m_id, m_dlgOrder->getContract(),
		m_dlgOrder->m_backfillEndDateTime, m_dlgOrder->m_backfillDuration,
		m_dlgOrder->m_barSizeSetting, m_dlgOrder->m_whatToShow, m_dlgOrder->m_useRTH,
		m_dlgOrder->m_formatDate, m_chartOptions);
}

void CClient2Dlg::OnFundamentalData()
{
	m_dlgOrder->init( this, "Request Fundamental Data", CDlgOrder::REQ_FUNDAMENTAL_DATA, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	m_pClient->reqFundamentalData( m_dlgOrder->m_id, m_dlgOrder->getContract(), m_dlgOrder->m_whatToShow);
}

void CClient2Dlg::OnCancelFundamentalData()
{
	m_dlgOrder->init( this, "Cancel Fundamental Data", CDlgOrder::CANCEL_FUNDAMENTAL_DATA, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	m_pClient->cancelFundamentalData( m_dlgOrder->m_id);
}


void CClient2Dlg::OnReqRealTimeBars()
{
	// run dlg box
	m_dlgOrder->init( this, "Request Real Time Bars", CDlgOrder::REQ_REAL_TIME_BARS, m_managedAccounts, &m_realTimeBarsOptions);

	if( m_dlgOrder->DoModal() != IDOK) return;

	m_pClient->reqRealTimeBars( m_dlgOrder->m_id, m_dlgOrder->getContract(),
		5 /* TODO: parse and use m_dlgOrder->m_barSizeSetting) */,
		m_dlgOrder->m_whatToShow, m_dlgOrder->m_useRTH > 0, m_realTimeBarsOptions);
}

void CClient2Dlg::OnCancelRealTimeBars()
{
	m_dlgOrder->init( this, "Cancel Real Time Bars", CDlgOrder::CANCEL_REAL_TIME_BARS, m_managedAccounts, /* options */ NULL);

	if( m_dlgOrder->DoModal() != IDOK) return;

	m_pClient->cancelRealTimeBars( m_dlgOrder->m_id);
}

/////////////////////////////////////////////////////////////////////////////
// handle events from socket

void CClient2Dlg::scannerParameters(const CString &xml)
{
	static CString myTitle("SCANNER PARAMETERS: ") ;
	DisplayMultiline(m_orderStatus, myTitle, xml);
}

void CClient2Dlg::DisplayMultiline(CHScrollListBox& box, const CString& title, const CString& data)
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

void CClient2Dlg::scannerData(int reqId, int rank,
                            const ContractDetails &contractDetails, const CString &distance,
                            const CString &benchmark, const CString &projection, const CString &legsStr) {
	Contract contract = contractDetails.summary;
	// create string
	CString str;
	str.Format("id =%i rank=%i conId=%i symbol=%s secType=%s expiry=%s strike=%f right=%s exchange=%s currency=%s localSymbol=%s marketName=%s tradingClass=%s distance=%s benchmark=%s projection=%s legsStr=%s",
		reqId,
		rank,
		contract.conId,
		contract.symbol,
		contract.secType,
		contract.expiry,
		contract.strike,
		contract.right,
		contract.exchange,
		contract.currency,
		contract.localSymbol,
		contractDetails.marketName,
		contract.tradingClass,
		distance,
		benchmark,
		projection,
		legsStr);

	int i =  m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::scannerDataEnd(int reqId)
{
	// create string
	CString str;
	str.Format("id =%i =============== end ===============", reqId);

	int i =  m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::historicalData(TickerId reqId, const CString& date, double open, double high, double low,
                               double close, int volume, int barCount, double WAP, int hasGaps)
{
	CString displayString;
	displayString.Format(
		"id=%d date=%s open=%f high=%f low=%f close=%f volume=%d barCount = %d WAP=%f hasGaps=%d",
		reqId, (const char *)date, open, high, low, close, volume, barCount, WAP, hasGaps);
	int i =  m_ticks.AddString(displayString);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::realtimeBar(TickerId reqId, long time, double open, double high, double low,
                               double close, long volume, double WAP, int count)
{
	CString displayString;
	displayString.Format(
		"id=%d time=%d open=%f high=%f low=%f close=%f volume=%d WAP=%f count = %d",
		reqId, time, open, high, low, close, volume, WAP, count);
    int i =  m_ticks.AddString(displayString);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::fundamentalData(TickerId reqId, const CString& data)
{
	CString title;
	title.Format( "fund data id=%d, len=%d", reqId, data.GetLength());
	DisplayMultiline(m_ticks, title, data);
}

void CClient2Dlg::currentTime(long time)
{
	CString displayString;
	displayString.Format("current time = %d", time);
	int i =  m_orderStatus.AddString(displayString);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex( top);
}

// VC++ 5.0 MFC does not have CString.Replace.  So, I use this:

void CClient2Dlg::CStringReplace(CString &pXml, const CString &cStr, const CString &rStr, CString &pDest)
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

void CClient2Dlg::receiveFA(faDataType pFaDataType, const CString& cxml)
{
	switch (pFaDataType) {
	case GROUPS:
		faGroupsXML = cxml;
		break ;
	case PROFILES:
		faProfilesXML = cxml;
		break ;
	case ALIASES:
		faAliasesXML = cxml;
		break ;
	}

	CString faStr("FA ");
	faStr += faDataTypeStr ( pFaDataType );
	faStr += ":";
	DisplayMultiline(m_orderStatus, faStr, cxml);

	if (!faError && faGroupsXML != "" && faProfilesXML != "" && faAliasesXML != "") {
		CDlgFinancialAdvisor dlg;
		dlg.receiveInitialXML(faGroupsXML, faProfilesXML, faAliasesXML);

		if (dlg.DoModal() != IDOK) return;

		dlg.extractXML(faGroupsXML, faProfilesXML, faAliasesXML);
		m_pClient->replaceFA( GROUPS, faGroupsXML );
		m_pClient->replaceFA( PROFILES, faProfilesXML );
		m_pClient->replaceFA( ALIASES, faAliasesXML );

	}
}

void CClient2Dlg::tickPrice( TickerId tickerId, TickType tickType, double price, int canAutoExecute)
{
	CString str;
	str.Format( "id=%i  %s=%f  canAutoExecute=%d",
		tickerId, (const char*)getField( tickType), price, canAutoExecute);
	int i = m_ticks.AddString( str);

	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::tickSize( TickerId tickerId, TickType tickType, int size)
{
	CString str;
	str.Format( "id=%i  %s=%i",
		tickerId, (const char*)getField( tickType), size);
	int i = m_ticks.AddString( str);

	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::tickGeneric(TickerId tickerId, TickType tickType, double value)
{
	CString str;
	str.Format( "id=%i  %s=%f",
		tickerId, (const char*)getField( tickType), value);
	int i = m_ticks.AddString( str);

	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::tickString(TickerId tickerId, TickType tickType, const CString& value)
{
	CString str;
	str.Format( "id=%i  %s=%s",
		tickerId, (const char*)getField( tickType), value);
	int i = m_ticks.AddString( str);

	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const CString& formattedBasisPoints,
						  double totalDividends, int holdDays, const CString& futureExpiry, double dividendImpact,
						  double dividendsToExpiry)
{
	CString str;
	str.Format( "id=%i  %s: basisPoints=%f / %s impliedFuture=%f holdDays=%i futureExpiry=%s dividendImpact=%f dividendsToExpiry=%f",
		tickerId, (const char*)getField( tickType), basisPoints, formattedBasisPoints, totalDividends, holdDays, futureExpiry, dividendImpact, dividendsToExpiry);
	int i = m_ticks.AddString( str);

	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta, double optPrice, double pvDividend,
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
		tickerId, (const char*)getField( tickType), impliedVolStr, deltaStr, gammaStr, vegaStr, thetaStr, 
		optPriceStr, pvDividendStr, undPriceStr);

	int i = m_ticks.AddString( str);

	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex( top);
}

void CClient2Dlg::orderStatus( OrderId orderId, const CString &status, int filled, int remaining,
        double avgFillPrice, int permId, int parentId, double lastFillPrice,
		int clientId, const CString& whyHeld)
{
	// create string
	CString str;
	str.Format( "orderId=%i clientId=%i permId=%i status=%s  filled=%i  remaining=%i  avgFillPrice=%f lastFillPrice=%f parentId=%i whyHeld=%s",
		orderId, clientId, permId, (const char *)status, filled, remaining, avgFillPrice, lastFillPrice, parentId, (const char*)whyHeld);

	// add to listbox
	int i = m_orderStatus.AddString( str);

	// move into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex( top);
}

void CClient2Dlg::openOrder( OrderId orderId, const Contract& contract,
							const Order& order, const OrderState& orderState)
{
	// create string
	CString str;
	str.Format("openOrder: orderId=%i", orderId);

	// add to listbox
	int i =  m_orderStatus.AddString(str);

	{
#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,contract.Prop)

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
		i = PRINT_CONTRACT_PROP(comboLegsDescrip);

		m_orderStatus.AddString("  comboLegs={");
		if (contract.comboLegs.get()) {
			const Contract::ComboLegList& comboLegs = *contract.comboLegs;
			const size_t comboLegsCount = comboLegs.size();

			const Order::OrderComboLegList& orderComboLegs = *order.orderComboLegs;
			size_t orderComboLegsCount = 0;
			if (order.orderComboLegs.get()) {
				orderComboLegsCount = orderComboLegs.size();
			}

			for( size_t i = 0; i < comboLegsCount; ++i) {
				const ComboLeg& comboLeg = *comboLegs[i];
				CString orderComboLegPriceStr("");

				if (comboLegsCount == orderComboLegsCount){
					const OrderComboLeg& orderComboLeg = *orderComboLegs[i];

					if (orderComboLeg.price != DBL_MAX) {
						orderComboLegPriceStr.Format("price=%f", orderComboLeg.price);
					}
				}

				str.Format( "    leg %i: conId=%i ratio=%i action=%s exchange=%s openClose=%i shortSaleSlot=%i designatedLocation=%s exemptCode=%i %s", 
					(i + 1), comboLeg.conId, comboLeg.ratio, comboLeg.action, comboLeg.exchange, comboLeg.openClose, 
					comboLeg.shortSaleSlot, comboLeg.designatedLocation, comboLeg.exemptCode, orderComboLegPriceStr);

				m_orderStatus.AddString( str);
			}
		}
		i = m_orderStatus.AddString("  }");

#undef PRINT_CONTRACT_PROP
	}

	if (contract.underComp) {

		const UnderComp& underComp = *contract.underComp;

#define PRINT_UNDER_COMP_PROP(Prop) \
	PRINT_PROP(underComp.##Prop,underComp.Prop)

		PRINT_UNDER_COMP_PROP(conId);
		PRINT_UNDER_COMP_PROP(delta);
		i = PRINT_UNDER_COMP_PROP(price);

#undef PRINT_UNDER_COMP_PROP
	}

	{
#define PRINT_ORDER_PROP(Prop) \
	PRINT_PROP(Prop,order.Prop)

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

		PRINT_ORDER_PROP(tif);
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
		if (order.smartComboRoutingParams.get()) {
			const TagValueList& smartComboRoutingParams = *order.smartComboRoutingParams;
			const size_t smartComboRoutingParamsCount = smartComboRoutingParams.size();
			if( smartComboRoutingParamsCount > 0) {
				const CString tagPrefix("  ");
				for( size_t i = 0; i < smartComboRoutingParamsCount; ++i) {
					const TagValue& tagValue = *smartComboRoutingParams[i];
					PropPrintHelpers::Print(m_orderStatus,
						tagPrefix + tagValue.tag, tagValue.value);
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

		if (!order.algoStrategy.IsEmpty()) {
			PRINT_ORDER_PROP(algoStrategy);
			m_orderStatus.AddString("  algoParams={");
			if (order.algoParams.get()) {
				const TagValueList& algoParams = *order.algoParams;
				const size_t algoParamsCount = algoParams.size();
				if( algoParamsCount > 0) {
					const CString tagPrefix("  ");
					for( size_t i = 0; i < algoParamsCount; ++i) {
						const TagValue& tagValue = *algoParams[i];
						PropPrintHelpers::Print(m_orderStatus,
							tagPrefix + tagValue.tag, tagValue.value);
					}
				}
			}
			i = m_orderStatus.AddString("  }");
		}

#undef PRINT_ORDER_PROP
	}

	{
#define PRINT_ORDER_STATE_PROP(Prop) \
	PRINT_PROP(Prop,orderState.Prop)

		i = m_orderStatus.AddString("OrderState:");

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

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::openOrderEnd()
{
	int i = m_orderStatus.AddString(" =============== end ===============");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}


void CClient2Dlg::deltaNeutralValidation(int reqId, const UnderComp& underComp)
{
	// create string
	CString str;
	str.Format("deltaNeutralValidation: reqId=%i", reqId);

	int i = m_orderStatus.AddString(str);

#define PRINT_UNDER_COMP_PROP(Prop) \
	PRINT_PROP(underComp.##Prop,underComp.Prop)

	PRINT_UNDER_COMP_PROP(conId);
	PRINT_UNDER_COMP_PROP(delta);
	i = PRINT_UNDER_COMP_PROP(price);

#undef PRINT_UNDER_COMP_PROP

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::tickSnapshotEnd( int reqId)
{
	CString str;
	str.Format("id=%i =============== end ===============", reqId);

	int i = m_ticks.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_ticks.SetTopIndex(top);
}

void CClient2Dlg::marketDataType( TickerId reqId, int marketDataType) 
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

void CClient2Dlg::updateAccountValue( const CString &key, const CString &val,
									  const CString &currency, const CString &accountName)
{
	s_accountDlg.updateAccountValue(key, val, currency, accountName);
}

void CClient2Dlg::updatePortfolio( const Contract& contract, int position,
								  double marketPrice, double marketValue,
								  double averageCost, double unrealizedPNL,
								  double realizedPNL, const CString &accountName)

{
	s_accountDlg.updatePortfolio(contract, position, marketPrice, marketValue,
            averageCost, unrealizedPNL, realizedPNL, accountName);
}

void CClient2Dlg::updateAccountTime(const CString &timeStamp)
{
	s_accountDlg.updateAccountTime(timeStamp);
}

void CClient2Dlg::accountDownloadEnd(const CString &accountName)
{
	s_accountDlg.accountDownloadEnd( accountName);

	CString str;
	str.Format("Account Download End: %s", accountName);
	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::contractDetails( int reqId, const ContractDetails &contractDetails)
{
	// add to listbox
	CString str;
	str.Format("id =%i ===================================", reqId);
	m_orderStatus.AddString(str);

	int i =  m_orderStatus.AddString(" ---- Contract Details Ex begin ----");

	CString secType;

	{
		const Contract& contract = contractDetails.summary;

#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,contract.Prop)

		i = m_orderStatus.AddString("Contract:");

		PRINT_CONTRACT_PROP(conId);
		PRINT_CONTRACT_PROP(symbol);
		PRINT_CONTRACT_PROP(secType);

		// store secType string for future use
		secType = contract.secType;

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

	{
#define PRINT_CONTRACT_DETAILS_PROP(Prop) \
	PRINT_PROP(Prop,contractDetails.Prop)

		i = m_orderStatus.AddString("Details:");

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
		if (contractDetails.secIdList.get()) {
			const TagValueList& secIdList = *contractDetails.secIdList;
			const size_t secIdListCount = secIdList.size();
			if( secIdListCount > 0) {
				const CString tagPrefix("  ");
				for( size_t i = 0; i < secIdListCount; ++i) {
					const TagValue& tagValue = *secIdList[i];
					PropPrintHelpers::Print(m_orderStatus,
						tagPrefix + tagValue.tag, tagValue.value);
				}
			}
		}
		i = m_orderStatus.AddString("  }");


#undef PRINT_CONTRACT_DETAILS_PROP
	}

	i = m_orderStatus.AddString(" ---- Contract Details Ex end ------");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::bondContractDetails( int reqId, const ContractDetails &contractDetails)
{
	this->contractDetails(reqId, contractDetails);
}

void CClient2Dlg::contractDetailsEnd( int reqId)
{
	CString str;
	str.Format("id =%i =============== end ===============", reqId);

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::execDetails( int reqId, const Contract& contract, const Execution& execution)
{
	int i = m_orderStatus.AddString("---- Execution Details begin ----");

	// create string
	CString str;
	str.Format("execDetails: reqId=%i", reqId);

	// add to listbox
	i =  m_orderStatus.AddString(str);

	{
#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,contract.Prop)

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

	{
#define PRINT_EXECUTION_PROP(Prop) \
	PRINT_PROP(Prop,execution.Prop)

		i = m_orderStatus.AddString("Execution:");

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

	i = m_orderStatus.AddString(" ---- Execution Details End ----");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::execDetailsEnd( int reqId)
{
	CString str;
	str.Format("reqId=%i =============== end ===============", reqId);

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::commissionReport( const CommissionReport& commissionReport)
{
	int i = m_orderStatus.AddString("---- Commission Report ----");

	{
#define PRINT_COMMISSION_REPORT_PROP(Prop) \
	PRINT_PROP(Prop,commissionReport.Prop)

		PRINT_COMMISSION_REPORT_PROP(execId);
		PRINT_COMMISSION_REPORT_PROP(commission);
		PRINT_COMMISSION_REPORT_PROP(currency);
		PRINT_COMMISSION_REPORT_PROP(realizedPNL);
		PRINT_COMMISSION_REPORT_PROP(yield);
		PRINT_COMMISSION_REPORT_PROP(yieldRedemptionDate);

#undef PRINT_COMMISSION_REPORT_PROP
	}

	i = m_orderStatus.AddString(" ---- Commission Report End ----");

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::position( const CString& account, const Contract& contract, int position, double avgCost)
{
	int i = m_orderStatus.AddString(" ---- Position begin ----");

	// create string
	CString str;
	str.Format( "account=%s", (const char *)account);

	// add to listbox
	i = m_orderStatus.AddString( str);

	{
#define PRINT_CONTRACT_PROP(Prop) \
	PRINT_PROP(Prop,contract.Prop)

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

void CClient2Dlg::positionEnd()
{
	CString str;
	str.Format("=============== end ===============");

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::accountSummary( int reqId, const CString& account, const CString& tag,
								 const CString& value, const CString& curency)
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

void CClient2Dlg::accountSummaryEnd( int reqId)
{
	CString str;
	str.Format("reqId=%i =============== end ===============", reqId);

	int i = m_orderStatus.AddString(str);

	// bring into view
	int top = i - N < 0 ? 0 : i - N;
	m_orderStatus.SetTopIndex(top);
}

void CClient2Dlg::verifyMessageAPI( const IBString& apiData) {}

void CClient2Dlg::verifyCompleted( bool isSuccessful, const IBString& errorText) {}

void CClient2Dlg::displayGroupList( int reqId, const IBString& groups) 
{
	m_dlgGroups->displayGroupList(reqId, (IBString&)groups);
}

void CClient2Dlg::displayGroupUpdated( int reqId, const IBString& contractInfo) 
{
	m_dlgGroups->displayGroupUpdated(reqId, (IBString&)contractInfo);
}

void CClient2Dlg::updateMktDepth(TickerId id, int position, int operation, int side,
		double price, int size)
{
	m_dlgMktDepth->updateMktDepth(id, position, "", operation, side, price, size);
}

void CClient2Dlg::updateMktDepthL2(TickerId id, int position, CString marketMaker,
	int operation, int side, double price, int size)
{
	m_dlgMktDepth->updateMktDepth(id, position, marketMaker, operation, side, price, size);
}

void CClient2Dlg::error(const CString errorMsg)
{
	int i = m_errors.AddString( errorMsg);
	int top = i - N < 0 ? 0 : i - N;
	m_errors.SetTopIndex( top);
}

void CClient2Dlg::error(const int id, const int errorCode, const CString errorMsg) {
	CString errorStr("Id: ");

	char buf[20];
	itoa(id, buf, 10);
	errorStr += CString(buf);
	errorStr += " | ";
	errorStr += "Error Code: ";
	itoa(errorCode, buf, 10);
	errorStr += CString(buf);
	errorStr += " | ";
	errorStr += "Error Msg: ";
	errorStr += errorMsg;
	error(errorStr) ;
	for (int ctr=0; ctr < NUM_FA_ERROR_CODES; ctr++) {
       faError |= (errorCode == faErrorCodes[ctr]) ;
	}
	if (errorCode == CDlgMktDepth::MKT_DEPTH_DATA_RESET) {
		m_dlgMktDepth->clear();
	}
}

void CClient2Dlg::winError( const CString &str, int lastError)
{
	// get windows error msg text
	void *lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR)&lpMsgBuf,
		0,
		NULL);

	// format msg
	CString fullMsg;
	if( lpMsgBuf && strlen( (const char *)lpMsgBuf) > 0)
		fullMsg.Format( "%s - %s (%i)", (const char *)str, lpMsgBuf, lastError);
	else
		fullMsg.Format( "%s (%i)", (const char *)str, lastError);

	// free the buffer.
	LocalFree( lpMsgBuf);

	// display it
	error( NO_VALID_ID, SYSTEM_ERROR, fullMsg);
}

void CClient2Dlg::connectionClosed()
{
	MessageBox( "Connection closed");
}

void CClient2Dlg::nextValidId( OrderId orderId)
{
	m_dlgOrder->m_id = orderId;
}

void CClient2Dlg::OnReqMktDepth()
{
	// run dlg box
	m_dlgOrder->init( this, "Request Market Depth", CDlgOrder::REQ_MKT_DEPTH, m_managedAccounts, &m_mktDepthOptions);

	if( m_dlgOrder->DoModal() != IDOK) return;

	// request ticker
	m_pClient->reqMktDepth(m_dlgOrder->m_id, m_dlgOrder->getContract(), m_dlgOrder->m_numRows, m_mktDepthOptions);
	m_dlgMktDepth->DoModal();
	m_pClient->cancelMktDepth(m_dlgOrder->m_id);
}

void CClient2Dlg::updateNewsBulletin(int msgId, int msgType, const CString& newsMessage,
                                     const CString& originExch)
{
	CString displayString;
	displayString.Format(" MsgId=%d :: MsgType = %d :: Origin= %s :: Message= %s",
		msgId, msgType, originExch, newsMessage);

	MessageBox( displayString, "IB News Bulletin", MB_ICONINFORMATION);
}

void CClient2Dlg::OnNewsBulletins()
{
	// TODO: Add your control notification handler code here
	CDlgNewsBulletins dlg;

	if (dlg.DoModal() != IDOK) return;

	dlg.subscribe()
		? m_pClient->reqNewsBulletins( dlg.allMsgs())
		: m_pClient->cancelNewsBulletins();
}

void CClient2Dlg::OnFinancialAdvisor()
{
	faGroupsXML = faProfilesXML = faAliasesXML = "" ;
	faError = false ;
	m_pClient->requestFA(GROUPS) ;
	m_pClient->requestFA(PROFILES) ;
	m_pClient->requestFA(ALIASES) ;
}

void CClient2Dlg::OnSetServerLogLevel()
{
	if (s_dlgLogConfig.DoModal() != IDOK) return;

	// set the TWS log level for API requests/responses
	m_pClient->setServerLogLevel( s_dlgLogConfig.serverLogLevel() );
}

void CClient2Dlg::OnReqAccts()
{
	// request the list of managed accounts
	m_pClient->reqManagedAccts();
}

void CClient2Dlg::managedAccounts(const CString& accountsList)
{
	m_financialAdvisor = true;
	m_managedAccounts = accountsList;

	CString displayString;
	displayString.Format("Connected : The list of managed accounts are : [%s]", accountsList);
	m_orderStatus.AddString( displayString);
}

void CClient2Dlg::OnCalculateImpliedVolatility()
{
	// run dlg box
	m_dlgOrder->init( this, "Calculate Implied Volatility", CDlgOrder::CALC_IMPL_VOL, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;
	// request calculate implied volatility
	m_pClient->calculateImpliedVolatility( m_dlgOrder->m_id, m_dlgOrder->getContract(),
		m_dlgOrder->m_lmtPrice, m_dlgOrder->m_auxPrice);
}

void CClient2Dlg::OnCalculateOptionPrice()
{
	// run dlg box
	m_dlgOrder->init( this, "Calculate Option Price", CDlgOrder::CALC_OPTION_PRICE, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;
	// request calculate option price
	m_pClient->calculateOptionPrice( m_dlgOrder->m_id, m_dlgOrder->getContract(),
		m_dlgOrder->m_lmtPrice, m_dlgOrder->m_auxPrice);
}

void CClient2Dlg::OnCancelCalculateImpliedVolatility()
{
	// run dlg box
	m_dlgOrder->init( this, "Cancel Calculate Implied Volatility", CDlgOrder::CANCEL_CALC_IMPL_VOL, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel calculate implied volatility
	m_pClient->cancelCalculateImpliedVolatility( m_dlgOrder->m_id);
}

void CClient2Dlg::OnCancelCalculateOptionPrice()
{
	// run dlg box
	m_dlgOrder->init( this, "Cancel Calculate Option Price", CDlgOrder::CANCEL_CALC_OPTION_PRICE, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// cancel calculate option price
	m_pClient->cancelCalculateOptionPrice( m_dlgOrder->m_id);
}

void CClient2Dlg::OnReqGlobalCancel()
{
	m_pClient->reqGlobalCancel();
}

void CClient2Dlg::OnReqMarketDataType()
{
	// run dlg box
	m_dlgOrder->init( this, "Request Market Data Type", CDlgOrder::REQ_MARKET_DATA_TYPE, m_managedAccounts, /* options */ NULL);
	if( m_dlgOrder->DoModal() != IDOK) return;

	// request market data type
	m_pClient->reqMarketDataType( m_dlgOrder->m_marketDataType);
}

void CClient2Dlg::OnReqPositions()
{
	// request positions
	m_pClient->reqPositions();
}

void CClient2Dlg::OnCancelPositions()
{
	// cancel positions
	m_pClient->cancelPositions();
}

void CClient2Dlg::OnReqAccountSummary()
{
	CDlgAccountSummary dlg("Request Account Summary", CDlgAccountSummary::REQUEST_ACCOUNT_SUMMARY);

	if ( dlg.DoModal() != IDOK) return;

	// request account summary
	m_pClient->reqAccountSummary(dlg.reqId(), dlg.groupName(), dlg.tags());
}

void CClient2Dlg::OnCancelAccountSummary()
{
	CDlgAccountSummary dlg("Cancel Account Summary", CDlgAccountSummary::CANCEL_ACCOUNT_SUMMARY);

	if ( dlg.DoModal() != IDOK) return;

	// cancel account summary
	m_pClient->cancelAccountSummary(dlg.reqId());
}

void CClient2Dlg::OnQueryGroups()
{
	m_dlgGroups->init(m_pClient);
	m_dlgGroups->DoModal();
}

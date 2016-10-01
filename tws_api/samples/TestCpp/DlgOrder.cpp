/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgOrder.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "Client2Dlg.h"
#include "DlgOrder.h"
#include "DlgComboLegs.h"
#include "DlgFAAllocationInfo.h"
//#include "DlgShareAllocation.h"
#include "DlgUnderComp.h"
#include "DlgAlgoParams.h"
#include "DlgSmartComboRoutingParams.h"

#include "Order.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOrder dialog

CDlgOrder::CDlgOrder(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOrder::IDD, pParent)
	, m_contract(new Contract)
	, m_order(new Order)
	, m_underComp(new UnderComp)
{

	m_pDlg = NULL;
	m_dlgType = CDlgOrder::ORDER;
	m_managedAccounts = "";

	//{{AFX_DATA_INIT(CDlgOrder)
	m_id = 0;
	m_action = _T("BUY");
	m_totalQuantity = 10;
	m_conId = 0;
	m_symbol = _T("QQQQ");
	m_expiry = _T("");
	m_right = _T("");
	m_multiplier = _T("");
	m_exchange = _T("SMART");
	m_primaryExchange = _T("ISLAND");
	m_currency = _T("USD");
	m_includeExpired = 0;
	m_orderType = _T("LMT");
	m_lmtPrice = 40.0f;
	m_auxPrice = 0.0f;
	m_strike = 0.0f;
	m_secType = _T("STK");
	m_localSymbol = _T("");
	m_tradingClass = _T("");
	m_secIdType = _T("");
	m_secId = _T("");
	m_genericTicks = _T("100,101,104,105,106,107,165,221,225,233,236,258,293,294,295,318");
	m_snapshotMktData = false;
	m_numRows = 20;
	m_useRTH = 1;
	m_formatDate = 1;
	m_whatToShow = _T("TRADES");
	CTime theTime = CTime::GetCurrentTime();
	CString str = theTime.Format( "%Y%m%d %H:%M:%S" );
	m_backfillEndDateTime = _T(str);
	m_backfillDuration = _T("1 M");
	m_barSizeSetting = _T("1 day");
	m_exerciseAction = 1;
	m_exerciseQuantity = 1;
	m_exerciseOverride = 0;
	m_marketDataType = REALTIME; // This is the default market data type selection
	//}}AFX_DATA_INIT

	updateContract();
	updateOrder();
}

CDlgOrder::~CDlgOrder()
{
}

extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, double &value);

void CDlgOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOrder)

	// Primary Id
	DDX_Text(pDX, IDC_EDIT_ID, m_id);

	// Contract description fields
	DDX_Text(pDX, IDC_EDIT_CONID, m_conId);
	DDX_Text(pDX, IDC_EDIT_SYMBOL, m_symbol);
	DDX_Text(pDX, IDC_EDIT_SEC_TYPE, m_secType);
	DDX_Text(pDX, IDC_EDIT_EXPIRY, m_expiry);
	DDX_Text(pDX, IDC_EDIT_STRIKE, m_strike);
	DDX_Text(pDX, IDC_EDIT_RIGHT, m_right);
	DDX_Text(pDX, IDC_EDIT_MULT, m_multiplier);
	DDX_Text(pDX, IDC_EDIT_EXCH, m_exchange);
	DDX_Text(pDX, IDC_EDIT_PRIM_EXCH, m_primaryExchange);
	DDX_Text(pDX, IDC_EDIT_CURRENCY, m_currency);
	DDX_Text(pDX, IDC_EDIT_LOCAL_SYMBOL, m_localSymbol);
	DDX_Text(pDX, IDC_EDIT_TRADING_CLASS, m_tradingClass);
	DDX_Text(pDX, IDC_EDIT_IS_EXPIRED, m_includeExpired);
	DDX_Text(pDX, IDC_EDIT_SEC_ID_TYPE, m_secIdType);
	DDX_Text(pDX, IDC_EDIT_SEC_ID, m_secId);

	// Market Data
	DDX_Text(pDX, IDC_EDIT_GENERIC_TICKS, m_genericTicks);

	int snapshotMktDataState = (m_snapshotMktData ? BST_CHECKED : BST_UNCHECKED);
	DDX_Check(pDX, IDC_CHECK_SNAPSHOT_MKT_DATA, snapshotMktDataState);
	m_snapshotMktData = (snapshotMktDataState == BST_CHECKED);

	// Market Depth
	DDX_Text(pDX, IDC_EDIT_NUM_MKT_DEPTH_ROWS, m_numRows);

	// Exercise options
	DDX_Text(pDX, IDC_EDIT_EXERCISE_ACTION, m_exerciseAction);
	DDX_Text(pDX, IDC_EDIT_EXERCISE_QUANTITY, m_exerciseQuantity);
	DDX_Text(pDX, IDC_EDIT_EXERCISE_OVERRIDE, m_exerciseOverride);

	// Order description
	DDX_Text(pDX, IDC_EDIT_ORDER_ACTION, m_action);
	DDX_Text(pDX, IDC_EDIT_ORDER_SIZE, m_totalQuantity);
	DDX_Text(pDX, IDC_EDIT_ORDER_TYPE, m_orderType);
	DDX_TextMax(pDX, IDC_EDIT_ORDER_PRICE, m_lmtPrice);
	DDX_TextMax(pDX, IDC_EDIT_ORDER_AUX_PRICE, m_auxPrice);
	DDX_Text(pDX, IDC_EDIT_ORDER_GOOD_AFTER_TIME, m_goodAfterTime);
	DDX_Text(pDX, IDC_EDIT_ORDER_GOOD_TILL_DATE, m_goodTillDate);

	// Historical Data
	DDX_Text(pDX, IDC_EDIT_HIST_END_DATE_TIME, m_backfillEndDateTime);
	DDX_Text(pDX, IDC_EDIT_HIST_DURATION, m_backfillDuration);
	DDX_Text(pDX, IDC_EDIT_BAR_SIZE, m_barSizeSetting);
	DDX_Text(pDX, IDC_EDIT_WHAT_TO_SHOW, m_whatToShow);
	DDX_Text(pDX, IDC_EDIT_USE_RTH, m_useRTH);
	DDX_Text(pDX, IDC_EDIT_DATE_FORMAT, m_formatDate);

	// Market Data Type
	DDX_Control(pDX, IDC_COMBO_MARKET_DATA_TYPE, m_marketDataTypeCombo);

	if (pDX->m_bSaveAndValidate) {
		updateContract();
		updateOrder();
	}

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOrder, CDialog)
	//{{AFX_MSG_MAP(CDlgOrder)
	ON_BN_CLICKED(IDC_BTN_ADD_COMBO_LEGS, OnBtnAddComboLegs)
	ON_BN_CLICKED(IDC_FA_INFO, OnFaInfo)
	ON_BN_CLICKED(IDC_BTN_UNDER_COMP, &CDlgOrder::OnBtnUnderComp)
	ON_BN_CLICKED(IDC_BTN_ALGO_PARAMS, &CDlgOrder::OnBtnAlgoParams)
	ON_BN_CLICKED(IDC_BTN_SMART_COMBO_ROUTING_PARAMS, &CDlgOrder::OnBtnSmartComboRoutingParams)
	ON_BN_CLICKED(IDC_BTN_OPTIONS, &CDlgOrder::OnBtnOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgOrder::init(CClient2Dlg* dlg, CString dlgTitle, DialogType dlgType, CString managedAccounts, TagValueListSPtr* options)
{
	m_pDlg = dlg;
	m_dlgTitle = dlgTitle;
	m_dlgType = dlgType;
	m_managedAccounts = managedAccounts;
	m_options = options;
}

/////////////////////////////////////////////////////////////////////////////
// CDlgOrder message handlers

void CDlgOrder::OnOK()
{
	m_marketDataType = m_marketDataTypeCombo.GetCurSel() + 1;

	CDialog::OnOK();
}

BOOL CDlgOrder::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText(m_dlgTitle);

	GetDlgItem(IDC_SHARE_ALLOC)->EnableWindow( m_pDlg->isFinancialAdvisor());

	// The only case when we want to disable edit field: REQ_CONTRACT_DETAILS
	GetDlgItem(IDC_EDIT_ID)->EnableWindow(m_dlgType != REQ_CONTRACT_DETAILS);

	// Process "Contract Description" fields
	enableContractDescFields(m_dlgType);

	// Process "Combo" fields
	enableComboFields(m_dlgType);

	// Process "Market Data" fields
	enableMarketDataFields(m_dlgType);

	// Process "Market Depth" fields
	enableMarketDepthFields(m_dlgType);

	// Process "Exercise Options" fields
	enableExerciseOptionsFields(m_dlgType);

	// Process "Order Description" fields
	enableOrderDescFields(m_dlgType);

	// Process "Historical Data" fields
	enableHistDataFields(m_dlgType);

	// Process "Sec Id Type" and "Sec Id" fields for placeOrders/reqContractDetails
	enableSecIdFields(m_dlgType);

	// Process "Market Data Type" fields
	enableMarketDataTypeFields(m_dlgType);

	// Process "Options" fields
	enableOptionsFields(m_dlgType);

	if ( CB_ERR == m_marketDataTypeCombo.GetCurSel() )
	{
		m_marketDataTypeCombo.SetCurSel( m_marketDataType - 1 );
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDlgOrder::OnBtnAddComboLegs()
{
	CDlgComboLegs dlgComboLegs(m_contract->comboLegs, m_order->orderComboLegs, m_exchange);
	if ( dlgComboLegs.DoModal() == IDOK ) {
		// do nothing - params passed by ref
		// and is being updated inside dialog
	}
}

/*void CDlgOrder::OnShareAlloc()
{
	// TODO: Add your control notification handler code here
	CDlgShareAllocation dlg;

	dlg.setAccts( m_managedAccounts);

	if( dlg.DoModal() != IDOK) return;

	m_strShareAllocations = dlg.getSharesAllocation();
}*/

void CDlgOrder::OnFaInfo()
{
	CDlgFAAllocationInfo dlg;
	if( dlg.DoModal() != IDOK) return;

	m_faGroup = dlg.m_group;
	m_faProfile = dlg.m_profile;
	m_faMethod = dlg.m_method;
	m_faPercentage = dlg.m_percentage;

}

void CDlgOrder::OnBtnUnderComp()
{
	CDlgUnderComp dlg(m_underComp.get());
	const int nRet = dlg.DoModal();
	if (nRet == IDOK) {
		m_contract->underComp = m_underComp.get();
	}
	else if (nRet == IDRESET) {
		m_contract->underComp = NULL;
	}
}


void CDlgOrder::OnBtnAlgoParams()
{
	CDlgAlgoParams dlg(m_order->algoStrategy, m_order->algoParams);
	if ( dlg.DoModal() == IDOK ) {
		// do nothing - params passed by ref
		// and is being updated inside dialog
	}
}

void CDlgOrder::OnBtnSmartComboRoutingParams()
{
	CDlgSmartComboRoutingParams dlg(m_order->smartComboRoutingParams, "Smart Combo Routing Parameters");
	if ( dlg.DoModal() == IDOK ) {
		// do nothing - params passed by ref
		// and is being updated inside dialog
	}
}

void CDlgOrder::OnBtnOptions()
{
	CString dlgTitle("");

	switch (m_dlgType){
		case ORDER:
			dlgTitle = "Order Misc Options";
			break;
		case REQ_HISTORICAL_DATA:
			dlgTitle = "Chart Options";
			break;
		case REQ_MKT_DATA:
			dlgTitle = "Market Data Options";
			break;
		case REQ_MKT_DEPTH:
			dlgTitle = "Market Depth Options";
			break;
		case REQ_REAL_TIME_BARS:
			dlgTitle = "Real Time Bars Options";
			break;
		default:
			break;
	}

	ASSERT (m_options);

	CDlgSmartComboRoutingParams dlg(*m_options, dlgTitle);
	if ( dlg.DoModal() == IDOK ) {
		// do nothing - params passed by ref
		// and is being updated inside dialog
	}
}


void CDlgOrder::enableFields(const unsigned* fields, size_t fieldsNum, bool enable)
{
	for (size_t i = 0; i < fieldsNum; ++i) {
		GetDlgItem(fields[i])->EnableWindow(enable);
	}
}

void CDlgOrder::enableContractDescFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned contractDescFields[] = {
		IDC_EDIT_CONID,
		IDC_EDIT_SYMBOL,
		IDC_EDIT_SEC_TYPE,
		IDC_EDIT_EXPIRY,
		IDC_EDIT_STRIKE,
		IDC_EDIT_RIGHT,
		IDC_EDIT_MULT,
		IDC_EDIT_EXCH,
		IDC_EDIT_PRIM_EXCH,
		IDC_EDIT_CURRENCY,
		IDC_EDIT_LOCAL_SYMBOL,
		IDC_EDIT_TRADING_CLASS,
		IDC_EDIT_IS_EXPIRED,
	};

	static const size_t contractDescFieldsNum =
		sizeof(contractDescFields) / sizeof(contractDescFields[0]);

	bool enable = (dialogType == ORDER || dialogType == REQ_MKT_DATA ||
		dialogType == REQ_MKT_DEPTH || dialogType == REQ_HISTORICAL_DATA ||
		dialogType == REQ_FUNDAMENTAL_DATA ||
		dialogType == REQ_REAL_TIME_BARS || dialogType == REQ_CONTRACT_DETAILS ||
		dialogType == EXERCISE_OPTIONS || dialogType == CALC_IMPL_VOL || 
		dialogType == CALC_OPTION_PRICE);

	enableFields(contractDescFields, contractDescFieldsNum, enable);
}

void CDlgOrder::enableComboFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned comboFields[] = {
		IDC_BTN_ADD_COMBO_LEGS,
	};

	static const size_t comboFieldsNum =
		sizeof(comboFields) / sizeof(comboFields[0]);

	bool enable = (dialogType == ORDER ||
		dialogType == REQ_MKT_DATA ||
		dialogType == REQ_HISTORICAL_DATA);
	enableFields(comboFields, comboFieldsNum, enable);

	static const unsigned deltaNeutralFields[] = {
		IDC_BTN_UNDER_COMP,
	};

	static const size_t deltaNeutralFieldsNum =
		sizeof(deltaNeutralFields) / sizeof(deltaNeutralFields[0]);

	enable = (dialogType == ORDER || 
		dialogType == REQ_MKT_DATA);
	enableFields(deltaNeutralFields, deltaNeutralFieldsNum, enable);

	static const unsigned algoFields[] = {
		IDC_BTN_ALGO_PARAMS,
		IDC_BTN_SMART_COMBO_ROUTING_PARAMS,
	};

	static const size_t algoFieldsNum =
		sizeof(algoFields) / sizeof(algoFields[0]);

	enable = (dialogType == ORDER);
	enableFields(algoFields, algoFieldsNum, enable);

}


void CDlgOrder::enableMarketDataFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned marketDataFields[] = {
		IDC_EDIT_GENERIC_TICKS,
		IDC_CHECK_SNAPSHOT_MKT_DATA,
	};

	static const size_t marketDataFieldsNum =
		sizeof(marketDataFields) / sizeof(marketDataFields[0]);

	bool enable = (dialogType == REQ_MKT_DATA);
	enableFields(marketDataFields, marketDataFieldsNum, enable);
}

void CDlgOrder::enableMarketDepthFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned marketDepthFields[] = {
		IDC_EDIT_NUM_MKT_DEPTH_ROWS,
	};

	static const size_t marketDepthFieldsNum =
		sizeof(marketDepthFields) / sizeof(marketDepthFields[0]);

	bool enable = (dialogType == REQ_MKT_DEPTH);
	enableFields(marketDepthFields, marketDepthFieldsNum, enable);
}

void CDlgOrder::enableExerciseOptionsFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned exerciseOptionsFields[] = {
		IDC_EDIT_EXERCISE_ACTION,
		IDC_EDIT_EXERCISE_QUANTITY,
		IDC_EDIT_EXERCISE_OVERRIDE,
	};

	static const size_t exerciseOptionsFieldsNum =
		sizeof(exerciseOptionsFields) / sizeof(exerciseOptionsFields[0]);

	bool enable = (dialogType == EXERCISE_OPTIONS);
	enableFields(exerciseOptionsFields, exerciseOptionsFieldsNum, enable);
}

void CDlgOrder::enableOrderDescFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned orderDescFields[] = {
		IDC_EDIT_ORDER_ACTION,
		IDC_EDIT_ORDER_SIZE,
		IDC_EDIT_ORDER_TYPE,
		//IDC_EDIT_ORDER_PRICE,
		//IDC_EDIT_ORDER_AUX_PRICE,
		IDC_EDIT_ORDER_GOOD_AFTER_TIME,
		IDC_EDIT_ORDER_GOOD_TILL_DATE,
	};

	static const size_t orderDescFieldsNum =
		sizeof(orderDescFields) / sizeof(orderDescFields[0]);

	bool enable = (dialogType == ORDER);
	enableFields(orderDescFields, orderDescFieldsNum, enable);

	static const unsigned orderDescCommonFields[] = {
		IDC_EDIT_ORDER_PRICE,
		IDC_EDIT_ORDER_AUX_PRICE,
	};

	static const size_t orderDescCommonFieldsNum =
		sizeof(orderDescCommonFields) / sizeof(orderDescCommonFields[0]);

	enable = (dialogType == ORDER || dialogType == CALC_IMPL_VOL || dialogType == CALC_OPTION_PRICE);
	enableFields(orderDescCommonFields, orderDescCommonFieldsNum, enable);
}

void CDlgOrder::enableHistDataFields(const CDlgOrder::DialogType dialogType)
{
	{
		static const unsigned histDataCommonFields[] = {
			IDC_EDIT_WHAT_TO_SHOW,
		};

		static const size_t histDataCommonFieldsNum =
			sizeof(histDataCommonFields) / sizeof(histDataCommonFields[0]);

		bool enable = (dialogType == REQ_HISTORICAL_DATA || dialogType == REQ_REAL_TIME_BARS || dialogType == REQ_FUNDAMENTAL_DATA);
		enableFields(histDataCommonFields, histDataCommonFieldsNum, enable);
	}

	{
		static const unsigned histDataFields[] = {
			IDC_EDIT_USE_RTH,
			IDC_EDIT_BAR_SIZE,
		};

		static const size_t histDataFieldsNum =
			sizeof(histDataFields) / sizeof(histDataFields[0]);

		bool enable = (dialogType == REQ_HISTORICAL_DATA || dialogType == REQ_REAL_TIME_BARS);
		enableFields(histDataFields, histDataFieldsNum, enable);
	}

	{
		static const unsigned histDataExtraFields[] = {
			IDC_EDIT_HIST_END_DATE_TIME,
			IDC_EDIT_HIST_DURATION,
			IDC_EDIT_DATE_FORMAT,
		};
		static const size_t histDataExtraFieldsNum =
			sizeof(histDataExtraFields) / sizeof(histDataExtraFields[0]);

		bool enable = (dialogType == REQ_HISTORICAL_DATA);
		enableFields(histDataExtraFields, histDataExtraFieldsNum, enable);
	}
}

void CDlgOrder::enableSecIdFields(const CDlgOrder::DialogType dialogType)
{
	{
		static const unsigned secIdFields[] = {
			IDC_EDIT_SEC_ID_TYPE,
			IDC_EDIT_SEC_ID
		};
		static const size_t secIdFieldsNum =
			sizeof(secIdFields) / sizeof(secIdFields[0]);

		bool enable = (dialogType == REQ_CONTRACT_DETAILS || dialogType == ORDER);
		enableFields(secIdFields, secIdFieldsNum, enable);
	}
}

void CDlgOrder::enableMarketDataTypeFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned marketDataTypeFields[] = {
		IDC_COMBO_MARKET_DATA_TYPE,
	};

	static const size_t marketDataTypeFieldsNum =
		sizeof(marketDataTypeFields) / sizeof(marketDataTypeFields[0]);

	bool enable = (dialogType == REQ_MARKET_DATA_TYPE);
	enableFields(marketDataTypeFields, marketDataTypeFieldsNum, enable);
}

void CDlgOrder::enableOptionsFields(const CDlgOrder::DialogType dialogType)
{
	static const unsigned optionsFields[] = {
		IDC_BTN_OPTIONS,
	};

	static const size_t optionsFieldsNum =
		sizeof(optionsFields) / sizeof(optionsFields[0]);

	bool enable = (dialogType == ORDER || dialogType == REQ_HISTORICAL_DATA ||
		dialogType == REQ_MKT_DATA || dialogType == REQ_MKT_DEPTH || dialogType == REQ_REAL_TIME_BARS);

	ASSERT (!enable || m_options);

	enableFields(optionsFields, optionsFieldsNum, enable);

	switch(dialogType){
		case ORDER:
			GetDlgItem(optionsFields[0])->SetWindowTextA("Order Misc Options");
			break;
		case REQ_HISTORICAL_DATA:
			GetDlgItem(optionsFields[0])->SetWindowTextA("Chart Options");
			break;
		case REQ_MKT_DATA:
			GetDlgItem(optionsFields[0])->SetWindowTextA("Mkt Data Options");
			break;
		case REQ_MKT_DEPTH:
			GetDlgItem(optionsFields[0])->SetWindowTextA("Mkt Depth Options");
			break;
		case REQ_REAL_TIME_BARS:
			GetDlgItem(optionsFields[0])->SetWindowTextA("RTB Options");
			break;
		default:
			GetDlgItem(optionsFields[0])->SetWindowTextA("Options");
			break;
	}
}

void CDlgOrder::updateContract()
{
	ASSERT(m_contract.get());

	Contract* contract = m_contract.get();

#define PUT_PROP(Prop) \
	contract->Prop = m_##Prop;

	PUT_PROP(conId);
	PUT_PROP(symbol);
	PUT_PROP(secType);
	PUT_PROP(expiry);
	PUT_PROP(strike);
	PUT_PROP(right);
	PUT_PROP(multiplier);
	PUT_PROP(exchange);
	PUT_PROP(primaryExchange);
	PUT_PROP(currency);
	PUT_PROP(localSymbol);
	PUT_PROP(tradingClass);
	PUT_PROP(includeExpired);
	PUT_PROP(secIdType);
	PUT_PROP(secId);

#undef PUT_PROP
}

void CDlgOrder::updateOrder()
{
	ASSERT(m_order.get());

	Order* order = m_order.get();

#define PUT_PROP(Prop) \
	order->Prop = m_##Prop;

	order->orderId = m_id;

	//PUT_PROP(clientId);
	//PUT_PROP(permId);
	PUT_PROP(action);
	PUT_PROP(totalQuantity);
	PUT_PROP(orderType);
	PUT_PROP(lmtPrice);
	PUT_PROP(auxPrice);

#undef PUT_PROP
}

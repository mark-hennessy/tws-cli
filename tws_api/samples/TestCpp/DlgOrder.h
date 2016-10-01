/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_DLGORDER_H__115EE565_0BA0_11D6_B0ED_00B0D074179C__INCLUDED_)
#define AFX_DLGORDER_H__115EE565_0BA0_11D6_B0ED_00B0D074179C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgOrder.h : header file
//

#include <memory>

#include "Contract.h"
#include "Order.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgOrder dialog

class CClient2Dlg;

class CDlgOrder : public CDialog
{
// Construction
public:
	enum DialogType { ORDER, CANCEL_ORDER, REQ_MKT_DATA, CANCEL_MKT_DATA, REQ_CONTRACT_DETAILS,
		              REQ_MKT_DEPTH, CANCEL_MKT_DEPTH, REQ_HISTORICAL_DATA, EXERCISE_OPTIONS,
	                  CANCEL_HISTORICAL_DATA, REQ_REAL_TIME_BARS, CANCEL_REAL_TIME_BARS, CALC_IMPL_VOL,
	                  CALC_OPTION_PRICE, CANCEL_CALC_IMPL_VOL, CANCEL_CALC_OPTION_PRICE, REQ_MARKET_DATA_TYPE,
	                  REQ_FUNDAMENTAL_DATA, CANCEL_FUNDAMENTAL_DATA};

	CDlgOrder(CWnd* pParent = NULL);   // standard constructor
	~CDlgOrder();

	void    init(CClient2Dlg* dlg, CString dlgTitle, DialogType dlgType, CString managedAccounts, TagValueListSPtr* options);

	Contract& getContract() { return *m_contract; }
	Order&    getOrder()    { return *m_order;    }

	const CString& getFaGroup()      const    { return m_faGroup; }
    const CString& getFaProfile()    const    { return m_faProfile; }
    const CString& getFaMethod()     const    { return m_faMethod; }
    const CString& getFaPercentage() const    { return m_faPercentage; }

// Dialog Data
	//{{AFX_DATA(CDlgOrder)
	enum { IDD = IDD_ORDER };
	long	m_id;
	CString	m_action;
	long	m_totalQuantity;
	long    m_conId;
	CString	m_symbol;
	CString	m_expiry;
	CString	m_right;
	CString	m_multiplier;
	CString	m_exchange;
	CString	m_primaryExchange;
	CString	m_currency;
	BOOL    m_includeExpired;
	CString	m_secIdType;
	CString	m_secId;
	CString	m_orderType;
	double	m_lmtPrice;
	double	m_auxPrice;
	double	m_strike;
	CString	m_secType;
	CString	m_localSymbol;
	CString	m_tradingClass;
	CString m_goodAfterTime;
	CString m_goodTillDate;
	CString m_genericTicks;
	bool    m_snapshotMktData;
	long    m_numRows;
	CString m_backfillEndDateTime;
	CString m_backfillDuration;
    CString m_barSizeSetting;
	long    m_useRTH;
	long    m_formatDate;
	CString m_whatToShow;
	long    m_exerciseAction;
	long    m_exerciseQuantity;
	long    m_exerciseOverride;
	CComboBox m_marketDataTypeCombo;
	int m_marketDataType;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOrder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    CClient2Dlg*            m_pDlg;
	DialogType              m_dlgType;
    CString                 m_dlgTitle;
    CString                 m_managedAccounts;
	CString                 m_faGroup;
    CString                 m_faProfile;
    CString                 m_faMethod;
    CString                 m_faPercentage;

	std::auto_ptr<Contract>  m_contract;
	std::auto_ptr<Order>     m_order;
	std::auto_ptr<UnderComp> m_underComp;

	TagValueListSPtr*		 m_options;

	// Generated message map functions
	//{{AFX_MSG(CDlgOrder)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAddComboLegs();
	afx_msg void OnFaInfo();
	afx_msg void OnBtnUnderComp();
	afx_msg void OnBtnAlgoParams();
	afx_msg void OnBtnSmartComboRoutingParams();
	afx_msg void OnBtnOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void enableFields(const unsigned* fields, size_t fieldsNum, bool enable);

	void enableContractDescFields(DialogType);
	void enableComboFields(DialogType);
	void enableMarketDataFields(DialogType);
	void enableMarketDepthFields(DialogType);
	void enableExerciseOptionsFields(DialogType);
	void enableOrderDescFields(DialogType);
	void enableHistDataFields(DialogType);
	void enableSecIdFields(DialogType);
	void enableMarketDataTypeFields(DialogType);
	void enableOptionsFields(DialogType);

private:

	void updateContract();
	void updateOrder();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGORDER_H__115EE565_0BA0_11D6_B0ED_00B0D074179C__INCLUDED_)

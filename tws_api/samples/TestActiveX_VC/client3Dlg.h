/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// client3Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "tws.h"
//}}AFX_INCLUDES

#if !defined(AFX_CLIENT3DLG_H__E9173BB6_0F7E_11D6_B0ED_00B0D074179C__INCLUDED_)
#define AFX_CLIENT3DLG_H__E9173BB6_0F7E_11D6_B0ED_00B0D074179C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "HScrollListBox.h"     //'<INSTALL_DIR>\Shared' must be added to include path
#include "TagValue.h"

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

#include <memory>

/////////////////////////////////////////////////////////////////////////////
// CClient3Dlg dialog

class CHScrollListBox;

class CDlgOrder;
class CDlgMktDepth;
class CDlgGroups;

class CClient3Dlg : public CDialog
{
// Construction
public:
	static const int NOT_AN_FA_ACCOUNT_ERROR;
	CClient3Dlg(CWnd* pParent = NULL);	// standard constructor
	~CClient3Dlg();

    bool isFinancialAdvisor()     { return m_financialAdvisor;}

	static void CStringReplace(CString &pXml, const CString &cStr, const CString &rStr, CString &pDest);
	static const CString RETURN_NEWLINE;
	static const CString RETURN;
	static const CString NEWLINE;
	static const CString TAB;
	static const CString FOUR_SPACES;

// Dialog Data
	//{{AFX_DATA(CClient3Dlg)
	enum { IDD = IDD_CLIENT3_DIALOG };
	CHScrollListBox	m_errors;
	CHScrollListBox	m_ticks;
	CHScrollListBox	m_orderStatus;
	CTws	m_tws;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClient3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClient3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OntickPriceTwsctrl1(long id, long tickType, double price, int canAutoExecute);
	afx_msg void OntickSizeTwsctrl1(long id, long tickType, long size);
	afx_msg void OnconnectionClosedTwsctrl1();
	afx_msg void OnConnect();
	afx_msg void OnReqMktData();
	afx_msg void OnCanMktData();
	afx_msg void OnWhatIf();
	afx_msg void OnPlaceOrder();
	afx_msg void OnCanorder();
	afx_msg void OnDisconnect();
	afx_msg void OnClear();
	afx_msg void OnSetExtOrdAttribs();
	afx_msg void OnReqOpenOrders();
	afx_msg void OnReqAcctData();
	afx_msg void OnFinancialAdvisor();
	afx_msg void OnReqHistoricalData();
	afx_msg void OnExerciseOptions();
	afx_msg void OnCancelHistData();
	afx_msg void OnReqRealTimeBars();
    afx_msg void OnCancelRealTimeBars();
	afx_msg void OnReqCurrentTime();
	afx_msg void OnMarketScanner();
	afx_msg void OnCalculateImpliedVolatility();
	afx_msg void OnCalculateOptionPrice();
	afx_msg void OnCancelCalculateImpliedVolatility();
	afx_msg void OnCancelCalculateOptionPrice();
	afx_msg void OnReqGlobalCancel();
	afx_msg void OnReqMarketDataType();
	afx_msg void OnReqPositions();
	afx_msg void OnCancelPositions();
	afx_msg void OnReqAccountSummary();
	afx_msg void OnCancelAccountSummary();
	afx_msg void OnGroups();
	afx_msg void OnFundamentalData();
	afx_msg void OnCancelFundamentalData();

	afx_msg void OntickOptionComputationTwsctrl1(long id, long tickType, double impliedVol, double delta, double optPrice, double pvDividend,
			double gamma, double vega, double theta, double undPrice);
	afx_msg void OnupdateAccountTimeTwsctrl1(LPCTSTR timeStamp);
	afx_msg void OnupdateAccountValueTwsctrl1(LPCTSTR key, LPCTSTR value, LPCTSTR curency, LPCTSTR accountName);
	afx_msg void OnpermIdTwsctrl1(long id, long permId);
	afx_msg void OnReqIds();
	afx_msg void OnReqExecutions();
	afx_msg void OnerrMsgTwsctrl1(long id, long errorCode, LPCTSTR errorMsg);
	afx_msg void OnnextValidIdTwsctrl1(long id);
	afx_msg void OnReqContractDetails();
	afx_msg void OnCancelMktDepth();
	afx_msg void OnReqMktDepth();
	afx_msg void OnupdateMktDepthTwsctrl1(long id, long position, long operation, long side, double price, long size);
	afx_msg void OnupdateMktDepthL2Twsctrl1(long id, long position, LPCTSTR marketMaker, long operation, long side, double price, long size);
	afx_msg void OnNewsBulletins();
	afx_msg void OnupdateNewsBulletinTwsctrl1(short msgId, short msgType, LPCTSTR message, LPCTSTR origExchange);
	afx_msg void OnSetServerLogLevel();
	afx_msg void OnmanagedAccountsTwsctrl1(LPCTSTR accountsList);
	afx_msg void OnReqAccts();
	afx_msg void OnReqAllOpenOrders();
	afx_msg void OnReqAutoOpenOrders();
	afx_msg void OnorderStatusTwsctrl1(long id, LPCTSTR status, long filled, long remaining, double avgFillPrice, long permId, long parentId, double lastFillPrice, long clientId, LPCTSTR whyHeld);
	afx_msg void OnreceiveFATwsctrl1(long faDataType, LPCTSTR cxml) ;
	afx_msg void OnhistoricalDataTwsctrl1(long reqId, LPCTSTR date, double open, double high, double low,
                      double close, long volume, long barCount, double WAP, long hasGaps) ;
    afx_msg void OnScannerParametersTwsctrl1(LPCTSTR xml);
	afx_msg void OnScannerDataExTwsctrl1(long reqId, long rank, IDispatch* contractDetails, LPCTSTR distance, LPCTSTR benchmark, LPCTSTR projection, LPCTSTR legsStr);
	afx_msg void OnScannerDataEndTwsctrl1(long reqId);
	afx_msg void OntickGenericTwsctrl1(long id, long tickType, double value);
	afx_msg void OntickStringTwsctrl1(long id, long tickType, LPCTSTR value);
	afx_msg void OntickEFPTwsctrl1(long tickerId, long field, double basisPoints, LPCTSTR formattedBasisPoints,
			          double totalDividends, long holdDays, LPCTSTR futureExpiry, double dividendImpact,
					  double dividendsToExpiry);
	afx_msg void OnrealtimeBarTwsctrl1(long tickerId, long time, double open, double high, double low, double close, long volume, double WAP, long count);
	afx_msg void OncurrentTimeTwsctrl1(long millis);
	afx_msg void OnFundamentalDataTwsctrl1(LONG reqId, LPCTSTR data);
	afx_msg void OnContractDetailsEndTwsctrl1(LONG reqId);
	afx_msg void OnOpenOrderEndTwsctrl1();
	afx_msg void OnAccountDownloadEndTwsctrl1(LPCTSTR accountName);
	afx_msg void OnDeltaNeutralValidationTwsctrl1(LONG reqId, IDispatch* underComp);
	afx_msg void OnTickSnapshotEndTwsctrl1(LONG reqId);
	afx_msg void OnMarketDataTypeTwsctrl1(long reqId, long marketDataType);

	afx_msg void OnContractDetailsExTwsctrl1(LONG reqId, IDispatch* contract);
	afx_msg void OnOpenOrderExTwsctrl1(LONG id, IDispatch* contract, IDispatch* order, IDispatch* orderState);
	afx_msg void OnExecDetailsExTwsctrl1(LONG reqId, IDispatch* contract, IDispatch* execution);
	afx_msg void OnExecDetailsEndTwsctrl1(LONG reqId);
	afx_msg void OnUpdatePortfolioExTwsctrl1(IDispatch* contract, long position, double marketPrice, double marketValue, double averageCost, double unrealizedPNL, double realizedPNL, LPCTSTR accountName);
	afx_msg void OnCommissionReportTwsctrl1(IDispatch* commissionReport);
	afx_msg void OnPositionTwsctrl1(LPCTSTR account, IDispatch* contract, int position, double avgCost);
	afx_msg void OnPositionEndTwsctrl1();
	afx_msg void OnAccountSummaryTwsctrl1(LONG reqId, LPCTSTR account, LPCTSTR tag, LPCTSTR value, LPCTSTR curency);
	afx_msg void OnAccountSummaryEndTwsctrl1(LONG reqId);
	afx_msg void OnVerifyMessageAPITwsctrl1(LPCTSTR apiData);
	afx_msg void OnVerifyCompletedTwsctrl1(BOOL isSuccessful, LPCTSTR errorText);
	afx_msg void OnDisplayGroupListTwsctrl1(LONG reqId, LPCTSTR groups);
	afx_msg void OnDisplayGroupUpdatedTwsctrl1(LONG reqId, LPCTSTR contractInfo);

	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	// helpers
	void placeOrder(bool whatIf);

private:

	static void DisplayMultiline(CHScrollListBox&, const CString& title, const CString& xml);

private:

	template<class ComInterface>
	struct PropPrintHelpers;

private:

	std::auto_ptr<CDlgOrder> m_dlgOrder;
	std::auto_ptr<CDlgMktDepth> m_dlgMktDepth;
	std::auto_ptr<CDlgGroups> m_dlgGroups;

	CComQIPtr<IExecutionFilter> m_execFilter;
	CComQIPtr<IScannerSubscription> m_scannerSubscr;

	CComQIPtr<ITagValueList> m_chartOptions;
	CComQIPtr<ITagValueList> m_mktDataOptions;
	CComQIPtr<ITagValueList> m_orderMiscOptions;
	CComQIPtr<ITagValueList> m_mktDepthOptions;
	CComQIPtr<ITagValueList> m_scannerSubscriptionOptions;
	CComQIPtr<ITagValueList> m_realTimeBarsOptions;

private:
	void error(CString &errorStr) ;
    bool        m_financialAdvisor;    
    CString     m_managedAccounts;
	CString faGroupsXML;
	CString faProfilesXML;
	CString faAliasesXML;
	bool faError ;

public:
	void receiveFATwsctrl1(long faDataType, LPCTSTR cxml);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT3DLG_H__E9173BB6_0F7E_11D6_B0ED_00B0D074179C__INCLUDED_)

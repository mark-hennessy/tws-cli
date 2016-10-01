/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_CLIENT2DLG_H__681373C1_0AC0_11D6_B0ED_00B0D074179C__INCLUDED_)
#define AFX_CLIENT2DLG_H__681373C1_0AC0_11D6_B0ED_00B0D074179C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EWrapper.h"       // '<INSTALL_DIR>\SocketClient\include' must be added to include path
#include "HScrollListBox.h" // '<INSTALL_DIR>\Shared' must be added to include path
#include "TagValue.h"

#include <memory>

class EClient;
class CHScrollListBox;

struct Contract;
struct ContractDetails;
struct Order;
struct OrderState;
struct Execution;
struct ExecutionFilter;
struct ScannerSubscription;
struct CommissionReport;

class CDlgOrder;
class CDlgMktDepth;
class CDlgGroups;

#define NOT_AN_FA_ACCOUNT_ERROR 321

/////////////////////////////////////////////////////////////////////////////
// CClient2Dlg dialog

class CClient2Dlg : public CDialog, public EWrapper
{
// Construction
public:
	CClient2Dlg(CWnd* pParent = NULL);	// standard constructor
	~CClient2Dlg();
 
    void cancelMktDepth(int tickerId);
    bool isFinancialAdvisor()     { return m_financialAdvisor;}

	static void CStringReplace(CString &pXml, const CString &cStr, const CString &rStr, CString &pDest);
	static const CString RETURN_NEWLINE;
	static const CString RETURN;
	static const CString NEWLINE;
	static const CString TAB;
	static const CString FOUR_SPACES;

// Dialog Data
	//{{AFX_DATA(CClient2Dlg)
	enum { IDD = IDD_CLIENT2_DIALOG };
	CHScrollListBox	    m_orderStatus;
	CHScrollListBox	    m_ticks;
    CHScrollListBox     m_errors;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClient2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL


// Implementation
private:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClient2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnReqMktData();
	afx_msg void OnCancelMktData();
	afx_msg void OnWhatIf();
	afx_msg void OnPlaceOrder();
	afx_msg void OnCancelOrder();
	afx_msg void OnDisconnect();
	afx_msg void OnClear();
	afx_msg void OnExtord();
	afx_msg void OnReqOpenOrders();
	afx_msg void OnReqAccountUpdate();
	afx_msg void OnReqExecutions();
	afx_msg void OnReqIds();
	afx_msg void OnReqContractDetails();
	afx_msg void OnReqMktDepth();
	afx_msg void OnCancelMktDepth();
	afx_msg void OnNewsBulletins();
	afx_msg void OnSetServerLogLevel();
	afx_msg void OnReqAllOpenOrders();
	afx_msg void OnReqAutoOpenOrders();
	afx_msg void OnReqAccts();
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
	afx_msg void OnQueryGroups();
	afx_msg void OnFundamentalData();
	afx_msg void OnCancelFundamentalData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// handle events from client

	void tickPrice( TickerId ddeId, TickType field, double price, int canAutoExecute);
	void tickSize( TickerId ddeId, TickType field, int size);
	void tickOptionComputation( TickerId ddeId, TickType field, double impliedVol,
		double delta, double optPrice, double pvDividend,
		double gamma, double vega, double theta, double undPrice);
    void tickGeneric(TickerId tickerId, TickType tickType, double value);
    void tickString(TickerId tickerId, TickType tickType, const CString& value);
	void tickEFP(TickerId tickerId, TickType tickType, double basisPoints,
		const CString& formattedBasisPoints, double totalDividends, int holdDays,
		const CString& futureExpiry, double dividendImpact, double dividendsToExpiry);
	void orderStatus( OrderId orderId, const CString &status, int filled, int remaining, 
        double avgFillPrice, int permId, int parentId, double lastFillPrice,
		int clientId, const CString& whyHeld);
	void openOrder( OrderId orderId, const Contract&, const Order&, const OrderState&);
	void openOrderEnd();
	void winError( const CString &str, int lastError);
	void connectionClosed();
	void updateAccountValue(const CString &key, const CString &val,
		const CString &currency, const CString &accountName);
	virtual void updatePortfolio( const Contract& contract, int position,
		double marketPrice, double marketValue, double averageCost,
		double unrealizedPNL, double realizedPNL, const CString &accountName);
	void updateAccountTime(const CString &timeStamp);
	void accountDownloadEnd(const CString &accountName);
	void nextValidId( OrderId orderId);
	void contractDetails( int reqId, const ContractDetails& contractDetails);
	void bondContractDetails( int reqId, const ContractDetails& contractDetails);
	void contractDetailsEnd( int reqId);
    void execDetails( int reqId, const Contract& contract, const Execution& execution);
	void execDetailsEnd( int reqId);
	void error(const int id, const int errorCode, const CString errorString);
	void error(const CString errorString);
	void updateMktDepth( TickerId id, int position, int operation, int side, 
			double price, int size);
	void updateMktDepthL2( TickerId id, int position, CString marketMaker, int operation, 
			int side, double price, int size);
	void updateNewsBulletin(int msgId, int msgType, const CString& newsMessage, const CString& originExch);
    void managedAccounts(const CString& accountsList);
    void receiveFA(faDataType pFaDataType, const CString& cxml);
    void historicalData(TickerId reqId, const CString& date, double open, double high, double low,
                      double close, int volume, int barCount, double WAP, int hasGaps) ;
	void scannerParameters(const CString &xml);
	void scannerData(int reqId, int rank, const ContractDetails &contractDetails, const CString &distance,
		const CString &benchmark, const CString &projection, const CString &legsStr);
	void scannerDataEnd(int reqId);
	void realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
	   long volume, double wap, int count);
	void currentTime(long time);
	void fundamentalData(TickerId reqId, const CString& data);
	void deltaNeutralValidation(int reqId, const UnderComp& underComp);
	void tickSnapshotEnd( int reqId);
	void marketDataType( TickerId reqId, int marketDataType);
	void commissionReport( const CommissionReport& commissionReport);
	void position( const CString& account, const Contract& contract, int position, double avgCost);
	void positionEnd();
	void accountSummary( int reqId, const CString& account, const CString& tag, const CString& value, const CString& curency);
	void accountSummaryEnd( int reqId);
	void verifyMessageAPI( const IBString& apiData);
	void verifyCompleted( bool isSuccessful, const IBString& errorText);
	void displayGroupList( int reqId, const IBString& groups);
	void displayGroupUpdated( int reqId, const IBString& contractInfo);

private:

	// trace
	void trace( const char *str);
	void trace( int val);
	void trace( double val);

	// helpers
	void placeOrder(bool whatIf);

private:

	static void DisplayMultiline(CHScrollListBox&, const CString& title, const CString& xml);

private:

	struct PropPrintHelpers;

private:

	std::auto_ptr<CDlgOrder> m_dlgOrder;
	std::auto_ptr<CDlgMktDepth> m_dlgMktDepth;
	std::auto_ptr<CDlgGroups> m_dlgGroups;

	std::auto_ptr<ExecutionFilter> m_execFilter;
	std::auto_ptr<ScannerSubscription> m_scannerSubscr;

	TagValueListSPtr m_chartOptions;
	TagValueListSPtr m_mktDataOptions;
	TagValueListSPtr m_mktDepthOptions;
	TagValueListSPtr m_scannerSubscriptionOptions;
	TagValueListSPtr m_realTimeBarsOptions;

private:

	EClient     *m_pClient;
    bool        m_financialAdvisor;    
    CString     m_managedAccounts;
	CString faGroupsXML;
	CString faProfilesXML;
	CString faAliasesXML;
	bool faError ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT2DLG_H__681373C1_0AC0_11D6_B0ED_00B0D074179C__INCLUDED_)

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_DLGEXTORD_H__203C4C23_0F90_11D6_B0ED_00B0D074179C__INCLUDED_)
#define AFX_DLGEXTORD_H__203C4C23_0F90_11D6_B0ED_00B0D074179C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgExtOrd.h : header file
//

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgExtOrd dialog

class CDlgExtOrd : public CDialog
{
// Construction
public:

	CDlgExtOrd(IOrder* order, CWnd* pParent = NULL);   // standard constructor

private:

	void setDlgToDefaultValues();

	void setDlgFromActiveXControl();
	void setActiveXControlFromDlg();

	void getAttribsFromComOrder();
	void setAttribsToComOrder();

	void setDlgToDefaultValuesPrim();
	void populateDialogComponents();

	void showHedgeParamTip();

private:

// Dialog Data
	//{{AFX_DATA(CDlgExtOrd)
	enum { IDD = IDD_EXTORD };

	// extended order fields
	CString m_timeInForce;
	CString m_activeStartTime;
	CString m_activeStopTime;
	CString m_ocaGroup;
	int     m_ocaType;
	CString m_orderRef;
	BOOL    m_transmit;
	long    m_parentId;
	BOOL    m_blockOrder;
	BOOL    m_sweepToFill;
	long    m_displaySize;
	long    m_triggerMethod;
	BOOL    m_outsideRth;
	BOOL    m_hidden;
	BOOL    m_overridePercentageConstraints;
	CString m_rule80A;
	BOOL    m_allOrNone;
	int     m_minQty;
	double  m_percentOffset;
	double  m_trailStopPrice;
	double  m_trailingPercent;

	// Institutional orders only
	CString m_openClose;
	long    m_origin;
	long    m_shortSaleSlot;
	CString m_designatedLocation;
	int     m_exemptCode;

	// SMART routing only
	double  m_discretionaryAmt;
	BOOL    m_eTradeOnly;
	BOOL    m_firmQuoteOnly;
	double  m_nbboPriceCap;
	bool	m_optOutSmartRouting;

	// BOX or VOL orders only
	int     m_auctionStrategy; // AUCTION_MATCH, AUCTION_IMPROVEMENT, AUCTION_TRANSPARENT

	// BOX order only
	double  m_startingPrice;
	double  m_stockRefPrice;
	double  m_delta;

	// pegged to stock or VOL orders
	double  m_stockRangeLower;
	double  m_stockRangeUpper;

	// VOLATILITY orders only
	double  m_volatility;
	int     m_volatilityType;
	BOOL    m_continuousUpdate;
	int     m_referencePriceType;
	CString m_deltaNeutralOrderType;
	double  m_deltaNeutralAuxPrice;
	long    m_deltaNeutralConId;
	CString m_deltaNeutralSettlingFirm;
	CString m_deltaNeutralClearingAccount;
	CString m_deltaNeutralClearingIntent;
	CString m_deltaNeutralOpenClose;
	BOOL    m_deltaNeutralShortSale;
	int     m_deltaNeutralShortSaleSlot;
	CString m_deltaNeutralDesignatedLocation;

	// SCALE orders only
	int     m_scaleInitLevelSize;
	int     m_scaleSubsLevelSize;
	double  m_scalePriceIncrement;
	double  m_scalePriceAdjustValue;
	int     m_scalePriceAdjustInterval;
	double  m_scaleProfitOffset;
	bool    m_scaleAutoReset;
	int     m_scaleInitPosition;
	int     m_scaleInitFillQty;
	bool    m_scaleRandomPercent;
	CString m_scaleTable;

	// HEDGE orders only
	CString m_hedgeType;
	CString m_hedgeParam;

	// Clearing info
	CString m_account;
	CString m_settlingFirm;
	CString m_clearingAccount;
	CString m_clearingIntent;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgExtOrd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgExtOrd)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
private:

	CComQIPtr<IOrder> m_order;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEXTORD_H__203C4C23_0F90_11D6_B0ED_00B0D074179C__INCLUDED_)

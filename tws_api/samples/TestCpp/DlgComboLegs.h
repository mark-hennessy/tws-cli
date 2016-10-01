/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_DLGCOMBOLEGS_H__BCE33E9E_1535_4181_8C3D_F5E0C632A979__INCLUDED_)
#define AFX_DLGCOMBOLEGS_H__BCE33E9E_1535_4181_8C3D_F5E0C632A979__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgComboLegs.h : header file
//

#include "Contract.h"
#include "Order.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgComboLegs dialog
class CDlgOrder;

class CDlgComboLegs : public CDialog
{
public:

	typedef Contract::ComboLegList ComboLegList;
	typedef shared_ptr<ComboLegList> ComboLegListSPtr;
	typedef Order::OrderComboLegList OrderComboLegList;
	typedef shared_ptr<OrderComboLegList> OrderComboLegListSPtr;

public:

	CDlgComboLegs(ComboLegListSPtr& comboLegs, OrderComboLegListSPtr& orderComboLegs,
		const CString& orderExchange, CWnd* pParent=NULL);

// Dialog Data
	//{{AFX_DATA(CDlgComboLegs)
	enum { IDD = IDD_COMBOLEGS };
	CListCtrl	m_lstComboLegs;
	int		m_conId;
	int		m_ratio;
	CString	m_side;
	CString	m_exchange;
	int		m_openClose;
	int     m_shortSaleSlot;
	CString m_designatedLocation;
	int     m_exemptCode;
	double  m_price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgComboLegs)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgComboLegs)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAddLeg();
	afx_msg void OnBtnRemoveLeg();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	ComboLegListSPtr& m_comboLegs;
	OrderComboLegListSPtr& m_orderComboLegs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOMBOLEGS_H__BCE33E9E_1535_4181_8C3D_F5E0C632A979__INCLUDED_)

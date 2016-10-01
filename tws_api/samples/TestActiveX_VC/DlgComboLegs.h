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

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgComboLegs dialog
class CTws;

class CDlgComboLegs : public CDialog
{
public:

	CDlgComboLegs(IComboLegList* comboLegs, IOrderComboLegList* orderComboLegs, 
		const CString& orderExchange, CTws* pTws, CWnd* pParent=NULL);

	IComboLegList* getComboLegs() { return m_comboLegs; }
	IOrderComboLegList* getOrderComboLegs() { return m_orderComboLegs; }

// Dialog Data
	//{{AFX_DATA(CDlgComboLegs)
	enum { IDD = IDD_COMBOLEGS };
	CListCtrl	m_lstComboLegs;
	ComboLeg    m_comboLeg;
	OrderComboLeg m_orderComboLeg;
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

	static void AddComboLeg(CListCtrl&, const ComboLeg&, const OrderComboLeg&);
	static void GetComboLeg(ComboLeg&, OrderComboLeg&, const CListCtrl&, size_t index);

	static void CopyTwsComboLeg2ComboLeg(ComboLeg&,	/* const */ IComboLeg*, 
		OrderComboLeg&, /* const */ IOrderComboLeg*);
	static void CopyComboLeg2TwsComboLeg(IComboLeg*, const ComboLeg&, 
		IOrderComboLeg*, const OrderComboLeg&);

private:

	CTws* m_pTws;
    CComQIPtr<IComboLegList> m_comboLegs;
    CComQIPtr<IOrderComboLegList> m_orderComboLegs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOMBOLEGS_H__BCE33E9E_1535_4181_8C3D_F5E0C632A979__INCLUDED_)

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_ACCTUPDATESDLG_H__3DACB626_ADF6_4C03_B10D_BD95E22EA5A4__INCLUDED_)
#define AFX_ACCTUPDATESDLG_H__3DACB626_ADF6_4C03_B10D_BD95E22EA5A4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AcctUpdatesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAcctUpdatesDlg dialog

class CAcctUpdatesDlg : public CDialog
{
// Construction
public:
	CAcctUpdatesDlg(CWnd* pParent = NULL);   // standard constructor
    CString getAcctCode()       {return m_acctCode; }
    bool    getSubscribe()      {return m_subscribe; }
// Dialog Data
	//{{AFX_DATA(CAcctUpdatesDlg)
	enum { IDD = IDD_ACCT_UPDATES };
	CString	m_acctCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcctUpdatesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAcctUpdatesDlg)
	afx_msg void OnUnsubscribe();
	afx_msg void OnSubscribe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    bool    m_subscribe;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCTUPDATESDLG_H__3DACB626_ADF6_4C03_B10D_BD95E22EA5A4__INCLUDED_)

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifndef _DLGACCOUNTSUMMARY_H__
#define _DLGACCOUNTSUMMARY_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgAccountSummary.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAccountSummary dialog
/////////////////////////////////////////////////////////////////////////////
class CDlgAccountSummary : public CDialog
{
// Construction
public:
	enum DialogType { REQUEST_ACCOUNT_SUMMARY, CANCEL_ACCOUNT_SUMMARY };

	CDlgAccountSummary(CString dlgTitle, DialogType dlgType, CWnd* pParent = NULL);   // standard constructor

	int reqId() const { return m_reqId; }
	CString groupName() const { return m_groupName; }
	CString tags() const { return m_tags; }

// Dialog Data
	//{{AFX_DATA(CDlgAccountSummary)
	enum { IDD = IDD_ACCOUNT_SUMMARY };
	int		m_reqId;
	CString	m_groupName;
	CString	m_tags;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAccountSummary)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DialogType              m_dlgType;
	CString                 m_dlgTitle;

	// Generated message map functions
	//{{AFX_MSG(CDlgAccountSummary)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // _DLGACCOUNTSUMMARY_H__

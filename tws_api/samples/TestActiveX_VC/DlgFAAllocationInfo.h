/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_DLGFAALLOCATIONINFO_H__D97A5C07_E5C6_466D_9078_15596368BFCF__INCLUDED_)
#define AFX_DLGFAALLOCATIONINFO_H__D97A5C07_E5C6_466D_9078_15596368BFCF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// FAAllocationInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFAAllocationInfo dialog

class CDlgFAAllocationInfo : public CDialog
{
// Construction
public:
	CDlgFAAllocationInfo(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CDlgFAAllocationInfo)
	enum { IDD = IDD_FA_INFO };
	CString	m_group;
	CString	m_method;
	CString	m_percentage;
	CString	m_profile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFAAllocationInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgFAAllocationInfo)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FAALLOCATIONINFO_H__D97A5C07_E5C6_466D_9078_15596368BFCF__INCLUDED_)

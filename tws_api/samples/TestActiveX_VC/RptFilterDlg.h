/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifndef _RPTFILTERDLG_H__
#define _RPTFILTERDLG_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// RptFilterDlg.h : header file
//

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

/////////////////////////////////////////////////////////////////////////////
// CRptFilterDlg dialog
//
// The valid format for m_time is "yyyymmdd-hh:mm:ss"
//
/////////////////////////////////////////////////////////////////////////////
class CRptFilterDlg : public CDialog
{
// Construction
public:

	CRptFilterDlg(IExecutionFilter* filter, CWnd* pParent = NULL);   // standard constructor

	int reqId() const { return m_reqId; }

private:

// Dialog Data
	//{{AFX_DATA(CRptFilterDlg)
	enum { IDD = IDD_EXEC_RPT_FILTER };
	int     m_reqId;
	long	m_clientId;
	CString	m_acctCode;
	CString	m_time;
	CString	m_symbol;
	CString	m_secType;
	CString	m_exchange;
	CString	m_side;
	//}}AFX_DATA

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRptFilterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRptFilterDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	CComQIPtr<IExecutionFilter> m_filter;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // _RPTFILTERDLG_H__

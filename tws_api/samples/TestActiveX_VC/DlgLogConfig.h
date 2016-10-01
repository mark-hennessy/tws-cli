/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined _DLGLOGCONFIG_H__
#define _DLGLOGCONFIG_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CDlgLogConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLogConfig dialog

class CDlgLogConfig : public CDialog
{
// Construction
public:
    enum LogLevel {SYS = 1, ERR, WRN, INF, DET };

	CDlgLogConfig(CWnd* pParent = NULL);   // standard constructor
    int serverLogLevel()        { return m_sLogLevel; }

// Dialog Data
	//{{AFX_DATA(CDlgLogConfig)
	enum { IDD = IDD_LOG_CONFIG };
	CComboBox	m_serverLogLevel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLogConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLogConfig)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	int	m_sLogLevel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // _DLGLOGCONFIG_H__

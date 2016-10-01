/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_NEWSBULLETINS_H__489E0D0C_366F_4D2B_80F5_2ABF179DBC7F__INCLUDED_)
#define AFX_NEWSBULLETINS_H__489E0D0C_366F_4D2B_80F5_2ABF179DBC7F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NewsBulletins.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgNewsBulletins dialog

class CDlgNewsBulletins : public CDialog
{
// Construction
public:
	CDlgNewsBulletins(CWnd* pParent = NULL);   // standard constructor

    bool    subscribe()             { return m_subscribe; }
    bool    allMsgs()               { return m_allIBMsgs; }

// Dialog Data
	//{{AFX_DATA(CDlgNewsBulletins)
	enum { IDD = IDD_NEWS_BULLETINS };
	CButton	m_allMsgs;
	CButton	m_newMsgs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgNewsBulletins)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgNewsBulletins)
	afx_msg void OnSubscribe();
	afx_msg void OnUnsubscribe();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    bool    m_subscribe;
    bool    m_allIBMsgs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSBULLETINS_H__489E0D0C_366F_4D2B_80F5_2ABF179DBC7F__INCLUDED_)

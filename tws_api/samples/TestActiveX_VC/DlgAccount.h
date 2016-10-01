/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_DLGACCOUNT_H__9E0E08F3_2709_11D6_9B97_00B0D0B520CA__INCLUDED_)
#define AFX_DLGACCOUNT_H__9E0E08F3_2709_11D6_9B97_00B0D0B520CA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgAccount.h : header file
//

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgAccount dialog
#include "HScrollListBox.h"     //'<INSTALL_DIR>\Shared' must be added to include path

class CHScrollListBox;
/////////////////////////////////////////////////////////////////////////////
// CClient3Dlg dialog
class CDlgAccount : public CDialog
{
// Construction
public:
	CDlgAccount(CWnd* pParent = NULL);   // standard constructor
    void updateAccountValue(const CString &key, const CString &val,
		const CString &currency, const CString &accountName);
	void updatePortfolio(IDispatch* contract, int position, double marketPrice,
		double marketValue, double averageCost, double unrealizedPNL,
		double realizedPNL, const CString& accountName);
	void updateAccountTime(const CString &timeStamp);

	void accountDownloadBegin( const CString &accountName);
	void accountDownloadEnd(const CString &accountName);

// Dialog Data
	//{{AFX_DATA(CDlgAccount)
	enum { IDD = IDD_ACCT };
	CHScrollListBox	m_portfolio;
	CHScrollListBox	m_accountValue;
	CEdit	m_updateTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAccount)
	protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAccount)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	void updateTitle();

private:

	CString m_accountName;
	bool    m_complete;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGACCOUNT_H__9E0E08F3_2709_11D6_9B97_00B0D0B520CA__INCLUDED_)

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#if !defined(AFX_DlgGroups_H__6EA50722_2652_11D6_9B97_00B0D0B520CA__INCLUDED_)
#define AFX_DlgGroups_H__6EA50722_2652_11D6_9B97_00B0D0B520CA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgGroups.h : header file
//
#include "Contract.h"
#include "HScrollListBox.h" // '<INSTALL_DIR>\Shared' must be added to include path

class EClient;

/////////////////////////////////////////////////////////////////////////////
// CDlgGroups dialog
class CDlgGroups : public CDialog
{
// Construction
public:
	CDlgGroups(CWnd* pParent = NULL);

	void init(EClient* client);

	void displayGroupList(int reqId, IBString& groups);
	void displayGroupUpdated(int reqId, IBString& contractInfo);

	// Dialog Data
	//{{AFX_DATA(CDlgGroups)
	enum { IDD = IDD_GROUPS };
	long			m_id;
	CComboBox		m_groupIdCombo;
	CHScrollListBox	m_groupMessages;
	CEdit			m_contractInfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgGroups)
protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation


protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgGroups)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	EClient* m_pClient;

	afx_msg void OnQueryDisplayGroups();
	afx_msg void OnSubscribeToGroupEvents();
	afx_msg void OnUnsubscribeFromGroupEvents();
	afx_msg void OnUpdateDisplayGroup();
	afx_msg void OnReset();

	void enableFields(bool enable);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgGroups_H__6EA50722_2652_11D6_9B97_00B0D0B520CA__INCLUDED_)

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgAccountSummary.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "DlgAccountSummary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAccountSummary dialog

CDlgAccountSummary::CDlgAccountSummary(CString dlgTitle, DialogType dlgType, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAccountSummary::IDD, pParent)
	, m_reqId(0)
	, m_dlgTitle(dlgTitle)
	, m_dlgType(dlgType)
	, m_groupName("All")
	, m_tags("AccruedCash,BuyingPower,NetLiquidation")
{
	//{{AFX_DATA_INIT(CDlgAccountSummary)
	//}}AFX_DATA_INIT
}

void CDlgAccountSummary::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAccountSummary)
	DDX_Text(pDX, IDC_EDT_ACCOUNT_SUMMARY_REQID, m_reqId);
	DDX_Text(pDX, IDC_EDT_ACCOUNT_SUMMARY_GROUP_NAME, m_groupName);
	DDX_Text(pDX, IDC_EDT_ACCOUNT_SUMMARY_TAGS, m_tags);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgAccountSummary, CDialog)
	//{{AFX_MSG_MAP(CDlgAccountSummary)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAccountSummary message handlers
void CDlgAccountSummary::OnOK()
{
	UpdateData();
	CDialog::OnOK();
}

BOOL CDlgAccountSummary::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText(m_dlgTitle);

	GetDlgItem(IDC_EDT_ACCOUNT_SUMMARY_GROUP_NAME)->EnableWindow( m_dlgType != CANCEL_ACCOUNT_SUMMARY);
	GetDlgItem(IDC_EDT_ACCOUNT_SUMMARY_TAGS)->EnableWindow( m_dlgType != CANCEL_ACCOUNT_SUMMARY);

	return TRUE;	// return TRUE unless you set the focus to a control
					// EXCEPTION: OCX Property Pages should return FALSE
}

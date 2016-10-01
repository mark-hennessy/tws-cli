/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// AcctUpdatesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "AcctUpdatesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcctUpdatesDlg dialog


CAcctUpdatesDlg::CAcctUpdatesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAcctUpdatesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAcctUpdatesDlg)
	m_acctCode = _T("");
	//}}AFX_DATA_INIT

    m_subscribe = false;
}


void CAcctUpdatesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAcctUpdatesDlg)
	DDX_Text(pDX, IDC_EDT_ACCT_CODE, m_acctCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAcctUpdatesDlg, CDialog)
	//{{AFX_MSG_MAP(CAcctUpdatesDlg)
	ON_BN_CLICKED(IDC_UNSUBSCRIBE, OnUnsubscribe)
	ON_BN_CLICKED(IDC_SUBSCRIBE, OnSubscribe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAcctUpdatesDlg message handlers

void CAcctUpdatesDlg::OnUnsubscribe()
{
    UpdateData();

    m_subscribe = false;

	CDialog::OnOK();
}

void CAcctUpdatesDlg::OnSubscribe()
{
    UpdateData();

    m_subscribe = true;

	CDialog::OnOK();
}

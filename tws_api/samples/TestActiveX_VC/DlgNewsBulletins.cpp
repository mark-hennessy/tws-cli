/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// NewsBulletins.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "DlgNewsBulletins.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgNewsBulletins dialog


CDlgNewsBulletins::CDlgNewsBulletins(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNewsBulletins::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNewsBulletins)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_subscribe = false;
	m_allIBMsgs = true;
}

BOOL CDlgNewsBulletins::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_newMsgs.SetCheck( 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgNewsBulletins::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNewsBulletins)
	DDX_Control(pDX, IDC_ALL_MSGS, m_allMsgs);
	DDX_Control(pDX, IDC_NEW_MSGS, m_newMsgs);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgNewsBulletins, CDialog)
	//{{AFX_MSG_MAP(CDlgNewsBulletins)
	ON_BN_CLICKED(IDC_SUBSCRIBE, OnSubscribe)
	ON_BN_CLICKED(IDC_UNSUBSCRIBE, OnUnsubscribe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgNewsBulletins message handlers

void CDlgNewsBulletins::OnSubscribe()
{
	m_subscribe = true;

	m_allIBMsgs = (m_allMsgs.GetCheck() == 1);
	CDialog::OnOK();
}

void CDlgNewsBulletins::OnUnsubscribe()
{
	m_subscribe = false;

	CDialog::OnOK();
}

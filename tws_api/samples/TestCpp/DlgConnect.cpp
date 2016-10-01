/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// CDlgConnect.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgConnect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgConnect dialog
	// Remember the last client Id
static UINT s_lastClientId = 0;

CDlgConnect::CDlgConnect(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgConnect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgConnect)
	m_port = 7496;
	m_clientId = s_lastClientId;
	//}}AFX_DATA_INIT
}


void CDlgConnect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgConnect)
	DDX_Text(pDX, IDC_EDIT1, m_ipAddress);
	DDX_Text(pDX, IDC_EDIT2, m_port);
	DDX_Text(pDX, IDC_EDIT3, m_clientId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgConnect, CDialog)
	//{{AFX_MSG_MAP(CDlgConnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgConnect::OnCancel()
{
	// TODO: Add extra cleanup here
	UpdateData(TRUE);
	s_lastClientId = m_clientId;

	CDialog::OnCancel();
}

void CDlgConnect::OnOK()
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	s_lastClientId = m_clientId;

	CDialog::OnOK();
}

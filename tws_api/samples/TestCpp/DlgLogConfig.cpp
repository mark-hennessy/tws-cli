/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// CDlgLogConfig.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
//#include "EClientSocket.h"
#include "DlgLogConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLogConfig dialog

CDlgLogConfig::CDlgLogConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLogConfig)
	//}}AFX_DATA_INIT

	m_sLogLevel = ERR; // This is the default log level when you connect to TWS
}


void CDlgLogConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLogConfig)
	DDX_Control(pDX, IDC_SERVER_LOGLEVEL, m_serverLogLevel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLogConfig, CDialog)
	//{{AFX_MSG_MAP(CDlgLogConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLogConfig message handlers

void CDlgLogConfig::OnOK()
{
	m_sLogLevel = m_serverLogLevel.GetCurSel();

	CDialog::OnOK();
}

BOOL CDlgLogConfig::OnInitDialog()
{
	CDialog::OnInitDialog();

	if ( CB_ERR == m_serverLogLevel.GetCurSel() )
	{
		m_serverLogLevel.SetCurSel( m_sLogLevel);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

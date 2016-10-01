/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// FAAllocationInfo.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgFAAllocationInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgFAAllocationInfo dialog


CDlgFAAllocationInfo::CDlgFAAllocationInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFAAllocationInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFAAllocationInfo)
	m_group = _T("");
	m_method = _T("");
	m_percentage = _T("");
	m_profile = _T("");
	//}}AFX_DATA_INIT
}


void CDlgFAAllocationInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFAAllocationInfo)
	DDX_Text(pDX, IDC_GROUP, m_group);
	DDX_Text(pDX, IDC_METHOD, m_method);
	DDX_Text(pDX, IDC_PERCENTGE, m_percentage);
	DDX_Text(pDX, IDC_PROFILE, m_profile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgFAAllocationInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgFAAllocationInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgFAAllocationInfo message handlers

void CDlgFAAllocationInfo::OnOK()
{
	UpdateData();

	CDialog::OnOK();
}

void CDlgFAAllocationInfo::OnCancel()
{
	CDialog::OnCancel();
}

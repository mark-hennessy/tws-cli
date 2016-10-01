/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgUnderComp.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgUnderComp.h"

#include "Contract.h"


// CDlgUnderComp dialog

IMPLEMENT_DYNAMIC(CDlgUnderComp, CDialog)

CDlgUnderComp::CDlgUnderComp(UnderComp* underComp, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUnderComp::IDD, pParent)
	, m_underComp(underComp)
	, m_conId(underComp->conId)
	, m_delta(underComp->delta)
	, m_price(underComp->price)
{
}

CDlgUnderComp::~CDlgUnderComp()
{
}

void CDlgUnderComp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONID, m_conId);
	DDX_Text(pDX, IDC_EDIT_DELTA, m_delta);
	DDV_MinMaxDouble(pDX, m_delta, -1, 1);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_price);
}


BEGIN_MESSAGE_MAP(CDlgUnderComp, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgUnderComp::OnOk)
	ON_BN_CLICKED(IDRESET, &CDlgUnderComp::OnReset)
END_MESSAGE_MAP()


// CDlgUnderComp message handlers

void CDlgUnderComp::OnOk()
{
	if (!UpdateData())
		return;

	m_underComp->conId = m_conId;
	m_underComp->delta = m_delta;
	m_underComp->price = m_price;

	EndDialog(IDOK);
}

void CDlgUnderComp::OnReset()
{
	m_underComp->conId = 0;
	m_underComp->delta = 0;
	m_underComp->price = 0;

	EndDialog(IDRESET);
}

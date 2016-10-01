/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgUnderComp.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "DlgUnderComp.h"

#include "Contract.h"
#include "../ActiveX/ComPropAccessor.h"


// CDlgUnderComp dialog

IMPLEMENT_DYNAMIC(CDlgUnderComp, CDialog)

CDlgUnderComp::CDlgUnderComp(IUnderComp* underComp, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUnderComp::IDD, pParent)
	, m_underComp(underComp)
{
	IUnderComp* comUnderComp = m_underComp;

	typedef CComPropAccessor<IUnderComp> Props;

#define GET_PROP(Prop) \
	Props::Get(m_##Prop, comUnderComp, &IUnderComp::get_##Prop);

	GET_PROP(conId);
	GET_PROP(delta);
	GET_PROP(price);

#undef GET_PROP
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

	updateComUnderComp();
	EndDialog(IDOK);
}

void CDlgUnderComp::OnReset()
{
	m_conId = 0;
	m_delta = 0;
	m_price = 0;

	updateComUnderComp();
	EndDialog(IDRESET);
}

void CDlgUnderComp::updateComUnderComp()
{
	ASSERT(m_underComp);

	IUnderComp* comUnderComp = m_underComp;

	typedef CComPropAccessor<IUnderComp> Props;

#define PUT_PROP(Prop) \
	Props::Put(comUnderComp, m_##Prop, &IUnderComp::put_##Prop);

	PUT_PROP(conId);
	PUT_PROP(delta);
	PUT_PROP(price);

#undef PUT_PROP
}

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "DlgSmartComboRoutingParams.h"
#include "Tws.h"
#include "../ActiveX/ComPropAccessor.h"
#include "TwsHelpers.h"

CDlgSmartComboRoutingParams::CDlgSmartComboRoutingParams(ITagValueList* smartComboRoutingParams,
							   CTws* pTws, CString dlgTitle, CWnd* pParent)
	: CDialog(CDlgSmartComboRoutingParams::IDD, pParent)
	, m_pTws(pTws)
	, m_smartComboRoutingParams(smartComboRoutingParams)
	, m_dlgTitle(dlgTitle)
{
}

CDlgSmartComboRoutingParams::~CDlgSmartComboRoutingParams()
{
}


void CDlgSmartComboRoutingParams::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSmartComboRoutingParams)
	DDX_Control(pDX, IDC_LST_SMART_COMBO_ROUTING_PARAMS, m_lstSmartComboRoutingParams);
	DDX_Text(pDX, IDC_EDT_PARAM, m_tagValue.tag);
	DDX_Text(pDX, IDC_EDT_VALUE, m_tagValue.value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSmartComboRoutingParams, CDialog)
	//{{AFX_MSG_MAP(CDlgSmartComboRoutingParams)
	ON_BN_CLICKED(IDC_BTN_ADD_PARAM, OnBtnAddParam)
	ON_BN_CLICKED(IDC_BTN_REMOVE_PARAM, OnBtnRemoveParam)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgSmartComboRoutingParams message handlers

BOOL CDlgSmartComboRoutingParams::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowText(m_dlgTitle);

	m_lstSmartComboRoutingParams.InsertColumn(0, "Param", LVCFMT_LEFT, 64, -1 );
	m_lstSmartComboRoutingParams.InsertColumn(1, "Value", LVCFMT_LEFT, 164, -1 );

	if (m_smartComboRoutingParams) {

		ITagValueList* comSmartComboRoutingParamsPtr = m_smartComboRoutingParams;
		typedef CComPropAccessor<ITagValueList> Props;

		LONG count = 0;
		Props::Get(count, comSmartComboRoutingParamsPtr, &ITagValueList::get_Count);

		if (count > 0) {

			for (LONG i = 0; i < count; ++i) {

				CComQIPtr<ITagValue> comTagValue;
				Props::GetQI_P1(comTagValue, comSmartComboRoutingParamsPtr, &ITagValueList::get_Item, i);

				if (!comTagValue)
					continue;

				TagValue param;
				CTwsHelpers::CopyTwsTagValue2TagValue(param, comTagValue);
				AddParam(m_lstSmartComboRoutingParams, param);
			}
		}
	}

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSmartComboRoutingParams::OnBtnAddParam() 
{
	UpdateData();
	AddParam(m_lstSmartComboRoutingParams, m_tagValue);
}

void CDlgSmartComboRoutingParams::OnBtnRemoveParam() 
{
	for ( int i = m_lstSmartComboRoutingParams.GetItemCount()-1; i >= 0 ; --i) {
		if ( m_lstSmartComboRoutingParams.GetItemState(i, LVIS_SELECTED) ) {
			m_lstSmartComboRoutingParams.DeleteItem( i);
		}
	}
}


void CDlgSmartComboRoutingParams::OnOK() 
{
	UpdateData();

	CComQIPtr<ITagValueList> smartComboRoutingParams;

	const size_t itemCount = m_lstSmartComboRoutingParams.GetItemCount();

	if ( itemCount > 0 ) {

		{
			CComPtr<IDispatch> dispSmartComboRoutingParams;
			dispSmartComboRoutingParams.Attach(m_pTws->createTagValueList());

			smartComboRoutingParams = dispSmartComboRoutingParams;
		}

		for ( size_t i = 0 ; i < itemCount; ++i ) {

			TagValue param;
			GetParam( param, m_lstSmartComboRoutingParams, i);

			CComBSTR comTagStr = param.tag;
			CComBSTR comValueStr = param.value;

			IDispatch* dispTagValuePtr;
			if (!SUCCEEDED(smartComboRoutingParams->Add( comTagStr, comValueStr, &dispTagValuePtr))) {
				continue;
			}
			// the following guarantees that we are not leaking
			// ITagValue COM obj references
			CComPtr<IDispatch> dispTagValue;
			dispTagValue.Attach(dispTagValuePtr);
		}
	}

	m_smartComboRoutingParams = smartComboRoutingParams;

	CDialog::OnOK();
}


void CDlgSmartComboRoutingParams::AddParam(CListCtrl& lstSmartComboRoutingParams, const TagValue& tagValue) 
{
	int insertPos = lstSmartComboRoutingParams.GetItemCount();

	lstSmartComboRoutingParams.InsertItem(insertPos, tagValue.tag);
	lstSmartComboRoutingParams.SetItemText(insertPos, 1, tagValue.value);
}

void CDlgSmartComboRoutingParams::GetParam(TagValue& tagValue, const CListCtrl& lstSmartComboRoutingParams,
							  size_t index) 
{
	tagValue.tag = lstSmartComboRoutingParams.GetItemText( index, 0);
	tagValue.value = lstSmartComboRoutingParams.GetItemText( index, 1);
}

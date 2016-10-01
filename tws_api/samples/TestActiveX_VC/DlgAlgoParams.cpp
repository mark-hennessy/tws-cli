/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "DlgAlgoParams.h"
#include "Tws.h"
#include "../ActiveX/ComPropAccessor.h"
#include "TwsHelpers.h"

CDlgAlgoParams::CDlgAlgoParams(const CString& algoStrategy, ITagValueList* algoParams,
							   CTws* pTws, CWnd* pParent)
	: CDialog(CDlgAlgoParams::IDD, pParent)
	, m_algoStrategy(algoStrategy)
	, m_pTws(pTws)
	, m_algoParams(algoParams)
{
}

CDlgAlgoParams::~CDlgAlgoParams()
{
}


void CDlgAlgoParams::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAlgoParams)
	DDX_Text(pDX, IDC_EDT_ALGO_STRATEGY, m_algoStrategy);
	DDX_Control(pDX, IDC_LST_ALGO_PARAMS, m_lstAlgoParams);
	DDX_Text(pDX, IDC_EDT_PARAM, m_tagValue.tag);
	DDX_Text(pDX, IDC_EDT_VALUE, m_tagValue.value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAlgoParams, CDialog)
	//{{AFX_MSG_MAP(CDlgAlgoParams)
	ON_BN_CLICKED(IDC_BTN_ADD_PARAM, OnBtnAddParam)
	ON_BN_CLICKED(IDC_BTN_REMOVE_PARAM, OnBtnRemoveParam)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgAlgoParams message handlers

BOOL CDlgAlgoParams::OnInitDialog() 
{
	CDialog::OnInitDialog();

    m_lstAlgoParams.InsertColumn(0, "Param", LVCFMT_LEFT, 64, -1 );
    m_lstAlgoParams.InsertColumn(1, "Value", LVCFMT_LEFT, 164, -1 );

	if (m_algoParams) {

		ITagValueList* comAlgoParamsPtr = m_algoParams;
		typedef CComPropAccessor<ITagValueList> Props;

		LONG count = 0;
		Props::Get(count, comAlgoParamsPtr, &ITagValueList::get_Count);

		if (count > 0) {

			for (LONG i = 0; i < count; ++i) {

				CComQIPtr<ITagValue> comTagValue;
				Props::GetQI_P1(comTagValue, comAlgoParamsPtr, &ITagValueList::get_Item, i);

				if (!comTagValue)
					continue;

				TagValue param;
				CTwsHelpers::CopyTwsTagValue2TagValue(param, comTagValue);
				AddParam(m_lstAlgoParams, param);
			}
		}
	}

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAlgoParams::OnBtnAddParam() 
{
    UpdateData();
	AddParam(m_lstAlgoParams, m_tagValue);
}

void CDlgAlgoParams::OnBtnRemoveParam() 
{
    for ( int i = m_lstAlgoParams.GetItemCount()-1; i >= 0 ; --i) {
        if ( m_lstAlgoParams.GetItemState(i, LVIS_SELECTED) ) {
            m_lstAlgoParams.DeleteItem( i);
        }
    }
}


void CDlgAlgoParams::OnOK() 
{
    UpdateData();

	CComQIPtr<ITagValueList> algoParams;

	if ( !m_algoStrategy.IsEmpty() ) {

		const size_t itemCount = m_lstAlgoParams.GetItemCount();

		if ( itemCount > 0 ) {
	
			{
				CComPtr<IDispatch> dispAlgoParams;
				dispAlgoParams.Attach(m_pTws->createTagValueList());

				algoParams = dispAlgoParams;
			}

			for ( size_t i = 0 ; i < itemCount; ++i ) {

				TagValue param;
				GetParam( param, m_lstAlgoParams, i);

				CComBSTR comTagStr = param.tag;
				CComBSTR comValueStr = param.value;

				IDispatch* dispTagValuePtr;
				if (!SUCCEEDED(algoParams->Add( comTagStr, comValueStr, &dispTagValuePtr))) {
					continue;
				}
				// the following guarantees that we are not leaking
				// ITagValue COM obj references
				CComPtr<IDispatch> dispTagValue;
				dispTagValue.Attach(dispTagValuePtr);
			}
		}
	}

	m_algoParams = algoParams;

	CDialog::OnOK();
}


void CDlgAlgoParams::AddParam(CListCtrl& lstAlgoParams, const TagValue& tagValue) 
{
	int insertPos = lstAlgoParams.GetItemCount();

	lstAlgoParams.InsertItem(insertPos, tagValue.tag);
	lstAlgoParams.SetItemText(insertPos, 1, tagValue.value);
}

void CDlgAlgoParams::GetParam(TagValue& tagValue, const CListCtrl& lstAlgoParams,
							  size_t index) 
{
	tagValue.tag = lstAlgoParams.GetItemText( index, 0);
	tagValue.value = lstAlgoParams.GetItemText( index, 1);
}

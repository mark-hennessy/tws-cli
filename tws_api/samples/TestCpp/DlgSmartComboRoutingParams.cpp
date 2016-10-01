/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "DlgSmartComboRoutingParams.h"

CDlgSmartComboRoutingParams::CDlgSmartComboRoutingParams(TagValueListSPtr& smartComboRoutingParams, CString dlgTitle, CWnd* pParent)
	: CDialog(CDlgSmartComboRoutingParams::IDD, pParent)
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
	DDX_Text(pDX, IDC_EDT_PARAM, m_edtParam);
	DDX_Text(pDX, IDC_EDT_VALUE, m_edtValue);
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

	const TagValueList* const smartComboRoutingParams = m_smartComboRoutingParams.get();

	if (smartComboRoutingParams && !smartComboRoutingParams->empty()) {

		TagValueList::const_iterator iter = smartComboRoutingParams->begin();
		const TagValueList::const_iterator iterEnd = smartComboRoutingParams->end();

		size_t insertPos = 0;
		for (; iter != iterEnd; ++iter) {

			const TagValue* const tagValue = iter->get();

			m_lstSmartComboRoutingParams.InsertItem(insertPos, tagValue->tag);
			m_lstSmartComboRoutingParams.SetItemText(insertPos, 1, tagValue->value);

			++insertPos;
		}
	}

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSmartComboRoutingParams::OnBtnAddParam()
{
	UpdateData();

	int insertPos = m_lstSmartComboRoutingParams.GetItemCount();

	m_lstSmartComboRoutingParams.InsertItem(insertPos, m_edtParam);
	m_lstSmartComboRoutingParams.SetItemText(insertPos, 1, m_edtValue);
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

	TagValueListSPtr smartComboRoutingParams;

	const size_t itemCount = m_lstSmartComboRoutingParams.GetItemCount();

	if ( itemCount > 0 ) {

		smartComboRoutingParams.reset( new TagValueList);
		smartComboRoutingParams->reserve( itemCount);

		for ( size_t i = 0; i < itemCount; ++i) {

			TagValueSPtr tagValue( new TagValue());
			tagValue->tag = m_lstSmartComboRoutingParams.GetItemText( i, 0);
			tagValue->value = m_lstSmartComboRoutingParams.GetItemText( i, 1);
			smartComboRoutingParams->push_back( tagValue);
		}
	}

	m_smartComboRoutingParams = smartComboRoutingParams;

	CDialog::OnOK();
}


/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "DlgAlgoParams.h"

CDlgAlgoParams::CDlgAlgoParams(CString& algoStrategy, TagValueListSPtr& algoParams, CWnd* pParent)
	: CDialog(CDlgAlgoParams::IDD, pParent)
	, m_algoStrategy(algoStrategy)
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
	DDX_Text(pDX, IDC_EDT_ALGO_STRATEGY, m_edtAlgoStrategy);
	DDX_Control(pDX, IDC_LST_ALGO_PARAMS, m_lstAlgoParams);
	DDX_Text(pDX, IDC_EDT_PARAM, m_edtParam);
	DDX_Text(pDX, IDC_EDT_VALUE, m_edtValue);
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

	m_edtAlgoStrategy = m_algoStrategy;

	m_lstAlgoParams.InsertColumn(0, "Param", LVCFMT_LEFT, 64, -1 );
	m_lstAlgoParams.InsertColumn(1, "Value", LVCFMT_LEFT, 164, -1 );

	const TagValueList* const algoParams = m_algoParams.get();

	if (algoParams && !algoParams->empty()) {

		TagValueList::const_iterator iter = algoParams->begin();
		const TagValueList::const_iterator iterEnd = algoParams->end();

		size_t insertPos = 0;
		for (; iter != iterEnd; ++iter) {

			const TagValue* const tagValue = iter->get();

			m_lstAlgoParams.InsertItem(insertPos, tagValue->tag);
			m_lstAlgoParams.SetItemText(insertPos, 1, tagValue->value);

			++insertPos;
		}
	}

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAlgoParams::OnBtnAddParam()
{
	UpdateData();

	// TODO: Please add any validation here before setting the combo leg details

	int insertPos = m_lstAlgoParams.GetItemCount();

	m_lstAlgoParams.InsertItem(insertPos, m_edtParam);
	m_lstAlgoParams.SetItemText(insertPos, 1, m_edtValue);
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

	TagValueListSPtr algoParams;

	if ( !m_edtAlgoStrategy.IsEmpty() ) {

		const size_t itemCount = m_lstAlgoParams.GetItemCount();

		if ( itemCount > 0 ) {

			algoParams.reset( new TagValueList);
			algoParams->reserve( itemCount);

			for ( size_t i = 0; i < itemCount; ++i) {

				TagValueSPtr tagValue( new TagValue());
				tagValue->tag = m_lstAlgoParams.GetItemText( i, 0);
				tagValue->value = m_lstAlgoParams.GetItemText( i, 1);
				algoParams->push_back( tagValue);
			}
		}
	}


	m_algoStrategy = m_edtAlgoStrategy;
	m_algoParams = algoParams;

	CDialog::OnOK();
}


/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgComboLegs.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgComboLegs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgComboLegs dialog
CDlgComboLegs::CDlgComboLegs(ComboLegListSPtr& comboLegs, 
							 OrderComboLegListSPtr& orderComboLegs, 
							 const CString& orderExchange,
							 CWnd* pParent /*=NULL*/)
	: CDialog(CDlgComboLegs::IDD, pParent)
	, m_comboLegs(comboLegs)
	, m_orderComboLegs(orderComboLegs)
{
	//{{AFX_DATA_INIT(CDlgComboLegs)
	m_conId = 0;
	m_ratio = 1;
	m_side = _T("BUY");
	m_exchange = orderExchange;
	m_openClose = 0;
	m_shortSaleSlot = 0;
	m_designatedLocation = _T("");
	m_exemptCode = -1;
	m_price = DBL_MAX;
	//}}AFX_DATA_INIT
}

extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, double &value);

void CDlgComboLegs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgComboLegs)
	DDX_Control(pDX, IDC_LST_COMBOLEGS, m_lstComboLegs);
	DDX_Text(pDX, IDC_EDT_CONID, m_conId);
	DDX_Text(pDX, IDC_EDT_RATIO, m_ratio);
	DDX_Text(pDX, IDC_EDT_SIDE, m_side);
	DDX_Text(pDX, IDC_EDT_EXCHANGE, m_exchange);
	DDX_Text(pDX, IDC_EDT_OPENCLOSE, m_openClose);
	DDX_Text(pDX, IDC_EDT_SHORT_SALE_SLOT, m_shortSaleSlot);
	DDX_Text(pDX, IDC_EDT_DESIGNATED_LOCATION, m_designatedLocation);
	DDX_Text(pDX, IDC_EDT_EXEMPT_CODE, m_exemptCode);
	DDX_TextMax(pDX, IDC_EDT_PRICE, m_price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgComboLegs, CDialog)
	//{{AFX_MSG_MAP(CDlgComboLegs)
	ON_BN_CLICKED(IDC_BTN_ADD_LEG, OnBtnAddLeg)
	ON_BN_CLICKED(IDC_BTN_REMOVE_LEG, OnBtnRemoveLeg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgComboLegs message handlers

BOOL CDlgComboLegs::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString title;
	title.Format("Combination Order Legs");
	SetWindowText(title);

	m_lstComboLegs.InsertColumn(0, "ConId", LVCFMT_LEFT, 65, -1 );
	m_lstComboLegs.InsertColumn(1, "Ratio", LVCFMT_LEFT, 40, -1 );
	m_lstComboLegs.InsertColumn(2, "Side", LVCFMT_LEFT, 40, -1 );
	m_lstComboLegs.InsertColumn(3, "Exchange", LVCFMT_LEFT, 70, -1 );
	m_lstComboLegs.InsertColumn(4, "Open/Close", LVCFMT_LEFT, 70, -1 );
	m_lstComboLegs.InsertColumn(5, "Short Sale Slot", LVCFMT_LEFT, 70, -1 );
	m_lstComboLegs.InsertColumn(6, "Designated Location", LVCFMT_LEFT, 70, -1 );
	m_lstComboLegs.InsertColumn(7, "Exempt Code", LVCFMT_LEFT, 70, -1 );
	m_lstComboLegs.InsertColumn(8, "Price", LVCFMT_LEFT, 70, -1 );

	if (m_comboLegs.get()) {
		const Contract::ComboLegList& comboLegs = *m_comboLegs;
		const size_t comboLegsCount = comboLegs.size();
		size_t insertPos = 0;

		for( size_t i = 0; i < comboLegsCount; ++i) {
			const ComboLeg& comboLeg = *comboLegs[i];

			char buf[20];

			_itoa(comboLeg.conId, buf, 10);
			m_lstComboLegs.InsertItem(insertPos, buf);

			_itoa(comboLeg.ratio, buf, 10);
			m_lstComboLegs.SetItemText(insertPos, 1, buf);

			m_lstComboLegs.SetItemText(insertPos, 2, comboLeg.action);

			m_lstComboLegs.SetItemText(insertPos, 3, comboLeg.exchange);

			_itoa(comboLeg.openClose, buf, 10);
			m_lstComboLegs.SetItemText(insertPos, 4, buf);

			_itoa(comboLeg.shortSaleSlot, buf, 10);
			m_lstComboLegs.SetItemText(insertPos, 5, buf);

			m_lstComboLegs.SetItemText(insertPos, 6, comboLeg.designatedLocation);

			_itoa(comboLeg.exemptCode, buf, 10);
			m_lstComboLegs.SetItemText(insertPos, 7, buf);

			++insertPos;
		}
	}

	if (m_orderComboLegs.get()) {

		const Order::OrderComboLegList& orderComboLegs = *m_orderComboLegs;
		const size_t orderComboLegsCount = orderComboLegs.size();
		size_t insertPos = 0;

		for( size_t i = 0; i < orderComboLegsCount; ++i) {
			const OrderComboLeg& orderComboLeg = *orderComboLegs[i];

			char buf[20];

			if (orderComboLeg.price != DBL_MAX) {
				sprintf(buf, "%f", orderComboLeg.price);
			}
			else {
				sprintf(buf, "%s", "");
			}
			m_lstComboLegs.SetItemText(insertPos, 8, buf);

			++insertPos;
		}
	}
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgComboLegs::OnBtnAddLeg()
{
	UpdateData();

	// TODO: Please add any validation here before setting the combo leg details

	int insertPos = m_lstComboLegs.GetItemCount();

	char buf[20];

	_itoa(m_conId, buf, 10);
	m_lstComboLegs.InsertItem(insertPos, buf);

	_itoa(m_ratio, buf, 10);
	m_lstComboLegs.SetItemText(insertPos, 1, buf);

	m_lstComboLegs.SetItemText(insertPos, 2, m_side);

	m_lstComboLegs.SetItemText(insertPos, 3, m_exchange);

	_itoa(m_openClose, buf, 10);
	m_lstComboLegs.SetItemText(insertPos, 4, buf);

	_itoa(m_shortSaleSlot, buf, 10);
	m_lstComboLegs.SetItemText(insertPos, 5, buf);

	m_lstComboLegs.SetItemText(insertPos, 6, m_designatedLocation);

	_itoa(m_exemptCode, buf, 10);
	m_lstComboLegs.SetItemText(insertPos, 7, buf);

	if (m_price != DBL_MAX) {
		sprintf(buf, "%f", m_price);
	}
	else {
		sprintf(buf, "%s", "");
	}
	m_lstComboLegs.SetItemText(insertPos, 8, buf);
}

void CDlgComboLegs::OnBtnRemoveLeg()
{
	for ( int i=m_lstComboLegs.GetItemCount() -1; i>=0 ; i-- ) {
		if ( m_lstComboLegs.GetItemState(i, LVIS_SELECTED) ) {
			m_lstComboLegs.DeleteItem( i);
		}
	}
}

void CDlgComboLegs::OnOK()
{
	UpdateData(); // get the order legs

	CString itemText;

	ComboLegListSPtr comboLegs;
	OrderComboLegListSPtr orderComboLegs;

	const size_t itemCount = m_lstComboLegs.GetItemCount();

	if ( itemCount > 0 ) {

		comboLegs.reset( new ComboLegList);
		orderComboLegs.reset( new OrderComboLegList);
		comboLegs->reserve( itemCount);
		orderComboLegs->reserve( itemCount);

		for ( size_t i = 0 ; i < itemCount; ++i ) {

			ComboLegSPtr comboLeg( new ComboLeg());
			OrderComboLegSPtr orderComboLeg( new OrderComboLeg());

			itemText = m_lstComboLegs.GetItemText( i, 0);
			comboLeg->conId = atoi( itemText);

			itemText = m_lstComboLegs.GetItemText( i, 1);
			comboLeg->ratio = atoi( itemText);

			itemText = m_lstComboLegs.GetItemText( i, 2);
			comboLeg->action = itemText;

			itemText = m_lstComboLegs.GetItemText( i, 3);
			comboLeg->exchange = itemText;

			itemText = m_lstComboLegs.GetItemText( i, 4);
			comboLeg->openClose = atoi( itemText);

			itemText = m_lstComboLegs.GetItemText( i, 5);
			comboLeg->shortSaleSlot = atoi( itemText);

			itemText = m_lstComboLegs.GetItemText( i, 6);
			comboLeg->designatedLocation = itemText;

			itemText = m_lstComboLegs.GetItemText( i, 7);
			comboLeg->exemptCode = atoi( !itemText.IsEmpty() ? itemText : "-1");

			comboLegs->push_back(comboLeg);

			itemText = m_lstComboLegs.GetItemText( i, 8);
			if (!itemText.IsEmpty()) {
				orderComboLeg->price = atof( itemText);
			}
			else {
				orderComboLeg->price = DBL_MAX;
			}

			orderComboLegs->push_back(orderComboLeg);
		}
	}

	m_comboLegs = comboLegs;
	m_orderComboLegs = orderComboLegs;

	CDialog::OnOK();
}

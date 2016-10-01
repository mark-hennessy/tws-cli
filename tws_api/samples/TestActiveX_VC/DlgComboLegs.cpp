/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgComboLegs.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "DlgComboLegs.h"
#include "Tws.h"
#include "../ActiveX/ComPropAccessor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgComboLegs dialog
CDlgComboLegs::CDlgComboLegs(IComboLegList* comboLegs, IOrderComboLegList* orderComboLegs, 
							 const CString& orderExchange,
							 CTws* pTws, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgComboLegs::IDD, pParent)
	, m_pTws(pTws)
	, m_comboLegs(comboLegs)
	, m_orderComboLegs(orderComboLegs)
{
	//{{AFX_DATA_INIT(CDlgComboLegs)
	m_comboLeg.conId = 0;
	m_comboLeg.ratio = 1;
	m_comboLeg.action = _T("BUY");
	m_comboLeg.exchange = orderExchange;
	m_comboLeg.openClose = 0;
	m_comboLeg.shortSaleSlot = 0;
	m_comboLeg.designatedLocation = _T("");
	m_comboLeg.exemptCode = -1;
	m_orderComboLeg.price = DBL_MAX;
	//}}AFX_DATA_INIT
}

extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, double &value);

void CDlgComboLegs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgComboLegs)
	DDX_Control(pDX, IDC_LST_COMBOLEGS, m_lstComboLegs);
	DDX_Text(pDX, IDC_EDT_CONID, m_comboLeg.conId);
	DDX_Text(pDX, IDC_EDT_RATIO, m_comboLeg.ratio);
	DDX_Text(pDX, IDC_EDT_SIDE, m_comboLeg.action);
	DDX_Text(pDX, IDC_EDT_EXCHANGE, m_comboLeg.exchange);
	DDX_Text(pDX, IDC_EDT_OPENCLOSE, m_comboLeg.openClose);
	DDX_Text(pDX, IDC_EDT_SHORT_SALE_SLOT, m_comboLeg.shortSaleSlot);
	DDX_Text(pDX, IDC_EDT_DESIGNATED_LOCATION, m_comboLeg.designatedLocation);
	DDX_Text(pDX, IDC_EDT_EXEMPT_CODE, m_comboLeg.exemptCode);
	DDX_TextMax(pDX, IDC_EDT_PRICE, m_orderComboLeg.price);
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

	if (m_comboLegs && m_orderComboLegs) {

		IComboLegList* comComboLegsPtr = m_comboLegs;
		typedef CComPropAccessor<IComboLegList> PropsComboLeg;
		IOrderComboLegList* comOrderComboLegsPtr = m_orderComboLegs;
		typedef CComPropAccessor<IOrderComboLegList> PropsOrderComboLeg;

		LONG count = 0;
		PropsComboLeg::Get(count, comComboLegsPtr, &IComboLegList::get_Count);
		PropsOrderComboLeg::Get(count, comOrderComboLegsPtr, &IOrderComboLegList::get_Count);

		if (count > 0) {

			for (LONG i = 0; i < count; ++i) {

				CComQIPtr<IComboLeg> comComboLeg;
				PropsComboLeg::GetQI_P1(comComboLeg, comComboLegsPtr, &IComboLegList::get_Item, i);
				CComQIPtr<IOrderComboLeg> comOrderComboLeg;
				PropsOrderComboLeg::GetQI_P1(comOrderComboLeg, comOrderComboLegsPtr, &IOrderComboLegList::get_Item, i);

				if (!comComboLeg)
					continue;
				if (!comOrderComboLeg)
					continue;

				ComboLeg comboLeg;
				OrderComboLeg orderComboLeg;
				CopyTwsComboLeg2ComboLeg(comboLeg, comComboLeg, orderComboLeg, comOrderComboLeg);
				AddComboLeg(m_lstComboLegs, comboLeg, orderComboLeg);
			}
		}
	}

    UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgComboLegs::OnBtnAddLeg() 
{
    UpdateData();
    AddComboLeg(m_lstComboLegs, m_comboLeg, m_orderComboLeg);
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

	CComQIPtr<IComboLegList> comboLegs;
	CComQIPtr<IOrderComboLegList> orderComboLegs;

	const size_t itemCount = m_lstComboLegs.GetItemCount();
	if (itemCount > 0) {

		{
			CComPtr<IDispatch> dispComboLegList;
			CComPtr<IDispatch> dispOrderComboLegList;
			dispComboLegList.Attach(m_pTws->createComboLegList());
			dispOrderComboLegList.Attach(m_pTws->createOrderComboLegList());

			comboLegs = dispComboLegList;
			orderComboLegs = dispOrderComboLegList;
		}
		for ( size_t i = 0 ; i < itemCount; ++i ) {

			IDispatch* dispComboLegPtr;
			IDispatch* dispOrderComboLegPtr;
			if (!SUCCEEDED(comboLegs->Add(&dispComboLegPtr))) {
				continue;
			}
			if (!SUCCEEDED(orderComboLegs->Add(&dispOrderComboLegPtr))) {
				continue;
			}
			CComPtr<IDispatch> dispComboLeg;
			CComPtr<IDispatch> dispOrderComboLeg;
			dispComboLeg.Attach(dispComboLegPtr);
			dispOrderComboLeg.Attach(dispOrderComboLegPtr);

			CComQIPtr<IComboLeg> comComboLeg(dispComboLeg);
			CComQIPtr<IOrderComboLeg> comOrderComboLeg(dispOrderComboLeg);
			if (!comComboLeg)
				continue;
			if (!comOrderComboLeg)
				continue;

			ComboLeg comboLeg;
			OrderComboLeg orderComboLeg;
			GetComboLeg(comboLeg, orderComboLeg, m_lstComboLegs, i);
			CopyComboLeg2TwsComboLeg(comComboLeg, comboLeg, comOrderComboLeg, orderComboLeg);
		}
	}

	m_comboLegs = comboLegs;
	m_orderComboLegs = orderComboLegs;

	CDialog::OnOK();
}

void CDlgComboLegs::AddComboLeg(CListCtrl& lstComboLegs, const ComboLeg& comboLeg, const OrderComboLeg& orderComboLeg) 
{
    int insertPos = lstComboLegs.GetItemCount();

    char buf[20];

    _itoa(comboLeg.conId, buf, 10);
    lstComboLegs.InsertItem(insertPos, buf); 

    _itoa(comboLeg.ratio, buf, 10);
    lstComboLegs.SetItemText(insertPos, 1, buf);

    lstComboLegs.SetItemText(insertPos, 2, comboLeg.action);

    lstComboLegs.SetItemText(insertPos, 3, comboLeg.exchange);

    _itoa(comboLeg.openClose, buf, 10);
    lstComboLegs.SetItemText(insertPos, 4, buf);

	_itoa(comboLeg.shortSaleSlot, buf, 10);
	lstComboLegs.SetItemText(insertPos, 5, buf);

	lstComboLegs.SetItemText(insertPos, 6, comboLeg.designatedLocation);

	_itoa(comboLeg.exemptCode, buf, 10);
	lstComboLegs.SetItemText(insertPos, 7, buf);

	if (orderComboLeg.price != DBL_MAX) {
		sprintf(buf, "%f", orderComboLeg.price);
	}
	else {
		sprintf(buf, "%s", "");
	}
	lstComboLegs.SetItemText(insertPos, 8, buf);
}

void CDlgComboLegs::GetComboLeg(ComboLeg& comboLeg, OrderComboLeg& orderComboLeg, const CListCtrl& lstComboLegs,
								size_t index) 
{
	CString itemText;

	itemText = lstComboLegs.GetItemText(index, 0);
	comboLeg.conId = atoi(itemText);

	itemText = lstComboLegs.GetItemText(index, 1);
	comboLeg.ratio = atoi(itemText);

	itemText = lstComboLegs.GetItemText(index, 2);
	comboLeg.action = itemText;

	itemText = lstComboLegs.GetItemText(index, 3);
	comboLeg.exchange = itemText;

	itemText = lstComboLegs.GetItemText(index, 4);
	comboLeg.openClose = atoi(itemText);

	itemText = lstComboLegs.GetItemText(index, 5);
	comboLeg.shortSaleSlot = atoi(itemText);

	itemText = lstComboLegs.GetItemText(index, 6);
	comboLeg.designatedLocation = itemText;

	itemText = lstComboLegs.GetItemText(index, 7);
	comboLeg.exemptCode = atoi(itemText);

	itemText = lstComboLegs.GetItemText(index, 8);
	if (!itemText.IsEmpty()) {
		orderComboLeg.price = atof( itemText);
	}
	else {
		orderComboLeg.price = DBL_MAX;
	}
}


void CDlgComboLegs::CopyTwsComboLeg2ComboLeg(
	ComboLeg& comboLeg, /* const */ IComboLeg* comComboLeg,
	OrderComboLeg& orderComboLeg, /* const */ IOrderComboLeg* comOrderComboLeg)
{
	ASSERT (comComboLeg);
	ASSERT (comOrderComboLeg);

	typedef CComPropAccessor<IComboLeg> PropsComboLeg;
	typedef CComPropAccessor<IOrderComboLeg> PropsOrderComboLeg;

#define GET_PROP(PropComboLeg) \
	PropsComboLeg::Get(comboLeg.PropComboLeg, comComboLeg, &IComboLeg::get_##PropComboLeg);

	GET_PROP(conId);
	GET_PROP(ratio);
	GET_PROP(action);
	GET_PROP(exchange);
	GET_PROP(openClose);
	GET_PROP(shortSaleSlot);
	GET_PROP(designatedLocation);
	GET_PROP(exemptCode);

#undef GET_PROP

#define GET_PROP(PropOrderComboLeg) \
	PropsOrderComboLeg::Get(orderComboLeg.PropOrderComboLeg, comOrderComboLeg, &IOrderComboLeg::get_##PropOrderComboLeg);

	GET_PROP(price);

#undef GET_PROP
}

void CDlgComboLegs::CopyComboLeg2TwsComboLeg(
	IComboLeg* comComboLeg, const ComboLeg& comboLeg,
	IOrderComboLeg* comOrderComboLeg, const OrderComboLeg& orderComboLeg)
{
	ASSERT (comComboLeg);
	ASSERT (comOrderComboLeg);

	typedef CComPropAccessor<IComboLeg> PropsComboLeg;
	typedef CComPropAccessor<IOrderComboLeg> PropsOrderComboLeg;

#define PUT_PROP(Prop) \
	PropsComboLeg::Put(comComboLeg, comboLeg.Prop, &IComboLeg::put_##Prop);

	PUT_PROP(conId);
	PUT_PROP(ratio);
	PUT_PROP(action);
	PUT_PROP(exchange);
	PUT_PROP(openClose);
	PUT_PROP(shortSaleSlot);
	PUT_PROP(designatedLocation);
	PUT_PROP(exemptCode);

#undef PUT_PROP

#define PUT_PROP(Prop) \
	PropsOrderComboLeg::Put(comOrderComboLeg, orderComboLeg.Prop, &IOrderComboLeg::put_##Prop);

	PUT_PROP(price);

#undef PUT_PROP
}
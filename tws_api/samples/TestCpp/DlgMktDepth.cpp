/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgMktDepth.cpp : implementation file
//
#include "stdafx.h"
#include "DlgMktDepth.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMktDepth dialog
const static int OPERATION_INSERT = 0;
const static int OPERATION_UPDATE = 1;
const static int OPERATION_DELETE = 2;

const static int SIDE_ASK = 0;
const static int SIDE_BID = 1;

const int CDlgMktDepth::MKT_DEPTH_DATA_RESET = 317;

CDlgMktDepth::CDlgMktDepth(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMktDepth::IDD, pParent)
	, m_active(false)
{
	//{{AFX_DATA_INIT(CDlgMktDepth)
	//}}AFX_DATA_INIT
}


void CDlgMktDepth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMktDepth)
	DDX_Control(pDX, IDC_LIST_BID, m_listBid);
	DDX_Control(pDX, IDC_LIST_ASK, m_listAsk);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMktDepth, CDialog)
	//{{AFX_MSG_MAP(CDlgMktDepth)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMktDepth message handlers
BOOL CDlgMktDepth::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Setup the bid / ask lists
	m_listBid.InsertColumn(0, "MM", LVCFMT_LEFT, 50, -1 );
	m_listBid.InsertColumn(1, "Price", LVCFMT_LEFT, 80, -1 );
	m_listBid.InsertColumn(2, "Size", LVCFMT_LEFT, 55, -1 );
	m_listBid.InsertColumn(3, "Cum Size", LVCFMT_LEFT, 55, -1 );
	m_listBid.InsertColumn(4, "Avg Price", LVCFMT_LEFT, 80, -1 );

	m_listAsk.InsertColumn(0, "MM", LVCFMT_LEFT, 50, -1 );
	m_listAsk.InsertColumn(1, "Price", LVCFMT_LEFT, 80, -1 );
	m_listAsk.InsertColumn(2, "Size", LVCFMT_LEFT, 55, -1 );
	m_listAsk.InsertColumn(3, "Cum Size", LVCFMT_LEFT, 55, -1 );
	m_listAsk.InsertColumn(4, "Avg Price", LVCFMT_LEFT, 80, -1 );

	m_active = true;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMktDepth::OnDestroy()
{
	m_active = false;
	CDialog::OnDestroy();
}

void CDlgMktDepth::clear()
{
	m_listBid.DeleteAllItems();
	m_listAsk.DeleteAllItems();
}

/////////////////////////////////////////////////////////////////////////////
// Public Methods
/////////////////////////////////////////////////////////////////////////////
void CDlgMktDepth::updateMktDepth( int id, int position, CString marketMaker,
    int operation, int side, double price, int size)
{
	if (!m_active)
		return;

	if (operation == OPERATION_INSERT )
	{
		addEntry( (side == SIDE_BID ? &m_listBid : &m_listAsk), position, marketMaker, price, size);
	}
	else if (operation == OPERATION_UPDATE )
	{
        updateEntry( (side == SIDE_BID ? &m_listBid : &m_listAsk), position, marketMaker, price, size);
	}
	else if (operation == OPERATION_DELETE)
	{
		deleteEntry( (side == SIDE_BID ? &m_listBid : &m_listAsk), position);
	}
}


/////////////////////////////////////////////////////////////////////////////
// Private Methods
/////////////////////////////////////////////////////////////////////////////
void CDlgMktDepth::addEntry(CListCtrl* pList, int position, CString marketMaker,
        double price, int size)
{
	CString val;

	int index = pList->InsertItem(position, marketMaker);

	val.Format("%f", price);
	pList->SetItemText(index, 1, val);

	val.Format("%d", size);
	pList->SetItemText(index, 2, val);

	updateList(pList, index);
}

void CDlgMktDepth::updateEntry(CListCtrl* pList, int position, CString marketMaker, double price, int size)
{
	CString val;

    val.Format("%s", marketMaker);
    pList->SetItemText(position, 0, val);

	val.Format("%f", price);
	pList->SetItemText(position, 1, val);

	val.Format("%d", size);
	pList->SetItemText(position, 2, val);

	updateList(pList, position);
}

void CDlgMktDepth::deleteEntry(CListCtrl* pList, int position)
{
	pList->DeleteItem( position);

	updateList(pList, position);
}


void CDlgMktDepth::updateList(CListCtrl* pList, int position)
{
	// need to recalc the cum

	CString val;
	CString strSize;
	CString strPrice;
	int     cumSize = 0;
	double  totalPrice = 0.0;

	if (position > 0 && position < pList->GetItemCount()) {
		cumSize = atoi(pList->GetItemText(position-1, 3));
		totalPrice = (atof(pList->GetItemText(position-1, 1)) * cumSize);
	}

	for (int i = position ; i < pList->GetItemCount() ; i++)
	{
		strPrice = pList->GetItemText(i, 1);
		strSize = pList->GetItemText(i, 2);
	    	int atoiStrSize = atoi(strSize);
		cumSize += atoiStrSize;
		totalPrice += (atof(strPrice) * atoiStrSize);
		val.Format("%d", cumSize);
		pList->SetItemText(i, 3, val);
		val.Format("%f", (totalPrice / cumSize));
		pList->SetItemText(i, 4, val);
	}
}

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgAccount.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgAccount.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAccount dialog

CDlgAccount::CDlgAccount(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAccount::IDD, pParent)
	, m_complete(false)
{
	//{{AFX_DATA_INIT(CDlgAccount)
	//}}AFX_DATA_INIT
}

BOOL CDlgAccount::OnInitDialog()
{
	CDialog::OnInitDialog();
	updateTitle();

	return TRUE;
}

void CDlgAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAccount)
	DDX_Control(pDX, IDC_EDIT2, m_updateTime);
	DDX_Control(pDX, IDC_LIST5, m_portfolio);
	DDX_Control(pDX, IDC_LIST4, m_keyValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAccount, CDialog)
	//{{AFX_MSG_MAP(CDlgAccount)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAccount message handlers

void CDlgAccount::updateAccountValue(const CString &key, const CString &val,
									const CString &currency, const CString &accountName)
{
    if ( m_keyValue.m_hWnd != NULL ) {
	    CString dspStr = "key=" + key + " value=" + val + " currency=" + currency +
						 " account=" + accountName;
	    m_keyValue.InsertString(0, dspStr);	
    }
}

void CDlgAccount::updateAccountTime(const CString &timeStamp) 
{
    if ( m_updateTime.m_hWnd != NULL ) {
	    m_updateTime.SetWindowText( timeStamp);
    }
}

void CDlgAccount::updatePortfolio( const Contract &contract, int position,
								 double marketPrice, double marketValue,
								 double averageCost, double unrealizedPNL,
								 double realizedPNL, const CString &accountName) 
{
    if ( m_portfolio.m_hWnd != NULL ) {
        CString str;
	    str.Format( "conId=%i symbol=%s  secType=%s  expiry=%s  strike=%f right=%s multiplier=%s primaryExchange=%s"
			" currency=%s localSymbol=%s tradingClass=%s position=%i mktPrice=%f mktValue=%f avgCost=%f unrealizedPNL=%f realizedPNL=%f account=%s",
		    contract.conId, (const char *)contract.symbol, (const char *)contract.secType, (const char *)contract.expiry,
			contract.strike, (const char *)contract.right, (const char*)contract.multiplier, (const char*)contract.primaryExchange,
			(const char *)contract.currency, (const char *)contract.localSymbol, (const char*)contract.tradingClass,
		    position, marketPrice, marketValue, averageCost, unrealizedPNL, realizedPNL, (const char *)accountName);

	    m_portfolio.InsertString(0, str);
    }
}

void CDlgAccount::accountDownloadBegin( const CString& accountName) 
{
	m_accountName = accountName;
	m_complete = false;

	// updateTitle();
}

void CDlgAccount::accountDownloadEnd( const CString& accountName) 
{
	if (!m_accountName.IsEmpty() && m_accountName != accountName) {
		return;
	}

	m_complete = true;
	updateTitle();
}

void CDlgAccount::updateTitle()
{
	CString title;
	if (!m_accountName.IsEmpty()) {
		title = m_accountName;
	}
	if (m_complete) {
		if (!title.IsEmpty()) {
			title += ' ';
		}
		title += "[complete]";
	}

	SetWindowText(title);
}
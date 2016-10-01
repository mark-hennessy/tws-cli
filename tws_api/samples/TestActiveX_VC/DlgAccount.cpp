/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgAccount.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "DlgAccount.h"

#include "../ActiveX/ComPropAccessor.h"

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
		// NOTE: the ClassWizard will add member initialization here
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
	DDX_Control(pDX, IDC_LIST2, m_portfolio);
	DDX_Control(pDX, IDC_LIST1, m_accountValue);
	DDX_Control(pDX, IDC_EDIT2, m_updateTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAccount, CDialog)
	//{{AFX_MSG_MAP(CDlgAccount)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAccount message handlers
void CDlgAccount::updateAccountValue(const CString &key, const CString &val, const CString &currency, const CString &accountName)
{
	CString dspStr = "key=" + key + " value=" + val + " currency=" + currency +
		" account name=" + accountName;

    if ( m_accountValue.m_hWnd != NULL ) {
	    int i = m_accountValue.InsertString(0, dspStr);
    }
}

void CDlgAccount::updateAccountTime(const CString &timeStamp) 
{
    if ( m_updateTime.m_hWnd != NULL ) {
	    m_updateTime.SetWindowText(timeStamp);
    }
}

void CDlgAccount::updatePortfolio(IDispatch* dispContract, int position,
								  double marketPrice, double marketValue,
								  double averageCost, double unrealizedPNL,
								  double realizedPNL, const CString& accountName)
{
	CComQIPtr<IContract> contract(dispContract);

	if (!contract) {
		return;
	}

	int     conId;
	CString symbol;
	CString secType;
	CString expiry;
	double strike;
	CString right;
	CString multiplier;
	CString primaryExchange;
	CString currency;
	CString localSymbol;
	CString tradingClass;

	typedef CComPropAccessor<IContract> Props;

#define GET_PROP(Prop) \
	Props::Get(Prop, contract, &IContract::get_##Prop);

	GET_PROP(conId);
	GET_PROP(symbol);
	GET_PROP(secType);
	GET_PROP(expiry);
	GET_PROP(strike);
	GET_PROP(right);
	GET_PROP(multiplier);
	GET_PROP(primaryExchange);
	GET_PROP(currency);
	GET_PROP(localSymbol);
	GET_PROP(tradingClass);

#undef GET_PROP

    CString str;
	str.Format( "conId=%i symbol=%s  secType=%s  expiry=%s  strike=%f right=%s multiplier=%s primaryExchange=%s currency=%s localSymbol=%s tradingClass=%s"
		" position=%i mktPrice=%f mktValue=%f averageCost=%f unrealizedPNL=%f realizedPNL=%f account name=%s",
		conId, (const char *)symbol, (const char *)secType, (const char *)expiry, strike, (const char *)right,
		(const char*)multiplier, (const char*)primaryExchange, (const char *)currency, (const char *)localSymbol, (const char *)tradingClass,
		position, marketPrice, marketValue, averageCost, unrealizedPNL, realizedPNL,
		accountName);

    if ( m_portfolio.m_hWnd != NULL ) {
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
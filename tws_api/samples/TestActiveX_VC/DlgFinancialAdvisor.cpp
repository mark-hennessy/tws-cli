/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgFinancialAdvisor.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "DlgFinancialAdvisor.h"


// CDlgFinancialAdvisor dialog

IMPLEMENT_DYNAMIC(CDlgFinancialAdvisor, CDialog)
CDlgFinancialAdvisor::CDlgFinancialAdvisor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFinancialAdvisor::IDD, pParent)
	, faGroupsXML(_T(""))
	, faProfilesXML(_T(""))
	, faAliasesXML(_T(""))
{
}

CDlgFinancialAdvisor::~CDlgFinancialAdvisor()
{
}

void CDlgFinancialAdvisor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FA_TEXT1, faGroupsXML);
	DDX_Text(pDX, IDC_FA_TEXT2, faProfilesXML);
	DDX_Text(pDX, IDC_FA_TEXT3, faAliasesXML);
}


BEGIN_MESSAGE_MAP(CDlgFinancialAdvisor, CDialog)
END_MESSAGE_MAP()


// CDlgFinancialAdvisor message handlers
void CDlgFinancialAdvisor::OnOK()
{
	//UpdateData();

	CDialog::OnOK();
}

void CDlgFinancialAdvisor::OnCancel()
{
	CDialog::OnCancel();
}

// VC++ 5.0 MFC does not have CString.Replace.  So, I use this:

void CStringReplace(CString &pXml, LPTSTR cStr, LPTSTR rStr, CString &pDest)
{
	int rlen, len, clen, lenFound ;
	LPTSTR pFind, builtBuf, pBuiltBuf, pBuf ;

	len = pXml.GetLength() ;
	clen = strlen( cStr ) ;
	rlen = strlen( rStr ) ;
	pBuf = pXml.GetBuffer( len );
	// next allocation size will always be large enough!
	builtBuf = pBuiltBuf = (LPTSTR)calloc(1, len * rlen + 1) ;

	do {
		pFind = strstr(pBuf, cStr) ;
		if (pFind == NULL)
			strcat(pBuiltBuf, pBuf) ;
		else {
			lenFound = pFind - pBuf ;
			memcpy(pBuiltBuf, pBuf, lenFound) ;
			memcpy(pBuiltBuf + lenFound, rStr, rlen) ;
			pBuiltBuf += lenFound + rlen ;
			pBuf += lenFound + clen ;
		}
		}
	while (pFind != NULL) ;
	pXml.ReleaseBuffer( );
	pDest = builtBuf ;
	free(builtBuf) ;
}

void CDlgFinancialAdvisor::receiveInitialXML(CString &pFaGroupXML, CString &pFaProfileXML, CString &pFaAliasesXML)
{
	// replace carriage return with CRLF for editing in MFC
	CStringReplace(pFaGroupXML, "\n", "\r\n", faGroupsXML) ;
	CStringReplace(pFaProfileXML, "\n", "\r\n", faProfilesXML) ;
	CStringReplace(pFaAliasesXML, "\n", "\r\n", faAliasesXML) ;
}

void CDlgFinancialAdvisor::extractXML(CString &pFaGroupXML, CString &pFaProfileXML, CString &pFaAliasesXML)
{
	// reverse the above substitution
	CStringReplace(faGroupsXML, "\r\n", "\n", pFaGroupXML) ;
	CStringReplace(faProfilesXML, "\r\n", "\n", pFaProfileXML) ;
	CStringReplace(faAliasesXML, "\r\n", "\n", pFaAliasesXML) ;
}

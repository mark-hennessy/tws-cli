/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgFinancialAdvisor.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgFinancialAdvisor.h"
#include "client2Dlg.h"

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

void CDlgFinancialAdvisor::receiveInitialXML(CString &pFaGroupXML, CString &pFaProfileXML, CString &pFaAliasesXML)
{
	CClient2Dlg::CStringReplace(pFaGroupXML, CClient2Dlg::NEWLINE, CClient2Dlg::RETURN_NEWLINE, faGroupsXML) ;
	CClient2Dlg::CStringReplace(pFaProfileXML, CClient2Dlg::NEWLINE, CClient2Dlg::RETURN_NEWLINE, faProfilesXML) ;
	CClient2Dlg::CStringReplace(pFaAliasesXML, CClient2Dlg::NEWLINE, CClient2Dlg::RETURN_NEWLINE, faAliasesXML) ;
}

void CDlgFinancialAdvisor::extractXML(CString &pFaGroupXML, CString &pFaProfileXML, CString &pFaAliasesXML)
{
	CClient2Dlg::CStringReplace(faGroupsXML, CClient2Dlg::RETURN_NEWLINE, CClient2Dlg::NEWLINE, pFaGroupXML) ;
	CClient2Dlg::CStringReplace(faProfilesXML, CClient2Dlg::RETURN_NEWLINE, CClient2Dlg::NEWLINE, pFaProfileXML) ;
	CClient2Dlg::CStringReplace(faAliasesXML, CClient2Dlg::RETURN_NEWLINE, CClient2Dlg::NEWLINE, pFaAliasesXML) ;
}

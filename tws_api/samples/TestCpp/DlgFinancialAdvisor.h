/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once


// CDlgFinancialAdvisor dialog

class CDlgFinancialAdvisor : public CDialog
{
	DECLARE_DYNAMIC(CDlgFinancialAdvisor)

public:
	CDlgFinancialAdvisor(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgFinancialAdvisor();

// Dialog Data
	enum { IDD = IDD_FA_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgFinancialAdvisor)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void receiveInitialXML(CString &pFaGroupXML, CString &pFaProfileXML, CString &pFaAliasesXML);
	void extractXML(CString &pFaGroupXML, CString &pFaProfileXML, CString &pFaAliasesXML);
private:
	CString faGroupsXML;
	CString faProfilesXML;
	CString faAliasesXML;

};

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once

#include "resource.h"
#include "Order.h"

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

class CTws;

class CDlgAlgoParams : public CDialog
{
public:

    CDlgAlgoParams(const CString& algoStrategy, ITagValueList* algoParams,
		CTws* pTws, CWnd* pParent=NULL);

	~CDlgAlgoParams();

public:

	const CString& getAlgoStrategy() const { return m_algoStrategy; }
	ITagValueList* getAlgoParams() { return m_algoParams; }

private:

// Dialog Data
	//{{AFX_DATA(CDlgAlgoParams)
	enum { IDD = IDD_ALGO_PARAMS };
	CListCtrl	m_lstAlgoParams;
	TagValue    m_tagValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAlgoParams)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:

	static void AddParam(CListCtrl&, const TagValue&);
	static void GetParam(TagValue&, const CListCtrl&, size_t index);

private:

	// Generated message map functions
	//{{AFX_MSG(CDlgAlgoParams)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAddParam();
	afx_msg void OnBtnRemoveParam();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	CString m_algoStrategy;

	CTws* m_pTws;
    CComQIPtr<ITagValueList> m_algoParams;
};

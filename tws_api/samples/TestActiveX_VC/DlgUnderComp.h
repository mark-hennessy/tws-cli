/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"

// CDlgUnderComp dialog

class CDlgUnderComp : public CDialog
{
	DECLARE_DYNAMIC(CDlgUnderComp)

public:
	explicit CDlgUnderComp(IUnderComp* underComp, CWnd* pParent = NULL);
	virtual ~CDlgUnderComp();

// Dialog Data
	enum { IDD = IDD_UNDER_COMP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:

	afx_msg void OnOk();
	afx_msg void OnReset();

private:

	void updateComUnderComp();

private:

	CComQIPtr<IUnderComp> m_underComp;

	long	m_conId;
	double	m_delta;
	double	m_price;
};

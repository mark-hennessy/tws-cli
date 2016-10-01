/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgGroups.cpp : implementation file
//

#include "stdafx.h"
#include "client2.h"
#include "DlgGroups.h"
#include "EClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// consts
const int N = 5;

/////////////////////////////////////////////////////////////////////////////
// CDlgGroups dialog

CDlgGroups::CDlgGroups(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGroups::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgGroups)
	m_id = 0;
	//}}AFX_DATA_INIT
}

BOOL CDlgGroups::OnInitDialog()
{
	CDialog::OnInitDialog();

	enableFields(false);
	m_groupMessages.ModifyStyle( 0, WM_HSCROLL, 0 );

	return TRUE;
}

void CDlgGroups::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGroups)

	// Primary Id
	DDX_Text(pDX, IDC_GROUPS_ID, m_id);
	DDX_Control(pDX, IDC_GROUPS_ID_COMBO, m_groupIdCombo);
	DDX_Control(pDX, IDC_GROUPS_MESSAGES, m_groupMessages);
	DDX_Control(pDX, IDC_GROUPS_CONTRACT_INFO, m_contractInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGroups, CDialog)
	//{{AFX_MSG_MAP(CDlgGroups)
	ON_BN_CLICKED(IDC_GROUPS_QUERY_DISPLAY_GROUPS, OnQueryDisplayGroups)
	ON_BN_CLICKED(IDC_GROUPS_SUBSCRIBE_TO_GROUP_EVENTS, OnSubscribeToGroupEvents)
	ON_BN_CLICKED(IDC_GROUPS_UNSUBSCRIBE_FROM_GROUP_EVENTS, OnUnsubscribeFromGroupEvents)
	ON_BN_CLICKED(IDC_GROUPS_UPDATE_DISPLAY_GROUP, OnUpdateDisplayGroup)
	ON_BN_CLICKED(ID_GROUPS_RESET, &CDlgGroups::OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgGroups::init(EClient* client)
{
	m_pClient = client;
}

/////////////////////////////////////////////////////////////////////////////
// Public Methods
/////////////////////////////////////////////////////////////////////////////
void CDlgGroups::displayGroupList(int reqId, IBString& groups)
{
	CString str;

	if (!groups.IsEmpty()){
		m_groupIdCombo.ResetContent();
		enableFields(true);

		// parse groups
		IBString group;
		int index = 0;
		while (AfxExtractSubString( group, groups, index, _T('|'))){
			m_groupIdCombo.AddString( group);
			index++;
		}
		m_groupIdCombo.SetCurSel( 0);

		str.Format("Display groups: reqId=%i groups=%s", reqId, groups);
	}
	else {
		str.Format("Display groups: reqId=%i groups=<empty>", reqId);
	}

	int i = m_groupMessages.AddString( str);
	m_groupMessages.SetTopIndex( i);
}

void CDlgGroups::displayGroupUpdated(int reqId, IBString& contractInfo)
{
	CString str;
	str.Format("Display group updated: reqId=%i contractInfo=%s", m_id, contractInfo);
	int i = m_groupMessages.AddString( str);
	m_groupMessages.SetTopIndex( i);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgGroups message handlers
void CDlgGroups::OnQueryDisplayGroups()
{
	enableFields(false);
	m_groupIdCombo.ResetContent();
	UpdateData(true);

	CString str;
	str.Format("Querying display groups (reqId=%i) ...", m_id);
	int i = m_groupMessages.AddString( str);
	m_groupMessages.SetTopIndex( i);

	m_pClient->queryDisplayGroups( m_id);
}


void CDlgGroups::OnSubscribeToGroupEvents()
{
	UpdateData(true);
	int index = m_groupIdCombo.GetCurSel();
	CString strGroupId;
	m_groupIdCombo.GetLBText( index, strGroupId);

	int groupId = atoi( strGroupId);

	CString str;
	str.Format("Subscribing to group events (reqId=%i groupId=%i) ...", m_id, groupId);
	int i = m_groupMessages.AddString( str);
	m_groupMessages.SetTopIndex( i);

	m_pClient->subscribeToGroupEvents( m_id, groupId);
}

void CDlgGroups::OnUnsubscribeFromGroupEvents()
{
	UpdateData(true);
	CString str;
	str.Format("Unsubscribing from group events (reqId=%i) ...", m_id);
	int i = m_groupMessages.AddString( str);
	m_groupMessages.SetTopIndex( i);
	m_pClient->unsubscribeFromGroupEvents( m_id);
}

void CDlgGroups::OnUpdateDisplayGroup()
{
	UpdateData(true);

	CString contractInfo;
	m_contractInfo.GetWindowTextA(contractInfo);
	if (!contractInfo.IsEmpty()){
		CString str;
		str.Format("Updating display group (reqId=%i contractInfo=%s) ...", m_id, contractInfo);
		int i = m_groupMessages.AddString( str);
		m_groupMessages.SetTopIndex( i);

		m_pClient->updateDisplayGroup( m_id, contractInfo);
	}
}

void CDlgGroups::OnReset()
{
	m_groupMessages.ResetContent();
	enableFields(false);
	m_groupIdCombo.ResetContent();
	m_contractInfo.SetWindowTextA("");
}

void CDlgGroups::enableFields(bool enable)
{
	static const unsigned fields[] = {
		IDC_GROUPS_ID_COMBO,
		IDC_GROUPS_SUBSCRIBE_TO_GROUP_EVENTS,
		IDC_GROUPS_UNSUBSCRIBE_FROM_GROUP_EVENTS,
		IDC_GROUPS_UPDATE_DISPLAY_GROUP,
		IDC_GROUPS_CONTRACT_INFO,
	};

	static const size_t fieldsNum =
		sizeof(fields) / sizeof(fields[0]);

	for (size_t i = 0; i < fieldsNum; ++i) {
		GetDlgItem(fields[i])->EnableWindow(enable);
	}
}

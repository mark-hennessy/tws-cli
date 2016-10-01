/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgExtOrd.cpp : implementation file
//

#include "stdafx.h"
#include "DlgScanner.h"
#include "ScannerSubscription.h"
#include "EClient.h"
#include "DlgSmartComboRoutingParams.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgScanner dialog


CDlgScanner::CDlgScanner(ScannerSubscription* subscription, EClient* client, TagValueListSPtr& options, CWnd* pParent)
	: CDialog(CDlgScanner::IDD, pParent)
	, m_client(client)
	, m_subscription(subscription)
	, m_scannerSubscriptionOptions(options)

{
	//{{AFX_DATA_INIT(CDlgScanner)
	m_id = 0;
	//}}AFX_DATA_INIT

#define GET_PROP(Prop) \
	m_##Prop = subscription->Prop;

	GET_PROP(instrument);
	GET_PROP(locationCode);
	GET_PROP(scanCode);
	GET_PROP(numberOfRows);

	GET_PROP(abovePrice);
	GET_PROP(belowPrice);
	GET_PROP(aboveVolume);
	GET_PROP(averageOptionVolumeAbove);
	GET_PROP(marketCapAbove);
	GET_PROP(marketCapBelow);
	GET_PROP(moodyRatingAbove);
	GET_PROP(moodyRatingBelow);
	GET_PROP(spRatingAbove);
	GET_PROP(spRatingBelow);
	GET_PROP(maturityDateAbove);
	GET_PROP(maturityDateBelow);
	GET_PROP(couponRateAbove);
	GET_PROP(couponRateBelow);
	GET_PROP(excludeConvertible);
	GET_PROP(scannerSettingPairs);
	GET_PROP(stockTypeFilter);

#undef GET_PROP
}

extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, int &value);
extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, double &value);

void CDlgScanner::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgScanner)
	DDX_Text(pDX, IDC_ID, m_id );
	DDX_Text(pDX, IDC_NUMBER_OF_ROWS, m_numberOfRows );
	DDX_Text(pDX, IDC_INSTRUMENT, m_instrument );
	DDX_Text(pDX, IDC_LOCATION_CODE, m_locationCode );
	DDX_Text(pDX, IDC_SCAN_CODE, m_scanCode);
	DDX_Text(pDX, IDC_MOODY_RATING_ABOVE, m_moodyRatingAbove );
	DDX_Text(pDX, IDC_MOODY_RATING_BELOW, m_moodyRatingBelow );
	DDX_Text(pDX, IDC_S_AND_P_RATING_ABOVE, m_spRatingAbove );
	DDX_Text(pDX, IDC_S_AND_P_RATING_BELOW, m_spRatingBelow );
	DDX_Text(pDX, IDC_MATURITY_DATE_ABOVE, m_maturityDateAbove );
	DDX_Text(pDX, IDC_MATURITY_DATE_BELOW, m_maturityDateBelow );
	DDX_Text(pDX, IDC_EXCLUDE_CONVERTIBLE, m_excludeConvertible );
	DDX_TextMax(pDX, IDC_ABOVE_PRICE, m_abovePrice);
	DDX_TextMax(pDX, IDC_BELOW_PRICE, m_belowPrice);
	DDX_TextMax(pDX, IDC_ABOVE_VOLUME, m_aboveVolume);
	DDX_TextMax(pDX, IDC_MARKET_CAP_ABOVE, m_marketCapAbove);
	DDX_TextMax(pDX, IDC_MARKET_CAP_BELOW, m_marketCapBelow);
	DDX_TextMax(pDX, IDC_COUPON_RATE_ABOVE, m_couponRateAbove);
	DDX_TextMax(pDX, IDC_COUPON_RATE_BELOW, m_couponRateBelow);
	DDX_TextMax(pDX, IDC_EXCLUDE_CONVERTIBLE, m_excludeConvertible);
	DDX_TextMax(pDX, IDC_AVERAGE_OPTION_VOLUME_ABOVE, m_averageOptionVolumeAbove);
	DDX_Text(pDX, IDC_SCANNER_SETTING_PAIRS, m_scannerSettingPairs);
	DDX_Text(pDX, IDC_STOCK_TYPE_FILTER, m_stockTypeFilter);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate) {
		if (m_subscription)
			updateScanSubscription();
	}

}

BEGIN_MESSAGE_MAP(CDlgScanner, CDialog)
	//{{AFX_MSG_MAP(CDlgScanner)
	ON_BN_CLICKED(IDC_BTN_REQUEST_PARAMETERS, OnRequestParameters)
	ON_BN_CLICKED(IDC_BTN_SUBSCRIBE, OnSubscribe)
	ON_BN_CLICKED(IDC_BTN_CANCEL_SUBSCRIPTION, OnCancelSubscription)
	ON_BN_CLICKED(IDC_BTN_OPTIONS, OnScannerSubscriptionOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgScanner::OnRequestParameters() {
	OnOK();
	m_client->reqScannerParameters();
}

void CDlgScanner::OnSubscribe() {
	OnOK();
	m_client->reqScannerSubscription(m_id, *m_subscription, m_scannerSubscriptionOptions);
}

void CDlgScanner::OnCancelSubscription() {
	OnOK();
	m_client->cancelScannerSubscription(m_id);
}

void CDlgScanner::OnScannerSubscriptionOptions()
{
	CDlgSmartComboRoutingParams dlg(m_scannerSubscriptionOptions, "Scanner Subscription Options");
	if ( dlg.DoModal() == IDOK ) {
		// do nothing - params passed by ref
		// and is being updated inside dialog
	}
}

void CDlgScanner::updateScanSubscription()
{
	ASSERT(m_subscription);

#define PUT_PROP(Prop) \
	m_subscription->Prop = m_##Prop;

	PUT_PROP(instrument);
	PUT_PROP(locationCode);
	PUT_PROP(scanCode);
	PUT_PROP(numberOfRows);

	PUT_PROP(abovePrice);
	PUT_PROP(belowPrice);
	PUT_PROP(aboveVolume);
	PUT_PROP(averageOptionVolumeAbove);
	PUT_PROP(marketCapAbove);
	PUT_PROP(marketCapBelow);
	PUT_PROP(moodyRatingAbove);
	PUT_PROP(moodyRatingBelow);
	PUT_PROP(spRatingAbove);
	PUT_PROP(spRatingBelow);
	PUT_PROP(maturityDateAbove);
	PUT_PROP(maturityDateBelow);
	PUT_PROP(couponRateAbove);
	PUT_PROP(couponRateBelow);
	PUT_PROP(excludeConvertible);
	PUT_PROP(scannerSettingPairs);
	PUT_PROP(stockTypeFilter);

#undef PUT_PROP

}

/////////////////////////////////////////////////////////////////////////////
// CDlgScanner message handlers

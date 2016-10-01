/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// DlgExtOrd.cpp : implementation file
//

#include "stdafx.h"
#include "client3.h"
#include "client3Dlg.h"
#include "DlgScanner.h"
#include "ScannerSubscription.h"
#include "../ActiveX/ComPropAccessor.h"
#include "DlgSmartComboRoutingParams.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgScanner dialog


CDlgScanner::CDlgScanner(IScannerSubscription* subscription,
						 ITagValueList* comScannerSubscriptionOptions,
						 CTws* pTws, CWnd* pParent)
	: CDialog(CDlgScanner::IDD, pParent)
	, m_pTws(pTws)
	, m_subscription(subscription)
	, m_comScannerSubscriptionOptions(comScannerSubscriptionOptions)
{
	//{{AFX_DATA_INIT(CDlgScanner)
    m_id = 0;
	//}}AFX_DATA_INIT

	IScannerSubscription* comScanSubscription = m_subscription;

	typedef CComPropAccessor<IScannerSubscription> Props;

#define GET_PROP(Prop) \
	Props::Get(m_##Prop, comScanSubscription, &IScannerSubscription::get_##Prop);

	GET_PROP(instrument);
	GET_PROP(locations);
	GET_PROP(scanCode);
	GET_PROP(numberOfRows);

	GET_PROP(priceAbove);
	GET_PROP(priceBelow);
	GET_PROP(volumeAbove);
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

void CDlgScanner::OnRequestParameters() {
	OnOK();
	m_pTws->reqScannerParameters();
}

void CDlgScanner::OnSubscribe() {
	OnOK();
	m_pTws->reqScannerSubscriptionEx(m_id, m_subscription, m_comScannerSubscriptionOptions);
}

void CDlgScanner::OnCancelSubscription() {
	OnOK();
	m_pTws->cancelScannerSubscription( m_id);
}

extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, int &value);
extern void DDX_TextMax(CDataExchange* pDX, int ctrlID, double &value);

void CDlgScanner::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgScanner)
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_INSTRUMENT, m_instrument);
	DDX_Text(pDX, IDC_LOCATION_CODE, m_locations);
	DDX_Text(pDX, IDC_SCAN_CODE, m_scanCode);
	DDX_Text(pDX, IDC_NUMBER_OF_ROWS, m_numberOfRows);

	DDX_TextMax(pDX, IDC_PRICE_ABOVE, m_priceAbove);
	DDX_TextMax(pDX, IDC_PRICE_BELOW, m_priceBelow);
	DDX_TextMax(pDX, IDC_VOLUME_ABOVE, m_volumeAbove);
	DDX_TextMax(pDX, IDC_AVERAGE_OPTION_VOLUME_ABOVE, m_averageOptionVolumeAbove);
	DDX_TextMax(pDX, IDC_MARKET_CAP_ABOVE, m_marketCapAbove);
	DDX_TextMax(pDX, IDC_MARKET_CAP_BELOW, m_marketCapBelow);
	DDX_Text(pDX, IDC_MOODY_RATING_ABOVE, m_moodyRatingAbove);
	DDX_Text(pDX, IDC_MOODY_RATING_BELOW, m_moodyRatingBelow);
	DDX_Text(pDX, IDC_S_AND_P_RATING_ABOVE, m_spRatingAbove);
	DDX_Text(pDX, IDC_S_AND_P_RATING_BELOW, m_spRatingBelow);
	DDX_Text(pDX, IDC_MATURITY_DATE_ABOVE, m_maturityDateAbove);
	DDX_Text(pDX, IDC_MATURITY_DATE_BELOW, m_maturityDateBelow);
	DDX_TextMax(pDX, IDC_COUPON_RATE_ABOVE, m_couponRateAbove);
	DDX_TextMax(pDX, IDC_COUPON_RATE_BELOW, m_couponRateBelow);
	DDX_TextMax(pDX, IDC_EXCLUDE_CONVERTIBLE, m_excludeConvertible);
	DDX_Text(pDX, IDC_SCANNER_SETTING_PAIRS, m_scannerSettingPairs);
	DDX_Text(pDX, IDC_STOCK_TYPE_FILTER, m_stockTypeFilter);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate) {
		if (m_subscription)
			updateComScanSubscription();
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

void CDlgScanner::OnScannerSubscriptionOptions()
{
	CDlgSmartComboRoutingParams dlgSmartComboRoutingParams(m_comScannerSubscriptionOptions, m_pTws, "Scanner Subscription Options");
	if ( dlgSmartComboRoutingParams.DoModal() == IDOK ) {
		m_comScannerSubscriptionOptions = dlgSmartComboRoutingParams.getSmartComboRoutingParams();
	}
}


void CDlgScanner::updateComScanSubscription()
{
	ASSERT(m_subscription);

	IScannerSubscription* comScanSubscription = m_subscription;

	typedef CComPropAccessor<IScannerSubscription> Props;

#define PUT_PROP(Prop) \
	Props::Put(comScanSubscription, m_##Prop, &IScannerSubscription::put_##Prop);

	PUT_PROP(instrument);
	PUT_PROP(locations);
	PUT_PROP(scanCode);
	PUT_PROP(numberOfRows);

	PUT_PROP(priceAbove);
	PUT_PROP(priceBelow);
	PUT_PROP(volumeAbove);
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
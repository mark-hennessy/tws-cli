/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "TwsHelpers.h"

#include "afxctl.h"
#include "../ActiveX/Tws_i.h"
#include "../ActiveX/ComPropAccessor.h"

#include "Order.h"

void CTwsHelpers::CopyTwsTagValue2TagValue(
	TagValue& tagValue, /* const */ ITagValue* comTagValue)
{
	ASSERT (comTagValue);

	typedef CComPropAccessor<ITagValue> Props;

#define GET_PROP(Prop) \
	Props::Get(tagValue.Prop, comTagValue, &ITagValue::get_##Prop);

	GET_PROP(tag);
	GET_PROP(value);

#undef GET_PROP
}

void CTwsHelpers::CopyTagValue2TwsTagValue(
	ITagValue* comTagValue, const TagValue& tagValue)
{
	ASSERT (comTagValue);

	typedef CComPropAccessor<ITagValue> Props;

#define PUT_PROP(Prop) \
	Props::Put(comTagValue, tagValue.Prop, &ITagValue::put_##Prop);

	PUT_PROP(tag);
	PUT_PROP(value);

#undef PUT_PROP
}
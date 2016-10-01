/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once

#include "../ActiveX/Tws_i.h"

struct TagValue;

class CTwsHelpers
{
public:

	static void CopyTwsTagValue2TagValue(TagValue&, /* const */ ITagValue*);
	static void CopyTagValue2TwsTagValue(ITagValue*, const TagValue&);
};

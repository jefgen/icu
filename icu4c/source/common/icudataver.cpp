// © 2016 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html
/*
******************************************************************************
*
*   Copyright (C) 2009-2011, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
******************************************************************************
*/

#include "unicode/utypes.h"
#include "unicode/icudataver.h"
#include "unicode/ures.h"
#include "uresimp.h" /* for ures_getVersionByKey */

U_CAPI void U_EXPORT2 u_getDataVersion(UVersionInfo dataVersionFillin, UErrorCode *status) {
    icu::StackUResourceBundle icudatares;
    
    if (U_FAILURE(*status)) {
        return;
    }
    
    if (dataVersionFillin != NULL) {
        ures_openDirectFillIn(icudatares.getAlias(), NULL, U_ICU_VERSION_BUNDLE , status);
        ures_getVersionByKey(icudatares.getAlias(), U_ICU_DATA_KEY, dataVersionFillin, status);
    }
}

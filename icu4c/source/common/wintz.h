// © 2016 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html
/*
********************************************************************************
*   Copyright (C) 2005-2011, International Business Machines
*   Corporation and others.  All Rights Reserved.
********************************************************************************
*
* File WINTZ.H
*
********************************************************************************
*/

#ifndef __WINTZ
#define __WINTZ

#include "unicode/utypes.h"

#if U_PLATFORM_USES_ONLY_WIN32_API

#ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
#endif
#   define VC_EXTRALEAN
#   define NOUSER
#   define NOSERVICE
#   define NOIME
#   define NOMCX
#include <windows.h>

/**
 * \file 
 * \brief C API: Utilities for dealing w/ Windows time zones.
 */

U_CDECL_BEGIN
/* Forward declarations for Windows types... */
typedef struct _TIME_ZONE_INFORMATION TIME_ZONE_INFORMATION;

// The following typedefs are used for mocking the Win32 APIs for testing.
typedef DWORD WINAPI GetDynamicTimeZoneInformation_Fn(PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation);
typedef GEOID WINAPI GetUserGeoID_Fn(GEOCLASS GeoClass);
typedef int WINAPI GetGeoInfoW_Fn(GEOID Location, GEOTYPE GeoType, LPWSTR lpGeoData, int cchData, LANGID LangId);
U_CDECL_END

// This is main Windows time zone detection function.
U_CAPI const char* U_EXPORT2
uprv_detectWindowsTimeZone();

// The following functions are only exported for testing.
U_CAPI void U_EXPORT2
uprv_setWindowsTimeZoneTestFunctions(GetDynamicTimeZoneInformation_Fn *a, GetUserGeoID_Fn *b, GetGeoInfoW_Fn *c);

U_CAPI void U_EXPORT2
uprv_clearWindowsTimeZoneTestFunctions();

#endif /* U_PLATFORM_USES_ONLY_WIN32_API  */

#endif /* __WINTZ */

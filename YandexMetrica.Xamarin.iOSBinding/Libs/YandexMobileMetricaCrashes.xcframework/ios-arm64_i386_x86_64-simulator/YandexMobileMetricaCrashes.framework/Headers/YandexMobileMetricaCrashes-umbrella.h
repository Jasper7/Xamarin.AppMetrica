/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#ifdef __OBJC__
    #import <UIKit/UIKit.h>
#else
    #ifndef FOUNDATION_EXPORT
        #if defined(__cplusplus)
            #define FOUNDATION_EXPORT extern "C"
        #else
            #define FOUNDATION_EXPORT extern
        #endif
    #endif
#endif

FOUNDATION_EXPORT double YandexMobileMetricaCrashesVersionNumber;
FOUNDATION_EXPORT const unsigned char YandexMobileMetricaCrashesVersionString[];

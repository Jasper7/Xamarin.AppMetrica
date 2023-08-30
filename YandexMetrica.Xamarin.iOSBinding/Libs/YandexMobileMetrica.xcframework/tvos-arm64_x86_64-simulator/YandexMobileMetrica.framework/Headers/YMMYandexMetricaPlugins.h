/*
 * Version for iOS
 * © 2021 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

@class YMMPluginErrorDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 * `YMMYandexMetricaPlugins` is an extension of `YMMYandexMetrica`.
 * Instance of object that implements `YMMYandexMetricaPlugins` can be obtained via
 * `YMMYandexMetrica#getPluginExtension` method call.
 * Only one `YMMYandexMetricaPlugins` instance is created.
 * You can either query it each time you need it, or save the reference by yourself.
 * NOTE: to use this extension you must activate AppMetrica first
 * via `[YMMYandexMetrica activateWithConfiguration:]`.
 *
 * @note See `YMMYandexMetrica#getPluginExtension`.
 */
@protocol YMMYandexMetricaPlugins <NSObject>

/**
 Sends unhandled error.
 @note See `YMMPluginErrorDetails` for more information.
 
 @param errorDetails Object describing the error.
 @param onFailure Block to be executed if an error occurs while reporting, the error is passed as block argument.
 */
- (void)reportUnhandledException:(YMMPluginErrorDetails *)errorDetails
                       onFailure:(nullable void (^)(NSError *error))onFailure
NS_SWIFT_NAME(reportUnhandledException(exception:onFailure:));

/**
 Sends custom error. Backtrace will be used for grouping. If you want to customize grouping use `reportError:details:onFailure`.
 @note See `YMMPluginErrorDetails` for more information.

 @param errorDetails Object describing the error.
                     @note For the error to be sent, errorDetails must contain non empty stacktrace.
                     Otherwise it will be ignored. If you can't provide stacktrace,
                     use `[YMMYandexMetricaPlugins reportErrorWithIdentifier:message:details:onFailure:]`
                     with filled identifier.
 @param message Short description or name of the error.
 @param onFailure Block to be executed if an error occurs while reporting, the error is passed as block argument.
 */
- (void)reportError:(YMMPluginErrorDetails *)errorDetails
            message:(nullable NSString *)message
          onFailure:(nullable void (^)(NSError *error))onFailure
NS_SWIFT_NAME(reportError(error:message:onFailure:));

/**
 Sends custom error with message. Identifier will be used for grouping errors.
 If you want to use backtrace for grouping instead use `reportError:message:onFailure`.
 @note See `YMMPluginErrorDetails` for more information.

 @param identifier Identifier used for grouping.
                   The maximum length is 300 characters.
                   If the value exceeds the limit, AppMetrica truncates it.
 @param message Short description or name of the error.
                The maximum length is 1000 characters.
                If the value exceeds the limit, AppMetrica truncates it.
 @param errorDetails Object describing the error.
 @param onFailure Block to be executed if an error occurs while reporting, the error is passed as block argument.
 */
- (void)reportErrorWithIdentifier:(NSString *)identifier
                          message:(nullable NSString *)message
                          details:(nullable YMMPluginErrorDetails *)errorDetails
                        onFailure:(nullable void (^)(NSError *error))onFailure
NS_SWIFT_NAME(reportError(identifier:message:error:onFailure:));

/**
 * Notifies AppMetrica that plugin initialization has finished.
 * Plugins should call this method so that AppMetrica correctly handles sessions
 * considering specific Flutter (or another plugin) iOS application lifecycle.
 * It should be called right after activation if the application is in foreground state.
 */
- (void)handlePluginInitFinished NS_SWIFT_NAME(handlePluginInitFinished());

@end

NS_ASSUME_NONNULL_END

/*
 * Version for iOS
 * © 2021 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

@class YMMStackTraceElement;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kYMMPlatformNative;
extern NSString * const kYMMPlatformFlutter;
extern NSString * const kYMMPlatformUnity;
extern NSString * const kYMMPlatformReactNative;
extern NSString * const kYMMPlatformXamarin;
extern NSString * const kYMMPlatformCordova;

@interface YMMPluginErrorDetails : NSObject

/**
 Name of the class/interface/symbol (depending on the plugin you are using) of the error.
 The maximum length is 100 characters.
 If the value exceeds the limit, AppMetrica truncates it.
 */
@property (nonatomic, copy, nullable) NSString *exceptionClass;
/**
 Error message briefly describing the error.
 The maximum length is 1000 characters.
 If the value exceeds the limit, AppMetrica truncates it.
 */
@property (nonatomic, copy, nullable) NSString *message;
/**
 Error backtrace.
 The maximum number of stack frames in a backtrace is 200.
 If the value exceeds the limit, AppMetrica truncates it.
 @note See `YMMStackTraceElement` for more information.
 */
@property (nonatomic, copy, nullable) NSArray<YMMStackTraceElement *> *backtrace;
/**
 Name of the plugin in which the error occurred.
 Use constants defined in `YMMPluginErrorDetails` for popular plugins or a custom string for a plugin that does not have a corresponding constant.
 The maximum length is 100 characters.
 If the value exceeds the limit, AppMetrica truncates it.
 */
@property (nonatomic, copy, nullable) NSString *platform;
/**
 Virtual machine version.
 Use this property to specify the version of plugin you are using (e. g. Unity version, Flutter version, etc.).
 The maximum length is 100 characters.
 If the value exceeds the limit, AppMetrica truncates it.
*
 */
@property (nonatomic, copy, nullable) NSString *virtualMachineVersion;
/**
 Plugin environment. Arbitrary dictionary containing any additional information about the plugin.
 The maximum number of key-value parameters is 50. The maximum length is 100 characters for the key and 2000 for the value.
 If the value exceeds the limit, AppMetrica truncates it.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *pluginEnvironment;

- (instancetype)init;
- (instancetype)initWithExceptionClass:(nullable NSString *)exceptionClass
                               message:(nullable NSString *)message
                             backtrace:(nullable NSArray<YMMStackTraceElement *> *)backtrace
                              platform:(nullable NSString *)platform
                 virtualMachineVersion:(nullable NSString *)virtualMachineVersion
                     pluginEnvironment:(nullable NSDictionary<NSString *, NSString *> *)pluginEnvironment
NS_SWIFT_NAME(init(exceptionClass:message:backtrace:platform:virtualMachineVersion:pluginEnvironment:));


@end

NS_ASSUME_NONNULL_END

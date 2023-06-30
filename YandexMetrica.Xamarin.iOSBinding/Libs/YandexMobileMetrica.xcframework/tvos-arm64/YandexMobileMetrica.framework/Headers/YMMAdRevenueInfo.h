
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMMAdType) {
    YMMAdTypeUnknown = 0,
    YMMAdTypeNative = 1,
    YMMAdTypeBanner = 2,
    YMMAdTypeRewarded = 3,
    YMMAdTypeInterstitial = 4,
    YMMAdTypeMrec = 5,
    YMMAdTypeOther = 6,
};

/** The class to store Ad Revenue data.

 The Ad Revenue object should be passed to the AppMetrica by using the
 `reportRevenue` method of the `YMMYandexMetrica` or `YMMYandexMetricaReporting` classes.

 @note This interface has the mutable version `YMMMutableAdRevenueInfo`.
 */
@interface YMMAdRevenueInfo : NSObject <NSCopying, NSMutableCopying>

/**
 * Amount of money received via ad revenue.
 * It cannot be negative.
 */
@property (nonatomic, strong, readonly) NSDecimalNumber *adRevenue;
/**
 * Currency in which money from `adRevenue` is represented.
 * Must be in ISO-4217 format.
 */
@property (nonatomic, copy, readonly) NSString *currency;
/**
 * Ad type. See possible values in `YMMAdType`.
 */
@property (nonatomic, assign, readonly) YMMAdType adType;
/**
 * Ad network.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSString *adNetwork;
/**
 * Id of ad unit.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSString *adUnitID;
/**
 * Name of ad unit.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSString *adUnitName;
/**
 * Id of ad placement.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSString *adPlacementID;
/**
 * Name of ad placement.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSString *adPlacementName;
/**
 * Precision.
 * Example: "publisher_defined", "estimated".
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSString *precision;
/**
 * Arbitrary payload: additional info represented as key-value pairs.
 * Maximum size is 30 KB. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable, readonly) NSDictionary<NSString *, NSString *> *payload;

/**
 * Use `initWithAdRevenue:currency:` method instead.
 */
- (instancetype)init NS_UNAVAILABLE;
/**
 * Initializes Ad Revenue object with the specified adRevenue and currency.
 * @param adRevenue Amount of money received via ad revenue. See `adRevenue` property for more details.
 * @param currency Currency. See `currency` property for more details.
 * @return `AdRevenue` object.
 */
- (instancetype)initWithAdRevenue:(NSDecimalNumber *)adRevenue currency:(NSString *)currency;

@end

/**
 * Mutable version of the `YMMAdRevenueInfo` class.
*/
@interface YMMMutableAdRevenueInfo : YMMAdRevenueInfo

/**
 * Ad type. See possible values in `YMMAdType`.
 */
@property (nonatomic, assign) YMMAdType adType;
/**
 * Ad network.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSString *adNetwork;
/**
 * Id of ad unit.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSString *adUnitID;
/**
 * Name of ad unit.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSString *adUnitName;
/**
 * Id of ad placement.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSString *adPlacementID;
/**
 * Name of ad placement.
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSString *adPlacementName;
/**
 * Precision.
 * Example: "publisher_defined", "estimated".
 * Maximum length is 100 symbols. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSString *precision;
/**
 * Arbitrary payload: additional info represented as key-value pairs.
 * Maximum size is 30 KB. If the value exceeds this limit it will be truncated by AppMetrica.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *payload;

@end

NS_ASSUME_NONNULL_END

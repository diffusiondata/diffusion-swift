//  Diffusion Client Library for iOS and OS X / macOS
//
//  Copyright (c) 2022 - 2026 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A block that calculates the interval, in milliseconds, to wait before making
 a given retry attempt.

 @param interval the base interval, in milliseconds, that the retry strategy
 was created with

 @param attempt the attempt number for which the interval is being
 calculated. The first attempt is 1.

 @return the interval, in milliseconds, to wait before making this attempt

 @since 6.13
 */
typedef NSUInteger (^PTDiffusionRetryBackoffCalculator)(NSUInteger interval, NSUInteger attempt);

/**
 @ingroup PublicAPI_Session

 @brief Defines a retry strategy.

 A retry strategy will be applied when an initial to attempt to open a session
 fails with a SessionEstablishmentTransientException, and can also be used to
 govern recovery attempts made by a PTDiffusionRecoverableUpdateStream.

 The strategy is defined in terms of the number of milliseconds between retries and
 the maximum number of retries to attempt.

 By default, every attempt waits the same, fixed interval. Supplying a
 `PTDiffusionRetryBackoffCalculator` allows this to be varied, for example to
 implement an exponential backoff, by calculating the interval for each
 attempt individually.

 @since 6.9
 */
@interface PTDiffusionRetryStrategy : NSObject <NSCopying>

/**
 The retry strategy that indicates that no retry is to be attempted.

 @return The retry strategy indicating that no retry is to be attempted.
 */
+(instancetype)NO_RETRY;

/**
 Creates a new retry strategy object.

 @param interval    the number of milliseconds before the first retry and between
                    subsequent retries
 @param attempts    the number of retry attempts

 @return            the new retry strategy

 @since 6.9
 */
-(instancetype)initWithInterval:(const NSUInteger) interval andAttempts:(const NSInteger) attempts;

/**
 Creates a new retry strategy object that varies the interval between
 retries according to the given backoff calculator.

 @param interval    the base interval, in milliseconds, passed to `backoff`
                    for it to calculate the actual interval to apply

 @param attempts    the number of retry attempts

 @param backoff     a block that calculates the interval, in milliseconds, to
                    wait before making a given attempt. If `nil`, every
                    attempt waits the fixed `interval`, equivalent to using
                    `initWithInterval:andAttempts:`.

 @return            the new retry strategy

 @since 6.13
 */
-(instancetype)initWithInterval:(NSUInteger)interval
                    andAttempts:(NSInteger)attempts
                        backoff:(nullable PTDiffusionRetryBackoffCalculator)backoff;

/**
 Calculates the interval, in milliseconds, to wait before making the given
 retry attempt.

 If this strategy was created without a `PTDiffusionRetryBackoffCalculator`,
 this always returns `interval`, regardless of the attempt number.

 @param attempt the attempt number for which the interval is being
 calculated. The first attempt is 1.

 @return the interval, in milliseconds, to wait before making this attempt

 @since 6.13
 */
-(NSUInteger)intervalForAttempt:(NSUInteger)attempt;


/**
 Creates a new retry strategy that will retry indefinitely at the
 specified interval.

 @param interval    the number of milliseconds before the first retry and between
                    subsequent retries

 @return            the new retry strategy

 @since 6.9
 */
-(instancetype)initWithInterval:(const NSUInteger) interval;


/**
 No retry constructor

 @return            the new retry strategy

 @since 6.9
 */
-(instancetype)init;


/**
 The number of milliseconds between retries

 @since 6.9
 */
@property(nonatomic, readonly) NSUInteger interval;


/**
 The maximum number of retries to attempt

 @since 6.9
 */
@property(nonatomic, readonly) NSInteger attempts;


@end

NS_ASSUME_NONNULL_END

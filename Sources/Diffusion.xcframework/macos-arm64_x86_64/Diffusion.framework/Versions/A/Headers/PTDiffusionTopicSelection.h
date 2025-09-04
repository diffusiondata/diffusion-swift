//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2025 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionTopicType.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, PTDiffusionTopicSelectionType) {
    /**
      Represents selection of topics (i.e. subscription).

     @since 6.12
     */
    PTDiffusionTopicSelectionType_Select = 0,

    /**
     Represents deselection of topics (i.e. unsubscription).

     @since 6.12
     */
    PTDiffusionTopicSelectionType_Deselect = 1
};



/**
 @brief A topic selection that represents either a subscription (selection) or an
 unsubscription (deselection).

 @since 6.12
 */
@interface PTDiffusionTopicSelection : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The selection type

 @since 6.12
 */
@property(nonatomic, readonly) PTDiffusionTopicSelectionType type;


/**
 The the topic selector for the selection or deselection.

 @since 6.12
 */
@property(nonatomic, readonly) NSString* selectorExpression;


@end

NS_ASSUME_NONNULL_END

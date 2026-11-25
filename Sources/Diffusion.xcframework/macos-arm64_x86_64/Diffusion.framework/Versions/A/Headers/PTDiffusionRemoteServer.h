//  Diffusion Client Library for iOS and OS X / macOS
//
//  Copyright (c) 2020 - 2026 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionEnumeration.h>

@class PTDiffusionRemoteServerConnectionOption;

NS_ASSUME_NONNULL_BEGIN


/**
 @brief The type of a remote server.

 @since 6.5
 */
typedef NS_ENUM(SInt8, PTDiffusionRemoteServerType) {
    /**
     A secondary server that initiates a connection to a primary server.
     */
    PTDiffusionRemoteServerType_SecondaryInitiator = 1,

    /**
     A primary server that initiates a connection to a secondary server.
     */
    PTDiffusionRemoteServerType_PrimaryInitiator = 2,

    /**
     A secondary server that accepts a connection from a primary server.
     */
    PTDiffusionRemoteServerType_SecondaryAcceptor = 3,
};

/**
 @ingroup PublicAPI_RemoteServers

 @brief Base Interface for a remote server.

 This is used by the Remote Servers feature.

 @since 6.5
 */
@interface PTDiffusionRemoteServer : NSObject


/**
 The remote server name

 @since 6.5
 */
@property (nonatomic, readonly) NSString *name;


/**
 The URL for connection to remote server.

 @since 6.5
 */
@property (nonatomic, readonly) NSString * _Nullable url;


/**
 The principal used for the remote server connection

 @since 6.5
 */
@property (nonatomic, readonly) NSString *principal;


/**
 The remote server connection options

 @since 6.5
 */
@property (nonatomic, readonly) NSDictionary<PTDiffusionRemoteServerConnectionOption *, NSString *> *connectionOptions;


/**
 The missing topic notification filter expression or null if
 one has not been specified.

 @since 6.7
 */
@property (nonatomic, readonly) NSString *missingTopicNotificationFilter;


/**
 The remote server type.

 A {@link PTDiffusionRemoteServer} can be cast to the corresponding sub-type to
 access all methods, as follows:

 <table border=1>
    <tr>
        <th style="text-align:center;">Type</th>
        <th style="text-align:center;">Type class</th>
    </tr>
    <tr>
        <td style="text-align:center;"><code>PTDiffusionRemoteServerType_SecondaryInitiator</code> (Secondary Initiator)</td>
        <td style="text-align:center;">{@link PTDiffusionSecondaryInitiatorRemoteServer}</td>
    </tr>
    <tr>
        <td style="text-align:center;"><code>PTDiffusionRemoteServerType_PrimaryInitiator</code> (Primary Initiator)</td>
        <td style="text-align:center;">{@link PTDiffusionPrimaryInitiatorRemoteServer}</td>
    </tr>
    <tr>
        <td style="text-align:center;"><code>PTDiffusionRemoteServerType_SecondaryAcceptor</code> (Secondary Acceptor)</td>
        <td style="text-align:center;">{@link PTDiffusionSecondaryAcceptorRemoteServer}</td>
    </tr>
 </table>

 @since 6.10
 */
@property (nonatomic, readonly) PTDiffusionRemoteServerType type;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END

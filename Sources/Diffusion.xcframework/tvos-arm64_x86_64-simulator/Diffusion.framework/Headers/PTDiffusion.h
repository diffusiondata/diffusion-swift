//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2018 - 2023 DiffusionData Ltd., All Rights Reserved.
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
 @file PTDiffusion.h

 Collection of utility functions
 */

/**
 Escapes special characters in a string that is to be used within a topic
 property or a @ref md_session_filters "session filter".

 This is a convenience method which inserts an escape character `\` before any
 of the special characters `'`, `"` or `\`.

 @param string The string to be escaped.

 @return The string value with escape characters inserted as appropriate.

 @exception NSInvalidArgumentException If the given string is `nil`.

 @since 6.1
 */
NSString* PTDiffusionEscape(NSString * string);

/**
 Converts a string of the format required by the
 PTDiffusionSession#rolesPropertyKey into a set of strings.

 @param string Quoted roles, separated by whitespace or commas.

 @param roles If successful, upon return contains the set of roles.

 @param error If an error occurs, upon return contains an `NSError` object
 that describes the problem.

 @return An immutable set of roles.

 @since 6.2
 */
BOOL PTDiffusionRolesFromString(NSString * string, NSSet<NSString *> *_Nullable *_Nonnull roles, NSError ** error);

/**
 Converts a set of authorisation roles to the string format required by the
 PTDiffusionSession#rolesPropertyKey.

 @param roles The roles to format.

 @return A string representation of the supplied roles.

 @since 6.2
 */
NSString* PTDiffusionStringFromRoles(NSSet<NSString *> * roles);


NS_ASSUME_NONNULL_END

//
//  NSURL_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 1/3/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

/*! These are custom extensions to the NSURL class */

#import <Foundation/Foundation.h>


@interface NSURL(RFExtensions)

/*! Turns a string into an NSURL, with REFLEKTION_SERVER as the host if not in the original string
 @param string URL string, with or without a host
 @returns An NSURL with a host (either from the original string, or REFLEKTION_SERVER, as defined in RFCommon.h)
 */
+ (NSURL *) absoluteURLWithString:(NSString*)string;
@end
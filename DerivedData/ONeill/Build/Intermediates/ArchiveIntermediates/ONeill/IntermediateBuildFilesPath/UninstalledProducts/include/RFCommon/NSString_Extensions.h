//
//  NSString_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 1/4/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

/*! These are custom extensions to the NSString class */

#import <Foundation/Foundation.h>


@interface NSString(RFExtensions)
/*! Checks if the string starts with the prefix string 
 @param prefix The prefix to check for
 */
- (BOOL) startsWith:(NSString*)prefix;

/*! Checks if the string ends with the postfix string
 @param postfix The postfix to check for
 */
- (BOOL) endsWith:(NSString*)postfix;

/*! Checks if the string contains at least one occurance of the substring
 @param substring The substring to search for
 */
- (BOOL) contains:(NSString*)substring;

/*! Equivalent of python join, or componentsJoinedByString
 @param arrayOfStrings The array to join
  */
- (NSString*) join:(NSArray*)arrayOfStrings;

/*! Return an ordered array of the string split into bits between the start/end token, and those that aren't
 @param startToken The start token, eg @"{"
 @param endToken The end token, eg @"}"
 @returns For example, [@"foo{a} bar{b}" partitionBetween:@"{" andEnd:@"}"] would return an NSArray with the following strings:
 @"foo", @"{a}", @" bar", @"{b}
 */
- (NSMutableArray*) partitionBetween:(NSString*)startToken andEnd:(NSString*)endToken;

/*! Return an NSNumber if the string can be turned directly into a number, nil otherwise */
- (NSNumber *) numberValue;

/* Case insensitive comparision of strings */
- (BOOL) isEqualToStringCaseInsensitive:(NSString *)string;

/*! Replaces HTML entries (&#__) with decoded characters, or empty strings for those with no ASCII equivalent */
- (NSString*) stringStrippedOfHTMLEntries;
@end
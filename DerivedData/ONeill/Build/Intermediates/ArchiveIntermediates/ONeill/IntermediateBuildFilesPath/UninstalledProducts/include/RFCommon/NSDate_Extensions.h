//
//  NSDate_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 7/2/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate(RFExtensions)

+ (NSDate*) dateWithYear:(NSInteger)year;
+ (NSDate*) dateWithYear:(NSInteger)year month:(NSInteger)month;
+ (NSDate*) dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

@end

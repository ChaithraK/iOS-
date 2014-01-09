//
//  ONReachabilityManager.h
//  ONeill
//
//  Created by Chaithra Kumar on 12/30/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Reachability;

@interface ONReachabilityManager : NSObject
@property (strong, nonatomic) Reachability *reachability;
#pragma mark -
#pragma mark Shared Manager
+ (ONReachabilityManager *)sharedManager;
#pragma mark -
#pragma mark Class Methods
+ (BOOL)isReachable;
+ (BOOL)isUnreachable;
+ (BOOL)isReachableViaWWAN;
+ (BOOL)isReachableViaWiFi;




@end

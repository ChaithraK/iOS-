//
//  ONReachabilityManager.m
//  ONeill
//
//  Created by Chaithra Kumar on 12/30/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONReachabilityManager.h"
#import "Reachability.h"

@implementation ONReachabilityManager

#pragma mark -
#pragma mark Default Manager
+ (ONReachabilityManager *)sharedManager {
    static ONReachabilityManager *_sharedManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedManager = [[self alloc] init];
    });
    return _sharedManager;
}
#pragma mark -
#pragma mark Memory Management
- (void)dealloc {
    // Stop Notifier
    if (_reachability) {
        [_reachability stopNotifier];
    }
}
#pragma mark -
#pragma mark Class Methods
+ (BOOL)isReachable {
    return [[[ONReachabilityManager sharedManager] reachability] isReachable];
}
+ (BOOL)isUnreachable {
    return ![[[ONReachabilityManager sharedManager] reachability] isReachable];
}
+ (BOOL)isReachableViaWWAN {
    return [[[ONReachabilityManager sharedManager] reachability] isReachableViaWWAN];
}
+ (BOOL)isReachableViaWiFi {
    return [[[ONReachabilityManager sharedManager] reachability] isReachableViaWiFi];
}
#pragma mark -
#pragma mark Private Initialization
- (id)init {
    self = [super init];
    if (self) {
        // Initialize Reachability
        self.reachability = [Reachability reachabilityWithHostname:@"www.google.com"];
        // Start Monitoring
        [self.reachability startNotifier];
    }
    return self;
}
@end

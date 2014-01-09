//
//  RFActivityIndicator.h
//
//  Created by Jim Tucek on 7/16/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/* 
 A simple singleton to handle multithreaded network activity indication.
 Just call [RFActivityIndicator show] every time something starts using the
 wifi, and [RFActivityIndicator hide] once it's done.
 
 [RFActivityIndicator reset] can be called to force it to go away,
 and should be put in the AppDelegate's applicationDidEnterBackground: method 
 to ensure the spinner doesn't get stuck on because something forgot to 
 cancel out their show with a hide.
 
 Any number of UIActivityIndicatorViews can also be registered with the
 RFActivityIndicator singleton, which will be started/stopped along with
 the indicator in the status bar.  The references are weak, so you don't have
 to worry about explicitly dereferencing them.
 
 This all should be thread safe.
*/

#import <UIKit/UIKit.h>

@interface RFActivityIndicator : NSObject {
    int count;
    dispatch_queue_t activityQueue;
    NSMutableArray * activityIndicators;
}

+ (RFActivityIndicator *) sharedManager;

+ (void) show;
+ (void) hide;
+ (void) reset;

+ (void) registerActivityIndicator:(UIActivityIndicatorView*)spinner;
+ (void) deregisterActivityIndicator:(UIActivityIndicatorView*)spinner;

@end
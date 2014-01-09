//
//  ONeillAppDelegate.m
//  ONeill
//
//  Created by Chaithra Kumar on 11/21/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONeillAppDelegate.h"
#import "ONCategory.h"
#import "AFNetworking.h"
#import "RFCommon/RFCommon.h"
#import "Reachability.h"
#import "ONReachabilityManager.h"
#import "TestFlight.h"



# define URLPREFIX  "http://10.7.1.216:6543/"

@implementation ONeillAppDelegate

@synthesize categoryMasterlist,cartListArray;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    
    [ONReachabilityManager sharedManager];
   
    NSString *DevSTR=[[[UIDevice currentDevice] identifierForVendor] UUIDString];
    [TestFlight setDeviceIdentifier:DevSTR];
     [TestFlight takeOff:@"1394a083-88f5-44a9-a2e7-d65ae5894142"];
    //----------------TODO:Remove the above line when uploading to AppStore-------------//
    [[UIApplication sharedApplication] setStatusBarHidden:YES];
     categoryMasterlist=[[NSMutableArray alloc] initWithCapacity:1000];
    self.cartListArray=[[NSMutableArray alloc] init];
    
    

    
   
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end

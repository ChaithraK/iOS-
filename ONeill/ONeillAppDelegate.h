//
//  ONeillAppDelegate.h
//  ONeill
//
//  Created by Chaithra Kumar on 11/21/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ONReachabilityManager.h"


@interface ONeillAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property(nonatomic,retain)NSMutableArray *categoryMasterlist;  //TODO :Need to be removed and persistence integrated.
@property(nonatomic,retain)NSMutableArray *cartListArray;       //TODO :Need to be removed and persistence integrated
@property(nonatomic,strong)ONReachabilityManager *reachabilityMgr;

@end

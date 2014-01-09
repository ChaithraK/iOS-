//
//  UITableView_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 7/1/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableView(RFExtensions)


// Only works for single section tables right now
- (void) animateDataReorderingFrom:(NSArray*)originalOrder to:(NSArray*)newOrder;

@end

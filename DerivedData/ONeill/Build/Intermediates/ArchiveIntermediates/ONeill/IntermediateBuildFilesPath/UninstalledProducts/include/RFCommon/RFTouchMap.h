//
//  RFTouchMap.h
//  RFCommon
//
//  Created by Jim Tucek on 6/17/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RFTouchMap : UIView {
    NSMutableArray * touchRegions;
    NSMutableArray * touchActions;
    NSMutableArray * touchRegionNames;
    NSInteger touchDownRegionIndex;
    CGPoint touchDownPoint;
    NSMutableArray * touchRegionDebugHighlights;

    UIView * touchDownEffect;
}

@property (nonatomic) CGFloat debugAlpha;
@property (nonatomic) UIColor * touchDownColor;
@property (nonatomic) BOOL debugTouchRegions;

- (void) addTouchRegion:(CGRect)rect withAction:(void (^)(CGPoint touchPoint))touchUpFunction withName:(NSString*)name;
- (BOOL) hasTouchRegionAtPoint:(CGPoint)point;

@end

//
//  RFCirclePackChartView.h
//  RFCommon
//
//  Created by Jim Tucek on 7/17/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//
/*
 TODO: If the frame gets reset (ala resize b/c of rotation),
 make sure the view remains centered on the same point
 */
#import <UIKit/UIKit.h>
#import "RFCirclePack.h"
#import "RFAnimationHelper.h"

@interface RFCirclePackChartView : UIView {
    RFAnimationHelper * currentAnimation;
    BOOL animating;
    
    uint debugDraws;            // DEBUG
    double debugDrawTime;       // DEBUG
}
@property (nonatomic) RFCirclePack * rootCircle;

@property (nonatomic) float zoom;
@property (nonatomic) float tx;
@property (nonatomic) float ty;

@property (nonatomic) BOOL hideBordersDuringAnimation;
@property (nonatomic) BOOL hideLabelsDuringAnimation;
@property (nonatomic) BOOL allowZoomInOnBottomLevelCircles;

- (void) addCircleToRoot:(RFCirclePack*)child;
- (void) setColorTheme:(UIColor*)color withRange:(float)range;
- (void) centerViewOnCircle:(RFCirclePack*)child animate:(BOOL)animated;

- (void) prepareForDrawing;


@end

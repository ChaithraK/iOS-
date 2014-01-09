//
//  RFPieChartView.h
//  RFCommon
//
//  Created by Jim Tucek on 7/12/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface RFPieChartView : UIView {
    NSTimer * animationTimer;
    NSTimeInterval animationStartTime;
    NSTimeInterval animationDuration;
    
    UILabel * titleLabel;
    
    NSMutableArray * labels;
    float * labelWidths;
    
    NSMutableArray * colors;
    float totalAmount;
    int count;
    
    float * sliceStartRadians;
    float * sliceMidRadians;
    float * sliceEndRadians;
    float * sliceValues;
    
    float animationPercent;
    
    // Size Dependent Constants
    CGFloat lastWidth;
    CGFloat lastHeight;
    CGFloat circleCenterX;
    CGFloat circleCenterY;
    CGFloat circleRadius;
    CGFloat circleStrokeWidth;
}

@property (nonatomic) CGFloat outerRadiusPercent;
@property (nonatomic) CGFloat innerRadiusPercent;

@property (nonatomic) UIColor * borderColor;
@property (nonatomic) CGFloat borderWidth;

@property (nonatomic) int randomColorSeed;
@property (nonatomic) CGFloat minLabelScaleFactor;
@property (nonatomic) BOOL keepLabelsHorizontal;

- (void) reset;

- (void) addSliceNamed:(NSString*)name withColor:(UIColor*)color withAmount:(float)amount;

- (void) updateWithAnimation:(BOOL)animated;

- (void) setChartTitle:(NSString*)title;

@end

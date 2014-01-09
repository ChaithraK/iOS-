//
//  RFHalfCircleChartView.h
//  RFCommon
//
//  Created by Jim Tucek on 7/10/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RFHalfCircleChartView : UIView {
    UIView * containerView;
    UILabel * titleLabel;
    UILabel * valueLabel;
    UIView * chartView;
    UILabel * minLabel;
    UILabel * maxLabel;
}

@property (nonatomic) NSNumber * value;
@property (nonatomic) NSNumber * minValue;
@property (nonatomic) NSNumber * maxValue;
@property (nonatomic) NSString * valuePrefix;
@property (nonatomic) NSString * valuePostfix;
@property (nonatomic) NSString * valueString;
@property (nonatomic) NSString * minValueString;
@property (nonatomic) NSString * maxValueString;
@property (nonatomic) int decimalPlaces;

@property (nonatomic, readonly) UILabel * titleLabel;
@property (nonatomic, readonly) UILabel * valueLabel;
@property (nonatomic, readonly) UILabel * minLabel;
@property (nonatomic, readonly) UILabel * maxLabel;

@property (nonatomic) UIColor * barFullColor;
@property (nonatomic) UIColor * barEmptyColor;
@property (nonatomic) UIColor * barBorderColor;

@property (nonatomic, readonly) float percent;

- (void) setTitle:(NSString*)title;
- (NSString*) title;

- (void) updateWithAnimation:(BOOL)animate;


@end

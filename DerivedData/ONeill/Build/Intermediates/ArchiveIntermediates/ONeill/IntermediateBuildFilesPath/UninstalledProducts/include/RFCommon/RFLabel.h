//
//  RFLabel.h
//  RFCommon
//
//  Created by Jim Tucek on 4/18/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RFLabel : UILabel

@property (nonatomic) CGFloat topMargin;
@property (nonatomic) CGFloat leftMargin;
@property (nonatomic) CGFloat rightMargin;
@property (nonatomic) CGFloat bottomMargin;

- (void) setMargins:(CGFloat)margins;

- (void) setHorizontalMargins:(CGFloat)margins;
- (void) setVerticalMargins:(CGFloat)margins;
- (CGFloat) verticalMargins;
- (CGFloat) horizontalMargins;

@end

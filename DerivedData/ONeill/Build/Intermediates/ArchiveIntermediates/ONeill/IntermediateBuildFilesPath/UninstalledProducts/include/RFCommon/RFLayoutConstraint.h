//
//  RFLayoutConstraint.h
//  RFCommon
//
//  Created by Jim Tucek on 3/27/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//
/*
 This is a subclass of NSLayoutConstraint that is designed to keep track of what view it has been
 added too, so that you can call [constraint remove] without knowing which view has ownership of
 the constraint.
 
 It works like a normal NSLayoutConstraint, except that you should call [constraint addToView:uiview]
 instead of [uiview addConstraint:constraint]!
 
 */
#import <UIKit/UIKit.h>

@interface RFLayoutConstraint : NSLayoutConstraint

@property (nonatomic, weak) UIView * parent;
- (void) addToView:(UIView*)view;

- (void) remove;

// Convenience constructor for constraints between two items with the same attribute and a multiplier of 1
+ (RFLayoutConstraint*) constraintWithItem:(id)view1 toItem:(id)view2 attribute:(NSLayoutAttribute)attribute relatedBy:(NSLayoutRelation)relation constant:(CGFloat)c;

@end

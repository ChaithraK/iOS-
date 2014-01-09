//
//  UIView_FixEdgeInserts.h
//  RFCommon
//
//  Created by Jim Tucek on 9/27/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

/*! These are custom extensions to the UIButton class */

#import <UIKit/UIKit.h>

@interface UIButton (RFExtensions)

/*! Fix the edge insets for a particular control state 
 @param newEdgeInsets The edge insets to apply to the background image
 @param controlState The control state to modify
 */
- (void) fixEdgeInsets:(UIEdgeInsets)newEdgeInsets forState:(UIControlState)controlState;

/*! Fixes the edge insets for all control states 
 
 This function exists because the contentEdgeInsets property of UIButtons normally does not effect the positioning of the background image.  This sets the content edge for the button, and replaces the background image with one with identical edge insets.

 @param newEdgeInsets The edge insets to apply to the UIButton and it's background image
 */
- (void) fixEdgeInsets:(UIEdgeInsets)newEdgeInsets;


/*! Fix the edge insets for just the background image 
 @param newEdgeInsets The edge insets to apply to the UIButton and it's background image
 */
- (void) fixBackgroundImageEdgeInserts:(UIEdgeInsets)newEdgeInsets;


@end

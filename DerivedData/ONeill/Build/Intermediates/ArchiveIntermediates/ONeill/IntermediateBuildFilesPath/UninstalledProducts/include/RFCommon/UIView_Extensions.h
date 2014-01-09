//
//  UIView_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 3/13/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

/*! These are custom extensions to the UIView class */

#import <UIKit/UIKit.h>


@interface UIView(RFExtensions)

/*! Returns the interfaceOrientation of the view's parent view controller */
- (UIInterfaceOrientation) interfaceOrientation;

/*! Returns the view's parent view controller */
- (UIViewController *) parentUIViewController;


/*! Sends the view to the back of the view order (within its parent view) */
- (void) sendToBack;

/*! Brings the view to the front of the view order (within its parent view) */
- (void) bringToFront;


/*! Sets the view's frame if it's different from the existing frame
 @param frame The new frame
 
 This function is used to avoid upsetting in progress UIView animations.
 */
- (void) setFrameIfDifferent:(CGRect)frame;

/*! Sets the view's frame such that the top left corner as at point
 @param point The point where the view's top left corner should be at
 */
- (void) setTopLeftCornerTo:(CGPoint)point;

/*! Adds a 1 px border to the layer */
- (void) addDebugBorder;

/*! A new read/write NSString property to UIViews

 Note: If not set, it defaults to the view's class name with it's hex address appended, eg UILabel0x0abcdef
 */
@property (nonatomic) NSString * name;

@end

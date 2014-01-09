//
//  RFSemiModalViewController.h
//  RFCommon
//
//  Created by Jim Tucek on 10/31/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RFCustomNavigationController.h"

@interface RFSemiModalViewController : UIViewController<RFCustomNavigationControllerProtocol> {
    UIView * backgroundView;
}
// RFCustomNavigationControllerProtocol
@property (nonatomic) RFOImage * backgroundImage;

@property (nonatomic) BOOL touchBackgroundToDismiss;
@property (nonatomic) BOOL swipeBackgroundToDismiss;
@property (nonatomic) NSTimeInterval fadeOutDuration;

- (void) setBackgroundColor:(UIColor*)color;
- (void) setBackgroundAlpha:(CGFloat)alpha;
- (void) dismiss;

@end

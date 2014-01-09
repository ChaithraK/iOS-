//
//  RFCustomNavigationController.h
//  RFCommon
//
//  Created by Jim Tucek on 11/16/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RFOImage.h"
#import "RFInternetImageView.h"

@class RFCustomNavigationController;

@protocol RFCustomNavigationControllerProtocol

@optional
- (UIViewController*) sideMenuViewController;
- (UIView*) topMenuView;
- (RFOImage*) backgroundImage;
- (BOOL) allowSimultaneousPanGesture;
- (BOOL) backButtonClicked;
@end

@interface RFCustomNavigationController : UIViewController<UIGestureRecognizerDelegate> {
    NSMutableArray * viewControllerStack;
    
    UIViewController * currentSemiModalViewController;  // There can only be one!  (and nothing on top of it)
    
    BOOL currentViewControllerAllowsSimultaneousPanGesture;
    
    RFInternetImageView * backgroundImageView;
    UIView * backgroundImageMatte;
    
    UIViewController * sideMenuViewController;
    UIPanGestureRecognizer * sideMenuPanGestureRecognizer;
    BOOL blockedScrollViewOriginalEnabledState;
}

@property (nonatomic, readonly) UIViewController<RFCustomNavigationControllerProtocol> * currentViewController;
@property (nonatomic) IBOutlet UIView * contentView;

@property (nonatomic) IBOutlet UIView * navigationBar;
@property (nonatomic) IBOutlet UIButton * navigationBarSideMenuToggleButton;
@property (nonatomic) IBOutlet UILabel * navigationBarTitle;
@property (nonatomic) IBOutlet UIButton * navigationBarBackButton;
@property (nonatomic) UIView * navigationBarInset;
@property (nonatomic) CGFloat navigationBarInsetPadding;
@property (nonatomic) RFOImage * backgroundImage;

// Adding and Removing View Controllers
- (void) switchToViewController:(UIViewController<RFCustomNavigationControllerProtocol>*)newVC;
- (void) pushViewController:(UIViewController<RFCustomNavigationControllerProtocol>*)newVC;
- (void) pushSemiModalViewController:(UIViewController*)newVC;
- (void) popViewController;
- (void) goBack;
- (IBAction) backButtonClicked;

// Navigation Bar & Side Menu
- (void) setupNavigationBarForVC:(UIViewController<RFCustomNavigationControllerProtocol>*)topVC;
- (void) setupSideMenuForVC:(UIViewController<RFCustomNavigationControllerProtocol>*)topVC;

// For preventing any other UIScrollViews from moving while pulling out the side menu
@property (nonatomic, weak) UIScrollView * scrollViewToBlock;
@property (nonatomic) BOOL isBlockingScrolling;

// Side Menu Movement
@property (nonatomic, readonly) BOOL sideMenuIsOut;
- (void) showSideMenuAnimated:(BOOL)animated;
- (void) hideSideMenuAnimated:(BOOL)animated;
- (void) toggleSideMenuAnimated:(BOOL)animated;
- (void) applyTransformToSideMenuElements:(CGAffineTransform)transform; // Can be overridden in a subclass to transform additional elements

@end

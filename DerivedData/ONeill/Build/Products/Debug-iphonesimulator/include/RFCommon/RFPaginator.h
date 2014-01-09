//
//  RFPaginator.h
//  RFCommon
//
//  Created by Jim Tucek on 9/4/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/*
 This class handles pagination of UIViewControllers
 
 It interacts with a delegate to get pages via the RFPaginatorDelegate protocol methods.

 For now, we'll assume that the delegate can/will provide an infinite number of pages. 
*/

#import <UIKit/UIKit.h>


@class RFPaginator;

@protocol RFPaginatorDelegate

// This signals to the delegate the user has settled on a particular page number
- (void) paginator:(RFPaginator*)paginator turnedToPage:(NSInteger)pageNumber;

// The delegate should return a complete UIView for the given page number, or nil if the user can't turn the page that way
- (UIView *) viewForPageNumber:(NSInteger)pageNumber inPaginator:(RFPaginator*)paginator;

@optional

- (void) paginator:(RFPaginator *)paginator turningPastFirstPageBy:(CGFloat)pixels;
- (void) paginator:(RFPaginator *)paginator turningPastLastPageBy:(CGFloat)pixels;
- (void) paginator:(RFPaginator *)paginator touchUpOnPageNumber:(NSInteger)pageNumber;
- (void) paginator:(RFPaginator *)paginator settledOnPageNumber:(NSInteger)pageNumber;

- (UIView *) viewForFrontCoverInPaginator:(RFPaginator*)paginator;

@end

@interface RFPaginator : UIView<UIScrollViewDelegate> {
    // Slide pagination variables
    UIScrollView * slideView;
    CGFloat _scrollViewLastXOffset;
    NSMutableArray * pagesToRemoveAfterPageChangeAnimation;
    BOOL _animatingScrollViewPageChange;
    UIView * leftPageView;
    UIView * centerPageView;
    UIView * rightPageView;
    
    // Other variables
    BOOL delegateSupportsTurningPastFirstPageNotification;
    BOOL delegateSupportsTurningPastLastPageNotification;
    BOOL delegateSupportsTouchUpNotification;
    BOOL delegateSupportsSettledNotification;
    BOOL delegateSupportsFrontCoverView;
}

@property (nonatomic, readonly) NSInteger currentPageNumber;
@property (nonatomic, readonly) UIView * currentPageView;
@property (nonatomic, readonly) NSInteger maxPageNumberSeen;
@property (nonatomic) id<RFPaginatorDelegate> delegate;

- (id) initWithFrame:(CGRect)frame withDelegate:(id<RFPaginatorDelegate>)delegate;

- (void) gotoPageNumber:(NSInteger)pageNumber withAnimation:(BOOL)animated;

- (void) setNumberOfPagesToExpect:(NSUInteger)count;

- (void) setScrollEnabled:(BOOL)enabled;
- (BOOL) isScrollEnabled;

@end

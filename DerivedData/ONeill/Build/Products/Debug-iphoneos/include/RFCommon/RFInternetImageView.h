//
//  RFInternetImageView.h
//  RFCommon
//
//  Created by Jim Tucek on 7/24/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/*
 RFInternetImageView is a subclass of UIImageView that is meant to load & display images
 from the internet, via an RFOImage container class.
 
 An RFOImage consists of a URL (NSString), and a width and height.
 
 The RFInternetImageView can take in multiple possible RFOImages, and will automatically
 load and display the one with the best resolution.  While images are downloading, it will
 display a lower resolution version (if avaliable), and a download spinner.
 
 For example:
 RFInternetImageView * iv = [
 
*/
#import <UIKit/UIKit.h>
#import "RFImageCacheManager.h"
#import "RFImageScalerManager.h"
#import "RFOImage.h"

@class RFInternetImageView;

@protocol RFInternetImageViewDelegate   // For notifying a delegate the there is an image showing
- (void) internetImageViewHasImage:(RFInternetImageView*)view;
@end

@interface RFInternetImageView : UIImageView<RFImageCacheManagerDelegate, RFImageScalerDelegate, RFOImageDataSource> {
    NSMutableArray  *mipmap;
    NSString        *downloadingImageURL;
    NSString        *currentImageURL;
    CGSize scalingImageDesiredSize;
    UIActivityIndicatorView * downloadSpinner;
}
@property (nonatomic, weak) id<RFInternetImageViewDelegate> delegate;
@property (nonatomic) CGFloat aspectRatio;
@property (nonatomic) BOOL greedyDownload;
@property (nonatomic) BOOL downloading;
@property (nonatomic) BOOL hasImage;
@property (nonatomic) BOOL cacheResizedImages;
@property (nonatomic) BOOL autoSetImage;
@property (nonatomic) BOOL autoResizeImageData;
@property (nonatomic) BOOL whiteSpinner;
@property (nonatomic) BOOL noSpinner;
@property (nonatomic) BOOL hideSpinnerWhenTiny;
@property (nonatomic) BOOL keepSpinnerEvenWhenHidden;
@property (nonatomic) BOOL decodeImageDataInBackgroundThread;
@property (nonatomic) NSTimeInterval imageChangeSpeed;
@property (nonatomic, readonly) NSUInteger count;

// Convenience constructor
+ (RFInternetImageView*) imageViewWithArbitraryFrame;
+ (RFInternetImageView*) imageViewWithImage:(RFOImage*)image;

- (id) initWithFrame:(CGRect)frame;
- (void) defaultInit;

// Adding images
- (void) addImageScaleWithURL:(NSString *)url withWidth:(NSUInteger)w withHeight:(NSUInteger)h;
- (void) addImageScales:(NSArray*)arrayOfRFOImages;
- (void) addImageScale:(RFOImage *)image;
- (void) replaceImageScalesWith:(RFOImage*)image;

// Displaying images
- (void) setImageForSize:(CGSize)size;
- (void) setImageForCurrentFrame;
- (void) setImageToLargest;

// Anti-aliased image resizing
- (void) resizeImageToCurrentFrame;
- (void) resizeImageToSize:(CGSize)size;

// Changing images manually
- (void) fadeInImage:(UIImage*)image;
- (void) setImage:(UIImage*)image;

// Reusing the RFInternetImageView
- (void) recycleAndClearImage;
- (void) recycleAndKeepImage;

@end

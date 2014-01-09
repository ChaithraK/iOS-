//
//  RFImageScalerManager.h
//
//  Created by Jim Tucek on 9/24/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/* 
 This is a singleton to handle scaling images.  It can also cache them based on desired dimension and
 an UID (typically their origin url).
 
 Usage:
    Typically, you'd want to call
    [RFImageScalerSingleton resizeImage:(UIImage*)img forDelegate:delegate toSize:(CGSize)size withURL:(NSString*)url

    And then when the UIImage was ready, the manager will call:
    [delegate image:(UIImage*)original resizedTo:(UIImage*)img]
 
    The URL can be nil, or even a made up URL; It's just needed so that the cache-to-disk has something unique to key on
    (Caching is disabled if URL is nil)

    This may take awhile because of the processing required, or be nearly instantaneous due to caching.
 
    Todo: When doing this on a retina device, should the image sizes automatically be doubled?
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h> 

#define RFImageScalerSingleton ((RFImageScalerManager *)[RFImageScalerManager sharedManager])
#define ImageScalerJPGQuality .8

// This is the default amount of diskspace to use on cached images (16 Mb)
#define RFImageScalerDefaultDiskSize 1024*1024*16
#define RFImageScalerConcurrentScalingOperations 1

@protocol RFImageScalerDelegate
- (void) image:(UIImage *)originalImage resizedTo:(UIImage*)img;
@end

@interface RFImageScalerManager : NSObject {
    NSOperationQueue * imageScalingQueue;
    NSString * cacheDir;
    NSUInteger cacheSize;
    NSMutableDictionary * cacheMap;
    
    NSLock * cacheTrimLock;
}

@property (nonatomic) NSUInteger maxCacheSize;
@property (nonatomic) NSTimeInterval simulatedLag;

// Singleton accessor
+ (RFImageScalerManager *) sharedManager;
+ (void) startUp;

- (void) resizeImage:(UIImage*)sourceImage forDelegate:(id<RFImageScalerDelegate>)delegate toSize:(CGSize)size withURL:(NSString*)url;

- (BOOL) cacheHasImageForUID:(NSString*)uid withSize:(CGSize)size;
- (UIImage *) getCachedImageForURL:(NSString *)url withSize:(CGSize)size;
- (UIImage *) getCachedImageForURL:(NSString *)url;

- (void) trimCache;
- (void) emptyCache;

@end
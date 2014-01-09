//
//  RFOImage.h
//  RFCommon
//
//  Created by Jim Tucek on 8/14/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/* This is a container class for images with known urls, widths, and heights */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RFOImageDataSource
- (NSArray *) images;
@optional
- (void) preload;
@end

@interface RFOImage : NSObject

@property (nonatomic) NSString * url;
@property (nonatomic) NSUInteger width;
@property (nonatomic) NSUInteger height;
@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) NSUInteger resolution;
@property (nonatomic, readonly) BOOL isPortrait;
@property (nonatomic, readonly) BOOL isLandscape;
@property (nonatomic, readonly) BOOL isSquare;

+ (RFOImage*) imageWithURL:(NSString*)url;
+ (RFOImage*) imageWithURL:(NSString*)url withWidth:(NSUInteger)w withHeight:(NSUInteger)h;
+ (RFOImage*) imageWithNSObject:(NSObject*)object;

- (id) initWithURL:(NSString *)url withWidth:(NSUInteger)w withHeight:(NSUInteger)h;
- (void) setSize:(CGSize)size;
- (BOOL) isSmallerThan:(RFOImage *)otherImage;
- (BOOL) isSameSizeAs:(RFOImage *)otherImage;
- (BOOL) isCached;
- (void) preload;

- (BOOL) isJPG;

// Alias src to the url
- (void) setSrc:(NSString*)src;
- (NSString*) src;

@end
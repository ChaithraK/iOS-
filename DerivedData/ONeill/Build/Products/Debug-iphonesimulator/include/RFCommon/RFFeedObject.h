//
//  RFFeedObject.h
//  RFCommon
//
//  Created by Jim Tucek on 10/30/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RFFeed.h"
#import "RFOImage.h"

@interface RFFeedObject : NSObject<RFOImageDataSource, RFFeedParser> {
    BOOL preloaded;
}

@property (nonatomic) NSInteger oid;
@property (nonatomic) NSString * ctype;
@property (nonatomic, readonly) BOOL preloaded;

- (void) preload;

- (id) initWithDictionary:(NSDictionary*)d;
- (void) addImage:(RFOImage*)image;

// RFOImageDataSource
@property (nonatomic) NSMutableArray * images;

@end

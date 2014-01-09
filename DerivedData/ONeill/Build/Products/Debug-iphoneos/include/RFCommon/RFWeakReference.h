//
//  RFWeakReference.h
//  RFCommon
//
//  Created by Jim Tucek on 12/10/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
// A container for a weak reference, so that they can be put into NSArrays with the self-nil'ing behavior

#import <Foundation/Foundation.h>

@interface RFWeakReference : NSObject

@property (nonatomic, weak) NSObject * object;

// Note: Using this convenience puts a strong refernce to the object in the autorelease pool, so the weak
// reference might not self-nil right away.  The alternative is to do alloc/init and then .object = 
+ (RFWeakReference*) withObject:(__weak NSObject*)object;

- (id) initWithObject:(__weak NSObject*)object;

@end
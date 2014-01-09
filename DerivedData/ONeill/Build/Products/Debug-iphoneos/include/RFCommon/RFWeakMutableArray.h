//
//  RFWeakMutableArray.h
//  RFCommon
//
//  Created by Jim Tucek on 2/6/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//
//  This is an object that acts like an NSMutableArray, but stores all references to objects
//  as weak references

#import <Foundation/Foundation.h>
#import "RFWeakReference.h"
#import "RFCommon/RFCommon.h"

@interface RFWeakMutableArray : NSObject<IndexedSubscriptReadProtocol, IndexedSubscriptWriteProtocol, NSFastEnumeration> {
    NSMutableArray * storageArray;
}

- (id) initWithCapacity:(NSUInteger)capacity;

// NSMutableArray Duck Typing
- (void) insertObject:(id)obj atIndex:(NSUInteger)index;
- (void) removeObjectAtIndex:(NSUInteger)index;
- (void) addObject:(id)obj;
- (void) removeObject:(id)obj;
- (void) removeLastObject;
- (void) removeAllObjects;

// NSArray Duck Typing
- (NSUInteger) count;

- (void) trimNulledObjects;

@end

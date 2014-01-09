//
//  NSMutableDictionary_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 12/12/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

/*! These are custom extensions to the NSMutableDictionary class */

#import <Foundation/Foundation.h>


@interface NSMutableDictionary(RFExtensions)
/*! Map a function onto all the leaves of a NS(Mutable)Array/NS(Mutable)Dictionary
 
 This will recurse into any sub arrays and dictionaries, calling
 mapFunction(value,isMutable) on all leafs of the array/dictionary tree.
 
 mapFunction will get called once for all leafs of of the tree, with value being the NSObject* for the leaf and
 isMutable acting as a boolean flag signaling if the parent container of the leaf is mutable.
 
 For non-mutable containers (NSArrays and NSDictionaries), the return value of mapFunction is ignored.
 
 For mutable containers (NSMutableArrays and NSMuatableDictionaries), the return value replaces the leaf object.
 If mapFunction's return value is nil, that key or index is deleted from the array or dictionary.  mapFunction
 should return the original input value for no change.
 
 @param mapFunction The code block to map onto all the leafs
 */
- (void) mapBlockOntoAllLeafs:(NSObject * (^)(NSObject * value, BOOL isMutable)) mapFunction;


/*! Strips all NSNulls from the leafs of an NSMutableArray/NSDictionary tree */
- (void) stripNSNulls;


/*! Recycle an NSMutableDictionary, creating a new one if the input pointer is nil
 
 This function calls removeAllObjects on the input NSMutableDictionary and returns it, or allocates and returns an empty NSMutableDictionary
 with the given capacity if the input dictionary is nil.
 
 @param dictionary An existing NSMutableDictionary to empty out, or nil
 @param capacity The capacity hint to alloc a new NSMutableDictionary with, if needed
 
 @returns An empty NSMutableDictionary
 */
+ (NSMutableDictionary*) recycle:(NSMutableDictionary *)dictionary withCapacity:(NSUInteger)capacity;
@end



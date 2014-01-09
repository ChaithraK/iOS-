//
//  NSDictionary_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 12/12/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

/*! These are custom extensions to the NSDictionary class */

#import <Foundation/Foundation.h>


@interface NSDictionary(RFExtensions)
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


/*! Makes a mutable deep copy of a NSDictionary
 
 That is, all the stored values are also copied, so they can be mucked with without changing
 the originals.
 */
- (NSMutableDictionary*) mutableDeepCopy;
@end




//
//  NSObject_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 2/7/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

/*! These are custom extensions to the NSObject class */

#import <Foundation/Foundation.h>


@interface NSObject(RFExtensions)

/*! Convenience function for testing if an object is a NSArray object */
- (BOOL) isNSArray;

/*! Convenience function for testing if an object is a NSData object */
- (BOOL) isNSData;

/*! Convenience function for testing if an object is a NSDictionary object */
- (BOOL) isNSDictionary;

/*! Convenience function for testing if an object is a NSMutableArray object */
- (BOOL) isNSMutableArray;

/*! Convenience function for testing if an object is a NSMutableDictionary object */
- (BOOL) isNSMutableDictionary;

/*! Convenience function for testing if an object is a NSNull object */
- (BOOL) isNSNull;

/*! Convenience function for testing if an object is a NSNumber object */
- (BOOL) isNSNumber;

/*! Convenience function for testing if an object is a NSString object */
- (BOOL) isNSString;


/*! Convenience function for accessing a value referenced by a key with index, eg object[@"corgi[1]"]
 
 @param key The key string with or without an index in brackets, eg @"corgi[1]"
 
 @returns The same thing if you had done object[@"corgi"][1]
 
 Note: If there is no index with brackets in the key string, valueForKey: gets called instead
 */
- (id) valueForKeyWithIndex:(NSString*)key;


/*! Convenience function for setting a value referenced by a key with index, eg object[@"corgi[1]"] = value
 
 @param value The value to save
 @param key The key with or without an index in brackets, eg @"corgi[1]"
 
 Note: This does the same thing as object["corgi"][1] = value
 Note: If there is no index with brackets in the key string, setValue:forKey: gets called instead
 */
- (void) setValue:(id)value forKeyWithIndex:(NSString *)key;


/*! Convenience function for accessing a value referenced by a key path with indexs
 
 @param keyPath The keyPath string with or without an index in brackets, eg @"akita.corgi[1].puppies[3]"
 
 @returns The same thing if you had done object[@"akita"][@"corgi"][1][@"puppies"][3]
*/
- (id) valueForKeyPathWithIndexes:(NSString*)keyPath;

/*! Convenience function for setting a value referenced by a key path with indexs

 @param value The value to save
 @param keyPath The keyPath string with or without an index in brackets, eg @"akita.corgi[1].puppies[3]"
 
 @returns The same thing if you had done object[@"akita"][@"corgi"][1][@"puppies"][3] = value
 */
- (void) setValue:(id)value forKeyPathWithIndexes:(NSString *)keyPath;

@end

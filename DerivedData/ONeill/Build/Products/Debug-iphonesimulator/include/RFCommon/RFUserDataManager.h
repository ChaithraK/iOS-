//
//  RFUserDataManager.h
//
//  Created by Jim Tucek on 6/21/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/*
 This is a singleton class for managing user data that is saved locally on
 the device.
 
 The class works like a NSMutableDictionary, except that the keys must be
 strings and the values must be NSObjects (instead of id's).

 Data is stored/accessed as key/value pairs, where the keys are NSStrings
 and the values are NSObjects.
 
 Data is loaded from the device's disk via loadUserData, and saved back onto
 it via saveUserData.
 
 Default values for different keys are set up in a NSDictionary returned by
 defaultValues.  This function is the only one that should need to be over-
 ridden to create app specific user data managers.
 
 Values can be reset to their defaults by calling resetObjectForKey, or with
 resetAllObjects.
 
 Keys that are magic are:
    run_count       - An NSNumber tracking how many times the app has launced
    last_version    - An NSString of the app's last version (when saved)
    current_version - An NSString of the app's current version
*/

#import <Foundation/Foundation.h>

@interface RFUserDataManager : NSObject {
    NSMutableDictionary * _udata;
    NSDictionary * _defaults;
}

// Singleton accessor
+ (RFUserDataManager *) sharedManager;

// Load/save the data from/to disk
- (void) loadUserData;
- (void) saveUserData;

// Override this to add/change default values
- (NSDictionary *) defaultValues;

// Object Subscripting
- (void) setObject:(NSObject *)object forKeyedSubscript:(NSString *)key;
- (id) objectForKeyedSubscript:(NSString *)key;

// Reset values to their defaults (if any)
- (void) resetObjectForKey:(NSString *)key;
- (void) resetAllObjects;

// Methods for tracking app version changes (might want to do something
// when changing from v1 to v2, for example)
- (BOOL) appUpdated;
- (void) registerAppUpdate;
- (NSInteger) runCount;
- (NSString *) currentVersion;
- (NSString *) lastVersion;

// For debugging
- (void) print;

@end

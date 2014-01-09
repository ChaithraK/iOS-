//
//  RFLocationManager.h
//  RFCommon
//
//  Created by Jim Tucek on 5/7/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//
/*
 This is a more user (programmer) friendly interface to the CLLocationManger that lets
 us poll the location, instead of having to deal with notifications.
 
 It also supports an autoSleep feature, that turns off the location services for a period of
 time if there are too many updates in a row without a location change.
*/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#define RFLocationSingleton ((RFLocationManager *)[RFLocationManager sharedManager])

@interface RFLocationManager : NSObject<CLLocationManagerDelegate> {
    CLLocationManager * locationManager;
    CLLocation * lastLocation;
    CLLocation * fakeLocation;
    
    BOOL running;
    BOOL sleeping;
    
    NSString * latKey;
    NSString * lngKey;

    uint locationUpdatesWithoutMovement;
}

@property (nonatomic) BOOL autoSleep;
@property (nonatomic) NSTimeInterval sleepTime;

+ (RFLocationManager *) sharedManager;  // Singleton accessor, use RFLocationSingleton preprocessor definition instead

// CLLocationManager interfaces
- (void) start;
- (void) stop;
- (void) sleep;
- (BOOL) running;
- (BOOL) sleeping;

- (CLLocationAccuracy) desiredAccuracy;
- (void) setDesiredAccuracy:(CLLocationAccuracy)accuracy;

- (void) setLatKey:(NSString*)lat;
- (void) setLngKey:(NSString*)lng;

- (CLLocation*) location;
- (CLLocationDegrees) latitude;
- (CLLocationDegrees) longitude;

- (void) setFakeLocation:(CLLocation*)location;
- (void) setFakeLocationWithLat:(CLLocationDegrees)latitude andLng:(CLLocationDegrees)longitude;
- (void) clearFakeLocation;

// RFServerRequest helper function (for adding lat/lng stamps to argument dictionary)
- (void) addLatLngToArguments:(NSMutableDictionary*)argumentsDictionary;
- (NSMutableDictionary*) argumentsFromLatLng;


@end

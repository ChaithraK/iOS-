//
//  RFCommon.h
//  RFCommon
//
//  Created by Jim Tucek on 7/17/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

#import <UIKit/UIKit.h>

// Global variable for saving the HTTP Auth header (so it only needs to be computed once)
extern NSString * global_http_auth_header;
#define HTTP_AUTH_HEADER global_http_auth_header

// Global variable for storing the reflektion server url
extern NSString * global_reflecktion_server_url;
#define REFLEKTION_SERVER global_reflecktion_server_url

// Shorthand for seeing if we're on an ipad or not
#define ON_IPAD ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define ON_IPHONE ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
#if TARGET_IPHONE_SIMULATOR
#define ON_SIMULATOR TRUE
#else
#define ON_SIMULATOR FALSE
#endif


// Convenience defines for seeing if we're in portrait or landscape mode
#define IS_LANDSCAPE UIDeviceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)
#define IS_PORTRAIT UIDeviceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation)

#define IS_RETINA ([UIScreen mainScreen].scale > 1.0)

#define DEBUG_REFLEKTION_SERVER @""
#define RELEASE_REFLEKTION_SERVER @""


#ifdef DEBUG
    #define DEFAULT_REFLEKTION_SERVER DEBUG_REFLEKTION_SERVER
#else
    #define DEFAULT_REFLEKTION_SERVER RELEASE_REFLEKTION_SERVER
#endif

#define USE_BEST_GRAPHICS_PERFORMANCE 0

#define MAXIMUM_CLIPS_PER_SPREAD 8
#define MAXIMUM_PAGES_PER_SPREAD 5
#define NAVIGATION_BAR_HEIGHT 40

#define NOTIFICATION_LOGIN_FAILED @"notification-login-failed"

@protocol KeyedSubscriptReadProtocol <NSObject>
- (id) objectForKeyedSubscript:(NSString*)key;
@end
@protocol KeyedSubscriptWriteProtocol <NSObject>
- (void) setObject:(id)obj forKeyedSubscript:(id<NSCopying>)key;
@end

@protocol IndexedSubscriptReadProtocol <NSObject>
- (id) objectAtIndexedSubscript:(NSUInteger)idx;
@end
@protocol IndexedSubscriptWriteProtocol <NSObject>
- (void) setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;
@end



CGRect roundRectCoordinates(CGRect inRect);
CGRect CGRectMakeFromArray(NSArray * array);
NSInteger compareFileModificationTimes(id f1, id f2, void * context);

// Some convenience setters that will set dest to src if src is not null
// (src is usually a object from a NSDictionary)
#define SET_ID_IF_NOT_NULL(dest,src) { id tmp = src; if(tmp != nil && tmp != (id)[NSNull null]) { dest = tmp; } }
#define SET_INT_IF_NOT_NULL(dest,src) { const NSNumber * tmp = src; if(tmp != nil && tmp != (id)[NSNull null]) { dest = [tmp integerValue]; } }
#define SET_FLOAT_IF_NOT_NULL(dest,src) { const NSNumber * tmp = src; if(tmp != nil && tmp != (id)[NSNull null]) { dest = [tmp floatValue]; } }



#define UIViewAutoresizingFlexibleSize (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight)

#define UIViewAutoresizingFlexibleMargins (UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin)

#define UIViewAutoresizingFlexibleAll (UIViewAutoresizingFlexibleSize | UIViewAutoresizingFlexibleMargins)

#ifdef DEBUG

// The following are some logging macros that only get compiled into the debug version
// Eg, if you use:
// DBLog(@"Elements in array = %d",[array count]);
// That entire line will be ommited from the release version
// (so watch out for function calls that have side effects, unlike [array count])

// Same as NSLog, except that it replaces the timestamping with
// ObjectAddress [Function Name] Message
#define DBLog(args...) _DebugLog(__FILE__,__LINE__,__PRETTY_FUNCTION__,self,args);

// DBLog without the newline at the end
#define DBLogN(args...) _DebugLogN(__FILE__,__LINE__,__PRETTY_FUNCTION__,self,args);

// DBLog without prefix or new line at the end (plain output) 
#define DBLogP(args...) _DebugLogP(__FILE__,args);

// Same as NSLog, except it adds a line of dashes above and below the output (for making error logging more obvious)
#define DBELog(args...) _DBError(); _DebugLog(__FILE__,__LINE__,__PRETTY_FUNCTION__,self,args); _DBError();

#else

#define DBLog(x...) {}
#define DBLogN(x...) {}
#define DBLogP(x...) {}
#define DBELog(x...) {}

#endif

void _DebugLog(const char *srcFileName, int lineNumber, const char *funcName, id self, NSString *format, ...);
void _DebugLogN(const char *srcFileName, int lineNumber, const char *funcName, id self, NSString *format, ...);
void _DebugLogP(const char *srcFileName, NSString *format, ...);
void _DBError();



@interface RFMemTracker : NSObject
@property (nonatomic) NSString * message;
@property (nonatomic) NSUInteger uid;
- (id) initWithMessage:(NSString *) m;
- (NSUInteger) myUID;
+ (NSUInteger) makeUID;
@end
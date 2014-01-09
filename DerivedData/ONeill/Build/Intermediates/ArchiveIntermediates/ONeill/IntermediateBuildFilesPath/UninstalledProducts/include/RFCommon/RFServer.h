//
//  RFServer.h
//  RFCommon
//
//  Created by Jim Tucek on 10/3/12.
//  Copyright (c) 2012 Jim Tucek. All rights reserved.
//
/*
 This is a singleton to handle all communication with the Reflektion server, including managing the csrf tokens.
 
 Typically, to communicate with the server, you'll do something like this:
 
 - (void) sendSomeRequest {
    RFServerRequest * request = [RFServerRequest requestForDelegate:self withCallback:@selector(someRequestReturnedFromServer:)];
    request.action = @"whatever.json"
    request.isPost = FALSE;         // default
    request.requiresCSRF = FALSE;   // default
    request.arguments = (an NSMutableDictionary with key/value mappings)
    request.userData = (an extra object you want to hook onto the request for when it is returned)
    [request send];
 }
 
 - (void) someRequestReturnedFromServer:(RFServerRequest*)request {
    NSDictionary * jsonDict = [request dictionaryFromData];
    // -- or -- (depends on whether the top level of the returned JSON is a dictionary or list)
    NSArray * jsonArray = [request arrayFromData];
 
    // Do stuff (request.userData will be whatever (NSObject *) you set it to)
 }
 
 The helper functions dictionaryFromData and arrayFromData will take the returned JSON and it into a 
 NSDictionary or NSArray (you must know which format the top level JSON object is going to be)
 */

#import <Foundation/Foundation.h>
#import "RFCommon.h"

@class RFServerManager;
@class RFServerRequest;

#define RFServer ((RFServerManager*)[RFServerManager sharedManager])

@interface RFServerManager : NSObject {
    NSLock * requestQueueLock;
    NSMutableArray * requestQueue;
    NSOperationQueue * operationQueue;

    NSString * CSRFToken;
    NSString * CSRFServer;
    BOOL CSRFPending;       // Flag to prevent concurrent requests for the CSRF

    NSString * HTTPAuthToken;
}
@property (nonatomic) NSTimeInterval simulatedLag;
@property (nonatomic, readonly) NSString * csrf;
@property (nonatomic) BOOL paused;

// Singleton Accessor
+ (RFServerManager *) sharedManager;

// CSRF Token Management
- (BOOL) CSRFTokenIsValid;
- (void) getCSRFTokenFromServer;
- (void) resetCSRFToken;

// HTTP Authentication
- (void) setHTTPAuthUsername:(NSString*)username withPassword:(NSString*)password;
- (void) clearHTTPAuth;

// Request Management
- (void) cancelAllRequestsFor:(id)delegate;
- (void) sendRequest:(RFServerRequest*)request;
- (void) sendRequestGreedy:(RFServerRequest*)request;

// For Debugging
- (void) printData:(NSData*)data;
- (void) printRequest:(RFServerRequest*)request;

@end



@interface RFServerRequest : NSObject {
    NSUInteger contentLengthEstimate;
    NSMutableDictionary * files;
    NSMutableDictionary * mimetypes;
    id<NSObject> retainedDelegate;
}

// You should set delegate, callback, action, and arguments, then call send.
// dictionaryFromData and arrayFromData will turn the returned data into an NSDictionary/NSArray respectively

@property (nonatomic) __weak id<NSObject> delegate;
@property (nonatomic) BOOL retainDelegate;

@property (nonatomic) SEL callback;
@property (nonatomic) NSString * action;
@property (nonatomic) NSMutableDictionary * arguments;
@property (nonatomic) BOOL requiresCSRF;
@property (nonatomic) BOOL isPOST;
@property (nonatomic) BOOL isMultipartFormData;
@property (nonatomic) NSData * data;
@property (nonatomic) NSUInteger tryCount;
@property (nonatomic) NSTimeInterval timeout;
@property (nonatomic) NSObject * extraData;

@property (nonatomic) BOOL canceled;

@property (nonatomic, readonly) NSURL * URL;
@property (nonatomic, readonly) NSString * method;
@property (nonatomic, readonly) BOOL running;
@property (nonatomic, readonly) BOOL finished;
@property (nonatomic, readonly) NSString * dataString;
@property (nonatomic) NSString * HTTPAuthHeader;

+ (RFServerRequest*) requestForDelegate:(id)delegate withCallback:(SEL)callback;
+ (RFServerRequest*) noResponseRequest;
+ (RFServerRequest*) debugRequest;

- (void) send;

- (void) sendSynchronousRequest;                // Blocking, should only be called by the RFServerManager
- (void) signalDelegate;                        // Signals into main thread

- (NSMutableDictionary *) dictionaryFromData;
- (NSMutableArray*) arrayFromData;

- (BOOL) isGET;
- (void) setIsGET:(BOOL)isGET;
- (void) setValue:(NSObject*)value forKey:(NSString *)key;
- (void) addFileData:(NSData *)data named:(NSString *)name withMimeType:(NSString*)mimetype;

- (void) printData;

@end
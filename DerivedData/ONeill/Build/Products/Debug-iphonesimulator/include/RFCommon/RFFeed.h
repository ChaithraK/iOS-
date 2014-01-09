//
//  RFFeed.h
//  RFCommon
//
//  Created by Jim Tucek on 7/24/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/*
 This is a feed management class.  It works by taking a URL and parser object.
 
 The parser object must conform to the RFFeedParser protocol, because the parser
 object is responsible for creating new RFFeedObjects from the incoming JSON data,
 ala duck-typing.
 
 For example, if your was expecting RFOClips, then you'd set up the feed like:
    
    RFFeed * feed = [[RFFeed alloc] initWithURL:@"content/clips.json"];
    feed.parser = [[RFOClip alloc] init];
*/

#import <Foundation/Foundation.h>

@class RFFeed;
@class RFFeedObject;

@protocol RFFeedParser
- (RFFeedObject *) createFeedObjectFromDictionary:(NSDictionary*)d;
@end

@protocol RFFeedDelegate
- (void) newItemsInFeed:(RFFeed*)feed withCount:(NSInteger)count;
@end

@interface RFFeed : NSObject {
    NSString * url;                         // Root URL of the feed
    NSMutableArray * seenOIDs;              // List of FeedItems OID's, for filtering out already seen items
    NSMutableArray * items;                 // Storage of all items loaded so far
    BOOL hasLoadedAnything;
}

@property (weak, nonatomic) id<RFFeedDelegate> delegate;        // The delegate that wants to be notified of new feed items
@property (nonatomic) id<RFFeedParser> parser;                  // The singleton object that parses NSDictionaries into FeedObjects

@property (nonatomic) BOOL filterNonUnique;
@property (nonatomic) NSArray * filterItemsTo;                  // If set, ignore items who's ctype doesn't appear in this array
@property (nonatomic) NSUInteger requestCount;

@property (nonatomic, readonly) BOOL requestingMoreItemsFromServer;
@property (nonatomic, readonly) NSUInteger requestsInARowWithNoItems;
@property (nonatomic, readonly) NSUInteger offset;
@property (nonatomic, readonly) NSString * url;

@property (nonatomic) NSUInteger itemsDisplayedPerPage;        // For automatically loading more items and preloading upcoming items
@property (nonatomic) BOOL autoLoadMore;
@property (nonatomic) BOOL autoPreload;


- (id) initWithURL:(NSString *)feedURL;

// Feed Loading
- (void) reset;
- (void) loadMoreItems;
- (BOOL) atEndOfFeed;

// Feed Item Management
- (NSUInteger) count;
- (RFFeedObject *) dequeue;                                 // Removes and returns the oldest item in the feed
- (RFFeedObject *) objectAtIndexedSubscript:(NSUInteger)i;  // Object subscripting, eg feed[i]


@end

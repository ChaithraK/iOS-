//
//  RFImageCacheManager.h
//
//  Created by Jim Tucek on 7/11/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

/// WTF
/*! This is a singleton to handle downloading and caching images.
 
 Usage:
    Typically, you'd want to call
    [RFImageCacheSingleton getImageForURL:@"http://.../whatever.jpg" forDelegate:delegate]
 
    And then when the UIImage was ready, the manager will call:
    [delegate imageDownloaded:(UIImage *)img fromURL:(NSString*)url]
 
    This may take a while for the internet connection, or be nearly instantaneous due to caching.
    The img may be nil, in case of error.
 
    If your delegate is going away (eg a view that is being removed), it may be helpful to call
    [RFImageCacheSingleton cancelAllTransactionsFor:delegate]
    which does what you'd expect.  The delegate references are weak, however, so this probably isn't
    needed
 
    withPriority:(RFImageDownloaderPriority) can be used to change the priority of your request
 
    If the url starts with "project://", then it will instead load the image named whatever comes next from
    the app binary (this is assuming you've added it to the project!)  This always acts like the image
    wasn't cached.
*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define RFImageCacheSingleton ((RFImageCacheManager *)[RFImageCacheManager sharedManager])

// This is the default amount of diskspace to use on cached images (64 Mb)
#define RFImageCacheDefaultDiskSize 1024*1024*64
#define RFImageCacheConcurrentConnections 4

/*! RFImageCacheManagerDelegate protocol
 */
@protocol RFImageCacheManagerDelegate
- (void) imageDownloaded:(UIImage *)img fromURL:(NSString*)url;
@end

typedef enum {
    RFImageDownloaderLowPriority = -1,
    RFImageDownloaderNormalPriority = 0,
    RFImageDownloaderHighPriority = 1
} RFImageDownloaderPriority;

/*! RFImageCacheManager
 */
@interface RFImageCacheManager : NSObject<RFImageCacheManagerDelegate> {
    NSOperationQueue * downloadingOperationQueue;

    NSMutableDictionary * notificationDictionary;
    NSMutableArray * urlPriorityList;
        
    NSLock * queueLock;
    NSLock * cacheTrimLock;
    
    NSString * cacheDir;
    NSUInteger cacheSize;
}
@property (nonatomic) NSUInteger maxCacheSize;
@property (nonatomic) NSTimeInterval simulatedLag;
@property (nonatomic) BOOL paused;
@property (nonatomic) BOOL useRetinaImages;

// Singleton accessor
+ (RFImageCacheManager *) sharedManager;

// Image downloading
- (void) preloadImageForURL:(NSString*)url;
- (void) getImageForURL:(NSString *)url forDelegate:(NSObject<RFImageCacheManagerDelegate>*)delegate;
- (void) getImageForURL:(NSString *)url forDelegate:(NSObject<RFImageCacheManagerDelegate>*)delegate withPriority:(RFImageDownloaderPriority)priority;

// Cache Management
- (BOOL) cacheHasImageForURL:(NSString*)url;
- (UIImage *) getCachedImageForURL:(NSString *)url;
- (NSString*) localPathForImageURL:(NSString*)url;
- (void) emptyCache;

- (void) cancelAllTransactionsFor:(id)delegate;

@end


@interface RFImageDownloadRequest : NSObject
@property (nonatomic, readonly) NSString * url;
@property (nonatomic, readonly) RFImageDownloaderPriority priority;
- (id) initWithURL:(NSString*)url andPriority:(RFImageDownloaderPriority)priority;
@end



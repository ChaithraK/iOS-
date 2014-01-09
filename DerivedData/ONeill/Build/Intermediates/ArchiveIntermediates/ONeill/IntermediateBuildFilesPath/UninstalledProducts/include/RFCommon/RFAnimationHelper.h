//
//  RFAnimationHelper.h
//  RFCommon
//
//  Created by Jim Tucek on 8/13/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^RFAnimationBlock)(float animationPercent);
typedef void (^RFAnimationBlockFinally)();

typedef enum {
    RFAnimationCurveLinear,
    RFAnimationCurveEaseIn,
    RFAnimationCurveEaseOut,
    RFAnimationCurveEaseInOut,
    RFAnimationCurveEaseOutIn,
    RFAnimationCurveEaseInBack,
    RFAnimationCurveEaseOutBack,
    RFAnimationCurveEaseInOutBack,
    RFAnimationCurveEaseOutInBack,
    RFAnimationCurveEaseInElastic,
    RFAnimationCurveEaseOutElastic,
    RFAnimationCurveEaseInOutElastic,
    RFAnimationCurveEaseOutInElastic,
    RFAnimationCurveEaseInBounce,
    RFAnimationCurveEaseOutBounce,
    RFAnimationCurveEaseInOutBounce,
    RFAnimationCurveEaseOutInBounce
} RFAnimationCurve; // For the curves, see: http://wiki.sparrow-framework.org/_media/manual/transitions.png

@interface RFAnimationHelper : NSObject {
    RFAnimationBlock animationBlock;
    RFAnimationBlockFinally finallyBlock;
    NSTimeInterval firstAnimationTickTime;
    NSTimer * timer;
    BOOL running;
}

@property (nonatomic) RFAnimationCurve animationCurve;
@property (nonatomic) NSTimeInterval duration;
@property (nonatomic) NSTimeInterval frequency;
@property (nonatomic, readonly) BOOL running;

- (id) initWithAnimationBlock:(RFAnimationBlock)block;
- (id) initWithAnimationBlock:(RFAnimationBlock)block curve:(RFAnimationCurve)curve;
- (id) initWithAnimationBlock:(RFAnimationBlock)block curve:(RFAnimationCurve)curve duration:(NSTimeInterval)duration;
- (id) initWithAnimationBlock:(RFAnimationBlock)block curve:(RFAnimationCurve)curve duration:(NSTimeInterval)duration conclusion:(RFAnimationBlockFinally)finally;

- (void) start;
- (void) stop;

+ (float) interpolateBetween:(float)start andEnd:(float)end atP:(float)percent;

@end

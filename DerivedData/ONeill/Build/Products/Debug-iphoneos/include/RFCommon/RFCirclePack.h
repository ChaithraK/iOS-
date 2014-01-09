//
//  RFCirclePack.h
//  RFCommon
//
//  Created by Jim Tucek on 8/14/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RFCirclePack : NSObject {
    NSMutableArray * children;
    BOOL needToLayoutChildren;
        
    float childBoundingCircleRadius;
    NSString * valueString;             // Cached NSString representation of the value, for labeling
    
    CGColorRef CGColor;                 // Cached references to the CoreGraphics color references
    CGColorRef CGBorderColor;           // from self.color and self.borderColor (for minor rendering speed improvement)
    
    BOOL globalPositionsNeedToBeCalculated;
}

@property (nonatomic, weak) RFCirclePack * parent;
@property (nonatomic, readonly) NSArray * children;
@property (nonatomic, readonly) uint numberOfDescendants;

@property (nonatomic) NSString * name;
@property (nonatomic) UIColor * color;
@property (nonatomic) UIColor * borderColor;

@property (nonatomic) float localR;     // This circle's position and radius in it's parent's [-1,1] coordinate space
@property (nonatomic) float localX;
@property (nonatomic) float localY;

@property (nonatomic) float globalR;    // This circle's position and radius in the global [-1,1] coordinate space of
@property (nonatomic) float globalX;    // the root circle.  Manually calculating these only when needed makes the
@property (nonatomic) float globalY;    // rendering go about twice as fast, as opposed to using a ton of 
- (void) calculateGlobalPositions;      // CGContextTranslate / Scales

@property (nonatomic, readonly) CGColorRef CGColor;
@property (nonatomic, readonly) CGColorRef CGBorderColor;

@property (nonatomic) float value;
@property (nonatomic, readonly) float distanceFromCenter;

- (void) layoutChildrenIfNeeded;


- (id) initWithName:(NSString*)name value:(float)value;
- (id) initWithName:(NSString*)name color:(UIColor*)color value:(float)value;
- (void) addChild:(RFCirclePack*)child;

- (void) setValueToOneForCirclesWithChildrenRecursively:(BOOL)recurseOnAncestors;
- (void) setValueToNumberOfChildrenRecursively:(BOOL)recurseOnAncestors;
- (void) inheritValueFromChildrenRecursively:(BOOL)recurseOnAncestors;

- (RFCirclePack*) childAtPoint:(CGPoint)point;


- (void) fastDrawWithRef:(CGContextRef)context drawBorders:(BOOL)drawBorders drawLabels:(BOOL)drawLabels;


@end
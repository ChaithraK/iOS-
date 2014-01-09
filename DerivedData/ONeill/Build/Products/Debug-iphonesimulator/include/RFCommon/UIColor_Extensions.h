//
//  UIColor_Extensions.h
//  RFCommon
//
//  Created by Jim Tucek on 8/15/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//

/*! These are custom extensions to the UIColor class */

#import <UIKit/UIKit.h>


@interface UIColor (RFExtensions)

/*! Creates a UIColor from a string that HTML/CSS would treat as a color
 
 @param htmlColor Either:
 
 - A CSS color, eg 'red' or 'fuchsia' (case insensitive).
 - A hex string, with or without the leading #, in the form of RGB, RGBA, RRGGBB, or RRGGBBAA
 - 'rgb(R,G,B)' where R, G, and B are integers between 0 and 255
 - 'rgba(R,G,B,A)' where R, G, and B are integers between 0 and 255, and A is a float between 0 and 1 (per css spec)
 
 @returns The equivalent UIColor, or nil for invalid input.
*/
+ (UIColor *) colorWithHTMLString:(NSString*) htmlColor;


/*! Creates a UIColor from a hex RGB string
 
 @param hexString A hex string, with or without the leading #, in the form of RGB, RGBA, RRGGBB, or RRGGBBAA
 
 @returns The equivalent UIColor, or nil for invalid input.
*/
+ (UIColor *) colorWithHexString:(NSString *) hexString;


/*! Creates a UIColor from a named CSS/HTML color

 @param cssName A CSS color, eg 'red' or 'fuchsia' (case insensitive).
 
 @returns The equivalent UIColor, or nil for invalid input.
*/
+ (UIColor *) colorWithCSSName:(NSString*)cssName;


/*! Creates a UIColor from the rgb() / rgba() CSS way of declaring color
 
 @param rgb Either:
 
 - 'rgb(R,G,B)' where R, G, and B are integers between 0 and 255
 - 'rgba(R,G,B,A)' where R, G, and B are integers between 0 and 255, and A is a float between 0 and 1 (per css spec)
 
 @returns The equivalent UIColor, or nil for invalid input.
 */
+ (UIColor *) colorWithRGBString:(NSString *)rgb;


/*! Creates a UIColor with RGB values ranging from 0 to 255 */
+ (UIColor *) colorWithR:(int)r G:(int)g B:(int)b;


/*! Returns a random color with an alpha of 1 */
+ (UIColor *) randomColor;


/*! Returns a random color with an alpha of 1, from a seed number
 
 @param seed An unsigned integer to seed the random number generator with.  This has the effect that the same
 seed number will always generate the same random color, which is good for consistently coloring views by their
 related index, for example.
*/
+ (UIColor *) randomColorWithSeed:(NSUInteger)seed;


/*! Returns the alpha component of a UIColor */
- (CGFloat) alpha;

/*! Returns a patterned color from a image file in the project */
+ (UIColor *) colorWithPatternImageNamed:(NSString*)fileName;

/*! Returns a NSString representation of the color as an RGB string (values between 0 and 255) */
- (NSString*) rgbString;
@end

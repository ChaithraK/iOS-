//
//  RFExpressionEvaluator.h
//  Typography-testbed
//
//  Created by Michael Dixon on 12/5/12.
//  Copyright (c) 2012 Michael Dixon. All rights reserved.
//

/*! A Javascript expression evaluator singleton
 
 This is a singleton that evaluates javascript expressions with a hidden UIWebView.  There's a 10ms lag the first
 time an expression is evaluated, but otherwise it is plenty fast (if the expression is simple).
*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RFExpressionEvaluator : NSObject {
    UIWebView * _webView;
}

+ (RFExpressionEvaluator *) sharedEvaluator;

/*! Evaluates a JavaScript expression where you expect a boolean response
 @param expression The expression to evaluate
 @returns TRUE if the expression evaluates to "true", otherwise FALSE
*/
+ (BOOL) evaluateBooleanExpression: (NSString*) expression;


/*! Evaluate a JavaScript expression where you expect a numeric response
 @param expression The expression to evaluate
 @returns An NSNumber if the expression evaluated correctly, otherwise nil.
*/
+ (NSNumber*) evaluateNumericExpression: (NSString*) expression;

/*! Evaluate a JavaScript expression with min/max calls where you expect a numberic response
 @param expression The expression to evaluate
 @returns An NSNumber if the expression evaluated correctly, otherwise nil.
*/
+ (NSNumber*) evaluateNumericExpressionWithMinMax: (NSString*) expression;

@end

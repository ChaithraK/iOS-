//
//  RFCroppedInternetImageView.h
//  RFCommon
//
//  Created by Jim Tucek on 1/24/13.
//  Copyright (c) 2013 Reflektion. All rights reserved.
//

#import <RFCommon/RFCommon.h>
#import "RFInternetImageView.h"

@interface RFCroppedInternetImageView : RFInternetImageView

@property (nonatomic) CGRect croppingRect;

@end

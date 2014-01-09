//
//  RFPictureFrameView.h
//  RFCommon
//
//  Created by Jim Tucek on 11/13/12.
//  Copyright (c) 2012 Reflektion. All rights reserved.
//
/*
 This class takes a view and adds it to itself, ensuring that despite any resizing,
 the subview will remain centered, with the correct aspect ratio, as big as possible
 while still being smaller than the maximum size, if defined.
 
 EG:
 [pictureFrame setMaxPictureSize:CGSizeMake(100,200)];
 [pictureFrame setAspectRatio:(width / height)];  // Aspect ratio will be inferred from maxSize otherwise
 [pictureFrame setPictureView:someview];
 
 */
#import <UIKit/UIKit.h>

@interface RFPictureFrameView : UIView

@property (nonatomic) UIView * pictureView;
@property (nonatomic) CGFloat aspectRatio;
@property (nonatomic) CGSize maxPictureSize;

@end

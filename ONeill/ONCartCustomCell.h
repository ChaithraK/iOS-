//
//  ONCartCustomCell.h
//  ONeill
//
//  Created by chaithra on 12/13/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <RFCommon/RFInternetImageView.h>
#import "RFCommon/RFCommon.h"


@interface ONCartCustomCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *ItemZtitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *ItemColor;
@property (weak, nonatomic) IBOutlet UILabel *ItemSize;
@property (weak, nonatomic) IBOutlet UILabel *ItemQuantity;
@property (weak, nonatomic) IBOutlet UILabel *ItemPrice;

@property (weak, nonatomic) IBOutlet RFInternetImageView *ItemImageView;

@end

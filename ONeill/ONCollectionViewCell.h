//
//  ONCollectionViewCell.h
//  ONeill
//
//  Created by chaithra on 11/30/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RFCommon/RFCommon.h"
#import "RFCommon/RFInternetImageView.h"

@interface ONCollectionViewCell : UICollectionViewCell
@property (weak, nonatomic) IBOutlet RFInternetImageView *productImageView;
@property (weak, nonatomic) IBOutlet UILabel *productTitle;
@property (weak, nonatomic) IBOutlet UILabel *itemPriceLabel;
@property (weak, nonatomic) IBOutlet UILabel *itemOldPriceLabel;

@end

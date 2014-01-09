//
//  ONStaticCell.m
//  ONeill
//
//  Created by Chaithra Kumar on 1/7/14.
//  Copyright (c) 2014 Chaithra Kumar. All rights reserved.
//

#import "ONStaticCell.h"

@implementation ONStaticCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end

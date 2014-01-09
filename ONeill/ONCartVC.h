//
//  ONCartVC.h
//  ONeill
//
//  Created by Chaithra Kumar on 12/19/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ONProductItem.h"

@interface ONCartVC : UIViewController<UITableViewDataSource,UITableViewDelegate>
@property (weak, nonatomic) IBOutlet UITableView *cartTableView;
@property (weak, nonatomic) IBOutlet UILabel *cartTotalPricelabel;

@property (weak, nonatomic) IBOutlet UILabel *cartShippingPriceLabel;
@property (weak, nonatomic) IBOutlet UILabel *cartTaxPricelabel;
@property (weak, nonatomic) IBOutlet UILabel *cartFinalPriceLabel;
@property(nonatomic,strong)NSMutableArray *cartArray;
@end

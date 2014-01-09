//
//  ONShoppingListVC.h
//  ONeill
//
//  Created by Chaithra Kumar on 12/23/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ONProductItem.h"

@interface ONShoppingListVC : UITableViewController
@property(nonatomic,strong)NSMutableArray *cartArray;
@property (strong, nonatomic)  UILabel *cartTotalPricelabel;
@property (strong, nonatomic)  UILabel *cartDiscountsLabel;

@property (strong, nonatomic)  UILabel *cartShippingPriceLabel;
@property (strong, nonatomic)  UILabel *cartTaxPricelabel;
@property (strong, nonatomic)  UILabel *cartFinalPriceLabel;

-(void)checkoutItem:(id)sender;

@end

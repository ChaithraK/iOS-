//
//  ONShoppingDetailsVC.h
//  ONeill
//
//  Created by Chaithra Kumar on 1/7/14.
//  Copyright (c) 2014 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iCarousel.h"
#import "Cartitem.h"

@interface ONShoppingDetailsVC : UIViewController<iCarouselDataSource,iCarouselDelegate,UITableViewDataSource,UITableViewDelegate>
@property (weak, nonatomic) IBOutlet iCarousel *itemcarousal;
@property (weak, nonatomic) IBOutlet UITableView *staticTableView;
@property (weak, nonatomic) IBOutlet UIStepper *quantityStepper;
@property (weak, nonatomic) IBOutlet UILabel *quantitylabel;
@property(strong,nonatomic)Cartitem *productitem;

@property (weak, nonatomic) IBOutlet UILabel *price;
@property (weak, nonatomic) IBOutlet UILabel *final_price;
@property(nonatomic,strong)NSMutableArray *unarchievedMediaList;

- (IBAction)removeItem:(id)sender;

@end

//
//  ONDetailsVC.h
//  ONeill
//
//  Created by chaithra on 12/9/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iCarousel.h"
#import <RFCommon/RFCommon.h>
#import "RFCommon/RFServer.h"
#import "ONProductItem.h"

@interface ONDetailsVC : UIViewController<iCarouselDataSource,iCarouselDelegate,UITableViewDataSource,UITableViewDelegate,UICollectionViewDataSource,UICollectionViewDelegate>
@property (weak, nonatomic) IBOutlet UILabel *oldPrice;
@property (weak, nonatomic) IBOutlet UIScrollView *bhScrollView;
@property (weak, nonatomic) IBOutlet UITableView *pickerTableView;
@property(nonatomic,strong)ONProductItem *productItem;
@property(nonatomic,strong)NSString *skuStr;
@property (weak, nonatomic) IBOutlet UILabel *priceLabel;
@property (weak, nonatomic) IBOutlet UIButton *addtoCart;
@property (weak, nonatomic) IBOutlet UITextView *descriptionTextView;
@property (weak, nonatomic) IBOutlet UIView *contentView;

@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (weak, nonatomic) IBOutlet UIStepper *quantityStepper;

@property (weak, nonatomic) IBOutlet UILabel *quantityLabel;


@property (weak, nonatomic) IBOutlet iCarousel *customCarousalView;
@property(strong,nonatomic)NSMutableArray *listArray;
@property(nonatomic,strong)NSIndexPath *selectedIndexpath;
- (IBAction)addToCart:(id)sender;



-(IBAction)unwindingfromSelection:(UIStoryboardSegue *)segue;
-(void)getRecommendations:(NSString*)sku;
-(void)loadDetailsOfProduct:(ONProductItem *)item;

@end

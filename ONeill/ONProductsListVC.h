//
//  ONProductsListVC.h
//  ONeill
//
//  Created by chaithra on 11/30/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ONCollectionViewCell.h"
#import <RFCommon/RFCommon.h>
#import "RFCommon/RFServer.h"
#import "MBProgressHUD.h"

@interface ONProductsListVC : UICollectionViewController<UICollectionViewDataSource,UICollectionViewDelegate>


@property(nonatomic,strong)NSMutableArray *productsArray;
@property(nonatomic,strong)NSString *titleString;
@property(nonatomic,strong)MBProgressHUD *hud;

-(void)fetchProductsList:(NSString *)titleString;

@end

//
//  ONHomeVC.h
//  ONeill
//
//  Created by Chaithra Kumar on 11/21/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ONeillAppDelegate.h"

@interface ONHomeVC : UIViewController<UITabBarControllerDelegate>
{
    NSArray *filteredArr;
}
@property (weak, nonatomic) IBOutlet UIImageView *carousalImageView;
@property(nonatomic,strong)NSArray *categoryList;
@property(nonatomic,strong)ONeillAppDelegate *appDelegate;

-(void)getCategories;
-(void)categoriesData:(id)jsondata;
-(NSArray *)filterCategoriesWithId:(NSInteger)cat_id;

@end

//
//  ONCartVC.h
//  ONeill
//
//  Created by Chaithra Kumar on 11/22/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ONSearchVC : UITableViewController
{
    NSArray *searchResults;
    BOOL istoggle;
    BOOL shouldNavigateHierarchy;
    NSMutableArray *tempArray;
    NSString *destTitle;
}

@property(nonatomic,strong)NSMutableArray *listArray;
@property(nonatomic,strong)NSString *titleString;

-(NSMutableArray *)getChildrenForCategory:(NSInteger)catName;

@end

//
//  ONSelectionListVC.h
//  ONeill
//
//  Created by chaithra on 12/12/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ONSelectionListVC : UITableViewController
@property(nonatomic,strong)NSMutableArray *selectionList;
@property(nonatomic,strong)NSIndexPath *selectedIndexPath;
@property(nonatomic,strong)NSString *selectedString;

@end

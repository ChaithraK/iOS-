//
//  ONCategory.h
//  ONeill
//
//  Created by chaithra on 12/3/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ONCategory : NSObject

@property(nonatomic,strong)NSString *cat_name;
@property(nonatomic)NSInteger *cat_id;
@property(nonatomic)NSInteger *parent_id;

@end

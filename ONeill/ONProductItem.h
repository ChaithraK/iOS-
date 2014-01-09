//
//  ONProductItem.h
//  ONeill
//
//  Created by chaithra on 12/11/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ONProductItem : NSObject

@property(nonatomic,strong)NSString *sku;
@property(nonatomic,strong)NSString *name;
@property(nonatomic,strong)NSString *url;
@property(nonatomic,strong)NSString *description;
@property(nonatomic,strong)NSString *obj_id;
@property(nonatomic,strong)NSString *price;
@property(nonatomic,strong)NSString *final_price;
@property(nonatomic,strong)NSString *image_url;
@property(nonatomic,strong)NSMutableArray *stock_color;
@property(nonatomic,strong)NSMutableArray *stock_size;
@property(nonatomic,strong)NSMutableArray *media_list;
@property(nonatomic,strong)NSString *selectedColor;
@property(nonatomic,strong)NSString *selectedSize;
@property(nonatomic,strong)NSString *selectedQuantity;

-(id)initWithDictionary:(NSDictionary *)jsonDictionary;


@end

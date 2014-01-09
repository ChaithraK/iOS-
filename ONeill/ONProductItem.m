//
//  ONProductItem.m
//  ONeill
//
//  Created by chaithra on 12/11/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONProductItem.h"

@implementation ONProductItem

@synthesize name,url,image_url,description,media_list,sku,stock_color,stock_size,obj_id,price,final_price,selectedColor,selectedQuantity,selectedSize;

-(id)initWithDictionary:(NSDictionary *)jsonDictionary
{
    if ((self = [super init])) {
        self.name=[jsonDictionary valueForKey:@"name"];
        self.final_price=[jsonDictionary valueForKey:@"final_price"];
        self.image_url=[jsonDictionary valueForKey:@"image_url"];
        
        self.sku=[jsonDictionary valueForKey:@"sku"];
        self.url=[jsonDictionary valueForKey:@"url"];
        self.media_list=[jsonDictionary valueForKey:@"media_list"];
        self.stock_size=[jsonDictionary objectForKey:@"stock_size"];
        self.stock_color=[jsonDictionary objectForKey:@"stock_color"];
        self.description=[jsonDictionary valueForKey:@"description"];
        self.price=[jsonDictionary valueForKey:@"price"];
        self.obj_id=[jsonDictionary valueForKey:@"id"];
        
        
    }
    return self;
}
@end

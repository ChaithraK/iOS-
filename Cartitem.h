//
//  ONeill.h
//  ONeill
//
//  Created by Chaithra Kumar on 1/8/14.
//  Copyright (c) 2014 Chaithra Kumar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Cartitem : NSManagedObject

@property (nonatomic, retain) NSString * color;
@property (nonatomic, retain) NSData * medialist;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * price;
@property (nonatomic, retain) NSString * quantity;
@property (nonatomic, retain) NSString * size;
@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSString * final_price;

@end

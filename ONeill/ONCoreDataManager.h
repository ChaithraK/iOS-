//
//  ONCoreDataManager.h
//  ONeill
//
//  Created by Chaithra Kumar on 12/30/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ONProductItem.h"
#import "Cartitem.h"

@interface ONCoreDataManager : NSObject

@property (readonly, strong, nonatomic) NSManagedObjectContext       *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel         *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

+(ONCoreDataManager *)sharedManager;
- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;
-(void)addItemToCart:(ONProductItem *)cartItem;
-(NSArray *)getShoppingList;
-(void)deleteItem:(Cartitem *)item;

@end

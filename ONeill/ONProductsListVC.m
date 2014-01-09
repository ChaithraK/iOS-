//
//  ONProductsListVC.m
//  ONeill
//
//  Created by chaithra on 11/30/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONProductsListVC.h"
#import "ONDetailsVC.h"
#import "ONProductItem.h"
#import  "ONReachabilityManager.h"
#import <RFCommon/RFActivityIndicator.h>
#import "MBProgressHUD.h"


#define kBgQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)


@interface ONProductsListVC ()

@end

@implementation ONProductsListVC

@synthesize productsArray,titleString;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
     self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"" style:UIBarButtonItemStylePlain target:nil action:nil];
    self.productsArray=[[NSMutableArray alloc] init];
    NSString *pStr= [self.titleString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    [self fetchProductsList:pStr];
    
    
	
    
}

-(void)viewWillAppear:(BOOL)animated
{
   
}

#pragma mark 
#pragma mark Network Operation

-(void)fetchProductsList:(NSString *)pString
{
    if ([ONReachabilityManager isReachable]) {
    NSString *urlStr=[NSString stringWithFormat:@"http://localhost:6543/search/request.json?ckey=11114-43294971&np=40&categories=%@&product_fields=description,media_list,stock_size,stock_color",pString];
        //NSURL *url=[NSURL URLWithString:urlStr];
        RFServerRequest *req=[RFServerRequest requestForDelegate:self withCallback:@selector(productsListResponse:)];
        req.action=urlStr;
        req.isGET=YES;
        [req send];
        
        self.hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
        self.hud.mode = MBProgressHUDModeIndeterminate;
        self.hud.labelText = @"Loading....";

        
//    dispatch_async(kBgQueue, ^{
//        NSData* data = [NSData dataWithContentsOfURL:
//                        url];
//        [self performSelectorOnMainThread:@selector(productsListResponse:)
//                               withObject:data waitUntilDone:YES];
//    });
    }
    else{
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"Sorry,No Network,Please try again later!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
    

}

//network response

-(void)productsListResponse:(RFServerRequest *)resp
{
    
    [self.hud hide:YES];

    if (resp.data==nil) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!Unable to load data from server!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }

    NSDictionary* json;
    @try {
        json = [resp dictionaryFromData];
        
//        json=[NSJSONSerialization
//              JSONObjectWithData:jsondata //1
//              
//              options:0
//              error:&error];
    }
    @catch (NSException *exception) {
        
            UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!There was a problem with the server.Unable to load data!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        
    }
    
    
    self.productsArray=[json valueForKey:@"products"];
    [self.collectionView reloadData];
    
}

#pragma mark -
#pragma mark UICollectionViewDataSource methods

-(NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

-(NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return [self.productsArray count];
}

-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    ONCollectionViewCell *mycell=[collectionView dequeueReusableCellWithReuseIdentifier:@"productlistCell" forIndexPath:indexPath];
    NSDictionary *itemDictionary=[self.productsArray objectAtIndex:indexPath.row];
    mycell.productTitle.text=[itemDictionary valueForKey:@"name"];
    mycell.itemPriceLabel.text=[itemDictionary valueForKey:@"final_price"];
    if (![[itemDictionary valueForKey:@"price"] isEqualToString:[itemDictionary valueForKey:@"final_price"]]) {
        NSMutableAttributedString *attString=[[NSMutableAttributedString alloc]initWithString:[itemDictionary valueForKey:@"price"]];
        [attString addAttribute:NSStrikethroughStyleAttributeName value:[NSNumber numberWithInt:1] range:NSMakeRange(0,[attString length])];
        mycell.itemOldPriceLabel.attributedText=attString;
    }
    

    [mycell.productImageView addImageScale:[RFOImage imageWithURL:[itemDictionary valueForKey:@"image_url"]]];
   
    return mycell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
   
    
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma 
#pragma mark product details screen

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    
    NSArray *arr = [self.collectionView indexPathsForSelectedItems];
    NSIndexPath *indexpath=arr[0];
    ONDetailsVC *detailsVC=[segue destinationViewController];
    ONProductItem *item=[[ONProductItem alloc] initWithDictionary:[self.productsArray objectAtIndex:indexpath.row]];
    detailsVC.productItem=item;
 
        
        
    
}





@end

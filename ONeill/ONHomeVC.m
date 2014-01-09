//
//  ONHomeVC.m
//  ONeill
//
//  Created by Chaithra Kumar on 11/21/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONHomeVC.h"
#import "ONSearchVC.h"
#import "AFNetworking.h"
#import  "SBJson4.h"
#import "ONeillAppDelegate.h"
#import "ONReachabilityManager.h"
#import <RFCommon/RFCommon.h>
#import "RFCommon/RFServer.h"


#define kBgQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

@interface ONHomeVC ()

@end

@implementation ONHomeVC

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
    self.appDelegate=[[UIApplication sharedApplication] delegate];
    self.carousalImageView.animationImages=[NSMutableArray arrayWithObjects:[UIImage imageNamed:@"1.jpg"],[UIImage imageNamed:@"2.jpg"],[UIImage imageNamed:@"3.jpg"],[UIImage imageNamed:@"4.jpg"],[UIImage imageNamed:@"5.jpg"],[UIImage imageNamed:@"6.jpg"], nil];
    self.tabBarController.delegate=self;
    
    self.carousalImageView.animationDuration=20;
    [self.carousalImageView startAnimating];
    [self getCategories];
    //UIAlertView *al=[[UIAlertView alloc] initWithTitle:@"req sent" message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    //[al show];
    
}

#pragma mark GET CATEGORIES.

-(void)getCategories
{
  
   
    if ([ONReachabilityManager isReachable]) {
       // NSURL *url=[NSURL URLWithString:@"http://10.7.1.216:6543/search/metadata.json?ckey=11114-43294971"];
        //http://10.7.1.23:6543;-- Staging URL.
        @try {
            
            RFServerRequest *req=[RFServerRequest requestForDelegate:self withCallback:@selector(categoriesList:)];
            req.action=@"http://localhost:6543/search/metadata.json?ckey=11114-43294971";
            req.isGET=YES;
            [req send];
//            dispatch_async(kBgQueue, ^{
//                NSData* data = [NSData dataWithContentsOfURL:
//                                url];
//                [self performSelectorOnMainThread:@selector(categoriesData:)
//                                       withObject:data waitUntilDone:YES];
//            });
        }
        @catch (NSException *exception) {
            UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!There was a problem with the server.Unable to load data!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
    }
    else{
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"Sorry, No Network,Please try again later!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];

    }

   
//    UIActivityIndicatorView *indicator=[[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
//    [self.view addSubview:indicator];
//    [indicator startAnimating];
   
}


-(void)categoriesList:(RFServerRequest *)resp
{
    NSLog(@"resp:%@",[resp description]);
    if (resp.data==nil) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!Unable to load data from server!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
    NSDictionary* json;
    @try {
          json = [resp dictionaryFromData];
        
            }
    @catch (NSException *exception) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!There was a problem with the server.Unable to load data!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        
    }
    self.categoryList = [json objectForKey:@"category_list"]; //2
    ONeillAppDelegate *appDelegate=[[UIApplication sharedApplication] delegate];
    appDelegate.categoryMasterlist=[self.categoryList mutableCopy];
    
    
}


//-(void)categoriesData:(NSData *)jsondata
//{
//    
//   
//    NSDictionary* json;
//    
//    NSError* error;
//    
//    @try {
//        
//         json = [NSJSONSerialization
//                              JSONObjectWithData:jsondata //1
//                              
//                              options:0
//                              error:&error];
//    }
//    @catch (NSException *exception) {
//        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!There was a problem with the server.Unable to load data!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
//        [alert show];
//
//        
//
//    }
//    
//    
//    
//    if(error) {
//        NSLog(@"%@",[error userInfo]);
//        NSLog(@"its an error");
//    
//    }
//    
//    self.categoryList = [json objectForKey:@"category_list"]; //2
//    ONeillAppDelegate *appDelegate=[[UIApplication sharedApplication] delegate];
//    appDelegate.categoryMasterlist=[self.categoryList mutableCopy];
//    
//    
//   
//    
//}

-(NSArray *)filterCategoriesWithId:(NSInteger)cat_id
{
    NSPredicate *menspredicate=[NSPredicate predicateWithFormat:@"parent_id == %ld",cat_id];
    //NSLog(@"predicate:%@",menspredicate);
    NSArray *lfilteredArr=[self.categoryList filteredArrayUsingPredicate:menspredicate];
    //NSLog(@"Filtered arr for %ld:%@",(long)cat_id,lfilteredArr);
    return lfilteredArr;
    
    
}


- (IBAction)showCategories:(id)sender {
    
    NSString *title;
    UIButton *selectedBtn=(UIButton *)sender;
    switch (selectedBtn.tag) {
        case 100:
            title=@"MENS";//id=3
            filteredArr=[self filterCategoriesWithId:3];
            break;

        case 101:
            title=@"WOMENS";//18
            filteredArr=[self filterCategoriesWithId:18];
            break;

        case 102:
            title=@"GIRLS";//57
            filteredArr=[self filterCategoriesWithId:26];
            break;

        case 103:
            title=@"BOYS";//54
            filteredArr=[self filterCategoriesWithId:14];
            break;

        case 104:
            title=@"SALE";//All
            filteredArr=[self filterCategoriesWithId:51];
            break;

        case 105:
            title=@"MORE";//All
            filteredArr=self.categoryList;//No filtering as of now
            break;
        default:
            break;
    }
    
    UINavigationController *vc=(UINavigationController *)[self.tabBarController.viewControllers objectAtIndex:2];
    ONSearchVC *svc=(ONSearchVC *)[vc.viewControllers objectAtIndex:0];
    svc.titleString=title;
    svc.listArray=[filteredArr mutableCopy];
    
    [self.tabBarController setSelectedIndex:2];
}



#pragma 
#pragma mark Tabbarcontroller delegates.

- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController
{
    if (tabBarController.selectedIndex==2) {
        UINavigationController *vc=(UINavigationController *)viewController;
        ONSearchVC *svc=(ONSearchVC *)[vc.viewControllers objectAtIndex:0];
        svc.titleString=@"TRENDING ITEMS";
        filteredArr=self.categoryList;
        svc.listArray=[filteredArr mutableCopy];
        
        //TODO load trending items in to the array and load it in the categories list
        

    }
    }

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}





@end

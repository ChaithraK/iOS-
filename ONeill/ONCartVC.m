//
//  ONCartVC.m
//  ONeill
//
//  Created by Chaithra Kumar on 12/19/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//


#import "ONCartVC.h"
#import "ONeillAppDelegate.h"
#import "ONCartCustomCell.h"
#import "ONCoreDataManager.h"

@interface ONCartVC ()

@end

@implementation ONCartVC

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
    self.cartTableView.delegate=self;
    self.cartTableView.dataSource=self;
    self.title=@"Shopping Cart";
	// Do any additional setup after loading the view.
}

-(void)viewWillAppear:(BOOL)animated
{
//    ONeillAppDelegate *appDelegate=[[UIApplication sharedApplication] delegate];
//    if ([appDelegate.cartListArray count]>0) {
//        self.cartArray=appDelegate.cartListArray;
//        [self.cartTableView reloadData];
//    }
    
    ONCoreDataManager *mgr=[ONCoreDataManager sharedManager];
    self.cartArray=[[mgr getShoppingList] mutableCopy];
    [self.cartTableView reloadData];
                    
    
    
    
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return [self.cartArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"shoppinglistCell";
    ONCartCustomCell *cell = (ONCartCustomCell *)[tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    //UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
    if (cell == nil) {
        cell = [[ONCartCustomCell alloc] initWithStyle:UITableViewCellStyleDefault  reuseIdentifier:CellIdentifier];
    }
    ONProductItem *item =[self.cartArray objectAtIndex:indexPath.row];
    cell.ItemZtitleLabel.text=item.name;
    cell.ItemPrice.text=item.final_price;
    cell.ItemColor.text=item.selectedColor;
    cell.ItemQuantity.text=item.selectedColor;
    cell.ItemSize.text=item.selectedSize;
    cell.ItemQuantity.text=@"1";
    NSLog(@"%@",item.image_url);
    //cell.ItemImageView=[RFInternetImageView imageViewWithImage:[RFOImage imageWithURL:item.image_url]];
    [cell.ItemImageView addImageScale:[RFOImage imageWithURL:item.image_url]];
    //cell.ItemImageView.image=[UIImage imageNamed:@"sh1.png"];
    
    return cell;
}

//- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
//{
//    return 200;
//}

//- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
//{
//
//}

/*
 // Override to support conditional editing of the table view.
 - (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
 {
 // Return NO if you do not want the specified item to be editable.
 return YES;
 }
 */

/*
 // Override to support editing the table view.
 - (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
 {
 if (editingStyle == UITableViewCellEditingStyleDelete) {
 // Delete the row from the data source
 [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
 }
 else if (editingStyle == UITableViewCellEditingStyleInsert) {
 // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
 }
 }
 */

/*
 // Override to support rearranging the table view.
 - (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
 {
 }
 */

/*
 // Override to support conditional rearranging of the table view.
 - (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
 {
 // Return NO if you do not want the item to be re-orderable.
 return YES;
 }
 */

/*
 #pragma mark - Navigation
 
 // In a story board-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
 {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 
 */








@end

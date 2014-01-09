//
//  ONShoppingListVC.m
//  ONeill
//
//  Created by Chaithra Kumar on 12/23/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONShoppingListVC.h"
#import "ONeillAppDelegate.h"
#import "ONCartCustomCell.h"
#import "ONCoreDataManager.h"
#import "Cartitem.h"
#import "ONShoppingDetailsVC.h"

@interface ONShoppingListVC ()

@end

@implementation ONShoppingListVC

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title=@"Shopping Cart";
     self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"" style:UIBarButtonItemStylePlain target:nil action:nil];
//    UIBarButtonItem *editButton=[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemEdit target:self action:@selector(editTable)];
//    self.navigationItem.rightBarButtonItem=editButton;
//    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
     self.navigationItem.rightBarButtonItem = self.editButtonItem;
}



-(void)viewWillAppear:(BOOL)animated
{
    
    ONCoreDataManager *mgr=[ONCoreDataManager sharedManager];
    self.cartArray=[[mgr getShoppingList] mutableCopy];
    
    [self.tableView reloadData];
    
    
    
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
   
    Cartitem *item =[self.cartArray objectAtIndex:indexPath.row];
    cell.ItemZtitleLabel.text=item.name;
    cell.ItemPrice.text=item.final_price;
    cell.ItemColor.text=item.color;
    cell.ItemQuantity.text=item.quantity;
    cell.ItemSize.text=item.size;
    //cell.ItemQuantity.text=@"1";
    //NSLog(@"%@",item.image_url);
    //cell.ItemImageView=[RFInternetImageView imageViewWithImage:[RFOImage imageWithURL:item.image_url]];
    [cell.ItemImageView addImageScale:[RFOImage imageWithURL:item.url]];
    //cell.ItemImageView.image=[UIImage imageNamed:@"sh1.png"];
    
    return cell;
}


- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 170;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{

    UIView *footerView=[[UIView alloc] initWithFrame:CGRectMake(0, 0, 320, 170)];
    footerView.backgroundColor=[UIColor lightGrayColor];
    [self addFooterlabels:footerView];
    
    return  footerView;
    
}

-(void)addFooterlabels:(UIView *)footerView
{
    UILabel *staticSubtotal=[[UILabel alloc] initWithFrame:CGRectMake(5, 20,100, 15)];
    staticSubtotal.font=[UIFont systemFontOfSize:14];
    staticSubtotal.text=@"SUBTOTAL:";
    [footerView addSubview:staticSubtotal];
    
    UILabel *staticDiscounts=[[UILabel alloc] initWithFrame:CGRectMake(5,40,100, 15)];
    staticDiscounts.text=@"DISCOUNTS:";
    staticDiscounts.font=[UIFont systemFontOfSize:14];
    [footerView addSubview:staticDiscounts];

    UILabel *staticShipping=[[UILabel alloc] initWithFrame:CGRectMake(5, 60,100, 15)];
    staticShipping.text=@"SHIPPING:";
    staticShipping.font=[UIFont systemFontOfSize:14];
    [footerView addSubview:staticShipping];


    UILabel *staticTax=[[UILabel alloc] initWithFrame:CGRectMake(5,80,150, 15)];
    staticTax.text=@"ESTIMATED TAX:";
    staticTax.font=[UIFont systemFontOfSize:14];
    [footerView addSubview:staticTax];


    UILabel *staticTotal=[[UILabel alloc] initWithFrame:CGRectMake(5,100,150, 15)];
    staticTotal.text=@"GRAND TOTAL:";
    staticTotal.font=[UIFont systemFontOfSize:16];
    [footerView addSubview:staticTotal];
    
    
    self.cartTotalPricelabel=[[UILabel alloc] initWithFrame:CGRectMake(235, 20,80, 15)];
    self.cartTotalPricelabel.font=[UIFont systemFontOfSize:14];
    self.cartTotalPricelabel.textAlignment=NSTextAlignmentRight;
    self.cartTotalPricelabel.text=@"$0.00";
    [footerView addSubview:self.cartTotalPricelabel];
    
    self.cartDiscountsLabel=[[UILabel alloc] initWithFrame:CGRectMake(235,40,80, 15)];
    self.cartDiscountsLabel.font=[UIFont systemFontOfSize:14];
    self.cartDiscountsLabel.textAlignment=NSTextAlignmentRight;
    self.cartDiscountsLabel.text=@"$0.00";
    [footerView addSubview:self.cartDiscountsLabel];

    self.cartShippingPriceLabel=[[UILabel alloc] initWithFrame:CGRectMake(235,60,80, 15)];
    self.cartShippingPriceLabel.font=[UIFont systemFontOfSize:14];
    self.cartShippingPriceLabel.textAlignment=NSTextAlignmentRight;
    self.cartShippingPriceLabel.text=@"$0.00";
    [footerView addSubview:self.cartShippingPriceLabel];

    self.cartTaxPricelabel=[[UILabel alloc] initWithFrame:CGRectMake(235,80,80, 15)];
    self.cartTaxPricelabel.font=[UIFont systemFontOfSize:14];
    self.cartTaxPricelabel.textAlignment=NSTextAlignmentRight;
    self.cartTaxPricelabel.text=@"$0.00";
    [footerView addSubview:self.cartTaxPricelabel];

    self.cartFinalPriceLabel=[[UILabel alloc] initWithFrame:CGRectMake(235,100,80, 15)];
    self.cartFinalPriceLabel.font=[UIFont systemFontOfSize:16];
    self.cartFinalPriceLabel.textAlignment=NSTextAlignmentRight;
    self.cartFinalPriceLabel.text=@"$0.00";
    [footerView addSubview:self.cartFinalPriceLabel];

    
    UIButton *checkoutBtn=[[UIButton alloc] init];
    [checkoutBtn addTarget:self action:@selector(checkoutItem:) forControlEvents:UIControlEventTouchUpInside];
    checkoutBtn.frame=CGRectMake(50, 124, 200, 40);
    //checkoutBtn.backgroundColor=[UIColor redColor];
    [checkoutBtn setTitle:@"CHECKOUT" forState:UIControlStateNormal];
    
    checkoutBtn.titleLabel.textColor=[UIColor blackColor];
    //checkoutBtn.titleLabel.textColor=[UIColor blackColor];
    [footerView addSubview:checkoutBtn];
    

    
    
}

//checkout event handling..
-(void)checkoutItem:(id)sender
{
    
}


// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}



// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        Cartitem *item=[self.cartArray objectAtIndex:indexPath.row];
        [self.cartArray removeObjectAtIndex:indexPath.row];
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
        ONCoreDataManager *mgr=[ONCoreDataManager sharedManager];
        [mgr deleteItem:item];
        
         
        
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}


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


#pragma mark - Navigation

// In a story board-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    ONShoppingDetailsVC *detailsVC=[segue destinationViewController];
    NSIndexPath *indexpath = [self.tableView indexPathForSelectedRow];
    
    detailsVC.productitem=[self.cartArray objectAtIndex:indexpath.row];
    detailsVC.title=[[self.cartArray objectAtIndex:indexpath.row] name];
}

 

@end

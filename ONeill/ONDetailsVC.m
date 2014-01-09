//
//  ONDetailsVC.m
//  ONeill
//
//  Created by chaithra on 12/9/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONDetailsVC.h"
#import "RFCommon/RFInternetImageView.h"
#import <RFCommon/RFCommon.h>
#import "RFCommon/RFServer.h"
#import "ONSelectionListVC.h"
#import "ONPickerCell.h"
#import "ONeillAppDelegate.h"
#import "ONItemCell.h"
#import "RFCommon/RFActivityIndicator.h"
#import "ONReachabilityManager.h"
#import "ONCoreDataManager.h"

@interface ONDetailsVC ()

@end

@implementation ONDetailsVC

@synthesize productItem,skuStr,selectedIndexpath;

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
    
    [self getRecommendations:self.productItem.sku];
    self.title=self.productItem.name;
     self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"" style:UIBarButtonItemStylePlain target:nil action:nil];
    self.customCarousalView.type=iCarouselTypeCoverFlow2;
    //self.customCarousalView.frame=CGRectMake(8, 75, 294, 215);
    
    self.customCarousalView.dataSource=self;
    self.customCarousalView.delegate=self;
    self.bhScrollView.contentSize=CGSizeMake(320,670);
    self.pickerTableView.dataSource=self;
    self.pickerTableView.delegate=self;
    self.contentView.backgroundColor=[UIColor greenColor];
    if ([self.productItem.price isEqualToString:self.productItem.final_price]) {
        //self.productItem.price=@" ";
        self.oldPrice.text=@" ";
    }
    else{
        NSMutableAttributedString *attString=[[NSMutableAttributedString alloc]initWithString:self.productItem.price];
        [attString addAttribute:NSStrikethroughStyleAttributeName value:[NSNumber numberWithInt:1] range:NSMakeRange(0,[attString length])];
        //yourLabel.attributedText = attString;
        self.oldPrice.attributedText=attString;
        self.productItem.selectedColor=nil;
        self.productItem.selectedSize=nil;

    }
    
    self.priceLabel.text=self.productItem.final_price;
    self.descriptionTextView.text=self.productItem.description;
    self.collectionView.dataSource=self;
    self.collectionView.delegate=self;
    
    self.quantityStepper.minimumValue=1;
    self.quantityStepper.maximumValue=99;
    [self.quantityStepper addTarget:self action:@selector(stepperEvent:) forControlEvents:UIControlEventTouchUpInside];
    
    self.productItem.selectedQuantity=@"1";
    
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark stepper Event
-(void)stepperEvent:(id)sender
{
    UIStepper *stepper=(UIStepper *)sender;
   // self.quantityLabel.text;
    //int val=stepper.value;
    self.quantityLabel.text=[NSString stringWithFormat:@"%0.0f",stepper.value];
                             NSLog(@"%@",self.quantityLabel.text);
    self.productItem.selectedQuantity=[NSString stringWithFormat:@"%0.0f",stepper.value];
}


#pragma mark iCaroudal dataSource methods

- (NSUInteger)numberOfItemsInCarousel:(iCarousel *)carousel
{
    return [self.productItem.media_list count];
}
- (UIView *)carousel:(iCarousel *)carousel viewForItemAtIndex:(NSUInteger)index reusingView:(UIView *)view
{
    //view=[[UIImageView alloc] initWithImage:[UIImage imageNamed:[self.productItem.media_list objectAtIndex:index]]];
    //
    
        NSString *imageURl=[[self.productItem.media_list objectAtIndex:index] valueForKey:@"small_url"];
        view=[RFInternetImageView imageViewWithImage:[RFOImage imageWithURL:imageURl withWidth:294 withHeight:215]]; //WithURL:imageURl]];
        //[view setFrame:CGRectMake(0, 0, 294.0f, 264.0f)];
        view.contentMode = UIViewContentModeCenter;
        return view;
}

#pragma 
#pragma mark Table View datasoruce and delegates

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 2;
}

// Row display. Implementers should *always* try to reuse cells by setting each cell's reuseIdentifier and querying for available reusable cells with dequeueReusableCellWithIdentifier:
// Cell gets various attributes set automatically based on table (separators) and data source (accessory views, editing controls)

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ONPickerCell *cell = (ONPickerCell *)[tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    if (cell == nil) {
        cell = [[ONPickerCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"Cell"];
    }
    if (indexPath.row==0) {
        cell.PickerTitleLabel.text=@"PICK A COLOR";
        
    }
    else
    {
        cell.PickerTitleLabel.text=@"PICK A SIZE";
    }
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    self.selectedIndexpath=indexPath;
}


#pragma mark network call for recommendation

-(void)getRecommendations:(NSString *)sku
{
    
    if ([ONReachabilityManager isReachable] ) {
        //make service call to fetch similar items from service and push the details screen.
        RFServerRequest *req=[RFServerRequest requestForDelegate:self withCallback:@selector(recommendationsData:)];
        //NSLog(@"skuStr:%@",[[self.productsArray objectAtIndex:indexpath.row] valueForKey:@"sku"]);
        NSString *urlStr=[NSString stringWithFormat:@"http://localhost:6543/api/6378a73d707ccbdeaec56550c40ad8c3/recommendation/get.json?ckey=11111-43294971&pid=%@",sku];
        
        
        req.action=urlStr;
        req.isGET=YES;
        [req send];
        [RFActivityIndicator show];
    }
    else{
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"Sorry,No Network,Please try again later!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
    
    
    
   
    
}

-(void)recommendationsData:(RFServerRequest *)req
{
    
    if (req.data==nil) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!Unable to load data from server!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
    
    NSDictionary * jsonDict = [req dictionaryFromData];
    NSLog(@"reconnedation data:%@",jsonDict);
    self.listArray=[[[jsonDict objectForKey:@"recommendations"] objectForKey:@"similar"]  objectForKey:@"products"];
    [self.collectionView  reloadData];
    
}


#pragma
#pragma mark product details screen

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    
    NSIndexPath *indexpath = [self.pickerTableView indexPathForSelectedRow];
   
    ONSelectionListVC *sellistVC=[segue destinationViewController];
    NSMutableArray *optionsArr;
    if (indexpath.row==0) {
         optionsArr=self.productItem.stock_color;
        sellistVC.title=@"PICK A COLOR";
                    
    }
    else
    {
       optionsArr=self.productItem.stock_size;
        sellistVC.title=@"PICK A SIZE";
    }
   
    sellistVC.selectionList=[optionsArr copy];
    
}

- (IBAction)addToCart:(id)sender {
    
    if (self.productItem.selectedColor == nil) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"Please pick a color" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
    else if (self.productItem.selectedSize == nil){
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"Please pick a size" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
    
    ONCoreDataManager *mgr=[ONCoreDataManager sharedManager];
    [mgr addItemToCart:self.productItem];
    
//    ONeillAppDelegate *appDelegate=[[UIApplication sharedApplication] delegate];
//    [appDelegate.cartListArray addObject:self.productItem];
    [[self.navigationController tabBarController] setSelectedIndex:1];
    [self.navigationController popToRootViewControllerAnimated:YES];
    
}

-(IBAction)unwindingfromSelection:(UIStoryboardSegue *)segue
{
    ONSelectionListVC *sourceVC=segue.sourceViewController;
    ONPickerCell *lcell=(ONPickerCell *)[self.pickerTableView cellForRowAtIndexPath:self.selectedIndexpath];
    if (self.selectedIndexpath.row==0) {
        self.productItem.selectedColor=sourceVC.selectedString;
    }
    else{
        self.productItem.selectedSize=sourceVC.selectedString;
    }
    lcell.selectionLabel.text=sourceVC.selectedString;
    
}

-(void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    [self.bhScrollView layoutIfNeeded];
    //self.bhScrollView.contentSize=self.contentView.bounds.size;
}

#pragma mark CollectionView dataSoruce

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return [self.listArray count];
}

 //The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    ONItemCell *mycell=[collectionView dequeueReusableCellWithReuseIdentifier:@"collectionCell" forIndexPath:indexPath];
    //mycell.cellImageView.image=[UIImage imageNamed:@"sh1.png"];
    //[mycell.cellImageView addImageScale:[RFOImage imageWithURL:[itemDictionary valueForKey:@"image_url"]]];
    NSString *imgURL=[[self.listArray objectAtIndex:indexPath.row] valueForKey:@"image_url"];
    [mycell.imageView  addImageScale:[RFOImage imageWithURL:imgURL]];
    
    return mycell;
}

#pragma mark CollectionView Delegate Methods

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    NSDictionary *dict=[self.listArray objectAtIndex:indexPath.row];
    
    ONProductItem *clickedItem=[[ONProductItem alloc] initWithDictionary:dict];
    [self loadDetailsOfProduct:clickedItem];
    
}
//http://localhost:6543/search/request.json?ckey=11114-43294971&np=1&search_keyphrase=43410011&product_fields=description,media_list,stock_size,stock_color
-(void)loadDetailsOfProduct:(ONProductItem *)item
{
    
    if ([ONReachabilityManager isReachable]) {
        //make service call to fetch similar items from service and push the details screen.
        RFServerRequest *req=[RFServerRequest requestForDelegate:self withCallback:@selector(detailsResponse:)];
        //NSLog(@"skuStr:%@",[[self.productsArray objectAtIndex:indexpath.row] valueForKey:@"sku"]);
        NSString *urlStr=[NSString stringWithFormat:@"http://localhost:6543/search/request.json?ckey=11114-43294971&search_keyphrase=%@&product_fields=description,media_list,stock_size,stock_color",item.sku];
        req.action=urlStr;
        req.isGET=YES;
        [req send];

    }
    else{
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"Sorry,No Network,Please try again later!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
    
    
    
   
 
}

-(void)detailsResponse:(RFServerRequest *)req
{
    
    if (req.data==nil) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"OOPS!Unable to load data from server!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
    
    NSDictionary * jsonDict = [req dictionaryFromData];
    NSLog(@"%@",jsonDict);
    NSArray *dataArr=[jsonDict objectForKey:@"products"];
    ONProductItem *detailsItem=[[ONProductItem alloc] initWithDictionary:[dataArr objectAtIndex:0]];
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main_iPhone" bundle: nil];
    ONDetailsVC *dest = [storyboard instantiateViewControllerWithIdentifier:@"detailsScene"];
    dest.productItem=detailsItem;
    [self.navigationController pushViewController:dest animated:YES];

}


@end

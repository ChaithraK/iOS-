//
//  ONShoppingDetailsVC.m
//  ONeill
//
//  Created by Chaithra Kumar on 1/7/14.
//  Copyright (c) 2014 Chaithra Kumar. All rights reserved.
//

#import "ONShoppingDetailsVC.h"
#import "RFCommon/RFInternetImageView.h"
#import <RFCommon/RFCommon.h>
#import "RFCommon/RFServer.h"
#import "ONStaticCell.h"
#import "ONCoreDataManager.h"

@interface ONShoppingDetailsVC ()

@end

@implementation ONShoppingDetailsVC

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
    self.itemcarousal.type=iCarouselTypeCoverFlow2;
    self.unarchievedMediaList=[NSKeyedUnarchiver unarchiveObjectWithData:self.productitem.medialist];
    
    self.itemcarousal.dataSource=self;
    self.itemcarousal.delegate=self;
    self.staticTableView.dataSource=self;
    self.staticTableView.delegate=self;
    self.staticTableView.scrollEnabled=NO;
    self.quantityStepper.minimumValue=1;
    self.quantityStepper.maximumValue=99;
    [self.quantityStepper setValue:[self.productitem.quantity doubleValue]];
    self.quantitylabel.text=self.productitem.quantity;
    
    [self.quantityStepper addTarget:self action:@selector(stepperEvent:) forControlEvents:UIControlEventTouchUpInside];

    
    
    self.final_price.text=self.productitem.final_price;
    
    if ([self.productitem.price isEqualToString:self.productitem.final_price]) {
        //self.productItem.price=@" ";
        self.price.text=@" ";
    }
    else{
        NSMutableAttributedString *attString=[[NSMutableAttributedString alloc]initWithString:self.productitem.price];
        [attString addAttribute:NSStrikethroughStyleAttributeName value:[NSNumber numberWithInt:1] range:NSMakeRange(0,[attString length])];
        //yourLabel.attributedText = attString;
        self.price.attributedText=attString;
       
        
    }

   
	// Do any additional setup after loading the view.
}

#pragma mark stepper Event
-(void)stepperEvent:(id)sender
{
    UIStepper *stepper=(UIStepper *)sender;
    self.quantitylabel.text=[NSString stringWithFormat:@"%0.0f",stepper.value];
    self.productitem.quantity=[NSString stringWithFormat:@"%0.0f",stepper.value];
}


#pragma mark iCaroudal dataSource methods

- (NSUInteger)numberOfItemsInCarousel:(iCarousel *)carousel
{
    return [self.unarchievedMediaList count];
}
- (UIView *)carousel:(iCarousel *)carousel viewForItemAtIndex:(NSUInteger)index reusingView:(UIView *)view
{
    //view=[[UIImageView alloc] initWithImage:[UIImage imageNamed:[self.productItem.media_list objectAtIndex:index]]];
    //
    
    NSString *imageURl=[[self.unarchievedMediaList objectAtIndex:index] valueForKey:@"small_url"];
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
    ONStaticCell *cell = (ONStaticCell *)[tableView dequeueReusableCellWithIdentifier:@"scell" forIndexPath:indexPath];
    if (cell == nil) {
        cell = [[ONStaticCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"scell"];
    }
    if (indexPath.row==0) {
        cell.staticTitle.text=@"PICK A COLOR";
        cell.valueLabel.text=self.productitem.color;
        
    }
    else
    {
        cell.staticTitle.text=@"PICK A SIZE";
        cell.valueLabel.text=self.productitem.size;
    }
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    //self.selectedIndexpath=indexPath;
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)removeItem:(id)sender {
    
    //access core data and delete item and pop and reload the table.
    ONCoreDataManager *mgr=[ONCoreDataManager sharedManager];
    [mgr deleteItem:self.productitem];
    [self.navigationController popToRootViewControllerAnimated:YES];

    
    
}
@end

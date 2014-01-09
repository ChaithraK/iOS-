//
//  ONCartVC.m
//  ONeill
//
//  Created by Chaithra Kumar on 11/22/13.
//  Copyright (c) 2013 Chaithra Kumar. All rights reserved.
//

#import "ONSearchVC.h"
#import "ONProductsListVC.h"
#import "ONeillAppDelegate.h"




@interface ONSearchVC ()

@end

@implementation ONSearchVC

@synthesize listArray,titleString;

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
    self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"" style:UIBarButtonItemStylePlain target:nil action:nil];
    self.automaticallyAdjustsScrollViewInsets=YES;
//    if ([listArray count]==0) {
//        listArray=[[NSMutableArray alloc] initWithObjects:@"Board Shorts",@"Freak Series",@"Hybrid Shorts",@"Shirts",@"T-Shirts",@"Hoodies",@"jackets",@"Jack ONeill",@"Tank Tops",@"Jeans-Pants",@"O'Neill Collab Series",@"PBR X O'Neill",nil];
//    }
    
    

    // Uncomment the following line to preserve selection between presentations.
     self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)viewWillAppear:(BOOL)animated
{
    
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

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return self.titleString;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    
    if (tableView == self.searchDisplayController.searchResultsTableView) {
        return [searchResults count];
        
    } else {
        return [listArray count];
        
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"listCell";
    [self.searchDisplayController.searchResultsTableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"listCell"];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    
    
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    
    if (tableView == self.searchDisplayController.searchResultsTableView) {
        cell.textLabel.text = [[searchResults objectAtIndex:indexPath.row] valueForKey:@"name"];
    } else {
        cell.textLabel.text = [[listArray objectAtIndex:indexPath.row] valueForKey:@"name"];
    }
    cell.accessoryType=UITableViewCellAccessoryDisclosureIndicator;
    
    return cell;
}

- (void)filterContentForSearchText:(NSString*)searchText scope:(NSString*)scope
{
    NSPredicate *resultPredicate = [NSPredicate
                                    predicateWithFormat:@"name  contains[cd] %@",
                                    searchText];
    
    searchResults = [listArray filteredArrayUsingPredicate:resultPredicate];
}



-(BOOL)searchDisplayController:(UISearchDisplayController *)controller
shouldReloadTableForSearchString:(NSString *)searchString
{
    [self filterContentForSearchText:searchString
                               scope:[[self.searchDisplayController.searchBar scopeButtonTitles]
                                      objectAtIndex:[self.searchDisplayController.searchBar
                                                     selectedScopeButtonIndex]]];
    
    return YES;
}

- (NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;
{
    NSString *idStr=[[self.listArray objectAtIndex:indexPath.row] valueForKey:@"id"];
    tempArray=[self getChildrenForCategory:[idStr integerValue]];
    if ([tempArray count]>0) {
        shouldNavigateHierarchy=YES;
        //self.listArray=[listarr mutableCopy];
    }
    else{
        shouldNavigateHierarchy=NO;
        destTitle=[[self.listArray objectAtIndex:indexPath.row] valueForKey:@"name"];
    }
    return indexPath;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{

    if (!shouldNavigateHierarchy) {
        
    }
    else{
        //Instantiating a new controller using StoryBoarding..:-).. using same scene for navigating multiple category hierarchies.Happy programming!!
            //NSArray *listarr=[self getChildrenForCategory:[self.listArray objectAtIndex:indexPath.row]];
            UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main_iPhone" bundle: nil];
            ONSearchVC *dest = [storyboard instantiateViewControllerWithIdentifier:@"searchVC"];
            dest.listArray=[tempArray mutableCopy];
            dest.titleString=[[self.listArray objectAtIndex:indexPath.row] valueForKey:@"name"];
            [self.navigationController pushViewController:dest animated:YES];

    }
}



-(BOOL)shouldPerformSegueWithIdentifier:(NSString *)identifier sender:(id)sender
{
    
    if (shouldNavigateHierarchy) {
        return NO;
    }
    else{
        return YES;
    }
}

-(NSMutableArray *)getChildrenForCategory:(NSInteger)cat_id
{
//    NSMutableArray *mylistArray;
//    if (istoggle) {
//        mylistArray=[[NSMutableArray alloc] initWithObjects:@"Board Shorts",@"Collab Series",@"PBR X O'Neill",nil];
//        
//        istoggle=FALSE;
//    }
//    else{
//        istoggle=TRUE;
//    }
    ONeillAppDelegate *appDelegate=[[UIApplication sharedApplication] delegate];
    NSMutableArray *masterlist=appDelegate.categoryMasterlist;
    NSPredicate *menspredicate=[NSPredicate predicateWithFormat:@"parent_id == %ld",cat_id];
    //NSLog(@"predicate:%@",menspredicate);
    NSMutableArray *lfilteredArr=[[masterlist filteredArrayUsingPredicate:menspredicate] mutableCopy];
    //asg(@"Filtered arr for %ld:%@",(long)cat_id,lfilteredArr);
    return lfilteredArr;
    

    
    
    
}


-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"listing"]) {
        
        ONProductsListVC *listVC=[segue destinationViewController];
        listVC.title= destTitle;
        listVC.titleString= destTitle;
        
        
    }
}

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

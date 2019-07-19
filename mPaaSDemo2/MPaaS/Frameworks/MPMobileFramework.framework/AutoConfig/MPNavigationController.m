//
//  MPNavigationController.m

#import "MPNavigationController.h"

@interface MPNavigationController()

@end

@implementation MPNavigationController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"主页";
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Test" style:UIBarButtonItemStylePlain target:self action:@selector(btnClick)];
}

- (void)btnClick
{
    NSLog(@"Click");
}

@end
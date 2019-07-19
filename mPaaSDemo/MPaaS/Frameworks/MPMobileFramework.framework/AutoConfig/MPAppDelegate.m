//
//  MPAppDelegate.m

#import "MPAppDelegate.h"
#import "MPViewController.h"

@interface MPAppDelegate ()

@property (nonatomic, strong) UIViewController* rootController;
@property (nonatomic, strong) MPViewController* controller;

@end

@implementation MPAppDelegate

- (id)init
{
    self = [super init];
    if (self)
    {        
        _controller = [[MPViewController alloc] init];
        self.rootController = self.controller;
    }
    return self;
}


- (UIViewController *)rootControllerInApplication:(DTMicroApplication *)application
{
    return self.rootController;
}

- (void)application:(DTMicroApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    
}

- (void)application:(DTMicroApplication *)application willResumeWithOptions:(NSDictionary *)launchOptions
{

}

@end

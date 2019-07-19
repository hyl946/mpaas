//
//  MPDrawerLauncherAppDelegate.m

#import "MPNavigationLauncherAppDelegate.h"
#import "MPNavigationController.h"

@interface MPNavigationLauncherAppDelegate ()

@property (nonatomic, strong) UIViewController* rootController;
@property (nonatomic, strong) MPNavigationController* controller;

@end

@implementation MPNavigationLauncherAppDelegate

- (id)init
{
    self = [super init];
    if (self)
    {        
        _controller = [[MPNavigationController alloc] init];
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

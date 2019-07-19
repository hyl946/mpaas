//
//  MPDrawerLauncherAppDelegate.m

#import "MPDrawerLauncherAppDelegate.h"
#import "MPDrawerController.h"

@interface MPDrawerLauncherAppDelegate ()

@property (nonatomic, strong) UIViewController* rootController;
@property (nonatomic, strong) MPDrawerController* drawerController;

@end

@implementation MPDrawerLauncherAppDelegate

- (id)init
{
    self = [super init];
    if (self)
    {        
        _drawerController = [[MPDrawerController alloc] init];
        self.rootController = self.drawerController;
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

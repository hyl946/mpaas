//
//  MPAppDelegate.h

#import <Foundation/Foundation.h>

@interface MPAppDelegate : NSObject <DTMicroApplicationDelegate>

- (UIViewController *)rootControllerInApplication:(DTMicroApplication *)application;

@end

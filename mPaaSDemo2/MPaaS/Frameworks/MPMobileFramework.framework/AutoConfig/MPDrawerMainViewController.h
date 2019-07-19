//
//  MPDrawerMainViewController.h

#import <UIKit/UIKit.h>

@class MPDrawerMainViewController;

@protocol MPDrawerMainViewControllerDelegate <NSObject>

@optional

- (void)mainViewControllerDidClickTheLeftButton:(MPDrawerMainViewController *)mainViewController withButton:(UIButton *)btn;
- (void)mainViewController:(MPDrawerMainViewController *)mainViewController didPan:(UIPanGestureRecognizer *)pan;

@end

@interface MPDrawerMainViewController : DTViewController

@property (nonatomic,weak)id<MPDrawerMainViewControllerDelegate>delegate;

@end
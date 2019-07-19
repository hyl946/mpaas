//
//  MPDrawerLeftView.h

#import <UIKit/UIKit.h>

@interface MPDrawerLeftView : UIView

@property (strong) UIView* userBackgroundView;
@property (strong) UIImageView* userImageView;
@property (strong) UILabel* userNameLabel;

@property (strong) UIScrollView* buttonScrollView;
@property (strong) UIButton* userInfoButton;
@property (strong) UIButton* userCenterButton;

@end
//
//  ASAlertView.h
//
//
//  Created by yl on 16/3/12.
//  Copyright (c) 2016年 yl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ASAlertButtonItem.h"

@class ASAlertView;
typedef void(^ASAlertViewHandler)(ASAlertView *alertView);
@interface ASAlertView : UIView

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) UIView *contentView;
@property (nonatomic, strong)UIImage *headerImage;

@property (nonatomic, copy) ASAlertViewHandler willShowHandler;
@property (nonatomic, copy) ASAlertViewHandler didShowHandler;
@property (nonatomic, copy) ASAlertViewHandler willDismissHandler;
@property (nonatomic, copy) ASAlertViewHandler didDismissHandler;

@property (nonatomic, readonly, getter = isVisible) BOOL visible;

@property (nonatomic, strong) UIColor *viewBackgroundColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *titleColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *titleFont NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *buttonFont NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *cancelButtonColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *cancelButtonFont NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default [UIFont boldSystemFontOfSize:18.]
@property (nonatomic, strong) UIColor *customButtonColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *customButtonFont NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default [UIFont systemFontOfSize:18.]
@property (nonatomic, assign) CGFloat cornerRadius NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default is 8.0
@property (nonatomic, assign) CGFloat shadowRadius NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default is 8.0

@property (nonatomic, assign) CGFloat scrollViewPadding;
@property (nonatomic, assign) CGFloat buttonHeight;
@property (nonatomic, assign) CGFloat containerWidth;
@property (nonatomic, assign) CGFloat vericalPadding;
@property (nonatomic, assign) CGFloat contentScrollViewMaxHeight;
@property (nonatomic, assign) CGFloat contentScrollViewMinHeight;
@property (nonatomic, assign) CGFloat bottomScrollViewHeight;
@property (nonatomic, assign) BOOL showButtonLine;
@property (nonatomic, assign) BOOL showBlurBackground;
// Create
- (id)initWithTitle:(NSString *)title
            message:(NSString *)message
              image:(UIImage *)header;
- (id)initWithTitle:(NSString *)title
        contentView:(UIView *)contentView
              image:(UIImage *)header;
// Buttons
- (void)addButtonWithTitle:(NSString *)title type:(ASAlertViewButtonType)type handler:(ASAlertButtonHandler)handler;
- (void)setDefaultButtonImage:(UIImage *)defaultButtonImage forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (void)setCancelButtonImage:(UIImage *)cancelButtonImage forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (void)setCustomButtonImage:(UIImage *)customButtonImage forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
// AlertView action
- (void)show;
- (void)dismiss;
// Operation
- (void)cleanAllPenddingAlert;
@end

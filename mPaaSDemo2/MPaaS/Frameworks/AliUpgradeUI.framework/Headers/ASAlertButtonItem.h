//
//  ASAlertButtonItem.h
//
//
//  Created by yl on 16/3/12.
//  Copyright (c) 2016年 yl. All rights reserved.
//


#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ASAlertViewButtonType) {
    ASAlertViewButtonTypeDefault = 0,
    ASAlertViewButtonTypeCustom = 1,
    ASAlertViewButtonTypeCancel = 2
};

@class ASAlertView;
@class ASAlertButtonItem;
typedef void(^ASAlertButtonHandler)(ASAlertView *alertView, ASAlertButtonItem *button);

@interface ASAlertButtonItem : UIButton


@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) ASAlertViewButtonType type;
@property (nonatomic, copy) ASAlertButtonHandler action;
@property (nonatomic) BOOL defaultRightLineVisible;

@end

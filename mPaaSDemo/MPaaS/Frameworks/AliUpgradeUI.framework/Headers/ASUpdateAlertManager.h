//
//  ASUpdateAlertManager.h
//  AccountSecurity
//
//  Created by ouxi on 16/3/14.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASAlertView.h"

typedef void(^ASAlertViewClickBlock)(int btnIndex, ASAlertView *alertView);

@interface ASUpdateAlertManager : NSObject

@property(nonatomic, strong, readonly)ASAlertView *currentAlert;

+ (instancetype)sharedInstance;

- (BOOL)alertVisible;

- (void)hiddenAlert;

- (void)showUpgradeAlertWithTitle:(NSString *)targetVersion
                           header:(UIImage *)headerImage
                          message:(NSString *)updateMessage
                cancelButtonTitle:(NSString *)cancelButtonTitle
                  sureButtonTitle:(NSString *)sureButtonTitle
                       onClickBtn:(ASAlertViewClickBlock)btnIndex;



@end

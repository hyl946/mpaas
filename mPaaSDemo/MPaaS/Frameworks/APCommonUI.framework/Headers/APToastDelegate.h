//
//  APToastDelegate.h
//  CommonUI
//
//  Created by  songdh on 14-1-6.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol APToastDelegate <NSObject>

/**
 * 得到当前toast显示文本
 *
 * @param text:当前toast展示的文本
 *
 */
- (void)queryToastText:(NSString*)text;

/**
 * toast显示时调用此方法
 */
- (void)toastAppear;

/**
 * toast消失时调用此方法
 */
- (void)toastDissAppear;
@end

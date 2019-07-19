//
//  APBarButtonItem.h
//  APCommonUI
//
//  Created by WenBi on 13-12-8.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APVisualStyle;

/**
 *  A bar button item is a button used for a <code>UIToolBar</code> or <code>APNavigationBar</code.
 */
@interface APBarButtonItem : UIBarButtonItem

@property(nonatomic, strong) APVisualStyle *visualStyle;
@property(nonatomic, strong) NSString *backButtonTitle; // 返回按钮title
@property(nonatomic, strong) UIImage *backButtonImage;  // 返回按钮图片
@property(nonatomic, strong) UIColor *titleColor;       // 返回按钮文本颜色

/**
 *  设置按钮间的间距
 *
 *  @return 返回UIBarButtonSystemItemFlexibleSpace风格的空按钮
 */
+ (APBarButtonItem *)flexibleSpaceItem;

/**
 *  创建默认的返回按钮样式
 *
 *  @param title   显示文本
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return APBarButtonItem
 */
+ (APBarButtonItem *)backBarButtonItemWithTitle:(NSString *)title target:(id)target action:(SEL)action;

/**
 *  创建默认的返回按钮样式
 *
 *  @param title   显示文本
 *  @param count   最大显示文字数
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return APBarButtonItem
 */
+ (APBarButtonItem *)backBarButtonItemWithTitle:(NSString *)title maxWordsCount:(NSInteger)count target:(id)target action:(SEL)action;

@end

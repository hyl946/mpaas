//
//  APMenuItem.h
//  APScrollPadDemo
//
//  Created by NianXi on 15/4/27.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APMenuItem : UIView

@property (nonatomic, weak) UIButton *button;
@property (nonatomic, weak) UILabel *label;

/**
 *  分享面板上Item的init方法
 *
 *  @param icon    图标
 *  @param title   标题
 *
 *  @return APMenuItem
 */
- (instancetype)initWithIcon:(UIImage *)icon
                       title:(NSString *)title;

@end

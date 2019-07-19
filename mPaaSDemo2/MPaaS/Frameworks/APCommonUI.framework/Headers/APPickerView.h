//
//  ALPPicketView.h
//  TestCell
//
//  Created by zhiyuan.yzy on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APPickerView;

@protocol APPickerDelegate <UIPickerViewDataSource, UIPickerViewDelegate>

/*
 * 点取消息时回调
 */
- (void)cancelPickerView:(APPickerView *)pickerView;

/*
 * 点完成时回调，选中项可通过pickerView selectedRowInComponent返回
 */
- (void)selectedPickerView:(APPickerView *)pickerView;

@end

@interface APPickerView : UIView

@property(nonatomic, strong) UIPickerView *pickerView;

@property(nonatomic, weak) id<APPickerDelegate> delegate;

/*
 * 创建组件
 *
 * @param title 标题，可为nil
 * @return 创建的组件，默认不显示，需调用show
 */
+ (APPickerView *)pickerViewWithTitle:(NSString *)title;

/*
 * 初始化对象
 *
 * @param frame 显示位置
 * @param title 显示标题，不显示可设nil
 * @return 默认返回对象不显示，要显示需要调show
 */
- (id)initWithFrame:(CGRect)frame withTitle:(NSString *)title;

/*
 * 显示
 */
- (void)show;

/*
 * 隐藏
 */
- (void)hide;

/**
 * 重载数据
 */
- (void)reload;

@end

//
//  APNumericKeyboard.h
//  2014117
//
//  Created by yang.zy on 14-1-22.
//  Copyright (c) 2014年 yang.zy. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, APNumericKeyboardMode) {
    APNumericKeyboardModeCommon,  //通用键盘
    APNumericKeyboardModeChat,    //聊天键盘
    APNumericKeyboardModeInvalid  //无效键盘，目前不可用
};

@interface APNumericKeyboard : UIView

/**
 *  创建键盘组件，默认为通用键盘
 *
 *  @return 初始化的键盘组件
 */
+ (APNumericKeyboard *)sharedKeyboard;

/**
 *  创建键盘组件
 *
 *  @param mode 键盘模式
 *
 *  @return 初始化的键盘组件
 */
+ (APNumericKeyboard *)sharedKeyboardWithMode:(APNumericKeyboardMode)mode;

/**
 *  手动设置textinput，外部需要设置keyboard的y轴
 */
@property (nonatomic, weak) id<UITextInput> textInput;

/**
 *  身份证x
 */
@property (nonatomic, assign) BOOL idNumber;

/**
 *  设置键盘模式
 */
@property (nonatomic, assign, readonly) APNumericKeyboardMode mode;

/**
 *  小数点，是否隐藏
 */
@property (nonatomic, assign) BOOL dotHidden;

/**
 *  是否收起键盘
 */
@property (nonatomic, assign) BOOL dismissHidden;

/**
 *  提交按钮是否可点
 */
@property (nonatomic, assign) BOOL submitEnable;

/**
 *  提交按钮文案
 *  注意：根据视觉要求，此文案最多显示三个汉字，国际化时请注意英文文案长度
 */
@property (nonatomic, strong) NSString *submitText;

@end

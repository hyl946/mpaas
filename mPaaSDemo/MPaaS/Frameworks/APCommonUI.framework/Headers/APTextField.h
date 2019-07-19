//
//  APTextField.h
//  APCommonUI
//
//  Created by WenBi on 13-10-27.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
@class APTextFieldDelegateProxy;

@class APTextValidator;

typedef NS_ENUM(NSInteger, APTextFieldStyle) {
    APTextFieldStylePlain,
    APTextFieldStyleBordered,
};

typedef NS_ENUM(NSInteger, APKeyboardType) {
    APKeyboardTypeIDCard = 100,
};

/**
 *  输入框控件
 *
 */
@interface APTextField : UITextField

// 验证器、原始文本
@property(nonatomic, strong) APTextValidator *validator;
@property(nonatomic, strong) NSString        *normalizedText;
// 用于显示身份证‘X’的键
@property(nonatomic, strong) UIButton        *buttonX;
@property (nonatomic, assign) BOOL           keyboardTypeIDCard;
@property(nonatomic, strong) APTextFieldDelegateProxy *delegateProxy;

#pragma mark - APTextField静态方法

/**
 *  创建输入框组件
 *  @param style 文本框样式
 *  @param originY 输入框的y坐标
 *  @return 返回输入框组件
 */
+ (APTextField *)textFieldWithStyle:(APTextFieldStyle)style originY:(CGFloat)originY;

/**
 *  Initializes and returns an newly created text field object with the height of 43.0.
 *
 *  @return An initialized text field object.
 */
- (id)init;

#pragma mark - APTextField实例方法

/**
 * 检查输入的有效性
 * @return 返回验证结果
 */
- (BOOL)checkInputValidity;

/**
 * 格式化文本
 * @return 返回格式化后的文本
 */
- (NSString *)formatText:(NSString *)text;


/**
 * 格式化之前的原始文本
 * @param textField 文本框
 * @return 返回格式化之前的文本
 */
- (NSString *)getOriginTextWithFormatText:(NSString *)formatText;



@end

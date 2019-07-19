//
//  APInputBox.h
//  APCommonUI
//
//  Created by yang.zy on 14-1-17.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
@class APTextField;
@class APButton;
@class APVisualStyle;
@class UITextField;
@class UIButton;


typedef NS_ENUM(NSInteger, APInputBoxType)
{
    APInputBoxTypeMobileNumber,     // 手机号码
    APInputBoxTypeCreditCard,       // 信用卡
    APInputBoxTypeBankCard,         // 借记卡
    APInputBoxTypeAmount,           // 金额
    APInputBoxTypeIDNumber,         // 身份证
    APInputBoxTypeNotEmpty,         // 非空
    APInputBoxTypeAlipayAccount,    // 支付宝账号
    APInputBoxTypeNone              // 不校验
};

typedef enum APInputBoxStyle
{
    APInputBoxStyleNone, // 没有背景图片
    APInputBoxStyleiOS6, // 圆角的背景图片
    APInputBoxStyleiOS7  // 非圆角的背景图片
} APInputBoxStyle;



@interface APInputBox : UIView

#pragma mark - APInputBox属性

// 文本输入框
@property(strong, nonatomic)   APTextField      *textField;
@property(strong, nonatomic)   NSString         *textFieldText;
@property(strong, nonatomic)   NSString         *textFieldFormat;
@property(assign, nonatomic)   CGFloat          horizontalMargin;
@property(assign, nonatomic)   CGFloat          textFieldHorizontalMargin;


// 按钮
@property(strong, nonatomic)   UIButton         *iconButton;
@property(assign, nonatomic)   BOOL             hidesButtonWhileNotEmpty;
@property(assign, nonatomic)   BOOL             hidesButton;


// 显示在输入框左边的lable
@property(nonatomic, readonly) UILabel          *titleLabel;
@property(nonatomic, assign)   CGFloat          titleLabelWidth;


// 样式、验证器、背景图、文本框类型
@property(assign, nonatomic)   APInputBoxStyle  style;
@property(readonly, nonatomic) UIImageView      *backgroundImage;
@property(assign, nonatomic)   APInputBoxType   inputBoxType;


#pragma mark - APInputBox静态方法
/**
 *  创建输入框组件
 *  @param  originY 输入框的y坐标
 *  @param  type 文本输入框的类型
 *  @return 输入框组件
 */
+ (APInputBox *)inputboxWithOriginY:(CGFloat)originY
                       inputboxType:(APInputBoxType)type;

/**
 *  创建带图标按钮的输入框组件
 *  @param  originY 输入框的y坐标
 *  @param  icon 按钮上的图标，44x44
 *  @param  type 文本输入框的类型
 *  @return 带按钮的输入框组件
 */
+ (APInputBox *)inputboxWithOriginY:(CGFloat)originY
                         buttonIcon:(UIImage *)icon
                       inputboxType:(APInputBoxType)type;

/**
 *  @return 控件高度,默认值44，iPhone6 plus 为47
 */
+ (float)heightOfControl;


#pragma mark - APInputBox实例方法

- (id)initWithFrame:(CGRect)frame inputboxType:(APInputBoxType)type;

- (void)buildIconButton:(UIImage *)icon;



/**
 *  按照指定格式对文本添加空格
 *  @param  文本内容
 *  @return 添加空格后的文本
 */
- (NSString *)formatText:(NSString *)text;

/**
 *  对于没有在初始化时指定icon的inputBox, 可以使用此方法添加
 *  @param icon 按钮上的图标
 *
 */
- (void)setRightButtonIcon:(UIImage *)icon;


/**
 * 检查输入的有效性.
 */
- (BOOL)checkInputValidity;




/**
 * 过滤文本，只可输入数字，限定最大长度
 * 参数为相应delegate参数，maxLength为最大长度
 */
- (BOOL)shouldChangeRange:(NSRange)range
        replacementString:(NSString *)string
            withMaxLength:(int)maxLength;

/**
 * 限定最大长度
 * @maxLength 最大长度，不包括format的空格
 */
- (BOOL)shouldChangeRange:(NSRange)range
        replacementString:(NSString *)string
withFormatStringMaxLength:(int)maxLength;







@end

//
//  APFloatView.h
//  APCommonUI
//
//  Created by 去疾 on 15/12/21.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum : NSUInteger {
    APCommonUIFloatStylePushSettinigTipRedEnvelop,       //红色主题“抢红包”样式
    APCommonUIFloatStylePushSettinigTipMessage,          //蓝色主题“新消息”样式
} APCommonUIFloatStyle;


typedef void(^APFloatViewCompletionBlock)(void);


/**
 *  类似APLimitView，但不能复用，目前参考其实现
 *
 */
@interface APFloatView : UIView

/**
 *  主图片
 */
@property(nonatomic, strong) UIImageView *imageView;

/**
 *  主文案
 */
@property(nonatomic, strong) UILabel *titleLabel;

/**
 *  副文案
 */
@property(nonatomic, strong) UILabel *detailTitleLabel;

/**
 *  底部事件按钮。无关闭按钮时，默认文案为“确定”
 */
@property(nonatomic, strong) UIButton *actionButton;

/**
 *  确认按钮(actionButton)点击的回调
 */
@property (nonatomic, copy) APFloatViewCompletionBlock actionButtonBlock;

/**
 *  关闭按钮(“x”)点击的回调
 */
@property (nonatomic, copy) APFloatViewCompletionBlock closeButtonBlock;

/**
 *  判断当前界面是否有弹框显示，若返回YES，表明界面上已显示限流弹框,初始化方法控件不生效
 *
 *  @return 展示中返回YES，否则返回NO
 */
+ (BOOL)isShowing;

/**
 *  展示浮层提示框
 *
 *  @param superview   父view
 *  @param title       主文案，只能显示一行
 *  @param detailTitle 副文案，最多显示两行
 *
 *  @return 初始化后的APSettingTipFloatView控件
 */
+ (APFloatView *)showInSuperview:(UIView *)superview title:(NSString *)title detailTitle:(NSString *)detailTitle andStyle:(APCommonUIFloatStyle)style;

/**
 *  展示浮层提示框，直接在keyWindow中展示
 *
 *  @param title       主文案，只能显示一行
 *  @param detailTitle 副文案，最多显示两行
 *
 *  @return 初始化后的APSettingTipFloatView控件
 */
+ (APFloatView *)showInWindowWithTitle:(NSString *)title detailTitle:(NSString *)detailTitle andStyle:(APCommonUIFloatStyle)style;

/**
 *  消除当前显示的浮层提示
 */
+ (void)dismiss;

#pragma mark 回调方法
/**
 *  设置点击底部按钮时执行的block
 *  @param block  执行的block
 */
- (void)setActionButtonDidClickBlock:(void (^)(void))block;

/**
 *  设置点击右上角关闭按钮时执行的block
 *
 *  @param block 执行的block
 */
- (void)setCloseButtonDidDissmissBlock:(void (^)(void))block;


/**
 *  获取当前使用的float view对象
 *
 *  @return APFloatView实例对象
 */
 
+ (APFloatView *)sharedInstance;


@end

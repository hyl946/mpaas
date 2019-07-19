//
//  APToastView.h
//  CommonUI
//
//  Created by  tudou on 13-4-12.
//  Copyright (c) 2013年  tudou. All rights reserved.
//

#import <UIKit/UIKit.h>

#define APToast_Default_Duration 2.0    // APToast默认展示时间
#define APToast_Strong_Duration 1.5     // APToast强提示展示时长
#define APToast_Weak_Duration 1.0       // APToast弱提示展示时长

// log输出函数声明，由外部设置
typedef void(*apuiExternLogFuncType)(NSString *tag, NSString *format, ...);
extern apuiExternLogFuncType g_apuiExternLogFunc;
#define APUI_EXLOG(fmt, ...) {if(g_apuiExternLogFunc)g_apuiExternLogFunc(@"@APUI",fmt,##__VA_ARGS__);}


/**
 *  添加新的toastIcon时，请向后添加，不要在中间插入，否则业务使用会有问题
 */
typedef enum{
    APToastIconNone = 0,    // 无图标
    APToastIconSuccess,     // 成功图标
    APToastIconFailure,     // 失败图标
    APToastIconLoading,     // 加载图标
    APToastIconNetFailure,  // 网络失败
    APToastIconSecurityScan,// 安全扫描
    APToastIconNetError,    // 网络错误，完全无法连接
    APToastIconProgress,    // 加载图标，显示加载进度
    APToastIconAlert,       // 警示图标
} APToastIcon;

/**
 * Toast
 */
@interface APToastView : UIView

@property (nonatomic, assign) CGFloat xOffset; // 设置相对父视图中心位置X坐标方向的偏移量
@property (nonatomic, assign) CGFloat yOffset; // 设置相对父视图中心位置Y坐标方向的偏移量

/**
 * 首页卡券页面弹得特殊样式toast。
 */
- (void)setSocialTipToastStyle;

/**
 * 设置一个tag串，紧挨着presentToastView时打到log里，用来标识这个ToastView是哪弹的。
 */
+ (void)setLogTag:(NSString*)logTag;


#pragma mark - 带tag的版本，tag串会打到log文件里，用来标识这个ToastView是哪弹的。业务尽量使用这组方法，方便出问题时定位哪里弹的toast。

+ (APToastView *)presentTagToastWithin:(UIView *)superview
                              withIcon:(APToastIcon)icon
                                  text:(NSString *)text
                              duration:(NSTimeInterval)duration
                                logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                             logTag:(NSString*)logTag;
/**
 *  不推荐。 为使带tag的方法接口名保持一致，请使用 presentTagToastWithin 初始化，之后此方法会废弃。
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                             logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithin:(UIView *)superview text:(NSString *)text logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithText:(NSString *)text logTag:(NSString*)logTag;
+ (APToastView *)presentModelTagToastWithin:(UIView *)superview text:(NSString *)text logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                                logTag:(NSString*)logTag
                         completion:(void (^)())completion;
+ (APToastView *)presentTagToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                              delay:(NSTimeInterval)delay
                                logTag:(NSString*)logTag
                         completion:(void (^)())completion;
+ (APToastView *)presentModalTagToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                                     logTag:(NSString*)logTag
                              completion:(void (^)())completion;
+ (APToastView *)presentModalTagToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                                   delay:(NSTimeInterval)delay
                                     logTag:(NSString*)logTag
                              completion:(void (^)())completion;

#pragma mark - 没有带tag的老版本


/**
 * 显示Toast
 *
 * @param superview 父视图
 * @param icon      图标类型
 * @param text      显示文本
 * @param duration  显示时长
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration;

/**
 * 显示Toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param icon      图标类型
 * @param text      显示文本
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text;

/**
 * 显示Toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param text      显示文本
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview text:(NSString *)text;

/*
 * 模态显示提示，此时屏幕不响应用户操作，需调用dismissToast方法使Toast消失
 *
 * @param text 显示文本，默认为loading加载
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithText:(NSString *)text;

/*
 * 模态toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param text      显示文本
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentModelToastWithin:(UIView *)superview text:(NSString *)text;

/*
 * 使toast消失
 */
- (void)dismissToast;

/**
 *  设置进度的前缀文本，如果不设置，默认为“加载数据”
 *
 *  @param prefix 文本
 */
- (void) setProgressPrefix:(NSString*)prefix;

/**
 * 显示当前加载数据的进度百分比
 *
 * @param value      当前已加载的数据，范围为<0.0，1.0>
 *
 */
- (void) setProgressText:(float)value;


/**
 * 显示Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                         completion:(void (^)())completion;

/**
 * 显示Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param delay         延迟显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                              delay:(NSTimeInterval)delay
                         completion:(void (^)())completion;

/**
 * 显示模态Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentModalToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                              completion:(void (^)())completion;


/**
 * 显示模态Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param delay         延迟显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentModalToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                                   delay:(NSTimeInterval)delay
                              completion:(void (^)())completion;

@end

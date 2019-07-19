//
//  DTBaseViewController.h
//  Alipay Mobile Common
//
//  Created by WenBi on 13-3-30.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DTNavigationBarAppearanceProtocol.h"

@class DTMicroApplication;

typedef NS_ENUM(NSUInteger, kViewAppearStateType) {
    kViewAppearStateTypeNone = 0,
    kViewAppearStateTypeWillAppear,
    kViewAppearStateTypeDidAppear,
    kViewAppearStateTypeDidLoad
};

/**
 * 所有业务应用的视图控制器的基类。
 */
@interface DTBaseViewController : UIViewController <UIGestureRecognizerDelegate, DTNavigationBarAppearanceProtocol>

/** 获取当前 view controller 所在的 app 对象。 */
@property(nonatomic, assign, readonly) DTMicroApplication *application;

@property (nonatomic, assign) BOOL isMiddlePage;
@property (nonatomic, assign) BOOL multiLayer;
@property (nonatomic, strong) UIImage *preControllerImage;

@property (nonatomic, assign) kViewAppearStateType viewAppearState;
@property (nonatomic, assign) BOOL is3DTouchLaunch; // 标示是3DTouch启动VC

/**
 * Pops the receive from the navigation controller.
 */
- (void)back;

/**
 *  执行RPC，去掉主线程参与
 *  区别：该方法和callAsyncBlock的区别是completion保持子线程回调。
 *  目的：减少默认的主线程抢占导致的UI性能问题，从而数据处理等默认都在子线程;
 *       只有在有必要的UI处理时，业务主动调用框架API（如：APTMainCall）切换到主线程。
 *  建议：业务使用该方法，callAsyncBlock将逐步废弃。
 *
 *  @param block      执行block
 *  @param completion 结束block
 *
 *  @return
 */
- (id)callNoMainThreadAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;
/**
 *  执行RPC，completion会在主线程回调
 *
 *  @return 如果没有RPC模块，这个接口是不会执行的，返回nil。
 */
- (id)callAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;
- (void)stopAllAsyncBlock;

/**
 *  返回页面的类名
 */
- (NSString *)pageID;

/**
 * Called just before release the controller's view from memory.
 *
 * Regardless of clicking back button or popping gesture, this method is 
 * always reachable.
 */
- (void)viewWillDestroy;

/**
 * 展示title边上的小菊花，注意：要在viewDidAppear里或者之后才显示。
 * 注意：标题字数少于5个使用
 */
- (void)startTitleLoading;

/**
 * 消失title边上的小菊花
 * 注意：标题字数少于5个使用
 */
- (void)stopTitleLoading;

/**
 * 显示navigationbar返回按钮title
 *
 * 注意：
 * 1、默认显示规则：二级页面显示一级页面的title；二级以上页面显示“返回”
 * 2、不使用默认显示规则，可以重写该方法
 *
 */
- (void)displayBackButtonTitle;

/**
 *  显示navigationbar返回按钮默认文案
 *  注意：
 *  默认显示规则：二级页面显示一级页面的title；二级以上页面显示“返回”；
 *  最好在viewWillAppear之后调用；
 *
 *  @return 返回按钮默认文案
 */
- (NSString *)backButtonDefaultTitle;

/**
 *  是否在viewWillDisappear里自动清除所有APActionSheet控件。
 *  注意：默认是返回YES，如果不想自动清除，就重写该方法返回NO。
 *
 *  @return 自动清除返回YES，否则返回NO。
 */
- (BOOL)autoDismissAPActionSheets;

/**
 * 清除主窗口（window）中所有的弹出框（UIAlertView）。
 * 这个清除操作，并不会导致弹出框委拖的调用，也就是说，使用该方法清除弹出框，弹出框的委拖接收不到任何回调。
 */
+ (void)dismissAlertViews;

/**
 *  App语言设置修改时调用该方法. 子类在语言设置改变时需要做更新布局、更新资源文件等, 实现此方法.
 *
 *  @param info 语言设置修改时的附加信息.内容格式为 @{APLanguageSettingInfoOldKey:@"en",APLanguageSettingInfoNewKey:@"zh-Hans"};
 *
 */
- (void)languageSettingDidChange:(NSDictionary *)info   NS_REQUIRES_SUPER ;

@end

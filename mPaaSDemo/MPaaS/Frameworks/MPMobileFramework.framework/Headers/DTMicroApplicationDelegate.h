//
//  DTMicroApplication.h
//  Alipay Mobile Runtime Framework
//
//  Created by WenBi on 13-3-30.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class DTMicroApplication;

@protocol DTMicroApplicationDelegate <NSObject>

@required

/**
 * 请求应用对象的代理返回根视图控制器。
 *
 * @param application 应用对象。
 *
 * @return 应用的根视图控制器。
 */
- (UIViewController *)rootControllerInApplication:(DTMicroApplication *)application;

@optional

/**
 * 通知应用代理，应用对象已经对经被实例化。
 *
 * @param application 应用对象。
 */
- (void)applicationDidCreate:(DTMicroApplication *)application;

/**
 * 通知应用代理，应用将要启动。
 *
 * @param application 启动的应用对象。
 * @param options 应用运行参数。
 */
- (void)application:(DTMicroApplication *)application willStartLaunchingWithOptions:(NSDictionary *)options;

/**
 * 通知应用代理，应用已启动。
 *
 * @param application 启动的应用对象。
 */
- (void)applicationDidFinishLaunching:(DTMicroApplication *)application;

/**
 * 通知应用代理，应用即将暂停进入后台运行。
 *
 * @param application 启动的应用对象。
 */
- (void)applicationWillPause:(DTMicroApplication *)application;

/**
 * 通知应用代理，应用将被重新激活。
 *
 * @param application 要激活的应用对象。
 */
- (void)application:(DTMicroApplication *)application willResumeWithOptions:(NSDictionary *)options;

/**
 * 通知应用代理，应用已经被激活。
 *
 * @param application 要激活的应用对象。
 */
- (void)applicationDidResume:(DTMicroApplication *)application;

/**
 * 通知应用代理，应用已经被激活。
 *
 * @param application 要激活的应用对象，带上参数的版本。
 */
- (void)application:(DTMicroApplication *)application didResumeWithOptions:(NSDictionary *)options;

/**
 * 通知应用的代理，应用将要退出。
 *
 * @param application 应用对象。
 */
- (void)applicationWillTerminate:(DTMicroApplication *)application;

/**
 * 通知应用的代理，应用将要退出。
 *
 * @param application 应用对象。
 * @param animated 是否以动画方式退出。
 */
- (void)applicationWillTerminate:(DTMicroApplication *)application animated:(BOOL)animated;

/**
 * 询问应用的代理，应用是否可以启动。
 * 注意：只用特殊情况返回：NO，要保证默认是YES才可以启动的。
 *
 * @param application 应用对象。
 * @param params      启动参数。
 * @param launchMode  启动方式。
 *
 * @return 是否可以启动
 */
- (BOOL)applicationShouldStart:(DTMicroApplication *)application params:(NSDictionary *)params aunchMode:(DTMicroApplicationLaunchMode) launchMode;

/**
 *  询问应用的代理是否要启动多个应用对象。
 *  注意：默认是NO标识不支持；业务可以通过参数params，sourceId，栈顶App等来决定是否返回YES；
 *
 *  @param params     启动参数。
 *  @param launchMode 启动方式。
 *  @param sourceId   启动来源。
 *
 *  @return 返回YES创建一个新的App对象，否则不创建新app对象。
 */
- (BOOL)applicationShouldStartMultapplication:(NSDictionary *)params launchMode:(DTMicroApplicationLaunchMode) launchMode sourceId:(NSString *)sourceId;

/**
 * 询问应用的代理，应用是否可以退出
 * 注意：只用特殊情况返回：NO，要保证默认是YES才可以退出的。
 *
 * @param application 应用对象。
 *
 * @return 是否可以退出
 */
- (BOOL)applicationShouldTerminate:(DTMicroApplication *)application;

/**
 * 询问应用的代理，是否以无动画启动rootViewController
 * 注意：如果返回YES，则屏蔽startApplication的动画设置
 *
 * @param application 应用对象。
 *
 * @return YES：无动画启动；NO：默认处理方式
 */
- (BOOL)applicationStartRootControllerWithNoAnimation:(DTMicroApplication *)application;

/**
 *  通知应用代理，收到通知消息。
 *
 *  @param application 应用对象。
 *  @param userInfo    封装消息信息。
 *  @param completion  执行完成的block回调。
 */
- (void)application:(DTMicroApplication *)application didReceviceMessage:(NSDictionary *)userInfo completion:(void(^)(NSDictionary *result))completion;

/**
 * 通知应用的代理，应用将以Present方式启动viewController
 *
 * @param application 应用对象。
 * @param params      启动参数。
 * @param navigationController 导航控制器。
 *
 * @return 无
 */
- (void)applicationShouldPresent:(DTMicroApplication *)application params:(NSDictionary *)params navigationController:(UINavigationController *)navigationController;

/**
 * 通知应用的代理，应用已经Present方式启动viewController完成。
 *
 * @param application 应用对象。
 * @param params      启动参数。
 *
 * @return 无
 */
- (void)applicationDidPresent:(DTMicroApplication *)application params:(NSDictionary *)params;

/**
 *  返回应用的启动方式，通过该方法可以动态的修改app的启动方式。
 *
 *  @param application 应用对象。
 *  @param params      启动参数。
 *
 *  @return 返回应用的启动方式。
 */
- (DTMicroApplicationLaunchMode)applicationLaunchMode:(DTMicroApplication *)application params:(NSDictionary *)params;

@end
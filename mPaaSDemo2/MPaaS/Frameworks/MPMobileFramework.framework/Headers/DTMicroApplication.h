//
//  DTMicroApplication.h
//  Alipay Mobile Runtime Framework
//
//  Created by WenBi on 13-3-31.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTMicroApplicationLaunchMode.h"
#import "DTMicroApplicationDescriptor.h"

extern NSString * const kDTMicroApplicationDidCreateNotification;       // 应用创建完成通知。
extern NSString * const kDTMicroApplicationWillTerminateNotification;   // 应用将要退出通知。
extern NSString * const kDTMicroApplicationDoesNotFoundNotification;    // 应用找不到通知，对本地app是app代理类找不到所致。
extern NSString * const kDTMicroApplicationWillStartNotification;       // 应用将要启动通知。

@protocol DTMicroApplicationDelegate;
@class DTViewController;

@interface DTMicroApplication : NSObject

/**
 * 应用的描述信息，如：AppId对应descriptor.name。
 */
@property(nonatomic, strong) DTMicroApplicationDescriptor *descriptor;

/**
 * 当前 app 的代理。
 */
@property(nonatomic, strong) id <DTMicroApplicationDelegate> delegate;

/**
 *  当前 app 所属的所有 view controller.
 */
@property(nonatomic, strong) NSMutableArray *viewControllers;

/**
 *  应用类型。
 */
@property(nonatomic, strong) NSString *type;

/**
 * 启动 app 的源。
 */
@property(nonatomic, strong) NSString *sourceId;

/**
 * 这个 app 的运行模式。
 */
@property(nonatomic, assign) DTMicroApplicationLaunchMode launchMode;

/**
 * 如果当前的app栈是：A,B 那么当B在启动A时：
 * YES：默认值，会退出A上的所有App，结果：A；
 * NO： 不退出A上的App，而是退出自己，然后重新启动A，结果：B，A(注意：前后两个A不是同一个对象)；
 */
@property(nonatomic, assign) BOOL appClearTop;

/**
 * 获取当前应用的根控制器。
 *
 * @return 当前应用的根控制器对象，这个控制器<b>必须</b>是<code>DTViewController</code>的一个子类。
 */
- (UIViewController *)rootController;

/**
 * 退出本应用，应该不在栈顶，则无法退出。
 *
 * @param animated 指定退出应用时，是否需要动画。
 */
- (void)exitAnimated:(BOOL)animated;

/**
 * 退出本应用，无论应用是否在栈顶。
 * 注意：测试接口请勿直接使用。
 */
- (void)forceExit;

/**
 * 处理push消息。
 *
 * @param params push数据。
 *
 * @return 处理成功返回YES，否则NO。
 */
- (BOOL)handleRemoteNotifications:(NSDictionary *)params;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 *  返回当前栈顶应用。
 *
 *  @return 返回当前栈顶应用。
*/
DTMicroApplication * DTMicroApplicationGetCurrent();

#ifdef __cplusplus
}
#endif // __cplusplus
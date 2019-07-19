//
//  DFCrashReport.h
//  APMobileRuntime
//
//  Created by liangbao.llb on 12/30/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <mach/mach.h>

/**
 *  启动APCrashReporter服务
 */
void enable_crash_reporter_service (void);

@interface DFCrashReport : NSObject

/**
 *  上传crash日志
 */
+ (void)uploadCrashReport;

/**
 *  获取内存中所有的VC
 *
 *  @return 返回包含所有VC的字符串
 */
+ (NSString *) allAliveVc;

/**
 *  指定Crashed Thread生成闪退日志(base64)
 *
 *  @param tid 指定的Crashed线程id
 *
 *  @return 闪退日志
 */
+ (NSString *)generateMonitorLogWithThread:(thread_t) tid;

/**
 *  指定Crashed Thread生成全栈日志（明文）
 *
 *  @param tid 指定的Crashed线程id
 *
 *  @return 全栈日志
 */
+ (NSString *)generateReadableMonitorLogWithThread:(thread_t) tid;

/**
 *  上次程序退出是否闪退退出
 *
 *  @return BOOL型 YES表示上次程序发生闪退退出，否则反之
 */
+ (BOOL)isCrashedLastTime;

/**
 *  上次程序退出是否是启动闪退
 *
 *  @return BOOL型 YES表示上次程序退出是启动闪退，否则反之
 */
+ (BOOL)isCrashedLastTimeInBootup;
@end

//
//  DTApplication.h
//  MobileFramework
//
//  Created by WenBi on 13-11-29.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum UIApplicationLaunchFlag
{
    UIApplicationLaunchFlagNone,                    // 默认值
    UIApplicationLaunchFlagFromRemoteNotification,  // Push通知唤起
    UIApplicationLaunchFlagFromOpenURL,             // 外部URL唤起
} UIApplicationLaunchFlag;

@interface UIApplication (MobileFrameworkAddtions)

@property(nonatomic, strong) NSDictionary *launchOptions;           // App启动时的参数。
@property(nonatomic, strong) NSURL *lastOpenedURL;                  // 最近唤起App的URL。
@property(nonatomic, assign) BOOL launchingOpenURL;                 // OpenURL是来自应用冷启动。
@property(nonatomic, strong) NSDictionary *lastRemoteNotification;  // 最近的Push通知消息。
@property(nonatomic, strong) NSString *sourceId;                    // 渠道Id。
@property(nonatomic, assign) UIApplicationLaunchFlag launchFlag;    // 启动方式。
@property(nonatomic, strong) NSDate *appActiveTime; // 冷启动：finish launch time，后台启动：will enter foreground time;
@property(nonatomic, assign) BOOL bFirstInstalled;  // 标识是否是全新安装。
// 注意：1、这个值是比较版本的前三位结果，效时间是在新版本第一次启动到下一次冷启动。
//      2、其他情况可以用NSUserDefault来获取版本自己判断:
//         当前版本Key: @"kCurrentVersion"  （8.5.0添加的）
//         前一版本Key: @"kPreviousVersion" （8.5.0添加的）
@property(nonatomic, assign) BOOL bCoverInstallation;

@end

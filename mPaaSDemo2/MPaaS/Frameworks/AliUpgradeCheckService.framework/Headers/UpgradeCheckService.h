//
//  UpgradeCheckService.h
//  AliUpgradeCheckService
//
//  Created by ouxi on 16/9/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CheckUpdateNetwork.h"

typedef void(^CheckNewVersion)(BOOL hasNewVersion, MOBILEAPPCOMMONClientUpgradeRes *upgradeInfo);

@protocol UpgradeViewDelegate <NSObject>

/**
 * 获取升级弹框的头像
 */
- (UIImage *)upgradeViewHeader;

/**
 * 网络请求提示toast
 */
- (void)showToastViewWith:(NSString *)message duration:(NSTimeInterval)timeInterval;

/**
 * 网络请求展示HUD
 */
- (void)showProgressHUD:(BOOL)animation;

/**
 * 网络请求隐藏HUD
 */
- (void)hideProgressHUD:(BOOL)animation;

@end

@protocol UpgradeDataSourcedelegate <NSObject>



@end

@interface UpgradeCheckService : NSObject

@property (nonatomic, weak) id<UpgradeViewDelegate> delegate;

+ (instancetype)sharedService;

- (instancetype)initWithDelegate:(id<UpgradeViewDelegate>)delegate;

/**
 * 主动检查更新，异步发网络请求
 * 业务方有自定义UI需求时可调用
 */
- (void)checkUpgradeWith:(CheckUpgradeComplete)complete failure:(CheckUpgradeFailure)failure;

/**
 * 主动检查更新，使用 - (void)checkHasNewVersion:(CheckNewVersion)complete 检查过则直接使用缓存弹框，否则异步发网络请求
 * 检测到有更新后直接提示升级框，需要业务方实现  - (UIImage *)upgradeViewHeader传递定制的icon
 * Param:showProgress YES:需要业务方实现   - (void)showProgressHUD:(BOOL)animation
 */
- (void)checkUpgradeAndShowAlertWith:(BOOL)showProgress;

/**
 主动检查是否有更新，有新版本后使用 - (void)checkUpgradeAndShowAlertWith:(BOOL)showProgress方法提示

 @param complete YES：有新版本；NO：无更新
 */
- (void)checkHasNewVersion:(CheckNewVersion)complete;
@end

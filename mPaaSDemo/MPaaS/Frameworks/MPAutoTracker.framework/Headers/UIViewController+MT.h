//
//  UIViewController+Log.h
//  APMonitor
//
//  Created by tashigaofei on 15/5/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MTViewControllerTrackerProtocol <NSObject>

@optional
- (void)mt_viewDidLoad;
- (void)mt_viewWillAppear:(BOOL)animated;
- (void)mt_viewDidAppear:(BOOL)animated;
- (void)mt_viewWillDisappear:(BOOL)animated;

@end

@interface UIViewController (MT)

@property (nonatomic, strong) NSString *appId;
@property (nonatomic, strong) NSString *logPageId;
@property (nonatomic, strong) NSString *logPageTitle;
@property (nonatomic, strong) NSString *logSourceAppId;

//abtest标示
@property (atomic, strong) NSString *logABTestInfo;

//数据回流
@property (atomic, strong) NSString *logEntityId;

//spmId
@property (atomic, strong) NSString *logSpmId;

//埋点扩展参数
@property (atomic, strong) NSDictionary *logExtendParam;

@end

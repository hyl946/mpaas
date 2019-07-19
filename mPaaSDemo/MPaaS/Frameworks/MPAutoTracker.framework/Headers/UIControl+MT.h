//
//  UIControl+AddAPMonitor.h
//  APRemoteLogging
//
//  Created by zhiyuan.yzy on 14-2-12.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MTControlTrackerProtocol <NSObject>

@optional
- (void)touchUpInside:(UIControl *)sender;

@end


@interface UIControl (MT)

@property (nonatomic, strong) NSString *actionName;
@property (nonatomic, strong) NSDictionary *customLogInfo;
@property (nonatomic, strong) NSString *tabButtonId;
@property (nonatomic, strong) NSString *logSpmId;
@property (nonatomic, strong) NSDictionary *logExtendParam;
@property (nonatomic, strong) NSString *logEntityId;
@property (nonatomic, strong) NSString *senderAction;


@end

//
//  UITableViewCell+AddAPMonitor.h
//  APRemoteLogging
//
//  Created by zhiyuan.yzy on 14-2-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MTTableViewCellTrackerProtocol <NSObject>

@optional
- (void)mt_selected:(BOOL)selected;

@end

@interface UITableViewCell (MT)

@property (nonatomic, strong) NSString *actionName;
@property (nonatomic, strong) NSDictionary *customLogInfo;
@property (nonatomic, strong) NSString *logSpmId;
@property (nonatomic, strong) NSDictionary *logExtendParam;
@property (nonatomic, strong) NSString *logEntityId;

@end

//
//  UIGestureRecognizer+Log.h
//  APMonitor
//
//  Created by tashigaofei on 14-8-28.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MTGestureRecognizerTrackerProtocol <NSObject>

@optional
- (void)tap:(UIGestureRecognizer *)sender;

@end

@interface UIGestureRecognizer (MT)

@property (nonatomic, strong) NSString *actionName;
@property (nonatomic, strong) NSDictionary *customLogInfo;
@property (nonatomic, strong) NSString *logSpmId;
@property (nonatomic, strong) NSDictionary *logExtendParam;
@property (nonatomic, strong) NSString *logEntityId;
@property (nonatomic, strong) NSString *senderAction;

@end

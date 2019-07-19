//
//  APLogAdditions+mPaaSDemo.m
//  mPaaSDemo
//
//  Created by yangwei on 2017/01/11. All rights reserved.
//

#import "APLogAdditions+mPaaSDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation APLogAdditions (mPaaSDemo)

- (NSString*)logServerURL
{
    return @"http://116.62.88.108/loggw/logUpload.do";
}

- (NSArray*)defaultUploadLogTypes
{
    return @[@(APLogTypeBehavior), @(APLogTypeCrash), @(APLogTypeAuto), @(APLogTypeMonitor), @(APLogTypeKeyBizTrace), @(APLogTypePerformance)];
}

- (NSString *)platformID
{
    return @"1B10A2F110016_IOS-default";
}

- (NSString *)userID
{
    return [[MPaaSInterface sharedInstance] userId];
}

@end

#pragma clang diagnostic pop


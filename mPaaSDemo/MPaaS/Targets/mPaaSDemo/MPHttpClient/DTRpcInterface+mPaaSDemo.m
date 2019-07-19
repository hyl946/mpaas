//
//  DTRpcInterface+mPaaSDemo.m
//  mPaaSDemo
//
//  Created by yangwei on 2017/01/11. All rights reserved.
//

#import "DTRpcInterface+mPaaSDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTRpcInterface (mPaaSDemo)

- (NSString*)gatewayURL
{
    return @"http://116.62.87.66/mgw.htm";
}

- (NSString*)signKeyForRequest:(NSURLRequest*)request
{
    return @"1B10A2F110016_IOS";
}

- (NSString *)productId
{
    return @"1B10A2F110016";
}

- (NSString*)commonInterceptorClassName
{
    return @"DTRpcCommonInterceptor";
}

@end

#pragma clang diagnostic pop


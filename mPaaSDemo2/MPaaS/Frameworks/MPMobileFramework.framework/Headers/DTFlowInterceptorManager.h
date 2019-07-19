//
//  DTFlowInterceptorManager.h
//  Promotion
//
//  Created by feng.chenf on 14-2-22.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DTFlowInterceptor <NSObject>

@optional

- (BOOL)beforeFlow:(UIViewController *)originalTargetController animated:(BOOL)animated;

@end

@interface DTFlowInterceptorManager : NSObject

+ (DTFlowInterceptorManager *)defaultManager;

- (void)addInterceptor:(id<DTFlowInterceptor>)interceptor;

- (void)removeInterceptor:(id<DTFlowInterceptor>)interceptor;

- (BOOL)handleBeforeFlow:(UIViewController *)originalTargetController animated:(BOOL)animated;

@end

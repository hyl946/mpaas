//
//  DTAutoTestDelegate.h
//  MobileFramework
//
//  Created by yixuan on 13-7-16.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DTAutoTestDelegate <NSObject>

@required

- (id)initWithAutoTarget:(id)obj;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (void)dealloc;

@end

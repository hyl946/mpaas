//
//  APMenuPad.h
//  APScrollPadDemo
//
//  Created by NianXi on 15/4/27.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APMenuPad;
@protocol APMenuPadDataSource <NSObject>

@required
/**
 *  行数
 *
 *  @return NSUInteger型 行数
 */
- (NSUInteger)numberOfLines;

/**
 *  第 index 行需要显示的 APSKLaunchpadItem 数组
 *
 *  @param menuPad 当前的菜单面板
 *  @param index   行号从0开始
 *
 *  @return 对应的APSKLaunchpadItem数组
 */
- (NSArray *)menuPad:(APMenuPad *)menuPad itemsAtIndex:(NSInteger)index;


@optional
/**
 *  菜单面板标题
 *
 *  @param menuPad 当前菜单面板
 *
 *  @return 用于显示在面板顶部的标题字符串
 */
- (NSString *)titleForMenuPad:(APMenuPad *)menuPad;

@end


/**
 *  钱包内的通用菜单面板
 */
@interface APMenuPad : NSObject

@property (nonatomic, weak) id <APMenuPadDataSource> dataSource;
@property (nonatomic, readonly) BOOL isShowing;

- (void)reload;
- (void)show;
- (void)dismiss;
@end

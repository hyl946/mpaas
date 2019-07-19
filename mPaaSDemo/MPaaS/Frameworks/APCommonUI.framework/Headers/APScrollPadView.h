//
//  APScrollPadView.h
//  APScrollPadDemo
//
//  Created by NianXi on 15/4/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
@class APScrollPadView;

@protocol APScrollPadViewDataSource <NSObject>

- (NSUInteger)numberOfLines;

- (NSArray *)apScrollPadView:(APScrollPadView *)scrollPadView viewsAtIndex:(NSInteger)index;

@optional
- (NSString *)titleForAPScrollPadView:(APScrollPadView *)scrollPadView;

@end

@protocol APScrollPadViewDelegate <NSObject>

- (CGFloat)apScrollPadView:(APScrollPadView *)scrollPadView heightAtIndex:(NSInteger)index;
@optional
- (CGFloat)apScrollPadViewCancellButtonHeight;

@end

/**
 *  这是一个支持多行scrollView分别自定义高度的视图
 */
@interface APScrollPadView : UIView
@property (nonatomic, weak) id <APScrollPadViewDataSource> dataSource;
@property (nonatomic, weak) id <APScrollPadViewDelegate> delegate;
@property (nonatomic)UIEdgeInsets viewInsets;
@property (nonatomic) BOOL isNeedSizeToFit; // default NO;
@property (nonatomic) BOOL isShowing;

- (void)reload;
- (void)show;
- (void)dismiss;

@end

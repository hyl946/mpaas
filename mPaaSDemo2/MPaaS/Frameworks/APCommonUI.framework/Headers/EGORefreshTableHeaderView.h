//
//  EGORefreshTableHeaderView.h
//  Demo
//
//  Created by Devin Doty on 10/14/09October14.
//  Copyright 2009 enormego. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef enum {
    EGOPullingDown = 1000,
    EGOPullingUp
} EGOPullDirection;

typedef enum{
	EGOOPullRefreshPulling = 0,
	EGOOPullRefreshNormal,
	EGOOPullRefreshLoading,	
} EGOPullRefreshState;

@class APActivityIndicatorView;
@protocol EGORefreshTableHeaderDelegate;
@interface EGORefreshTableHeaderView : UIView {
	
	__weak id _delegate;
	EGOPullRefreshState _state;

	UILabel *_lastUpdatedLabel;
	UILabel *_statusLabel;
//    APActivityIndicatorView *_activityView;
    EGOPullDirection _pullDirection;
    
    BOOL    isAutoPullFlag;
}
@property(nonatomic, strong) APActivityIndicatorView *activityView;

/**
 *  上拉加载时，设置初始状态文案信息，默认为“上拉加载更多”，显示
 *
 *  @param isOpen
 *
 */
- (void)setPullUp:(NSString *)tip;

/**
 *  下拉刷新时，设置初始状态文案信息，默认为“下拉刷新”。不显示
 *
 *  @param tip
 *
 */
- (void)setPullDown:(NSString *)tip;

/**
 *  设置松手后loading过程中的文案信息，默认为“加载中”。  
 *  注意：默认下拉刷新时不显示，上拉加载时显示
 *
 *  @param isOpen
 *
 */
- (void)setLoading:(NSString *)tip;

/**
 *  提示用户可以放手的文案信息，默认为“释放即可刷新”
 *
 *  @param isOpen
 *
 */
- (void)setRelease:(NSString *)tip;

/**
 *  是否显示上次刷新信息的文案，默认不显示
 *
 *  @param isOpen
 *
 */
- (void)ShowLastPullDate:(BOOL)isOpen;

/**
 *  是否显示加载状态信息的文案。
 *  
 *  默认：下拉刷新时不显示，上拉加载时，显示文案“加载中”
 *
 *  @param isOpen
 *
 */
- (void)ShowStatusLabel:(BOOL)isShow;

- (void)setDateFormat:(NSDateFormatter *)dateFromatter;

- (void)setAutoPull:(BOOL)isAutoPull;

@property(nonatomic,weak) id <EGORefreshTableHeaderDelegate> delegate;

- (void)refreshLastUpdatedDate;
- (void)egoRefreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDidEndDragging:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDataSourceDidFinishedLoading:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDataSourceDidFinishedLoadingWithoutUpdate:(UIScrollView *)scrollView;

- (void)autoUpdateScrollView:(UIScrollView *)scrollView;

#pragma Mark -- for LegacySystem not recommend
@property(nonatomic,assign) EGOPullRefreshState state;
@property(nonatomic,retain) NSString *statusText;
@property (nonatomic, retain) UILabel *lastUpdatedLabel;
@property (nonatomic, retain) UILabel *statusLabel;

- (void)setCurrentDate;

@end

@protocol EGORefreshTableHeaderDelegate
- (void)egoRefreshTableHeaderDidTriggerRefresh:(EGORefreshTableHeaderView*)view;
- (BOOL)egoRefreshTableHeaderDataSourceIsLoading:(EGORefreshTableHeaderView*)view;
@optional
- (NSDate*)egoRefreshTableHeaderDataSourceLastUpdated:(EGORefreshTableHeaderView*)view;
@end

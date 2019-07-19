//
//  APActivityIndicatorView.h
//  APCommonUI
//
//  Created by yangwei on 16/4/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum{
    APActivityIndicatorViewStyleTitleBar,   //导航栏加载，  直径：36px，环宽：3px
    APActivityIndicatorViewStyleRefresh,    //列表刷新加载， 直径：48px，环宽：4px
    APActivityIndicatorViewStyleToast,      //toast加载    直径：72px，环宽：6px
    APActivityIndicatorViewStyleLoading,    //页面加载      直径：90px，环宽：6px
}APActivityIndicatorViewStyle;


@interface APActivityIndicatorView : UIView

@property (nonatomic, assign) BOOL    hidesWhenStopped;
@property (nonatomic, strong) UIColor *trackColor;         //圆环颜色
@property (nonatomic, strong) UIColor *progressColor;      //指示器颜色
@property (nonatomic, assign) float progressWidth;         //设置圆环的宽度，自定义圆圈大小时，默认为2
@property (nonatomic, assign) CGFloat progress;            //加载指示器的弧长与圆环的比值，默认为0.1

/**
 *  圆圈样式的loading框
 *  说明：如果不使用默认style，需要自定义圆圈的大小，请使用initWithFrame:初始化，此时圆环宽度默认为2，可设置progressWidth调整
 *
 *  @param style  当前loading类型。
 *
 */
- (instancetype)initWithActivityIndicatorStyle:(APActivityIndicatorViewStyle)style;

- (void)startAnimating;

- (void)stopAnimating;

- (BOOL)isAnimating;


@end

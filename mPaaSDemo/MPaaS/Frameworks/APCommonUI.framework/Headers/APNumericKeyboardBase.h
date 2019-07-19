//
//  APNumericKeyboardBase.h
//  APCommonUI
//
//  Created by majie on 14-11-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APNumericKeyboardPubDef.h"

@interface APNumericKeyboardBase : UIView
{
    @protected
    CGFloat _keyboardHeight;
    NSInteger _keyboardKeyCount;
    CGFloat _keyboardLeftPadding;
    CGFloat _keyboardTopPadding;
    CGFloat _numericButtonLayoutWidth;
    CGFloat _numericButtonLayoutHeight;

    @package
    // 键盘的输入目标
    __weak id<UITextInput> _input;
}

@property (nonatomic, strong) NSMutableArray *buttons;

//初始化数据成员
- (void)configurerMembers;
//构造所有按钮键
- (void)createButtons;
//释放所有观察者
- (void)free;
//设置键盘按钮需要enable
- (void)setButtonEnable:(bool)flag;


@end

//
//  APNumericKeyboardDef.h
//  APCommonUI
//
//  Created by majie on 14-11-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#ifndef APCommonUI_APNumericKeyboardDef_h
#define APCommonUI_APNumericKeyboardDef_h

typedef void(^APNumericKeyboardButtonPressBlock) ();
typedef void(^APNumericKeyboardButtonBlock) (UIView *sender, int keyCode);

typedef enum {
    APNumericKeyboardButtonNumber1         = 0,
    APNumericKeyboardButtonBackspace1,
    APNumericKeyboardButtonReturn1,
    APNumericKeyboardButtonDismiss1,
    APNumericKeyboardButtonBlank1,

    APNumericKeyboardButtonInvalid
    
} APNumericKeyboardButtonType;


typedef enum {
    APNumericKeyboardButtonKeyCode0         = '0',
    APNumericKeyboardButtonKeyCode1         = '1',
    APNumericKeyboardButtonKeyCode2         = '2',
    APNumericKeyboardButtonKeyCode3         = '3',
    APNumericKeyboardButtonKeyCode4         = '4',
    APNumericKeyboardButtonKeyCode5         = '5',
    APNumericKeyboardButtonKeyCode6         = '6',
    APNumericKeyboardButtonKeyCode7         = '7',
    APNumericKeyboardButtonKeyCode8         = '8',
    APNumericKeyboardButtonKeyCode9         = '9',
    APNumericKeyboardButtonKeyCodeRadix     = '.',
    APNumericKeyboardButtonKeyCodeX         = 'X',
    
    
    APNumericKeyboardButtonKeyCodeBackspace = 10,
    APNumericKeyboardButtonKeyCodeReturn    = 11,
    APNumericKeyboardButtonKeyCodeDismiss   = 12,
    APNumericKeyboardButtonKeyCodeBlank     = 13,

    APNumericKeyboardButtonKeyCodeInvalid   = -1

} APNumericKeyboardButtonKeyCodeType;



// 存储每个键盘按钮信息的结构
typedef struct {
    int keyCode;
    CGRect	frame;
    APNumericKeyboardButtonType keyType;
} APNumericKeyboardKeyExInfo;

#define DEVICE_IS_IPHONE4 ([[UIScreen mainScreen] bounds].size.height == 480)
#define DEVICE_IS_IPHONE5 ([[UIScreen mainScreen] bounds].size.height == 568)
#define DEVICE_IS_IPHONE6 ([[UIScreen mainScreen] bounds].size.height == 667)
#define DEVICE_IS_IPHONE6Pluc ([[UIScreen mainScreen] bounds].size.height == 736)

#define APNumericKeyboardLineSize() \
        if (DEVICE_IS_IPHONE6Pluc) {\
            return 1.1 / 3;         \
        }                           \
        return 1. / 2;              \

#endif

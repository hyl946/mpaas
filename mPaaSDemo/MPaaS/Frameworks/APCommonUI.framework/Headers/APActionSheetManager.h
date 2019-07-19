//
//  APAlertViewManager.h
//  TestView3
//
//  Created by sampan(渔真) on 13-9-29.
//  Copyright (c) 2013年 sampan. All rights reserved.
//

#import <Foundation/Foundation.h>
@class APActionSheet;
@interface APActionSheetManager : NSObject<UIActionSheetDelegate>
{
    
}
@property(nonatomic,assign)bool backGroundMode;//是否为后台模式


/**
 *  创建APActionSheetManager对象，用来管理屏幕上所有的actionSheet
 *
 *  @return 初始化的APActionSheetManager
 */
+ (APActionSheetManager *)sharedAPActionSheetManager;

/**
 *  删除所有的actionSheet
 */
-(void)dismissAllUIActionSheet;

/**
 *  显示actionSheet，若为后台模式，押入后台池保存；否则立即前台显示
 *
 *  @param actionSheet 需要显示的actionSheet
 */
-(void)addToShowedPool:(APActionSheet*)actionSheet;
@end

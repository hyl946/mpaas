//
//  CheckUpdateNetwork.h
//
//
//  Created by ouxi on 16/5/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOBILEAPPCOMMONClientUpgradeRes.h"

typedef void(^CheckUpgradeComplete)(MOBILEAPPCOMMONClientUpgradeRes *response);
typedef void(^CheckUpgradeFailure)(NSException *error);

@interface CheckUpdateNetwork : NSObject

+ (void)checkAppVersion:(CheckUpgradeComplete)completion
                failure:(CheckUpgradeFailure)failure;

@end

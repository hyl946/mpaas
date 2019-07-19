//
//  NSURL+ParamsAnalysis.h
//  MobileFoundation
//
//  Created by liangbao.llb on 16/3/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (ParamsAnalysis)

+ (NSString *)getURLDecodedString:(NSString *)string;

/**
 *  以字典格式返回URL中的参数
 *
 *  @return 参数字典
 */
- (NSDictionary *)extractUrlParams;

@end

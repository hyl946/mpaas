//
//  APTextValidator.h
//  APCommonUI
//
//  Created by wenbi on 14-1-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 文本有效性验证器。
 */
@interface APTextValidator : NSObject

/**
 *  Creates and returns a new validator that checks the validity of amount.
 *
 *  @return A newly created validator.
 */
+ (APTextValidator *)amountValidator;

/**
 *  Creates and returns a new validator used for checking the validity of mobile number.
 *
 *  @return A newly created validator.
 */
+ (APTextValidator *)mobileNumberValidator;

/**
 *  Creates and returns a new validator that checks the validity of bank card number.
 *
 *  @return A newly created validator.
 */
+ (APTextValidator *)bankCardValidator;

/**
 *  Creates and returns a new validator that checks the validity of cridit card number.
 *
 *  @return A newly created validator.
 */
+ (APTextValidator *)creditCardValidator;

/**
 *  Creates and returns a new validator that checks the validity of ID card.
 *
 *  @return A newly created validator.
 */
+ (APTextValidator *)IDCardValidator;

/**
 *  Creates and returns a new validator that checks the validity of alipay account.
 *
 *  @return A newly created validator.
 */
+ (APTextValidator *)alipayAccountValidator;

/**
 *  Checks the validity of specified text.
 *
 *  @param text The text to be check.
 *
 *  @return <code>YES</code if the specified text is valid, otherwise <code>NO</code>.
 */
- (BOOL)checkText:(NSString *)text;

@end


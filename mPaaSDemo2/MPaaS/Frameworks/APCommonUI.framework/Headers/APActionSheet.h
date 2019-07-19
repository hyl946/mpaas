//
//  APActionSheet.h
//  TestView3
//
//  Created by sampan(渔真) on 13-9-29.
//  Copyright (c) 2013年 sampan. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, APActionSheetButtonType) {
    APActionSheetButtonTypeDefault = 0,
    APActionSheetButtonTypeDisabled,
    APActionSheetButtonTypeDestructive,
    APActionSheetButtonTypeCustom
};


/// Used for storing button configuration.
@interface APActionSheetItem : NSObject
@property (copy, nonatomic) NSString *title;
//@property (strong, nonatomic) UIImage *image;
@property (nonatomic) APActionSheetButtonType type;
//if set titleColor，please change type to APActionSheetButtonTypeCustom
@property (strong,nonatomic) UIColor *titleColor;
@end

@interface APActionSheet : UIView<UIAppearanceContainer>

/// Height of the button (internally it's a `UITableViewCell`).
@property (nonatomic) CGFloat buttonHeight UI_APPEARANCE_SELECTOR;
/// Height of the cancel button.
@property (nonatomic) CGFloat cancelButtonHeight UI_APPEARANCE_SELECTOR;
/// Color of the separator between buttons.
@property (strong, nonatomic) UIColor *separatorColor UI_APPEARANCE_SELECTOR;
/// Background color of the button when it's tapped (internally it's a UITableViewCell)
@property (strong, nonatomic) UIColor *selectedBackgroundColor UI_APPEARANCE_SELECTOR;
/// Text attributes of the title (passed in initWithTitle: or set via `title` property)
@property (copy, nonatomic) NSDictionary *titleTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *buttonTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *disabledButtonTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *destructiveButtonTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *cancelButtonTextAttributes UI_APPEARANCE_SELECTOR;

/// Duration of the show/dismiss animations. Defaults to 0.5.
@property (nonatomic) NSTimeInterval animationDuration UI_APPEARANCE_SELECTOR;
/// Boxed boolean value. Enables/disables control hiding with pan gesture. Enabled by default.
@property (strong, nonatomic) NSNumber *cancelOnPanGestureEnabled UI_APPEARANCE_SELECTOR;


@property(nonatomic,copy) NSString *title;
@property(nonatomic, readonly, getter=isVisible) BOOL visible;//If YES, the receiver is displayed; otherwise, NO.
@property(nonatomic) UIActionSheetStyle actionSheetStyle;//fake
/// View to display above the buttons (only if the title isn't set).
@property (strong, nonatomic) UIView *headerView;
/// Window visible before the actionSheet was presented.
@property (weak, nonatomic, readonly) UIWindow *previousKeyWindow;

@property(nonatomic,weak)id<UIActionSheetDelegate>delegate;
@property(nonatomic,weak)id<UIActionSheetDelegate>dtDelegate;//fake, please use delegate

+(void)setIsBackGroundMode:(BOOL)isBackGroundMode;
+(void)weakSetIsBackGroundMode:(id)isBackGroundMode;


#pragma mark - UIActionSheet

- (instancetype)initWithTitle:(NSString *)title delegate:(id<UIActionSheetDelegate>)delegate cancelButtonTitle:(NSString *)cancelButtonTitle destructiveButtonTitle:(NSString *)destructiveButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

// adds a button with the title. returns the index (0 based) of where it was added. buttons are displayed in the order added except for the
// destructive and cancel button which will be positioned based on HI requirements. buttons cannot be customized.
- (NSInteger)addButtonWithTitle:(NSString *)title;    // returns index of button. 0 based.
@property (copy, nonatomic) NSString *cancelButtonTitle;
@property(nonatomic, readonly) NSInteger numberOfButtons;//The number of buttons on the action sheet. (read-only)

/**
 *  Adds a button without an image. Has to be called before showing the action sheet.
 *
 *  @param handler A completion handler block to execute when a dismissal animation (after the user tapped on the button) has finished.
 */
- (NSInteger)addButtonWithTitle:(NSString *)title type:(APActionSheetButtonType)type;
- (NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;
@property(nonatomic) NSInteger cancelButtonIndex;      // if the delegate does not implement -actionSheetCancel:, we pretend this button was clicked on. default is -1
@property(nonatomic) NSInteger destructiveButtonIndex;        // sets destructive (red) button. -1 means none set. default is -1. ignored if only one button

@property(nonatomic, readonly) NSInteger firstOtherButtonIndex;

/// Displays the action sheet.
- (void)show;

//show action sheet till close called;
- (void)showTillClose;
- (void)closeWithAnimate:(BOOL)animate;

// hides alert sheet or popup. use this method when you need to explicitly dismiss the alert.
// it does not need to be called if the user presses on a button
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

- (void)setButton:(APActionSheetItem *)item atIndex:(NSInteger)index;

/**
 *  动态添加item
 *  注意：请在actionSheet show出来后并显示在屏幕时调用；如需在show前addButton，请使用<code> addButtonWithTitle </code>
 *
 *  @param item  自定义item
 *  @param index 添加的位置
 */
- (void)addButton:(APActionSheetItem *)item atIndex:(NSInteger)index;

- (void)showFromToolbar:(UIToolbar *)view;
- (void)showFromTabBar:(UITabBar *)view;
- (void)showFromBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated NS_AVAILABLE_IOS(3_2);
- (void)showFromRect:(CGRect)rect inView:(UIView *)view animated:(BOOL)animated NS_AVAILABLE_IOS(3_2);
- (void)showInView:(UIView *)view;

@end

//
//  DemoViewController.m
//  test
//
//  Created by mPaaS on 16/11/21.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import "DemoViewController.h"

@interface DemoViewController ()<UpgradeViewDelegate>
@property (nonatomic, strong) APToastView *toast;
@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(130, self.view.bounds.size.height/2-20, self.view.bounds.size.width-60, 40)];
    label.text = @"Hello World!";
    label.font = [UIFont systemFontOfSize:30];
    label.textColor = [UIColor redColor];
    [self.view addSubview:label];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(30, 100, [UIScreen mainScreen].bounds.size.width-60, 44);
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"Create Crash" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(createCrash) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectOffset(button.frame, 0, 80);
    button2.backgroundColor = [UIColor blueColor];
    [button2 setTitle:@"检测升级" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(checkUpgrade) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeCustom];
    button3.frame = CGRectOffset(button2.frame, 0, 80);
    button3.backgroundColor = [UIColor blueColor];
    [button3 setTitle:@"用户报活" forState:UIControlStateNormal];
    [button3 addTarget:self action:@selector(reportActive) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)createCrash
{
    NSArray * array = @[@"Crash被Hotpatch热修复啦", @"Hello World"];
    NSString * str = [array objectAtIndex:0];
    NSLog(@"String value:%@", str);
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:str message:nil delegate:nil
                                          cancelButtonTitle:nil otherButtonTitles:@"ok", nil];
    [alert show];
}

- (void)checkUpgrade
{
    UpgradeCheckService *service = [UpgradeCheckService sharedService];
    service.delegate = self;
    [service checkUpgradeAndShowAlertWith:YES];
}

- (void)reportActive
{
    // 用户报活
    [APRemoteLogger writeLogWithActionId:KActionID_Event extParams:nil appId:@"" seed:@"login" ucId:@""];
}

#pragma mark 定制升级UI
- (UIImage *)upgradeViewHeader
{
    return [UIImage imageNamed:@"FinancialCloud"];
}

- (void)showProgressHUD:(BOOL)animation
{
    self.toast = [APToastView presentToastWithin:self.view withIcon:APToastIconLoading text:nil];
}
- (void)hideProgressHUD:(BOOL)animation
{
    [self.toast dismissToast];
}

- (void)showToastViewWith:(NSString *)message duration:(NSTimeInterval)timeInterval
{
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Information" message:message delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alertView show];
}

@end

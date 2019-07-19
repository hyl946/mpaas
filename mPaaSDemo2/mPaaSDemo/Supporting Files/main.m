//
//  main.m
//  mPaaSDemo
//
//  Created by shenmo on 7/20/15.
//  Copyright (c) 2015 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

int main(int argc, char * argv[]) {
    enable_crash_reporter_service(); // USE MPAAS CRASH REPORTER
    @autoreleasepool {
        
        //        return UIApplicationMain(argc, argv, nil, @"AppDelegate");
        return UIApplicationMain(argc, argv, @"DFApplication", @"DFClientDelegate"); // NOW USE MPAAS FRAMEWORK
    }
}

//
//  DYYCarwashWorker.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYWorker.h"
#import "DYYCar.h"

@implementation DYYWorker

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(DYYCar *)car {
    if (car) {
        car.clean = YES;
        NSLog(@"Worker reports - Car wash was completed");
        [self takeObjectMoneyAndReportTransaction:car];
    }
}

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object {
    [self washCar:(DYYCar *)object];
    NSLog(@"Worker money is %lu, car money is %lu", self.money, object.money);
}

@end

//
//  DYYCarwashWorker.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashWorker.h"
#import "DYYCar.h"

@implementation DYYCarwashWorker

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(DYYCar *)car {
    if (car) {
        [self setState:kDYYEmployeeBusy];
        [car payMoneyAmount:self.washPrice];
        car.isClean = YES;
        [self takeMoneyAmount:self.washPrice];
        [self setState:kDYYEmployeeStandby];
        NSLog(@"Worker reports - Car wash was completed");
        NSLog(@"Worker money is %lu, car money is %lu", self.money, car.money);
        [self checkQueueAndProcess];
        [self setState:kDYYEmployeeFree];
    }
}

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object {
    [self washCar:(DYYCar *)object];
}

@end

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
        self.employeeStatus = kDYYEmployeeBusy;
        [self notifyObserversWithSelector:@selector(itemIsBusy:) withObject:self];
        [car payMoneyAmount:self.washPrice];
        car.isClean = YES;
        [self takeMoneyAmount:self.washPrice];
        self.employeeStatus = kDYYEmployeeStandby;
        [self notifyObserversWithSelector:@selector(itemIsStandBy:) withObject:self];
//        sleep(2);
        [self notifyObserversWithSelector:@selector(itemIsFreeToWork:) withObject:self];
        self.employeeStatus = kDYYEmployeeFree;
        NSLog(@"Worker reports - Car wash was completed");
    }
}

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object {
    [self washCar:(DYYCar *)object];
}

@end

//
//  DYYCarwashAccountant.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYAccountant.h"
@class DYYWorker;

@implementation DYYAccountant

#pragma mark -
#pragma mark Public Methods

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object {
    @synchronized(self) {
        [self takeObjectMoneyAndReportTransaction:object];
        NSLog(@"Accountant money is %lu", self.money);
    }
}

- (void)employeeDidBecomeStandBy:(id)employee {
    [self performWorkWithObject:employee];
}

@end

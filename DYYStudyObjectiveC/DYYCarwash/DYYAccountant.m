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
    [self takeWorkerMoneyAndReport:(DYYWorker *)object];
}

- (void)takeWorkerMoneyAndReport:(DYYWorker *)worker {
    [self setState:kDYYEmployeeBusy];
    NSUInteger workerMoney = [worker money];
    [worker payMoneyAmount:workerMoney];
    [self takeMoneyAmount:workerMoney];
    NSLog(@"Money amount of %lu was transferred from worker to accountant", workerMoney);
    NSLog(@"Accountant money is %lu", self.money);
    [self checkQueueAndProcess];
    [self setState:kDYYEmployeeFree];
}

- (void)itemIsStandBy:(id)item  {
    [self addObjectToProcess:item];
}

@end

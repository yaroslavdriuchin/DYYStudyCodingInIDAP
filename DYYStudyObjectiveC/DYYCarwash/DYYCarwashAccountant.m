//
//  DYYCarwashAccountant.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashAccountant.h"
@class DYYCarwashWorker;

@implementation DYYCarwashAccountant

#pragma mark -
#pragma mark Public Methods

- (void)processObject:(id)object {
    [self takeWorkerMoneyAndReport:(DYYCarwashWorker *)object];
}

- (void)takeWorkerMoneyAndReport:(DYYCarwashWorker *)worker {
    self.employeeStatus = kDYYEmployeeBusy;
    [self notifyObserversWithSelector:@selector(itemIsBusy:) withObject:self];
    NSUInteger workerMoney = [worker money];
    [worker payMoneyAmount:workerMoney];
    [self takeMoneyAmount:workerMoney];
    self.employeeStatus = kDYYEmployeeFree;
    [self notifyObserversWithSelector:@selector(itemIsFreeToWork:) withObject:self];
    NSLog(@"Money amount of %lu was transferred from worker to accountant", workerMoney);
    NSLog(@"Accountant money is %lu", self.money);
}

- (void)itemIsStandBy:(id)item  {
    [self addObjectToProcess:item];
}

@end

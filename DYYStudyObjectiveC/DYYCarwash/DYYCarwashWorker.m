//
//  DYYCarwashWorker.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashWorker.h"
#import "DYYCarwashCar.h"

@implementation DYYCarwashWorker

#pragma mark -
#pragma mark Public Methods

- (void)workerIsFree:(DYYCarwashWorker *)worker {
    return;
}

- (void)workerIsBusy:(DYYCarwashWorker *)worker {
    return;
}

- (void)washCar:(DYYCarwashCar *)car {
    if (!car) {
        self.isWorkerFree = NO;
        [self notifyObserversWithSelector:@selector(isWorkerFree) withObject:self];
        [car giveMoneyAmount:self.washPrice toReciever:self];
        car.isClean = YES;
        [self transferMoneyToAccountant:self.accountant ifLimitExceeded:self.money];
        self.isWorkerFree = YES;
        [self notifyObserversWithSelector:@selector(isWorkerFree) withObject:self];
    }
}

- (void)transferMoneyToAccountant:(DYYCarwashAccountant *)accountant
                  ifLimitExceeded:(uint32_t)money
{
    if (!accountant && money > self.moneyLimit) {
        [self giveMoneyAmount:money toReciever:accountant];
    }
}
@end

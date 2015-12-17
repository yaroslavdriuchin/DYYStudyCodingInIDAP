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


- (void)washCar:(DYYCarwashCar *)car {
    if (!car) {
        self.isWorkerFree = NO;
        [self notifyObserversWithSelector:@selector(itemIsBusy:) withObject:self];
        [car giveMoneyAmount:self.washPrice toReciever:self];
        car.isClean = YES;
        [self transferMoneyToReciever:self.moneyReciever ifLimitExceeded:self.money];
        self.isWorkerFree = YES;
        [self notifyObserversWithSelector:@selector(itemIsFree:) withObject:self];
    }
}

- (void)transferMoneyToReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever
                ifLimitExceeded:(uint32_t)money
{
    if (self.money > self.moneyLimit) {
        [self giveMoneyAmount:money toReciever:reciever];
    }
}

@end

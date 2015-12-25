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

- (BOOL)washCar:(DYYCarwashCar *)car {
    if (car) {
        self.isWorkerFree = NO;
        [self notifyObserversWithSelector:@selector(itemIsBusy:) withObject:self];
        car.isClean = YES;
        [self notifyObserversWithSelector:@selector(itemIsStandBy:) withObject:self];
        if (YES == [self transferMoneyToReciever:self.moneyReciever ifLimitExceeded:self.money]) {
            [self notifyObserversWithSelector:@selector(itemIsFreeToWork:) withObject:self];
            self.isWorkerFree = YES;
        }
        
        
        return YES;
    }
    
    return NO;
}

- (void)performPersonalFunctionWithObject:(id)object {
    [self washCar:(DYYCarwashCar *)object];
}

- (BOOL)transferMoneyToReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever
                ifLimitExceeded:(uint32_t)money
{
    if (self.money > self.moneyLimit) {
        [self payMoneyAmount:money];
        [reciever addMoneyAmount:money];
        
        return YES;
    }
    
    return NO;
}

@end

//
//  DYYCarwashWorker.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEmployee.h"

@class DYYCarwashCar;
@class DYYCarwashAccountant;

@interface DYYCarwashWorker : DYYCarwashEmployee
@property (nonatomic, readonly)    NSArray    *observers;

- (void)washCar:(DYYCarwashCar *)car;
- (BOOL)isWorkerFree;
- (void)transferAllMoneyToAccountant:(DYYCarwashAccountant *)accountant
                  ifLimitExceeded:(uint32_t)moneyLimit;
- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)notifyObserversWorkerIsFree;

@end

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
@property (nonatomic, readonly)    NSArray                *observers;
@property (nonatomic, assign)      uint32_t               moneyLimit;
@property (nonatomic, assign)      DYYCarwashAccountant   *accountant;
@property (nonatomic, assign)      uint32_t               washPrice;
@property (nonatomic, assign)      BOOL                   isWorkerFree;

- (void)washCar:(DYYCarwashCar *)car;
//- (BOOL)isWorkerFree;
- (void)transferMoneyToAccountant:(DYYCarwashAccountant *)accountant
                  ifLimitExceeded:(uint32_t)money;
- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)notifyObserversWorkerIsFree:(SEL)selector withObject:(id)object;

@end

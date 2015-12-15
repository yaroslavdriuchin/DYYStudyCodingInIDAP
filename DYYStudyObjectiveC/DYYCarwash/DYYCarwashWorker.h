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
@property (nonatomic, assign)      uint32_t               moneyLimit;
@property (nonatomic, assign)      DYYCarwashAccountant   *accountant;
@property (nonatomic, assign)      uint32_t               washPrice;
@property (nonatomic, assign)      BOOL                   isWorkerFree;

- (void)washCar:(DYYCarwashCar *)car;
- (void)workerIsFree:(DYYCarwashWorker *)worker;
- (void)workerIsBusy:(DYYCarwashWorker *)worker;
- (void)transferMoneyToAccountant:(DYYCarwashAccountant *)accountant
                  ifLimitExceeded:(uint32_t)money;

@end

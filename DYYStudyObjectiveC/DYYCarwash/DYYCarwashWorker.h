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

@interface DYYCarwashWorker: DYYCarwashEmployee

@property (nonatomic, assign)      uint32_t               moneyLimit;
@property (nonatomic, assign)      id                     moneyReciever;
//@property (nonatomic, assign)      uint32_t               washPrice;
@property (nonatomic, assign)      BOOL                   isWorkerFree;

- (BOOL)washCar:(DYYCarwashCar *)car;
- (BOOL)transferMoneyToReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever
                ifLimitExceeded:(uint32_t)money;
- (void)performPersonalFunctionWithObject:(id)object;

@end

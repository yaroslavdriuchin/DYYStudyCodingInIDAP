//
//  DYYCarwashAccountant.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"
@class DYYCarwashDirector;
@class DYYCarwashWorker;

@interface DYYCarwashAccountant : DYYEmployee

- (void)performPersonalFunctionWithObject:(id<DYYCarwashMoneyTransferProtocol>)object;
- (void)takeWorkerMoneyAndReport:(DYYCarwashWorker *)worker;
- (void)itemIsStandBy:(id)item;

@end

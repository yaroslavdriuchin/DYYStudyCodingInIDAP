//
//  DYYCarwashAccountant.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"
@class DYYDirector;
@class DYYWorker;

@interface DYYAccountant : DYYEmployee

- (void)takeWorkerMoneyAndReport:(DYYWorker *)worker;
- (void)employeeDidBecomeStandBy:(id)employee;

@end

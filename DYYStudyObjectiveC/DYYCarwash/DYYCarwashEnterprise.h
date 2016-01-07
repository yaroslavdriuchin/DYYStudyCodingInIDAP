//
//  DYYCarwashEnterprise.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashObserverProtocol.h"
#import "DYYCar.h"
@class DYYCarwashWorker;


@interface DYYCarwashEnterprise : NSObject <DYYCarwashObserverProtocol>

@property (nonatomic, retain)     id                   observableEmployee;
@property (nonatomic, assign)     NSUInteger           carsQueueLimit;
@property (nonatomic, assign)     NSUInteger           washPrice;

+ (DYYCarwashEnterprise *)enterpriseWithWorkers:(NSUInteger)workersQuantity
                            totalEmployeesLimit:(NSUInteger)employeesLimit;
- (void)addCarToCarwash:(DYYCar *)car;

@end

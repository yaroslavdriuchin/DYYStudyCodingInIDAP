//
//  DYYCarwashEmployee.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashMoneyTransferProtocol.h"
#import "DYYCarwashObserverProtocol.h"
#import "DYYCarwashObservable.h"

typedef NS_ENUM (NSUInteger, DYYEmployeeStatus) {
    kDYYEmployeeBusy = 0,
    kDYYEmployeeStandby,
    kDYYEmployeeFree,
};

@interface DYYEmployee : DYYCarwashObservable <DYYCarwashMoneyTransferProtocol, DYYCarwashObserverProtocol>

@property (nonatomic, assign)       NSUInteger             salary;
@property (nonatomic, assign)       NSUInteger             experienceYears;
@property (nonatomic, assign)       DYYEmployeeStatus      employeeStatus;
@property (nonatomic, readonly)     NSArray                *objectsProcessQueue;

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object;
- (void)addObjectToProcess:(id)object;
- (void)setState:(DYYEmployeeStatus)state;
- (void)checkQueueAndProcess;
- (void)itemIsFreeToWork:(id)item;
- (void)itemIsStandBy:(id)item;
- (void)itemIsBusy:(id)item;

@end

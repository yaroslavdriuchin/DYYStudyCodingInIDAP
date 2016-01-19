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
#import "DYYObservableObject.h"

typedef NS_ENUM (NSUInteger, DYYEmployeeState) {
    kDYYEmployeeBusy = 0,
    kDYYEmployeeStandby,
    kDYYEmployeeFree,
};

@interface DYYEmployee : DYYObservableObject <DYYCarwashMoneyTransferProtocol, DYYCarwashObserverProtocol>

@property (nonatomic, assign)       NSUInteger             salary;
@property (nonatomic, assign)       NSUInteger             experienceYears;
@property (nonatomic, assign)       DYYEmployeeState       employeeState;
@property (nonatomic, readonly)     NSArray                *objectsProcessQueue;

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object;
- (void)addObjectToProcess:(id)object;
- (void)setState:(DYYEmployeeState)state;
- (void)checkQueueAndProcess;

@end

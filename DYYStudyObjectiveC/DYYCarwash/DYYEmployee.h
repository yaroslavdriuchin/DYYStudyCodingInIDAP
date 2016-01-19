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
    kDYYEmployeeBegin = 0,
    kDYYEmployeeBusy,
    kDYYEmployeeStandby,
    kDYYEmployeeFree,
    kDYYEmployeeEnd
};

@interface DYYEmployee : DYYObservableObject <DYYCarwashMoneyTransferProtocol, DYYCarwashObserverProtocol>

@property (nonatomic, readonly)     NSArray                *objectsProcessQueue;

- (void)addObjectToProcess:(id)object;
- (void)checkQueueAndProcess;

@end

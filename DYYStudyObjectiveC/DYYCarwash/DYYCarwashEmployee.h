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

typedef NS_ENUM (NSUInteger, DYYEmployeeStatus) {
    kDYYEmployeeBusy = 0,
    kDYYEmployeeStandby,
    kDYYEmployeeFree,
};

@interface DYYCarwashEmployee : NSObject <DYYCarwashMoneyTransferProtocol, DYYCarwashObserverProtocol>

@property (nonatomic, assign)       uint32_t            salary;
@property (nonatomic, assign)       uint8_t             experienceYears;
@property (nonatomic, readonly)     NSArray             *observers;
@property (nonatomic, assign)       DYYEmployeeStatus   employeeStatus;

- (void)performPersonalFunctionWithObject:(id)object;
- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;
- (void)itemIsFreeToWork:(id)item ;
- (void)itemIsStandBy:(id)item;
- (void)itemIsBusy:(id)item;

@end

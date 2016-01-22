//
//  DYYCarwashEmployee.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"
#import "NSObject+DYYExtensions.h"
#import "DYYQueue.h"

@interface DYYEmployee ()

@property (nonatomic, assign)    NSUInteger         mutableMoney;
@property (nonatomic, retain)    DYYQueue           *mutableProcessingQueue;

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object;
- (void)finishProcessing;
- (void)finishPerformingWork;
- (void)takeObjectMoneyAndReport:(id<DYYCarwashMoneyTransferProtocol>)object;

@end

@implementation DYYEmployee

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.state = kDYYEmployeeFree;
        self.mutableProcessingQueue = [DYYQueue object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSUInteger)money {
    return self.mutableMoney;
}

#pragma mark -
#pragma mark DYYCarwashObserverProtocol

- (void)employeeDidStartWork:(id)employee {
}

- (void)employeeDidBecomeStandBy:(id)employee {
}

- (void)employeeDidBecomeFree:(id)employee {
}

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kDYYEmployeeBusy:
            return @selector(employeeDidStartWork:);
            
        case kDYYEmployeeStandby:
            return @selector(employeeDidBecomeStandBy:);
            
        case kDYYEmployeeFree:
            return @selector(employeeDidBecomeFree:);
            
        default:
            return nil;
    }
}

- (void)processObject:(id)object {
}

#pragma mark -
#pragma mark Public Methods

- (void)performWorkWithObject:(id)object {
    if (object) {
        if (self.state == kDYYEmployeeFree) {
            [self startProcessingObject:object];
            [self finishProcessing];
            [self finishPerformingWork];
        } else {
            [self.mutableProcessingQueue enqueue:object];
        }
    }
}

- (void)startProcessingObject:(id)object {
    self.state = kDYYEmployeeBusy;
    [self processObject:object];
}

- (void)finishProcessing {
    [self setState:kDYYEmployeeStandby];
}

- (void)finishPerformingWork {
    [self setState:kDYYEmployeeFree];
}

- (void)takeObjectMoneyAndReport:(id<DYYCarwashMoneyTransferProtocol>)object {
    [self setState:kDYYEmployeeBusy];
    NSUInteger objectMoney = [object money];
    [object payMoneyAmount:objectMoney];
    [self takeMoneyAmount:objectMoney];
    [self setState:kDYYEmployeeFree];
}

#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(NSUInteger)amount {
        self.mutableMoney -= amount;
}

- (void)takeMoneyAmount:(NSUInteger)amount {
        self.mutableMoney += amount;
}

@end

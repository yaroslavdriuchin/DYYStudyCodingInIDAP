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
- (void)performBackgroundWorkWithObject:(id)object;

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

#pragma mark -
#pragma mark Private Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kDYYEmployeeBusy:
            return @selector(employeeDidStartWork:);
            
        case kDYYEmployeeStandby:
            return @selector(employeeDidBecomeStandBy:);
            
        case kDYYEmployeeFree:
            return @selector(employeeDidBecomeFree:);
            
        default:
            return [super selectorForState:state];
    }
}

- (void)processObject:(id)object {
}

- (void)processObjectsQueue {
    if (self.mutableProcessingQueue) {
        @synchronized(self) {
            NSUInteger count = [self.mutableProcessingQueue count];
            if (count > 0) {
                for (NSUInteger index = 0; index < count; index++) {
                    id object = [self.mutableProcessingQueue dequeue];
                    [self performBackgroundWorkWithObject:object];
                }
            }
        }
    }
}

- (void)performBackgroundWorkWithObject:(id)object {
    [self processObject:object];
    [self performSelectorOnMainThread:@selector(finishProcessing) withObject:object waitUntilDone:NO];
}

#pragma mark -
#pragma mark Public Methods

- (void)performWorkWithObject:(id)object {
    @synchronized(object) {
        if (object) {
            if (self.state == kDYYEmployeeFree) {
                [self startProcessingObject:object];
                [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:object];
                [self finishPerformingWork];
            } else {
                [self.mutableProcessingQueue enqueue:object];
            }
        }
    }
}

- (void)startProcessingObject:(id)object {
    @synchronized(self) {
        self.state = kDYYEmployeeBusy;
    }
}

- (void)finishProcessing {
    @synchronized(self) {
        self.state = kDYYEmployeeStandby;
        [self processObjectsQueue];
    }
}

- (void)finishPerformingWork {
    @synchronized(self) {
        self.state = kDYYEmployeeFree;
    }
}

- (void)takeObjectMoneyAndReportTransaction:(id<DYYCarwashMoneyTransferProtocol>)object {
    @synchronized(self) {
        NSUInteger objectMoney = [object money];
        [object payMoneyAmount:objectMoney];
        [self takeMoneyAmount:objectMoney];
        NSLog(@"Money amount of %lu was transferred from %@", objectMoney, object);
    }
}

#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(NSUInteger)amount {
    @synchronized(self) {
        self.mutableMoney -= amount;
    }
}

- (void)takeMoneyAmount:(NSUInteger)amount {
    @synchronized(self) {
        self.mutableMoney += amount;
    }
}

@end

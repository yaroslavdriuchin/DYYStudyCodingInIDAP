//
//  DYYCarwashEmployee.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"

@interface DYYEmployee ()

@property (nonatomic, assign)    NSUInteger         mutableMoney;
@property (nonatomic, retain)    NSMutableArray     *mutableObjectsProcessQueue;

- (void)processObject:(id<DYYCarwashMoneyTransferProtocol>)object;

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
        self.objectState = kDYYEmployeeFree;
    }
    
    return self;
}

- (NSArray *)objectsProcessQueue {
    return [[self.mutableObjectsProcessQueue copy] autorelease];
}

#pragma mark -
#pragma mark Accesors

- (NSUInteger)money {
    return self.mutableMoney;
}

#pragma mark -
#pragma mark DYYCarwashObserverProtocol

- (void)employeeStartedWork:(id)employee {
}

- (void)employeeBecameStandBy:(id)employee {
}

- (void)employeeBecameBusy:(id)employee {
}

#pragma mark -
#pragma mark Public Methods

- (void)processObject:(id)object {
    return;
}

- (void)addObjectToProcess:(id)object {
    if (object) {
            if (self.objectState == kDYYEmployeeFree) {
                [self performSelector:@selector(processObject:) withObject:object];
            } else {
                    [self.mutableObjectsProcessQueue addObject:object];
                   }
    }
}

- (void)checkQueueAndProcess {
    for (id object in self.mutableObjectsProcessQueue) {
        [self performSelector:@selector(processObject:) withObject:object];
        [self.mutableObjectsProcessQueue removeObject:object];
    }
}

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kDYYEmployeeBusy:
            return @selector(employeeStartedWork:);
            
        case kDYYEmployeeStandby:
            return @selector(employeeBecameStandBy:);
            
        case kDYYEmployeeFree:
            return @selector(employeeBecameBusy:);
            
        default:
            return nil;
    }
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

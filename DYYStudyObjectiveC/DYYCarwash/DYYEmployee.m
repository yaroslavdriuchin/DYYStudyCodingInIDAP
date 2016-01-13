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
        self.employeeStatus = kDYYEmployeeFree;
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

- (void)itemIsFreeToWork:(id)item {
   return;
}

- (void)itemIsStandBy:(id)item {
   return;
}

- (void)itemIsBusy:(id)item {
    return;
}

#pragma mark -
#pragma mark Public Methods

- (void)processObject:(id)object {
    return;
}

- (void)addObjectToProcess:(id)object {
    if (object) {
        @synchronized(object) {
            if (self.employeeStatus == kDYYEmployeeFree) {
                [self performSelectorInBackground:@selector(processObject:) withObject:object];
            } else {
                    [self.mutableObjectsProcessQueue addObject:object];
            }
        }
    }
}

- (void)checkQueueAndProcess {
    @synchronized(self) {
    for (id object in self.mutableObjectsProcessQueue) {
        [self performSelectorInBackground:@selector(processObject:) withObject:object];
        [self.mutableObjectsProcessQueue removeObject:object];
        }
    }
}

- (void)setState:(DYYEmployeeStatus)state {
    @synchronized(self) {
    switch (state) {
        case kDYYEmployeeBusy:
            self.employeeStatus = kDYYEmployeeBusy;
            [self notifyObserversWithSelector:@selector(itemIsBusy:) withObject:self];
            break;
        case kDYYEmployeeStandby:
            self.employeeStatus = kDYYEmployeeStandby;
            [self notifyObserversWithSelector:@selector(itemIsStandBy:) withObject:self];
            break;
        case kDYYEmployeeFree:
            self.employeeStatus = kDYYEmployeeFree;
            [self notifyObserversWithSelector:@selector(itemIsFreeToWork:) withObject:self];
            break;
            
        default:
            break;
        }
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

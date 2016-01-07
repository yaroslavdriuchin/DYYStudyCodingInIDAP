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
@property (nonatomic, retain)    NSMutableArray     *itemsToProcessMutableQueue;

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

#pragma mark
#pragma mark - DYYCarwashWorker observer

- (void)setObservableEmployee:(id)employee {
    if (_observableEmployee != employee) {
        @synchronized(employee) {
            [_observableEmployee removeObserver:self];
            [employee release];
            _observableEmployee = [employee retain];
            [employee addObserver:self];
        }
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)performPersonalFunctionWithObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

- (void)addObjectToProcess:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(NSUInteger)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney - amount;
    }
}
- (void)takeMoneyAmount:(NSUInteger)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney + amount;
    }
}

@end

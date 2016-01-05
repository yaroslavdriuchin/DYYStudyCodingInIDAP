//
//  DYYCarwashEmployee.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEmployee.h"

@interface DYYCarwashEmployee ()

@property (nonatomic, assign)    uint32_t     mutableMoney;

@end

@implementation DYYCarwashEmployee

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

- (uint32_t)money {
    return self.mutableMoney;
}

#pragma mark -
#pragma mark DYYCarwashObserverProtocol

- (void)itemIsFreeToWork:(id)item {
    [self performPersonalFunctionWithObject:(id)item];
}

- (void)itemIsStandBy:(id)item {
    [self performPersonalFunctionWithObject:(id)item];
}

- (void)itemIsBusy:(id)item {
    return;
}

#pragma mark -
#pragma mark Public Methods

- (void)performPersonalFunctionWithObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(uint32_t)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney - amount;
    }
}
- (void)takeMoneyAmount:(uint32_t)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney + amount;
    }
}

@end

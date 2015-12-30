//
//  DYYCarwashEmployee.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEmployee.h"

@interface DYYCarwashEmployee ()

@property (nonatomic, retain)    NSMutableSet    *mutableObservers;
@property (nonatomic, assign)    uint32_t        mutableMoney;

@end

@implementation DYYCarwashEmployee

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSMutableSet set];
        self.employeeStatus = kDYYEmployeeFree;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

- (uint32_t)money {
    return self.mutableMoney;
}

#pragma mark -
#pragma mark DYYCarwashEmployee observer

- (void)addObserver:(id)observer {
    NSValue *reference = [[NSValue valueWithNonretainedObject:observer] autorelease];
    [self.mutableObservers addObject:reference];
}

- (void)removeObserver:(id)observer {
    NSArray *observers = self.observers;
    for (NSValue *reference in observers) {
        if (reference == observer) {
            [self.mutableObservers removeObject:reference];
            break;
        }
    }
}

- (void)itemIsFreeToWork:(id)item {
    [self performPersonalFunctionWithObject:(id)item];
}

- (void)itemIsStandBy:(id)item {
    [self performPersonalFunctionWithObject:(id)item];
}

- (void)itemIsBusy:(id)item {
    return;
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    NSArray *observers = self.observers;
    for (id observer in observers) {
        [observer performSelectorInBackground:selector withObject:self];
    }
}


#pragma mark -
#pragma mark Public Methods

- (void)performPersonalFunctionWithObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(uint32_t)amount {
        self.mutableMoney = self.mutableMoney - amount;
    }

- (void)addMoneyAmount:(uint32_t)amount {
        self.mutableMoney = self.mutableMoney + amount;
}

@end

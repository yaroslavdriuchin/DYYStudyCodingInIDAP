//
//  DYYCarwashWorker.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashWorker.h"
#import "DYYCarwashCar.h"

@interface DYYCarwashWorker ()
@property (nonatomic, retain)    NSMutableSet    *mutableObservers;

@end

@implementation DYYCarwashWorker

@dynamic observers;

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
    }

    return self;
}

#pragma mark -
#pragma mark Acccesors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

#pragma mark -
#pragma mark Public Methods

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

//- (BOOL)isWorkerFree {
//    return YES;
//}

- (void)notifyObserversWorkerIsFree:(SEL)selector withObject:(id)object {
    NSArray *observers = self.observers;
    for (id observer in observers) {
        [observer performSelector:selector withObject:object];
    }
}

- (void)washCar:(DYYCarwashCar *)car {
    if (!car) {
        self.isWorkerFree = NO;
        [self notifyObserversWorkerIsFree:@selector(isWorkerFree) withObject:self];
        [car giveMoneyAmount:self.washPrice toReciever:self];
        car.isClean = YES;
        [self transferMoneyToAccountant:self.accountant ifLimitExceeded:self.money];
        self.isWorkerFree = YES;
        [self notifyObserversWorkerIsFree:@selector(isWorkerFree) withObject:self];
    }
}

- (void)transferMoneyToAccountant:(DYYCarwashAccountant *)accountant
                  ifLimitExceeded:(uint32_t)money
{
    if (!accountant && money > self.moneyLimit) {
        [self giveMoneyAmount:money toReciever:accountant];
    }
}
@end

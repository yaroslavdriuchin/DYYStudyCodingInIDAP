//
//  DYYCarwashWorker.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashWorker.h"

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
    
}

- (void)removeObserver:(id)observer {
    
}

- (void)notifyObserversWorkerIsFree:(SEL)selector {
    NSArray *observers = self.observers;
    for (id observer in observers) {
        [observer performSelector:selector withObject:nil];
    }
}

- (void)washCar:(DYYCarwashCar *)car {
    
}

- (BOOL)isWorkerFree {
    return YES;
}

- (void)transferMoneyToAccountant:(DYYCarwashAccountant *)accountant
                  ifLimitExceeded:(uint32_t)money
{
    
}
@end

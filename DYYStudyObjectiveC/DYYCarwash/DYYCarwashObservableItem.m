//
//  DYYCarwashObservableItem.m
//  DYYStudyCoding
//
//  Created by Yar on 1/5/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashObservableItem.h"
@interface DYYCarwashObservableItem ()

@property (nonatomic, retain)    NSHashTable   *mutableObservers;

@end

@implementation DYYCarwashObservableItem

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSHashTable hashTableWithOptions:NSPointerFunctionsWeakMemory];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSArray *)observers {
    @synchronized(self) {
        return [self.mutableObservers allObjects];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    @synchronized(self) {
        [self.mutableObservers addObject:observer];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized(self) {
        NSArray *observers = self.observers;
        for (id reference in observers) {
            if (reference == observer) {
                [self.mutableObservers removeObject:reference];
                break;
            }
        }
    }
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    NSArray *observers = self.observers;
    for (id observer in observers) {
        [observer performSelectorInBackground:selector withObject:self];
    }
}

@end

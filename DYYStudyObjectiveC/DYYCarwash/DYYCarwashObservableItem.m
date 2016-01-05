//
//  DYYCarwashObservableItem.m
//  DYYStudyCoding
//
//  Created by Yar on 1/5/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashObservableItem.h"
@interface DYYCarwashObservableItem ()

@property (nonatomic, retain)    NSMutableSet    *mutableObservers;

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
        self.mutableObservers = [NSMutableSet set];
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
        NSValue *reference = [[NSValue valueWithNonretainedObject:observer] autorelease];
        [self.mutableObservers addObject:reference];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized(self) {
        NSArray *observers = self.observers;
        for (NSValue *reference in observers) {
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

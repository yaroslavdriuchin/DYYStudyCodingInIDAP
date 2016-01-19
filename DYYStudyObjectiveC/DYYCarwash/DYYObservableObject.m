//
//  DYYCarwashObservableItem.m
//  DYYStudyCoding
//
//  Created by Yar on 1/5/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import "DYYObservableObject.h"
@interface DYYObservableObject ()
@property (nonatomic, retain)    NSHashTable   *mutableObservers;

@end

@implementation DYYObservableObject

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSHashTable *)observers {
        return [[[self.mutableObservers allObjects] copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
        [self.mutableObservers addObject:observer];
}

- (void)removeObserver:(id)observer {
        NSHashTable *observers = self.observers;
        for (id reference in observers) {
            if (reference == observer) {
                [self.mutableObservers removeObject:reference];
                break;
        }
    }
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    NSHashTable *observers = self.mutableObservers;
    for (id observer in observers) {
        [observer performSelectorInBackground:selector withObject:object];
    }
}

- (void)setObservableEmployee:(id)employee {
    if (_observableEmployee != employee) {
            [_observableEmployee removeObserver:self];
            [employee release];
            _observableEmployee = [employee retain];
            [employee addObserver:self];
    }
}

@end

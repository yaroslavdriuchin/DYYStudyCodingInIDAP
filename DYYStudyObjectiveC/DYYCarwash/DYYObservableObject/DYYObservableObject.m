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

- (SEL)selectorForState:(NSUInteger)state;

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

- (void)setState:(NSUInteger)state {
    @synchronized(self) {
        if (self.state != state) {
            _state = state;
            SEL selector = [self selectorForState:state];
            if (selector) {
                [self notifyObserversWithSelector:selector withObject:self];
            }
        }
    }
}

- (void)addObserver:(id)observer {
    @synchronized(self) {
        [self.mutableObservers addObject:observer];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized(self) {
        [self.mutableObservers removeObject:observer];
    }
}

- (void)notifyObserversWithSelector:(SEL)selector {
    [self notifyObserversWithSelector:(SEL)selector withObject:(id)nil];
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    @synchronized(self) {
        NSHashTable *observers = self.mutableObservers;
        for (id observer in observers) {
            [observer performSelector:selector withObject:object];
        }
    }
}

- (SEL)selectorForState:(NSUInteger)state {
    return nil;
}

@end

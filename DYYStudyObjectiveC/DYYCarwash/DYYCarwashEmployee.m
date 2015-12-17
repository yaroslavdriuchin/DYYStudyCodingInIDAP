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

@end

//@dynamic observers;
//
//@dynamic money;

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
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSArray *)observers {
    return [self.mutableObservers allObjects];
}

#pragma mark -
#pragma mark Class Methods

+ (void)giveMoneyAmount:(uint32_t)value toReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever {
    if (!reciever) {
    }
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

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    NSArray *observers = self.observers;
    for (id observer in observers) {
        [observer performSelector:selector withObject:object];
    }
}

- (void)itemIsFree {
    return;
}

- (void)itemIsBusy {
    return;
}

//- (uint32_t)money {
//    return self.money;
//}
//
//- (void)setMoney:(uint32_t)value {
//    self.money = value;
//}

@end

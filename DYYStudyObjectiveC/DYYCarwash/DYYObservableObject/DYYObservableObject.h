//
//  DYYCarwashObservableItem.h
//  DYYStudyCoding
//
//  Created by Yar on 1/5/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYObservableObject : NSObject
@property (nonatomic, readonly)  NSHashTable    *observers;
@property (nonatomic, assign)    NSUInteger     state;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;

- (void)setState:(NSUInteger)state;
- (SEL)selectorForState:(NSUInteger)state;

@end

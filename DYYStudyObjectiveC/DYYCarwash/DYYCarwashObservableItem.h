//
//  DYYCarwashObservableItem.h
//  DYYStudyCoding
//
//  Created by Yar on 1/5/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYCarwashObservableItem : NSObject

@property (nonatomic, readonly)     NSArray    *observers;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;

@end

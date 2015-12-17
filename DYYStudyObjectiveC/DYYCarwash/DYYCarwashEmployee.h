//
//  DYYCarwashEmployee.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashMoneyTransferProtocol.h"
#import "DYYCarwashObservingProtocol.h"

@interface DYYCarwashEmployee : NSObject <DYYCarwashMoneyTransferProtocol>

//current employee amount of money is calculated in Cents
@property (nonatomic, assign)      uint32_t         salary;
@property (nonatomic, assign)      uint8_t          experienceYears;
@property (nonatomic, readonly)    NSArray          *observers;

- (void)giveMoneyAmount:(uint32_t)value toReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever;
- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;
- (void)itemIsFree;
- (void)itemIsBusy;

@end

//
//  DYYCarwashCar.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashCar.h"

@implementation DYYCarwashCar

#pragma mark -
#pragma mark Initializations and Deallocators

+ (instancetype)carWithAmountofMoney:(uint32_t)money {
    return [[[self alloc] initCarWithAmountofMoney:money] autorelease];
}

- (instancetype)initCarWithAmountofMoney:(uint32_t)money {
        self = [super init];
        if (self) {
            self.money = money;
        }
        
        return self;
    }

#pragma mark -
#pragma mark Public methods

- (void) giveMoneyAmount:(uint32_t)value toReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever {
    if (reciever) {
        self.money = self.money - value;
        reciever.money = reciever.money + value;
    }
}

- (BOOL)isCarAbleToPay:(uint32_t)price {
    if (self.money > price) {
        return NO;
        }
    
    return YES;
}

@end

//
//  DYYCarwashCar.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashCar.h"

@interface DYYCarwashCar()

@property (nonatomic, assign)    uint32_t    mutableMoney;

@end

@implementation DYYCarwashCar

#pragma mark -
#pragma mark Initializations and Deallocators

+ (instancetype)carWithAmountofMoney:(uint32_t)money {
    return [[[self alloc] initCarWithAmountofMoney:money] autorelease];
}

- (instancetype)initCarWithAmountofMoney:(uint32_t)money {
        self = [super init];
        if (self) {
            self.mutableMoney = money;
        }
        
        return self;
    }

#pragma mark -
#pragma mark Accessors

- (uint32_t)money {
    return self.mutableMoney;
}


#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(uint32_t)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney - amount;
    }
}

- (void)takeMoneyAmount:(uint32_t)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney + amount;
    }
}

#pragma mark -
#pragma mark Public methods

- (BOOL)isCarAbleToPay:(uint32_t)price {
    if (self.money >= price) {
        return YES;
        }
    
    return NO;
}

@end

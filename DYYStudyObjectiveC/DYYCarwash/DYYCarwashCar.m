//
//  DYYCarwashCar.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashCar.h"

@interface DYYCarwashCar()

@property (nonatomic, assign)    NSUInteger    mutableMoney;

@end

@implementation DYYCarwashCar

#pragma mark -
#pragma mark Initializations and Deallocators

+ (instancetype)carWithAmountofMoney:(NSUInteger)money {
    return [[[self alloc] initCarWithAmountofMoney:money] autorelease];
}

- (instancetype)initCarWithAmountofMoney:(NSUInteger)money {
        self = [super init];
        if (self) {
            self.mutableMoney = money;
        }
        
        return self;
    }

#pragma mark -
#pragma mark Accessors

- (NSUInteger)money {
    return self.mutableMoney;
}


#pragma mark -
#pragma mark DYYCarwashMoneyTransferProtocol

- (void)payMoneyAmount:(NSUInteger)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney - amount;
    }
}

- (void)takeMoneyAmount:(NSUInteger)amount {
    @synchronized(self) {
        self.mutableMoney = self.mutableMoney + amount;
    }
}

#pragma mark -
#pragma mark Public methods

- (BOOL)isCarAbleToPay:(NSUInteger)price {
    if (self.money >= price) {
        return YES;
        }
    
    return NO;
}

@end

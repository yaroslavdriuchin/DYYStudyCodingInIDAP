//
//  DYYCarwashCar.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCar.h"

@interface DYYCar()
@property (nonatomic, assign)    NSUInteger    mutableMoney;

@end

@implementation DYYCar

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
    self.mutableMoney -= amount;
}

- (void)takeMoneyAmount:(NSUInteger)amount {
    self.mutableMoney += amount;
}

@end

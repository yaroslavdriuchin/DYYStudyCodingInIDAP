//
//  DYYCarwashEmployee.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEmployee.h"

@implementation DYYCarwashEmployee

@dynamic money;

#pragma mark -
#pragma mark Class Methods

+ (void)giveMoneyAmount:(uint32_t)value toReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever {
    if (!reciever) {
    }
}

- (uint32_t)money {
    return self.money;
}

- (void)setMoney:(uint32_t)value {
    self.money = value;
}

@end

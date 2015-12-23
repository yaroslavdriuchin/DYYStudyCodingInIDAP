//
//  DYYCarwashAccountant.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashAccountant.h"

@implementation DYYCarwashAccountant

- (uint32_t)calculateMoneyInDollars {
    NSLog(@"Accountant reports %u dollars", self.money);
    return self.money;
}

@end

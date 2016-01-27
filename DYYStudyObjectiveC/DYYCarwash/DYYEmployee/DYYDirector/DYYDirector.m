//
//  DYYCarwashDirector.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYDirector.h"

@implementation DYYDirector

- (void)processObject:(id)object {
    @synchronized(object) {
        [self takeObjectMoneyAndReportTransaction:object];
        NSLog(@"Director reports money amount is %lu", self.money);
    }
}

- (void)employeeDidBecomeStandBy:(id)employee {
    [self performWorkWithObject:employee];
}

@end

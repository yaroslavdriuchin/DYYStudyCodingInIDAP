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
    [self takeAccountantMoneyAndReport:object];
}

- (void)takeAccountantMoneyAndReport:(DYYAccountant *)accountant {
    [self takeObjectMoneyAndReportTransaction:(id)accountant];
    NSLog(@"Director reports money amount is %lu", self.money);
}

- (void)employeeDidBecomeFree:(id)employee {
    [self performWorkWithObject:employee];
}

@end

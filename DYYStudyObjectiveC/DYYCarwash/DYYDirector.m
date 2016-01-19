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
    self.employeeState = kDYYEmployeeBusy;
    NSUInteger accountantMoney = [accountant money];
    [accountant payMoneyAmount:accountantMoney];
    [self takeMoneyAmount:accountantMoney];
    NSLog(@"Money amount of %lu was transferred from accountant to director", accountantMoney);
    NSLog(@"Director reports money amount is %lu", self.money);
    [self checkQueueAndProcess];
    self.employeeState = kDYYEmployeeFree;
}

- (void)itemIsFreeToWork:(id)item  {
    [self addObjectToProcess:item];
}

@end

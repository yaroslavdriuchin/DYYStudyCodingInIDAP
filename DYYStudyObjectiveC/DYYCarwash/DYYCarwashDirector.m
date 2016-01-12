//
//  DYYCarwashDirector.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashDirector.h"

@implementation DYYCarwashDirector

- (void)processObject:(id)object {
    [self takeAccountantMoneyAndReport:object];
}

- (void)takeAccountantMoneyAndReport:(DYYCarwashAccountant *)accountant {
    self.employeeStatus = kDYYEmployeeBusy;
    NSUInteger accountantMoney = [accountant money];
    [accountant payMoneyAmount:accountantMoney];
    [self takeMoneyAmount:accountantMoney];
    self.employeeStatus = kDYYEmployeeFree;
    NSLog(@"Money amount of %lu was transferred from accountant to director", accountantMoney);
    NSLog(@"Director reports money amount is %lu", self.money);
}

- (void)itemIsFreeToWork:(id)item  {
    [self addObjectToProcess:item];
}

@end

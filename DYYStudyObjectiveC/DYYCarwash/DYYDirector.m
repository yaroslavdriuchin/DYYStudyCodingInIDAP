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
    self.objectState = kDYYEmployeeBusy;
    NSUInteger accountantMoney = [accountant money];
    [accountant payMoneyAmount:accountantMoney];
    [self takeMoneyAmount:accountantMoney];
    NSLog(@"Money amount of %lu was transferred from accountant to director", accountantMoney);
    NSLog(@"Director reports money amount is %lu", self.money);
    self.objectState = kDYYEmployeeFree;
}

- (void)itemIsFreeToWork:(id)item  {
    [self performWorkWithObject:item];
}

@end

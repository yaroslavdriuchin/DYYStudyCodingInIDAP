//
//  DYYCarwashBasicTest.m
//  DYYStudyCoding
//
//  Created by Yar on 12/22/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashBasicTest.h"

#import "DYYCarwashEnterprise.h"
#import "DYYCarwashMoneyTransferProtocol.h"
#import "DYYCar.h"
#import "DYYEmployee.h"
#import "DYYCarwashWorker.h"
#import "DYYCarwashAccountant.h"
#import "DYYCarwashDirector.h"

@implementation DYYCarwashBasicTest

NSUInteger const kDYYCarsArrayOneLenght = 50;
NSUInteger const kDYYCarsArrayTwoLenght = 100;

+ (void)runCarwashBasicTest {
    //creating test Carwash with number of workers = 3, 1 accountant, 1 director
    DYYCarwashEnterprise *testCarwash = [[[DYYCarwashEnterprise alloc] init] autorelease];
    [testCarwash configureEnterpriseWorkersQuantity:3
                                totalEmployeesLimit:50
                                          washPrice:5];
    
    //Checking test Carwash is not nil
    NSAssert(testCarwash != nil, @"It's equal to nil, sucks");
    
    //defining basic Carwash parameters
    testCarwash.carsQueueLimit = 1000;
    
    NSMutableArray *carsOne = [NSMutableArray arrayWithCapacity:kDYYCarsArrayOneLenght];
//    NSMutableArray *carsTwo = [NSMutableArray arrayWithCapacity:kDYYCarsArrayTwoLenght];
    
    for (NSUInteger index = 0; index < kDYYCarsArrayOneLenght; index++) {
        DYYCar *car = [[[DYYCar alloc] initCarWithAmountofMoney:100] autorelease];
        [carsOne addObject:car];
    }
    
    //adding cars to carwash queue
    [testCarwash addCarsToCarwash:carsOne];
//    [testCarwash addCarsToCarwash:carsTwo];
    
    while (true) {
        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate distantFuture]];
    }
}

@end

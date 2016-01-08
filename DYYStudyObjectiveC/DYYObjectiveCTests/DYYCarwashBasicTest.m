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

+ (void)runCarwashBasicTest {
    //creating test Carwash with number of workers = 3, 1 accountant, 1 director
    DYYCarwashEnterprise *testCarwash = [DYYCarwashEnterprise enterpriseWithWorkers:3
                                                                totalEmployeesLimit:50];
    
    //Checking test Carwash is not nil
    NSAssert(testCarwash != nil, @"It's equal to nil, sucks");
    
    //defining basic Carwash parameters
    testCarwash.carsQueueLimit = 1000;
    testCarwash.washPrice = 5;
    
    //generating 3 test cars with initial amount of money
    DYYCar *testCarOne   = [[[DYYCar alloc] initCarWithAmountofMoney:100] autorelease];
    DYYCar *testCarTwo   = [[[DYYCar alloc] initCarWithAmountofMoney:100] autorelease];
    DYYCar *testCarThree = [[[DYYCar alloc] initCarWithAmountofMoney:100] autorelease];
    
    //adding cars to carwash queue
    [testCarwash addCarToCarwash:testCarOne];
    sleep(1);
    [testCarwash addCarToCarwash:testCarTwo];
    sleep(1);
    [testCarwash addCarToCarwash:testCarThree];
    sleep(1);

}
@end

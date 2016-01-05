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
#import "DYYCarwashCar.h"
#import "DYYCarwashEmployee.h"
#import "DYYCarwashWorker.h"
#import "DYYCarwashAccountant.h"
#import "DYYCarwashDirector.h"

@implementation DYYCarwashBasicTest

+ (void)runCarwashBasicTest {
    //creating test Carwash with different type of rooms
    DYYCarwashEnterprise *testCarwash = [DYYCarwashEnterprise buildCarwashWithOfficeRooms:1
                                                                           technicalRooms:1
                                                                       totalRoomsCapacity:5];
    
    //Checking test Carwash is not nil
    NSAssert(testCarwash != nil, @"It's equal to nil, sucks");
    
    //defining basic Carwash parameters
    testCarwash.employeesLimit = 100;
    testCarwash.carsQueueLimit = 1000;
    testCarwash.washPrice = 5;
    
    //creating different type of employees and adding them to employees array
    DYYCarwashWorker     *worker      =  [[[DYYCarwashWorker alloc] init] autorelease];
    DYYCarwashAccountant *accountant  =  [[[DYYCarwashAccountant alloc] init] autorelease];
    DYYCarwashDirector   *director    =  [[[DYYCarwashDirector alloc] init] autorelease];
    [testCarwash hireEmployee:worker];
    [testCarwash hireEmployee:accountant];
    [testCarwash hireEmployee:director];
    
    //setting observable worker for current carwash and adding carwash as observer
    [testCarwash setObservableEmployee:worker];
    [worker addObserver:testCarwash];
    
    //generating 3 test cars with initial amount of money
    DYYCarwashCar *testCarOne   = [[[DYYCarwashCar alloc] initCarWithAmountofMoney:100] autorelease];
    DYYCarwashCar *testCarTwo   = [[[DYYCarwashCar alloc] initCarWithAmountofMoney:100] autorelease];
    DYYCarwashCar *testCarThree = [[[DYYCarwashCar alloc] initCarWithAmountofMoney:100] autorelease];
    
    //adding cars to carwash queue
    [testCarwash addCarToCarwash:testCarOne];
    [testCarwash addCarToCarwash:testCarTwo];
    [testCarwash addCarToCarwash:testCarThree];

}
@end

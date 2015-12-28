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
#import "DYYCarwashRoom.h"
#import "DYYCarwashTechnicalRoom.h"
#import "DYYCarwashBuilding.h"
#import "DYYCarwashCar.h"
#import "DYYCarwashEmployee.h"
#import "DYYCarwashWorker.h"
#import "DYYCarwashAccountant.h"
#import "DYYCarwashDirector.h"

@implementation DYYCarwashBasicTest

+ (void)runCarwashBasicTest {
    //creating test Enterprise class
    DYYCarwashEnterprise *testEnterprise = [[[DYYCarwashEnterprise alloc] initWithAttributes] autorelease];
    
    testEnterprise.buildingsLimit = 5;
    testEnterprise.employeesLimit = 100;
    testEnterprise.carsQueueLimit = 1000;
    testEnterprise.washPrice = 5;
    
    NSAssert(testEnterprise != nil, @"It's equal to nil, sucks");
    
    //creating buildings with different type of rooms
    DYYCarwashBuilding *buildingOffice = [testEnterprise buildCarwashBuildingWithOfficeRooms:1
                                                                           technicalRooms:0
                                                                       totalRoomsCapacity:5];
    DYYCarwashBuilding *buildingTechnical = [testEnterprise buildCarwashBuildingWithOfficeRooms:0
                                                                                 technicalRooms:1
                                                                             totalRoomsCapacity:5];
    
    //checking tottal number of buildings in enterprise 2
    NSAssert([testEnterprise.buildings count] == 2, @"It's not as expected, it sucks");
    
    //creating different type of employeees and sending them to corresponding buildings
    DYYCarwashWorker     *worker      =  [[[DYYCarwashWorker alloc] init] autorelease];
    DYYCarwashAccountant *accountant  =  [[[DYYCarwashAccountant alloc] init] autorelease];
    DYYCarwashDirector   *director    =  [[[DYYCarwashDirector alloc] init] autorelease];
    
    [testEnterprise hireEmployee:worker];
    [testEnterprise hireEmployee:accountant];
    [testEnterprise hireEmployee:director];
    
    [testEnterprise sendEmployee:worker toBuilding:buildingTechnical];
    [testEnterprise sendEmployee:accountant toBuilding:buildingOffice];
    [testEnterprise sendEmployee:director toBuilding:buildingOffice];
    
    DYYCarwashCar *testCarOne   = [[[DYYCarwashCar alloc] initCarWithAmountofMoney:100] autorelease];
    DYYCarwashCar *testCarTwo   = [[[DYYCarwashCar alloc] initCarWithAmountofMoney:100] autorelease];
    DYYCarwashCar *testCarThree = [[[DYYCarwashCar alloc] initCarWithAmountofMoney:100] autorelease];
    [testEnterprise addCarToQueue:testCarOne];
    [testEnterprise addCarToQueue:testCarTwo];
    [testEnterprise addCarToQueue:testCarThree];
    [testEnterprise performCarQueueWash];

}
@end

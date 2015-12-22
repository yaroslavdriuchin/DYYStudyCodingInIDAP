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

- (void)runCarwashBasicTest {
//creating test Enterprise class
DYYCarwashEnterprise *testEnterprise = [[DYYCarwashEnterprise alloc] initWithAttributes];
testEnterprise.buildingsLimit = 5;
[testEnterprise buildCarwashBuildingWithOfficeRooms:1 technicalRooms:0 totalRoomsCapacity:5];
[testEnterprise buildCarwashBuildingWithOfficeRooms:0 technicalRooms:1 totalRoomsCapacity:5];

}

@end

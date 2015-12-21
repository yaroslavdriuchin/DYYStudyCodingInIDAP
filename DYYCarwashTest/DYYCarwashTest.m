//
//  DYYCarwashTest.m
//  DYYCarwashTest
//
//  Created by Yar on 12/21/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <Kiwi/Kiwi.h>
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

SPEC_BEGIN(DYYCarwashTest)

describe(@"testing DYYCarwash", ^{
    context(@"Creating DYYCarwash enterprise", ^{
        DYYCarwashEnterprise *testEnterprise = [[DYYCarwashEnterprise alloc] initWithAttributes];
        it(@"test object should be member of class DYYCarwashEnterprise and not nil", ^{
        [[testEnterprise should] beMemberOfClass:[DYYCarwashEnterprise class]];
        [testEnterprise shouldNotBeNil];
        });
        [testEnterprise buildCarwashBuildingWithOfficeRooms:1 technicalRooms:0 totalRoomsCapacity:5];
        [testEnterprise buildCarwashBuildingWithOfficeRooms:0 technicalRooms:1 totalRoomsCapacity:5];
        [[testEnterprise.buildings should] haveCountOf:98];
    });
});

SPEC_END
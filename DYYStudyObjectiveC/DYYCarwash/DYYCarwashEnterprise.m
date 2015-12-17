//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"

@interface DYYCarwashEnterprise()

@property (nonatomic, retain)   NSMutableArray   *mutableEmployees;
@property (nonatomic, retain)   NSMutableArray   *mutableBuildings;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;

@end

@implementation DYYCarwashEnterprise

#pragma mark
#pragma mark - Public Methods

- (DYYCarwashBuilding *)buildCarwashBuildingWithOfficeRooms:(NSUInteger)officeRooms
                                             technicalRooms:(NSUInteger)technicalRooms
{
    DYYCarwashBuilding *building = [[[DYYCarwashBuilding alloc] initBuildingWithRooms] autorelease];
    for (NSUInteger count = 0; count < officeRooms; count++) {
        [building addRoomOfClass:[DYYCarwashRoom class] toBuilding:building];
    }
    for (NSUInteger count = 0; count < technicalRooms; count++) {
        [building addRoomOfClass:[DYYCarwashTechnicalRoom class] toBuilding:building];
    }
    
    return building;
}

- (void)removeCarwashBuilding:(DYYCarwashBuilding *)building {
    [building removeBuilding:building];
}

- (NSArray *)carsQueue {
    return [[self.mutableCarsQueue copy] autorelease];
}

- (NSArray *)buildings {
    return [[self.mutableBuildings copy] autorelease];
}

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}


- (void)hireEmployee:(id)employee {
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
    }
}

- (void)addCarToQueue:(DYYCarwashCar *)car {
    if ([self.mutableCarsQueue count] < self.carsQueueLimit) {
        [self.mutableCarsQueue addObject:car];
    }
}

- (BOOL)sendEmployee:(id)employee
          toBuilding:(DYYCarwashBuilding *)building {
    if (nil != employee && nil != building && [employee class] == [DYYCarwashWorker class]) {
        DYYCarwashTechnicalRoom *technicalRoom = [building findFreeTechnicalRoom];
        if (technicalRoom) {
            [technicalRoom addEmployee:employee];
        } else {
            return NO;
        };
        if (nil != employee && nil != building && [employee class] != [DYYCarwashWorker class]) {
            DYYCarwashRoom *room = [building findFreeRoom];
            if (room) {
                [room addEmployee:employee];
            } else {
                return NO;
            }
        }
        
    }


#pragma mark
#pragma mark - DYYCarwashWorker observer

- (void)setObservableEmployee:(id)employee {
    if (_observableEmployee != employee) {
        [_observableEmployee removeObserver:self];
        [employee release];
        _observableEmployee = [employee retain];
        [employee addObserver:self];
    }
}

@end

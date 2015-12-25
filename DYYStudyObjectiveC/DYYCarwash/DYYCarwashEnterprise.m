//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"
#import "DYYCarwashRoom.h"
#import "DYYCarwashTechnicalRoom.h"
#import "DYYCarwashEmployee.h"
#import "DYYCarwashWorker.h"
#import "DYYCarwashDirector.h"
#import "DYYCarwashAccountant.h"
#import "DYYCarwashBuilding.h"


@interface DYYCarwashEnterprise()

@property (nonatomic, retain)   NSMutableArray   *mutableEmployees;
@property (nonatomic, retain)   NSMutableArray   *mutableBuildings;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;

@end

@implementation DYYCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableEmployees = nil;
    self.mutableBuildings = nil;
    self.mutableCarsQueue = nil;
    [super dealloc];
}

+ (instancetype)enterpriseWithAttributes {
    return [[[self alloc] initWithAttributes] autorelease];
}

- (instancetype)initWithAttributes {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        self.mutableBuildings = [NSMutableArray array];
        self.mutableCarsQueue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSArray *)carsQueue {
    return [[self.mutableCarsQueue copy] autorelease];
}

- (NSArray *)buildings {
    return [[self.mutableBuildings copy] autorelease];
}

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark
#pragma mark - Public Methods

- (DYYCarwashBuilding *)buildCarwashBuildingWithOfficeRooms:(NSUInteger)officeRooms
                                             technicalRooms:(NSUInteger)technicalRooms
                                         totalRoomsCapacity:(NSUInteger)roomsCapacity
{
    if (officeRooms + technicalRooms < self.buildingsLimit) {
        DYYCarwashBuilding *building = [[[DYYCarwashBuilding alloc] initBuildingWithRooms] autorelease];
        building.roomsCapacity = roomsCapacity;
        [self.mutableBuildings addObject:building];
        
        for (NSUInteger count = 0; count < officeRooms; count++) {
            [building addRoomOfClass:[DYYCarwashRoom class]];
        }
        
        for (NSUInteger count = 0; count < technicalRooms; count++) {
            [building addRoomOfClass:[DYYCarwashTechnicalRoom class]];
        }
        
        return building;
    }
    
    return nil;
}

- (void)removeCarwashBuilding:(DYYCarwashBuilding *)building {
    [building removeBuilding:building];
}

- (BOOL)hireEmployee:(id)employee {
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
        return YES;
    }
    
    return NO;
}

- (BOOL)addCarToQueue:(DYYCarwashCar *)car {
    if ([self.mutableCarsQueue count] <= self.carsQueueLimit) {
        [self.mutableCarsQueue addObject:car];
        if ([self.mutableCarsQueue count] > self.carsQueueLimit) {
            [self performCarQueueWash];
        }
        
        return YES;
    }
    
    return NO;
}

- (BOOL)sendEmployee:(id)employee
          toBuilding:(DYYCarwashBuilding *)building {
    if (nil != employee && nil != building && [employee class] == [DYYCarwashWorker class]) {
        DYYCarwashTechnicalRoom *technicalRoom = [building findFreeTechnicalRoom];
        if (technicalRoom) {
            [technicalRoom addEmployee:employee];
            return YES;
        }
            return NO;
        
    if (nil != employee && nil != building && [employee class] != [DYYCarwashWorker class]) {
        DYYCarwashRoom *room = [building findFreeRoom];
        if (room) {
            [room addEmployee:employee];
            return YES;
          }
       }
    }
    return NO;
}

- (void)performCarQueueWash {
    for (DYYCarwashCar *car in self.carsQueue) {
        if (car.isClean == NO && [car isCarAbleToPay:self.washPrice]) {
            for (DYYCarwashBuilding *building in self.buildings) {
                DYYCarwashTechnicalRoom *freeTechnicalRoom = [building findFreeTechnicalRoom];
                if (freeTechnicalRoom != nil
                    && freeTechnicalRoom.isFullWithCars == NO) {
                    for (DYYCarwashWorker *worker in freeTechnicalRoom.employees) {
                        if (worker.isWorkerFree == YES) {
                            if ([worker washCar:car] == YES) {
                                [car payMoneyAmount:self.washPrice];
                                [worker addMoneyAmount:self.washPrice];
                            }
                        }
                    }
                    
                }
            }
        }
    }
}

#pragma mark
#pragma mark - Private Methods

- (void)itemIsFreeToWork:(id)item {
    @synchronized(item) {
    [self performCarQueueWash];
    }
}
- (void)itemIsStandBy:(id)item {
        
    }
- (void)itemIsBusy:(id)item {
    
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

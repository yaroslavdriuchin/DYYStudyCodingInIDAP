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
@property (nonatomic, retain)   NSMutableArray   *mutableRooms;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;

@end

@implementation DYYCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableEmployees = nil;
    self.mutableRooms     = nil;
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
        self.mutableRooms     = [NSMutableArray array];
        self.mutableCarsQueue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSArray *)carsQueue {
    return [[self.mutableCarsQueue copy] autorelease];
}

- (NSArray *)rooms {
    return [[self.mutableRooms copy] autorelease];
}

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark
#pragma mark - Public Methods

- (DYYCarwashEnterprise *)buildCarwashWithOfficeRooms:(NSUInteger)officeRooms
                                     technicalRooms:(NSUInteger)technicalRooms
                                 totalRoomsCapacity:(NSUInteger)roomsCapacity
{
    DYYCarwashEnterprise *carwash = [[[DYYCarwashEnterprise alloc] init] autorelease];
    if (officeRooms + technicalRooms < self.roomsLimit) {
        for (NSUInteger count = 0; count < officeRooms; count++) {
            DYYCarwashRoom *newRoom = [[[DYYCarwashRoom alloc] init] autorelease];
            [self.mutableRooms addObject:newRoom];
        }
        
        for (NSUInteger count = 0; count < technicalRooms; count++) {
            DYYCarwashRoom *newTechnicalRoom = [[[DYYCarwashTechnicalRoom alloc] init] autorelease];
            [self.mutableRooms addObject:newTechnicalRoom];
        }
        
        return carwash;
    }
    
    return nil;
}

- (BOOL)hireEmployee:(id)employee {
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
        return YES;
    }
    
    return NO;
}

- (BOOL)addCarToCarwash:(DYYCarwashCar *)car {
    if ([self.mutableCarsQueue count] <= self.carsQueueLimit) {
        [self.mutableCarsQueue addObject:car];
        if ([self.mutableCarsQueue count] > self.carsQueueLimit) {
            [self performCarQueueWash];
        }
        
        return YES;
    }
    
    return NO;
}

- (NSArray *)findRoomsOfClass:(Class)roomClass {
    NSMutableArray *roomsOfClass = [NSMutableArray array];
    for (id room in self.mutableRooms) {
        if ([room isMemberOfClass:roomClass]) {
            [roomsOfClass addObject:room];
        }
    }

    return [[roomsOfClass copy] autorelease];
}

- (void)performCarQueueWash {
    for (DYYCarwashCar *car in self.mutableCarsQueue) {
        if (car.isClean == NO && [car isCarAbleToPay:self.washPrice]) {
            for (DYYCarwashTechnicalRoom *freeTechnicalRoom in self.mutableRooms) {
                if (freeTechnicalRoom.isFullWithCars == NO) {
                    for (DYYCarwashWorker *worker in [freeTechnicalRoom employees]) {
                        if (worker.employeeStatus == kDYYEmployeeFree) {
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

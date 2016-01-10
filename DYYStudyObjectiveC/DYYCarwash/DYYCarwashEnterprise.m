//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"
#import "DYYEmployee.h"
#import "DYYCarwashWorker.h"
#import "DYYCarwashDirector.h"
#import "DYYCarwashAccountant.h"

@interface DYYCarwashEnterprise()

@property (nonatomic, retain)   NSMutableArray   *mutableEmployees;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;
@property (nonatomic, assign)   NSUInteger       employeesLimit;
@property (nonatomic, retain)   id               observableEmployee;

- (void)hireEmployee:(id)employee;
- (void)washCarQueueWithWorker:(DYYCarwashWorker *)worker;
- (void)setObservableEmployee:(id)employee;

@end

@implementation DYYCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableEmployees = nil;
    self.mutableCarsQueue = nil;
    [super dealloc];
}

+ (DYYCarwashEnterprise *)enterpriseWithWorkers:(NSUInteger)workersQuantity
                            totalEmployeesLimit:(NSUInteger)employeesLimit
                                      washPrice:(NSUInteger)washPrice
{
    DYYCarwashEnterprise *enterprise = [[[self alloc] init] autorelease];
    enterprise.employeesLimit = employeesLimit;
    
    DYYCarwashAccountant *newAccountant = [[[DYYCarwashAccountant alloc] init] autorelease];
    [enterprise hireEmployee:newAccountant];
    
    DYYCarwashDirector *newDirector = [[[DYYCarwashDirector alloc] init] autorelease];
    [enterprise hireEmployee:newDirector];
    [newDirector setObservableEmployee:newAccountant];
    
    for (NSUInteger index = 0; index < workersQuantity; index++) {
        DYYCarwashWorker *newWorker = [[[DYYCarwashWorker alloc] init] autorelease];
        if (newWorker) {
            newWorker.washPrice = washPrice;
            [enterprise hireEmployee:newWorker];
            [enterprise setObservableEmployee:newWorker];
            [newAccountant setObservableEmployee:newWorker];
        }
    }
    
    return enterprise;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        self.mutableCarsQueue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark
#pragma mark - Public Methods

- (void)hireEmployee:(id)employee {
    @synchronized(self) {
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
        }
    }
}

- (void)addCarToCarwash:(DYYCar *)car {
    if (car != nil && [self.mutableCarsQueue count] < self.carsQueueLimit) {
        @synchronized(self) {
            [self.mutableCarsQueue addObject:car];
            for (DYYCarwashWorker *freeWorker in self.mutableEmployees) {
                if (freeWorker.employeeStatus == kDYYEmployeeFree
                    && [freeWorker class] == [DYYCarwashWorker class]) {
                    [self performSelectorInBackground:@selector(washCarQueueWithWorker:) withObject:freeWorker];
                    break;
                }
            }
        }
    }
}

- (void)washCarQueueWithWorker:(DYYCarwashWorker *)worker {
    for (DYYCar *car in self.mutableCarsQueue) {
        if (car.isClean == NO && [car isCarAbleToPay:worker.washPrice]) {
            [worker addObjectToProcess:car];
            [self.mutableCarsQueue removeObject:car];
            NSLog(@"Enterprise reports: car is clean, worker money = %lu, car money = %lu", worker.money, car.money);
            
            break;
        }
    }
}


#pragma mark
#pragma mark - Private Methods

- (void)itemIsFreeToWork:(id)item {
    @synchronized(item) {
        [self performSelectorInBackground:@selector(washCarQueueWithWorker:) withObject:item];
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
        @synchronized(employee) {
        [_observableEmployee removeObserver:self];
        [employee release];
        _observableEmployee = [employee retain];
        [employee addObserver:self];
        }
    }
}

@end

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

- (void)configureEnterpriseWorkersQuantity:(NSUInteger)workersQuantity
                       totalEmployeesLimit:(NSUInteger)employeesLimit
                                 washPrice:(NSUInteger)washPrice
{
    self.employeesLimit = employeesLimit;
    
    DYYCarwashAccountant *accountant = [[[DYYCarwashAccountant alloc] init] autorelease];
    [self hireEmployee:accountant];
    
    DYYCarwashDirector *director = [[[DYYCarwashDirector alloc] init] autorelease];
    [self hireEmployee:director];
    [director setObservableEmployee:accountant];
    
    for (NSUInteger index = 0; index < workersQuantity; index++) {
        DYYCarwashWorker *newWorker = [[[DYYCarwashWorker alloc] init] autorelease];
        if (newWorker) {
            newWorker.washPrice = washPrice;
            [self hireEmployee:newWorker];
            [self setObservableEmployee:newWorker];
            [accountant setObservableEmployee:newWorker];
            
        }
    }
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
                    [self washCarQueueWithWorker:freeWorker];
                    break;
                }
            }
        }
    }
}

- (void)washCarQueueWithWorker:(DYYCarwashWorker *)worker {
    @synchronized(self) {
    for (DYYCar *car in self.mutableCarsQueue) {
        if (car.isClean == NO) {
            [worker addObjectToProcess:car];
            [self.mutableCarsQueue removeObject:car];
            NSLog(@"Enterprise reports: car was transferred to worker's processing queue...");
            
            break;
            }
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
    return;
    }
- (void)itemIsBusy:(id)item {
    return;
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

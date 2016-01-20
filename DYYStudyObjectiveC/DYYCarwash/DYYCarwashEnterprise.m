//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"
#import "NSObject+DYYExtensions.h"
#import "DYYEmployee.h"
#import "DYYWorker.h"
#import "DYYDirector.h"
#import "DYYAccountant.h"

@interface DYYCarwashEnterprise()
@property (nonatomic, retain)   NSMutableArray   *mutableEmployees;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;

- (void)hireWorkers:(NSUInteger)workers withWashPrice:(NSUInteger)washPrice;
- (void)addEmployee:(DYYEmployee *)employee withObservers:(NSArray *)observers;
- (void)washCarQueueWithWorker:(DYYWorker *)worker;
- (void)resignEmployees;

@end

@implementation DYYCarwashEnterprise

static const NSUInteger kDYYWorkersCount = 5;
static const NSUInteger kDYYWashPrice = 5;

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    [self resignEmployees];
    self.mutableCarsQueue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        self.mutableCarsQueue = [NSMutableArray array];
        [self hireWorkers:kDYYWorkersCount withWashPrice:kDYYWashPrice];
    }
    
    return self;
}

#pragma mark
#pragma mark - Private Methods

- (id)freeEmployeeOfClass:(Class)class {
    for (DYYEmployee *employee in self.mutableEmployees) {
        if (employee.objectState == kDYYEmployeeFree
            && [employee isMemberOfClass:class])
        {
            return employee;
        }
    }
    
    return nil;
}

- (void)washCarQueueWithWorker:(DYYWorker *)worker {
    NSArray *cars = self.mutableCarsQueue;
    for (DYYCar *car in cars) {
            [worker performWorkWithObject:car];
//            [cars removeObject:car];
            NSLog(@"Enterprise reports: car was transferred to worker's processing queue...");
    }
}

- (void)addEmployee:(DYYEmployee *)employee withObservers:(NSArray *)observers {
    for (id observer in observers) {
        [employee addObserver:observer];
    }
    
    [self.mutableEmployees addObject:employee];
}

- (void)resignEmployees {
    id employees = self.mutableEmployees;
    NSUInteger count = [employees count];
    for (NSUInteger index = 0; index < count; index++) {
        DYYEmployee *employee = [employees objectAtIndex:index];
        for (id observer in employee.observers) {
            [employee removeObserver:observer];
        }
    }
}

- (void)employeeStartedWork:(id)employee {
        [self performSelector:@selector(washCarQueueWithWorker:) withObject:employee];
}

- (void)employeeDidBecomeStandBy:(id)employee {
}

- (void)employeeDidBecomeBusy:(id)employee {
}

#pragma mark
#pragma mark - Public Methods

- (void)hireWorkers:(NSUInteger)workers withWashPrice:(NSUInteger)washPrice
{
    DYYAccountant *accountant = [DYYAccountant object];
    DYYDirector *director = [DYYDirector object];
    
    [self addEmployee:accountant withObservers:@[director]];
    [self addEmployee:director withObservers:@[self]];
    
    for (NSUInteger index = 0; index < workers; index++) {
        DYYWorker *worker = [DYYWorker object];
        if (worker) {
            worker.washPrice = washPrice;
            [self addEmployee:worker withObservers:@[self, accountant]];
        }
    }
}

- (void)washCars:(NSArray *)cars {
    if (cars != nil && [self.mutableCarsQueue count] < self.carsQueueLimit) {
        self.mutableCarsQueue = [[cars copy] autorelease];
        DYYWorker *worker = [self freeEmployeeOfClass:[DYYWorker class]];
        [self washCarQueueWithWorker:worker];
    }
}

@end

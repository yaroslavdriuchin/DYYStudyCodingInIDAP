//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"
#import "DYYEmployee.h"
#import "DYYWorker.h"
#import "DYYDirector.h"
#import "DYYAccountant.h"

@interface DYYCarwashEnterprise()
@property (nonatomic, retain)   NSMutableArray   *mutableEmployees;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;
@property (nonatomic, assign)   NSUInteger       employeesLimit;

- (void)hireEmployee:(id)employee;
- (void)washCarQueueWithWorker:(DYYWorker *)worker;
- (id)new:(Class)objectClass;
- (void)resignEmployees;

@end

@implementation DYYCarwashEnterprise

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
    }
    
    return self;
}

#pragma mark
#pragma mark - Private Methods

- (void)hireEmployee:(id)employee {
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
    }
}


- (void)addCarsToCarwash:(NSArray *)cars {
    if (cars != nil && [self.mutableCarsQueue count] < self.carsQueueLimit) {
            self.mutableCarsQueue = [[cars copy] autorelease];
            DYYWorker *worker = [self returnFreeEmployeeOfClass:[DYYWorker class]];
            [self washCarQueueWithWorker:worker];
    }
}

- (id)returnFreeEmployeeOfClass:(Class)class {
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
            [worker addObjectToProcess:car];
//            [cars removeObject:car];
            NSLog(@"Enterprise reports: car was transferred to worker's processing queue...");
    }
}

- (id)new:(Class)objectClass {
    return [[[[objectClass class] alloc] init] autorelease];
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

- (void)employeeBecameStandBy:(id)employee {
}

- (void)employeeBecameBusy:(id)employee {
}

#pragma mark
#pragma mark - Public Methods

- (void)configureEnterpriseWorkersQuantity:(NSUInteger)workersQuantity
                       totalEmployeesLimit:(NSUInteger)employeesLimit
                                 washPrice:(NSUInteger)washPrice
{
    self.employeesLimit = employeesLimit;
    
    DYYAccountant *accountant = [DYYAccountant new];
    [self hireEmployee:accountant];
    
    DYYDirector *director = [DYYDirector new];
    [self hireEmployee:director];
    [accountant addObserver:director];
    
    for (NSUInteger index = 0; index < workersQuantity; index++) {
        DYYWorker *worker = [DYYWorker new];
        if (worker) {
            worker.washPrice = washPrice;
            [self hireEmployee:worker];
            [worker addObserver:self];
            [worker addObserver:accountant];
        }
    }
}

@end

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
//- (void)setObservableEmployee:(id)employee;
- (id)new:(Class)objectClass;

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
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
    }
}


- (void)addCarsToCarwash:(NSArray *)cars {
    if (cars != nil && [self.mutableCarsQueue count] < self.carsQueueLimit) {
            self.mutableCarsQueue = [[cars copy] autorelease];
            DYYWorker *worker = [self returnFreeWorker];
            [self washCarQueueWithWorker:worker];
    }
}

- (DYYWorker *)returnFreeWorker {
    for (DYYWorker *worker in self.mutableEmployees) {
        if (worker.employeeState == kDYYEmployeeFree
            && [worker class] == [DYYWorker class]) {
            return worker;
            
            break;
            }
        }
    
    return nil;
}

- (void)washCarQueueWithWorker:(DYYWorker *)worker {
    for (DYYCar *car in self.mutableCarsQueue) {
            [worker addObjectToProcess:car];
//            [self.mutableCarsQueue removeObject:car];
            NSLog(@"Enterprise reports: car was transferred to worker's processing queue...");
            
            break;
    }
}

#pragma mark
#pragma mark - Private Methods

- (void)employeeStartedWork:(id)employee {
        [self performSelector:@selector(washCarQueueWithWorker:) withObject:employee];
}

- (void)employeeBecameStandBy:(id)employee {
}

- (void)employeeBecameBusy:(id)employee {
}

- (id)new:(Class)objectClass {
    return [[[[objectClass class] alloc] init] autorelease];
}

@end

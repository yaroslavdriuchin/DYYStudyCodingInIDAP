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
        DYYCarwashWorker *worker = [[[DYYCarwashWorker alloc] init] autorelease];
        if (worker) {
            worker.washPrice = washPrice;
            [self hireEmployee:worker];
            [self setObservableEmployee:worker];
            [accountant setObservableEmployee:worker];
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


- (void)addCarsToCarwash:(NSArray *)cars {
    if (cars != nil && [self.mutableCarsQueue count] < self.carsQueueLimit) {
        @synchronized(self) {
            self.mutableCarsQueue = [[cars copy] autorelease];
            DYYCarwashWorker *worker = [self returnFreeWorker];
            [self washCarQueueWithWorker:worker];
        }
    }
}

- (DYYCarwashWorker *)returnFreeWorker {
    @synchronized(self) {
    for (DYYCarwashWorker *worker in self.mutableEmployees) {
        if (worker.employeeStatus == kDYYEmployeeFree
            && [worker class] == [DYYCarwashWorker class]) {
            return worker;
            
            break;
            }
        }
    }
    
    return nil;
}

- (void)washCarQueueWithWorker:(DYYCarwashWorker *)worker {
    @synchronized(self) {
    for (DYYCar *car in self.mutableCarsQueue) {
            [worker addObjectToProcess:car];
//            [self.mutableCarsQueue removeObject:car];
            NSLog(@"Enterprise reports: car was transferred to worker's processing queue...");
            
            break;
        }
        
    }
}


#pragma mark
#pragma mark - Private Methods

- (void)itemIsFreeToWork:(id)item {
    @synchronized(item) {
        [self performSelector:@selector(washCarQueueWithWorker:) withObject:item];
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
    @synchronized(employee) {
        [employee removeObserver:self];
        [employee release];
        [employee retain];
        [employee addObserver:self];
    }
}

@end

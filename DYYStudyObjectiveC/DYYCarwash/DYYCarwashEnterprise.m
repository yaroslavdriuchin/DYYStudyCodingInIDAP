//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"
#import "DYYCarwashEmployee.h"
#import "DYYCarwashWorker.h"
#import "DYYCarwashDirector.h"
#import "DYYCarwashAccountant.h"

@interface DYYCarwashEnterprise()

@property (nonatomic, retain)   NSMutableArray   *mutableEmployees;
@property (nonatomic, retain)   NSMutableArray   *mutableCarsQueue;

@end

@implementation DYYCarwashEnterprise

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableEmployees = nil;
    self.mutableCarsQueue = nil;
    [super dealloc];
}

+ (instancetype)enterpriseWithAttributes {
    return [[[self alloc] init] autorelease];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        self.mutableCarsQueue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesors

- (NSArray *)carsQueue {
    return [[self.mutableCarsQueue copy] autorelease];
}

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark
#pragma mark - Public Methods

- (BOOL)hireEmployee:(id)employee {
    if ([self.mutableEmployees count] < self.employeesLimit) {
        [self.mutableEmployees addObject:employee];
        return YES;
    }
    
    return NO;
}

- (void)addCarToCarwash:(DYYCarwashCar *)car {
    if ([self.mutableCarsQueue count] < self.carsQueueLimit) {
        @synchronized(car) {
            [self.mutableCarsQueue addObject:car];
            for (DYYCarwashWorker *freeWorker in self.mutableEmployees) {
                if (freeWorker.employeeStatus == kDYYEmployeeFree
                    && [freeWorker class] == [DYYCarwashWorker class]) {
                    [self performSelectorInBackground:@selector(washCarQueueWithWorker:) withObject:freeWorker];
                }
            }
        }
    }
}

- (void)washCarQueueWithWorker:(DYYCarwashWorker *)worker {
    for (DYYCarwashCar *car in self.mutableCarsQueue) {
        if (car.isClean == NO && [car isCarAbleToPay:self.washPrice]) {

                    [worker addCar:car];
                    if ([worker washCar:car] == YES) {
                        [car payMoneyAmount:self.washPrice];
                        [worker takeMoneyAmount:self.washPrice];
                        [self.mutableCarsQueue removeObject:car];
                        
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

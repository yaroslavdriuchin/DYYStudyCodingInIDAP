//
//  DYYCarwashWorker.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashWorker.h"
#import "DYYCarwashCar.h"

@interface DYYCarwashWorker ()

@property (nonatomic, retain)    NSMutableArray     *mutableObjectsProcessQueue;

@end

@implementation DYYCarwashWorker

#pragma mark -
#pragma mark Public Methods

- (void)addObjectToProcess:(id)object {
    if (object) {
        @synchronized(object) {
            if (self.employeeStatus == kDYYEmployeeBusy) {
                [self.mutableObjectsProcessQueue addObject:object];
            } else {
                    [self performPersonalFunctionWithObject:object];
                    }
        }
    }
}

- (void)washCar:(DYYCarwashCar *)car {
    if (car) {
        self.employeeStatus = kDYYEmployeeBusy;
        [self notifyObserversWithSelector:@selector(itemIsBusy:) withObject:self];
        car.isClean = YES;
        self.employeeStatus = kDYYEmployeeStandby;
        [self notifyObserversWithSelector:@selector(itemIsStandBy:) withObject:self];
        
        [self notifyObserversWithSelector:@selector(itemIsFreeToWork:) withObject:self];
        self.employeeStatus = kDYYEmployeeFree;
    }
}

- (void)performPersonalFunctionWithObject:(id)object {
    [self washCar:(DYYCarwashCar *)object];
}

@end

//
//  DYYCarwashTechnicalRoom.m
//  DYYStudyCoding
//
//  Created by Yar on 12/10/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashTechnicalRoom.h"

@interface DYYCarwashTechnicalRoom ()

@property (nonatomic, retain) NSMutableArray *mutableCars;

@end

@implementation DYYCarwashTechnicalRoom

+ (instancetype)carwashTechnicalRoomWithCars {
    return [[[self alloc] init] autorelease];
}

- (NSArray *)cars {
    return [[self.mutableCars copy] autorelease];
}

- (instancetype)init{
    self = [super init];
    if (self) {
        self.mutableCars = [NSMutableArray array];
        self.carsCapacity = arc4random_uniform(50);
        self.isFullWithCars = NO;
    }
    
    return self;
}

- (void)addCar:(DYYCarwashCar *)car {
    if (nil != car && [self.mutableCars count] < self.carsCapacity) {
        [self.mutableCars addObject:car];
    }
    
    else  {
            self.isFullWithCars = YES;
    }
}

- (void)removeCar:(DYYCarwashCar *)car {
    if (nil != car) {
        [self.mutableCars removeObject:car];
        if ([self.mutableCars count] < self.carsCapacity) {
            self.isFullWithCars = NO;
        }
    }
}

@end
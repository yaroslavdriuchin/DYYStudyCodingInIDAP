//
//  DYYCarwashTechnicalRoom.h
//  DYYStudyCoding
//
//  Created by Yar on 12/10/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashRoom.h"

@class DYYCarwashCar;

@interface DYYCarwashTechnicalRoom : DYYCarwashRoom

@property (nonatomic, readonly, assign) NSUInteger carsCapacity;
@property (nonatomic, retain)           NSArray    *cars;

+ (instancetype)carwashTechnicalRoomWithCarsCapacity:(NSUInteger)carsCapacity
                                   employeesCapacity:(NSUInteger)employeesCapacity;
- (instancetype)initTechnicalRoomWithCarsCapacity:(NSUInteger)carsCapacity
                                employeesCapacity:(NSUInteger)employeesCapacity;
- (void)addCar:(DYYCarwashCar *)car;
- (void)removeCar:(DYYCarwashCar *)car;

@end

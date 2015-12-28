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

@property (nonatomic, assign)             NSUInteger    carsCapacity;
@property (nonatomic, retain)             NSArray       *cars;
@property (nonatomic, assign)             BOOL          isFullWithCars;

+ (instancetype)carwashTechnicalRoomWithCars;
- (void)addCar:(DYYCarwashCar *)car;
- (void)removeCar:(DYYCarwashCar *)car;

@end

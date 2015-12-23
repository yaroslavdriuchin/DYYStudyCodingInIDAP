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
    return [[[self alloc] initTechnicalRoomWithCars] autorelease];
}

- (instancetype)initTechnicalRoomWithCars{
    self = [super init];
    if (self) {
        self.mutableCars = [NSMutableArray array];
        self.carsCapacity = arc4random_uniform(50);
        self.isFullWithCars = NO;
    }
    
    return self;
}

@end
//
//  DYYCarwashTechnicalRoom.h
//  DYYStudyCoding
//
//  Created by Yar on 12/10/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashOfficeRoom.h"

@interface DYYCarwashTechnicalRoom : DYYCarwashOfficeRoom

@property (nonatomic, readonly, assign) NSUInteger carsCapacity;
@property (nonatomic, retain)           NSArray    *cars;

@end

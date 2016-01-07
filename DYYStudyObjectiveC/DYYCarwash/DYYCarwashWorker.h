//
//  DYYCarwashWorker.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"

@class DYYCar;
@class DYYCarwashAccountant;

@interface DYYCarwashWorker: DYYEmployee

- (void)addObjectToProcess:(id)object;
- (void)washCar:(DYYCar *)car;
- (void)performPersonalFunctionWithObject:(id)object;

@end

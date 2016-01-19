//
//  DYYCarwashWorker.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"
@class DYYCar;
@class DYYAccountant;

@interface DYYWorker: DYYEmployee
@property (nonatomic, assign)   NSUInteger   washPrice;

- (void)washCar:(DYYCar *)car;

@end

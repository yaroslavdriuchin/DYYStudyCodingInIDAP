//
//  DYYCarwashEnterprise.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashObserverProtocol.h"
#import "DYYCar.h"
@class DYYWorker;

@interface DYYCarwashEnterprise : NSObject <DYYCarwashObserverProtocol>
@property (nonatomic, assign)     NSUInteger     carsQueueLimit;

- (void)washCars:(NSArray *)cars;

@end

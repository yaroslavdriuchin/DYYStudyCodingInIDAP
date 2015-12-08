//
//  DYYCarwashWorker.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEmployee.h"
@class DYYCarwashCar;
@class DYYCarwashAccountant;

@interface DYYCarwashWorker : DYYCarwashEmployee

- (void)washCar:(DYYCarwashCar *)car;
- (void)giveAllMoneyToAccountant:(DYYCarwashAccountant *)accountant;

@end

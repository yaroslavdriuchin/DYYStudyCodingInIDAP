//
//  DYYCarwashDirector.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"
@class DYYAccountant;

@interface DYYDirector : DYYEmployee

- (void)takeAccountantMoneyAndReport:(DYYAccountant *)object;
- (void)employeeDidBecomeFree:(id)employee;

@end

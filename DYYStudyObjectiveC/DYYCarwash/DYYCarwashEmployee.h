//
//  DYYCarwashEmployee.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYCarwashEmployee : NSObject

//current employee amount of money is calculated in Cents
@property (nonatomic, assign) uint32_t money;
@property (nonatomic, assign) uint32_t salary;
@property (nonatomic, assign) uint8_t  experienceYears;

@end

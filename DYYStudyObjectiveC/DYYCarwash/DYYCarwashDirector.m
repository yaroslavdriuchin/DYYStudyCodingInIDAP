//
//  DYYCarwashDirector.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashDirector.h"

@implementation DYYCarwashDirector

- (int32_t)calculateEnterpriseIncomeInDollars {
    NSLog(@"Director reports %u dollars", self.money % 100);
    
    return self.money;
}

@end

//
//  DYYCarwashDirector.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYEmployee.h"
@class DYYCarwashAccountant;

@interface DYYCarwashDirector : DYYEmployee

- (void)takeAccountantMoneyAndReport:(DYYCarwashAccountant *)object;
- (void)itemIsFreeToWork:(id)item;

@end

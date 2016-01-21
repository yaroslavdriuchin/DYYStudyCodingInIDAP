//
//  DYYCarwashCar.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashMoneyTransferProtocol.h"

@interface DYYCar : NSObject <DYYCarwashMoneyTransferProtocol>

@property (nonatomic, assign)   BOOL   isClean;

+ (instancetype)carWithAmountofMoney:(NSUInteger)money;
- (instancetype)initCarWithAmountofMoney:(NSUInteger)money;

@end

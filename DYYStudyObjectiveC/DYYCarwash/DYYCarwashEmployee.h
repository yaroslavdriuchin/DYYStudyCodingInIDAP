//
//  DYYCarwashEmployee.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashMoneyTransferProtocol.h"

@interface DYYCarwashEmployee : NSObject <DYYCarwashMoneyTransferProtocol>

//current employee amount of money is calculated in Cents
@property (nonatomic, assign) uint32_t money;
@property (nonatomic, assign) uint32_t salary;
@property (nonatomic, assign) uint8_t  experienceYears;

+ (void) giveMoneyAmount:(uint32_t)money toReciever:(id)reciever;

@end

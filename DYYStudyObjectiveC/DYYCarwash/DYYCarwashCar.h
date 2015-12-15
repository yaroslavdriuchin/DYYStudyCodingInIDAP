//
//  DYYCarwashCar.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCarwashMoneyTransferProtocol.h"

@interface DYYCarwashCar : NSObject <DYYCarwashMoneyTransferProtocol>

@property (nonatomic, assign)               BOOL        isClean;
@property (nonatomic, readwrite, assign)    uint32_t    money;

+ (instancetype)carWithAmountofMoney:(uint32_t)money;
- (instancetype)initCarWithAmountofMoney:(uint32_t)money;
- (void) giveMoneyAmount:(uint32_t)money toReciever:(id<DYYCarwashMoneyTransferProtocol>)reciever;
- (BOOL)isCar:(DYYCarwashCar *)car ableToPay:(uint32_t)price;
- (void)washCar:(DYYCarwashCar *)car;

@end

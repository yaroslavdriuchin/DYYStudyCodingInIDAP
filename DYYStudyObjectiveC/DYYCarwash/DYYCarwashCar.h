//
//  DYYCarwashCar.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYCarwashCar : NSObject

//Cleaniness of car: NO = dirty, YES = clean, money is calculated in Cents
@property (nonatomic, assign) BOOL     isClean;
@property (nonatomic, assign) uint32_t money;

//All cars are dirty by default, money is calculated in Cents
+ (instancetype)carWithAmountofMoney:(uint32_t)money;
- (instancetype)initCarWithAmountofMoney:(uint32_t)money;
- (BOOL)isCar:(DYYCarwashCar *)car ableToPay:(uint32_t)price;
- (void)washCar:(DYYCarwashCar *)car;

@end

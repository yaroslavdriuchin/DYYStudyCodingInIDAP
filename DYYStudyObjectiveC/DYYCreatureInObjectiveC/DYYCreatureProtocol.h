//
//  DYYCreatureProtocol.h
//  DYYStudyCoding
//
//  Created by Yar on 11/24/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYCreatureProtocol_h
#define DYYCreatureProtocol_h

#import <Foundation/Foundation.h>

@class DYYCreature;

typedef NS_ENUM (NSUInteger, DYYCreatureGender) {
    kDYYCreatureGenderUndefined = 0,
    kDYYCreatureGenderMale,
    kDYYCreatureGenderFemale,
};

@protocol DYYCreatureProtocol <NSObject>

@required

@property (nonatomic, assign)      uint16_t        age, weight;
@property (nonatomic, copy)        NSString        *name;
@property (nonatomic, copy)        NSSet           *children;

- (void)performGenderSpecificOperation;

@optional

- (void)sayHello;
- (void)sendCreatureToGiveBirth;
- (void)sendCreatureAtWar;

@end

#endif /* DYYCreatureProtocol_h */

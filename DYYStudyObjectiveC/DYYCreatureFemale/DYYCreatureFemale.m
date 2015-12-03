//
//  DYYCreatureFemale.m
//  DYYStudyCoding
//
//  Created by Yar on 11/24/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCreatureFemale.h"

#import "NSString+DYYExtensions.h"
#import "DYYCreatureProtocol.h"

@implementation DYYCreatureFemale

#pragma mark
#pragma mark - Public Methods

- (void)performGenderSpecificOperation {
    [self sendCreatureToGiveBirth];
}

- (void)sendCreatureToGiveBirth {
    NSString *name = [NSString randomStringWithMaxCapacity:10 alphabet:[NSString allLettersAlphabet]];
    static const uint32_t maxAge = 150;
    static const uint32_t maxWeight = 150;
    DYYCreatureGender randomGender = (DYYCreatureGender)(arc4random_uniform((int)(kDYYCreatureGenderUndefined)));
    DYYCreature *child = [DYYCreature creatureWithName:name
                                                   age:arc4random_uniform(maxAge)
                                                   weight:arc4random_uniform(maxWeight)
                                                   gender:randomGender];
    [self addChild:child];
    NSLog(@"Female creature gave birth to new creature. Congratulations!!!");
}

@end

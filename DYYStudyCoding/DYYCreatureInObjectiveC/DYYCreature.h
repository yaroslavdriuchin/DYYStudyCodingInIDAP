//
//  DYYCreatureInObjectiveC.h
//  DYYStudyCoding
//
//  Created by user on 11/19/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    kDYYCreatureGenderMale,
    kDYYCreatureGenderFemale,
    kDYYCreatureGenderUndefined,
} DYYCreatureGender;

@interface DYYCreature : NSObject

@property (nonatomic) DYYCreatureGender gender;
@property (nonatomic) uint16_t age, weight;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, copy) NSObject *children;
@property (nonatomic) BOOL creatureAtWar;

+ (void)sayHello;
- (void)sayHello;
- (void)setName:(NSString *) inputName andAge: (uint16_t) inputAge andWeight: (uint16_t) inputWeight;
- (BOOL)sendCreatureAtWar;
- (NSObject *)setChildrenArray;
- (BOOL)addChild: (DYYCreature *)object;
- (BOOL)removeChild: (DYYCreature *)object;

@end

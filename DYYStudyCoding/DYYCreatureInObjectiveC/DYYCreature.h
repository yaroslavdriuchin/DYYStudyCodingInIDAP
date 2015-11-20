//
//  DYYCreatureInObjectiveC.h
//  DYYStudyCoding
//
//  Created by user on 11/19/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger) {
    kDYYCreatureGenderMale,
    kDYYCreatureGenderFemale,
    kDYYCreatureGenderUndefined,
} DYYCreatureGender;

@interface DYYCreature : NSObject

@property (nonatomic, assign) DYYCreatureGender   gender;
@property (nonatomic, assign) uint16_t            age, weight;
@property (nonatomic, copy)   NSString            *name;
@property (nonatomic, copy)   NSSet               *children;
@property (nonatomic, assign) BOOL                creatureAtWar;

+ (DYYCreature *) createCreature;
+ (DYYCreature *) createCreatureWithName: (NSString *) inputName andAge: (uint16_t) inputAge andWeight: (uint16_t) inputWeight;
- (instancetype) init;
- (instancetype) initWithName:(NSString *) inputName andAge: (uint16_t) inputAge andWeight: (uint16_t) inputWeight;
- (void) sayHello;
- (BOOL) sendCreatureAtWar;
//- (NSObject *)setChildrenArray;
//- (BOOL)addChild: (DYYCreature *)object;
//- (BOOL)removeChild: (DYYCreature *)object;

@end

//
//  DYYCreatureInObjectiveC.h
//  DYYStudyCoding
//
//  Created by user on 11/19/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, DYYCreatureGender) {
    kDYYCreatureGenderMale = 1,
    kDYYCreatureGenderFemale,
    kDYYCreatureGenderUndefined,
} ;

@interface DYYCreature : NSObject

@property (nonatomic, assign) DYYCreatureGender   gender;
@property (nonatomic, assign) uint16_t            age, weight;
@property (nonatomic, copy)   NSString            *name;
@property (nonatomic, copy)   NSSet               *children;
@property (nonatomic, assign) BOOL                creatureAtWar;

+ (DYYCreature *)createCreature;
+ (DYYCreature *)creatureWithName:(NSString *) inputName age:(uint16_t) inputAge weight:(uint16_t) inputWeight;
- (instancetype)init;
- (instancetype)initWithName:(NSString *) inputName age:(uint16_t) inputAge weight:(uint16_t) inputWeight;
- (void)sayHello;
- (BOOL)sendCreatureAtWar;
- (NSSet *)children;
- (BOOL)addChild: (DYYCreature *)object;
- (BOOL)removeChild: (DYYCreature *)object;

@end

//
//  DYYCreatureInObjectiveC.h
//  DYYStudyCoding
//
//  Created by user on 11/19/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYCreatureProtocol.h"

@interface DYYCreature : NSObject <DYYCreatureProtocol>

@property (nonatomic, assign)           uint16_t            age, weight;
@property (nonatomic, copy)             NSString            *name;
@property (nonatomic, copy)             NSSet               *children;

+ (DYYCreature *)creatureWithName:(NSString *) inputName
                             age:(uint16_t) inputAge
                             weight:(uint16_t) inputWeight
                             gender:(DYYCreatureGender) gender;
- (instancetype)init;
- (instancetype)initWithName:(NSString *) inputName
                        age:(uint16_t) inputAge
                        weight:(uint16_t) inputWeight
                        gender:(DYYCreatureGender) gender;
- (NSSet *)children;
- (BOOL)addChild:(id<DYYCreatureProtocol>)object;
- (BOOL)removeChild:(id<DYYCreatureProtocol>)object;
- (void)performGenderSpecificOperation;
- (void)sayHello;

@end

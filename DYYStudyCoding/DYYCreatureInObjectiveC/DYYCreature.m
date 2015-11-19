//
//  DYYCreatureInObjectiveC.m
//  DYYStudyCoding
//
//  Created by user on 11/19/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
#pragma mark -
#pragma mark Private Declarations

#import "DYYCreature.h"
#import "DYYCreatureArrayOfChildren.h"

#pragma mark -
#pragma mark Public Implementations

@implementation DYYCreature

+ (void)sayHello
{
    NSLog(@"Hello!");
}

- (void)sayHello
{
    [super sayHello];
}

- (void)setName:(NSString *) inputName andAge: (uint16_t) inputAge andWeight: (uint16_t) inputWeight
{
    if(name != inputName) {
        name = [NSString stringWithString: inputName];
    }
    age    = inputAge;
    weight = inputWeight;
}

- (BOOL)sendCreatureAtWar
{
    [self creatureAtWar: YES];
    NSLog(@"Creature was sent to war");
}

- (NSObject *)setChildrenArray
{
    return children = [DYYCreatureArrayOfChildren initChildrenArrayObject];
}


- (BOOL)addChild: (DYYCreature *)object
{
    if (nil != object) {
            [DYYCreatureArrayOfChildren addObject: object];
    }
}

- (BOOL)removeChild: (DYYCreature *)object
{
    if (nil != object) {
        [DYYCreatureArrayOfChildren removeObject: object];
    }
}

@end

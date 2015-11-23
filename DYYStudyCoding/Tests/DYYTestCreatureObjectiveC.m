//
//  DYYTestCreatureObjectiveC.m
//  DYYStudyCoding
//
//  Created by user on 11/20/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYTestCreatureObjectiveC.h"


@implementation DYYTestCreatureObjectiveC

+ (void) DYYTestCreatureInit {
    @autoreleasepool {
        DYYCreature *objectOne = [DYYCreature createCreature];
        DYYCreature *objectTwo = [DYYCreature creatureWithName: @"Vasya" age: 45 weight: 45];
        [objectOne sayHello];
    }
}

@end
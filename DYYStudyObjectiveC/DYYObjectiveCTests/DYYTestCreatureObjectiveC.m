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
        //initializing object 1 without properties
        DYYCreature *objectOne = [DYYCreature createCreature];
        
        //initializing object 2 with properties
        DYYCreature *objectTwo = [DYYCreature creatureWithName: @"Olya" age: 45 weight: 45 gender: kDYYCreatureGenderMale];
        
        //testing if object 1 can say Hello
        [objectOne sayHello];
        
        //initializing object 3 with properties
        DYYCreature *objectThree = [DYYCreature creatureWithName: @"Petya" age: 55 weight: 75 gender: kDYYCreatureGenderFemale];
        
        //Adding children to object 2, it is Object 3 and Object 1
        [objectTwo addChild: objectThree];
        [objectTwo addChild: objectOne];
        
        //Let object 2 say Hello, expecting, Object 3 and Object 1 to say Hello as well
        [objectTwo sayHello];
        
        
        //removing children of object 2
        [objectTwo removeChild: objectThree];
        [objectTwo removeChild: objectOne];
        
        
        //        NSSet *childrenToCheck = [[objectTwo children] autorelease];
        //        NSLog(childrenToCheck);
    }
}

@end
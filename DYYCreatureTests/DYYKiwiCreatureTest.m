//
//  DYYKiwiCreatureTest.m
//  DYYStudyCoding
//
//  Created by Yar on 12/9/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Kiwi/Kiwi.h>
#import "DYYCreature.h"
#import "DYYCreatureMale.h"

SPEC_BEGIN(DYYKiwiCreatureTest)

describe(@"Testigng of DYYCreature in Kiwi", ^{
    context(@"Testing behavior of DYYCreature", ^{
        
        //initializing object 1 without properties and performing assertion test
        DYYCreature *objectOne = [DYYCreature creatureWithName: @"Mr. Babaykin" age: 45 weight: 100 gender: kDYYCreatureGenderMale];
        NSAssert(nil != objectOne, @"Object One sucks");
        
        //Performing assertion test on test object's data fields
        NSAssert(nil != objectOne.name, @"Name is null, it sucks");
        NSAssert(0 != objectOne.age,  @"Age is null, it sucks");
        NSAssert(0 != objectOne.weight, @"Weight is null, it sucks");
        
        //checking if class of created creature is DYYCreatureMale as expected
        [[objectOne should] beKindOfClass:[DYYCreatureMale class]];
        
        //initializing object 2 with properties and performing assertion test
        DYYCreature *objectTwo = [DYYCreature creatureWithName: @"Olya" age: 30 weight: 45 gender: kDYYCreatureGenderFemale];
        NSAssert(nil != objectTwo, @"Object Two sucks");
        
        //initializing object 3 with properties and performing assertion test
        DYYCreature *objectThree = [DYYCreature creatureWithName: @"Petya" age: 55 weight: 75 gender: kDYYCreatureGenderMale];
        NSAssert(nil != objectThree, @"Object Threee sucks");
        
        //Adding children to object 2, it is Object 3 and Object 1
        [objectTwo addChild: objectThree];
        [objectTwo addChild: objectOne];
        
        //checking if children was added to Object 2 set, performing assertion test
        NSSet *childrenToCheck = [objectTwo children];
        NSAssert(nil != childrenToCheck, @"Object Two kids not being added");
        
        //Let object 2 say Hello, expecting, Object 3 and Object 1 to say Hello as well
        [objectTwo sayHello];
        
        //removing children of object 2, checking if removing of kids was sucessful with assertion
        NSAssert(YES == [objectTwo removeChild: objectThree], @"Object Two child was not successfully replaced");
        NSAssert(YES == [objectTwo removeChild: objectOne], @"Object Two child was not successfully replaced");
        
        //adding 3 creatures to an array of object
        NSArray *creatures = [NSArray arrayWithObjects:objectOne, objectTwo, objectThree, nil];
        
        //performing gender-specific operation on all objects in array, expecting different response from Male and Femaloe creatures
        for(DYYCreature *creature in creatures) {
        [creature performGenderSpecificOperation];
            
        });
    });

SPEC_END

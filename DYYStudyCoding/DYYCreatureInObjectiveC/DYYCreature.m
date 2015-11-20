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

@interface DYYCreature()

@property (nonatomic, readwrite, retain) NSMutableSet *mutableChildren;

@end

@implementation DYYCreature

//@dynamic children;

#pragma mark -
#pragma mark Class Methods
+ (DYYCreature *) createCreature {
    return [[[self alloc] init] autorelease];
}

+ (DYYCreature *) createCreatureWithName: (NSString *) inputName andAge: (uint16_t) inputAge andWeight: (uint16_t) inputWeight {
    return [[[self alloc] initWithName: inputName andAge:inputAge andWeight:inputWeight] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocators

- (void) dealloc {
    self.name = nil;
    self.children = nil;
    
    [super dealloc];
}

- (instancetype) init {
    self = [super init];
    _mutableChildren = [NSMutableSet set];
    
    return self;
}

- (instancetype) initWithName:(NSString *) inputName andAge: (uint16_t) inputAge andWeight: (uint16_t) inputWeight {
    self = [super init];
    
    if (self.name != inputName) {
        self.name = [NSString stringWithString: inputName];
    }
    self.age    = inputAge;
    self.weight = inputWeight;
    _mutableChildren = [NSMutableSet set];
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void) sayHello {
    NSLog(@"Hello!");
    for (DYYCreature *child in self.children) {
        [child sayHello];
    }
}


- (BOOL) sendCreatureAtWar {
    self.creatureAtWar = YES;
    NSLog(@"Creature was sent to war");
    return self.creatureAtWar;
}

//- (NSObject *)setChildrenArray
//{
//    return children = [DYYCreatureArrayOfChildren initChildrenArrayObject];
//}


//- (BOOL)addChild: (DYYCreature *)object
//{
//    if (nil != object) {
//            [DYYCreatureArrayOfChildren addObject: object];
//    }
//}
//
//- (BOOL)removeChild: (DYYCreature *)object
//{
//    if (nil != object) {
//        [DYYCreatureArrayOfChildren removeObject: object];
//    }
//}
//

@end

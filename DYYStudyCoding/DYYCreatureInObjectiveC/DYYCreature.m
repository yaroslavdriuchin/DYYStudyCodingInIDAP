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
@class DYYCreatureArrayOfChildren;

@interface DYYCreature()

@property (nonatomic, readwrite, retain) NSMutableSet *mutableChildren;

@end

@implementation DYYCreature

@dynamic children;

#pragma mark -
#pragma mark Class Methods

+ (DYYCreature *)createCreature {
    return [[[self alloc] init] autorelease];
}

+ (DYYCreature *)creatureWithName:(NSString *) inputName age:(uint16_t) inputAge weight:(uint16_t) inputWeight {
    return [[[self alloc] initWithName: inputName age:inputAge weight:inputWeight] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    [_name release];
    [_children release];
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
    _mutableChildren = [NSMutableSet set];
    _name = [NSString init];
        
    }
    
    return self;
}

- (instancetype)initWithName:(NSString *) inputName age:(uint16_t) inputAge weight:(uint16_t) inputWeight {
    self = [self init];
    
    _name = [NSString stringWithString: inputName];
    _mutableChildren = [NSMutableSet set];
    _age    = inputAge;
    _weight = inputWeight;
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)sayHello {
    NSLog(@"Hello!");
    for (DYYCreature *child in self.children) {
        [child sayHello];
    }
}

- (BOOL)sendCreatureAtWar {
    self.creatureAtWar = YES;
    NSLog(@"Creature was sent to war");
    return self.creatureAtWar;
}

- (NSSet * )children {
    return [[self.mutableChildren copy] autorelease];
}

- (BOOL)addChild: (DYYCreature *)object {
    if (nil != object) {
        [self.mutableChildren addObject: object];
        [object retain];
    }
}

- (BOOL)removeChild: (DYYCreature *)object {
    if (nil != object) {
        [self.mutableChildren removeObject: object];
        [object release];
    }
}

@end

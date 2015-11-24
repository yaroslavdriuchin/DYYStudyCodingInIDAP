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

@class DYYCreatureMale;

@class DYYCreatureFemale;


@interface DYYCreature()

@property (nonatomic, readwrite, retain) NSMutableSet *mutableChildren;

- (Class)classForGender:(DYYCreatureGender)gender;

@end


@implementation DYYCreature

@dynamic gender;

#pragma mark -
#pragma mark Class Methods

+ (DYYCreature *)createCreature {
    return [[[self alloc] init] autorelease];
}

+ (DYYCreature *)creatureWithName:(NSString *) inputName
                             age:(uint16_t) inputAge
                             weight:(uint16_t) inputWeight
                             gender:(DYYCreatureGender)gender {
    return [[[self alloc] initWithName: inputName age:inputAge weight:inputWeight gender:gender] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.name = nil;
    self.children = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableChildren = [NSMutableSet set];
        
    }
    
    return self;
}

- (Class)classForGender:(DYYCreatureGender)gender {
    Class result = nil;
    if (gender == kDYYCreatureGenderMale) {
        result = [DYYCreatureMale class];
        }
    if (gender == kDYYCreatureGenderFemale) {
        result = [DYYCreatureFemale class];
    }
    
    return result;
}

- (instancetype)initWithName:(NSString *)inputName
                        age:(uint16_t)inputAge
                        weight:(uint16_t)inputWeight
                        gender:(DYYCreatureGender)gender
{
    Class objectClass = [self classForGender:gender];
    
    if (objectClass) {
        [self release];
    }
    
    self = [[objectClass alloc] init];
    
    if (self) {
    self.name = [NSString stringWithString: inputName];
    self.mutableChildren = [NSMutableSet set];
    self.age    = inputAge;
    self.weight = inputWeight;
    }
    
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

- (void)sendCreatureToGiveBirth {
    NSLog(@"Creature was sent to give birth to beautiful babies");
}

- (void)sendCreatureAtWar {
    NSLog(@"Creature was sent to war");
}

- (NSSet * )children {
    return [[self.mutableChildren copy] autorelease];
}

- (BOOL)addChild: (id<DYYCreatureProtocol>)object {
    if ([object conformsToProtocol:@protocol(DYYCreatureProtocol)]) {
        [self.mutableChildren addObject: object];
        
        return YES;
    }
    
    return NO;
}

- (BOOL)removeChild: (id<DYYCreatureProtocol>)object {
    if ([object conformsToProtocol:@protocol(DYYCreatureProtocol)]) {
        [self.mutableChildren removeObject: object];
        
        return YES;
    }
    
    return NO;
}

#pragma mark -
#pragma mark DYYCreatureProtocol

- (void)performGenderSpecificOperation {
    return;
}

@end

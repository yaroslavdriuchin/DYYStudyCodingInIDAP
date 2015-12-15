//
//  DYYCarwashBuilding.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashBuilding.h"

@interface DYYCarwashBuilding()

@property (nonatomic, retain) NSMutableArray *mutableRooms;

@end

@implementation DYYCarwashBuilding

#pragma mark -
#pragma mark Initializations and Deallocators

- (void)dealloc {
    self.mutableRooms = nil;
    
    [super dealloc];
}

+ (instancetype)buildingWithRoom {
    return [[[self alloc] initBuildingWithRoom] autorelease];
}

- (instancetype)initBuildingWithRoom {
    self = [super init];
    if (self) {
    self.mutableRooms = [NSMutableArray array];
    }

    return self;
}

- (NSArray *)rooms {
    return [[self.mutableRooms copy] autorelease];
}

- (void)addRoomToBuilding:(DYYCarwashBuilding *)building {
    if (nil != building) {
        DYYCarwashRoom *newRoom = [[[DYYCarwashRoom alloc] init] autorelease];
        [self.mutableRooms addObject:newRoom];
    }
}

@end

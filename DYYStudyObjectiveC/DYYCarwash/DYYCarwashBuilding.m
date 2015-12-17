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

+ (instancetype)buildingWithRooms {
    return [[[self alloc] initBuildingWithRooms] autorelease];
}

- (instancetype)initBuildingWithRooms {
    self = [super init];
    if (self) {
    self.mutableRooms = [NSMutableArray array];
    }

    return self;
}

- (void)removeBuilding:(DYYCarwashBuilding *)building {
    [self.mutableRooms removeAllObjects];
    [self dealloc];
}

#pragma mark -
#pragma mark Public Methods

- (NSArray *)rooms {
    return [[self.mutableRooms copy] autorelease];
}

- (void)addRoomOfClass:(Class)roomClass {
    if ([self.mutableRooms count] < self.roomsCapacity) {
        id newRoom = [[[roomClass alloc] init] autorelease];
        [self.mutableRooms addObject:newRoom];
    }
}

- (NSArray *)findRoomsOfClass:(Class)roomClass {
    NSMutableArray *roomsOfClass = [NSMutableArray array];
    for (id room in self.mutableRooms) {
        if ([room isMemberOfClass:roomClass]) {
            [roomsOfClass addObject:room];
        }
    }
    
    return [[roomsOfClass copy] autorelease];
}

- (DYYCarwashTechnicalRoom *)findFreeTechnicalRoom {
    NSArray *technicalRooms = [self findRoomsOfClass:[DYYCarwashTechnicalRoom class]];
    for (DYYCarwashTechnicalRoom *room in technicalRooms) {
        if (room.isFull == NO) {
            return room;
            
            break;
        }
    }
    
    return nil;
}

- (DYYCarwashRoom *)findFreeRoom {
    NSArray *rooms = [self findRoomsOfClass:[DYYCarwashRoom class]];
    for (DYYCarwashRoom *room in rooms) {
        if (room.isFull == NO) {
            return room;
            
            break;
        }
    }
    
    return nil;
}

@end

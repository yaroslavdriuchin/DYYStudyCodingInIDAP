//
//  DYYCarwashRoom.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashRoom.h"

@interface DYYCarwashRoom()

@property (nonatomic, retain) NSMutableArray *mutableEmployees;

@end

@implementation DYYCarwashRoom

#pragma mark -
#pragma mark Initializations and Deallocators

+ (instancetype)carwashRoomWithEmployees {
    return [[[self alloc] init] autorelease];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        self.employeesCapacity = arc4random_uniform(50);
        self.isFull = NO;
        }
    
    return self;
}

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

- (void)removeRoom:(DYYCarwashRoom *)room {
    [self.mutableEmployees removeAllObjects];
    [self dealloc];
}

- (void)addEmployee:(id)employee {
    if (nil != employee && [self.mutableEmployees count] < self.employeesCapacity) {
        [self.mutableEmployees addObject:employee];
        
    }
}

- (void)removeEmployee:(id)employee {
    if (nil != employee) {
        [self.mutableEmployees removeObject:employee];
    }
}


@end

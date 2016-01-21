//
//  DYYQueue.m
//  DYYStudyCoding
//
//  Created by Yar on 1/21/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import "DYYQueue.h"
#import "NSObject+DYYExtensions.h"

@interface DYYQueue ()
@property (nonatomic, retain)    NSMutableArray    *mutableObjects;

@end

@implementation DYYQueue

@dynamic count;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.mutableObjects = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    self.mutableObjects = [NSMutableArray object];
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSUInteger)count {
        return [self.mutableObjects count];
}

#pragma mark-
#pragma mark Public Methods

- (void)enqueue:(id)object {
    [self.mutableObjects addObject:object];
}

- (id)dequeue {
    id object = [self.mutableObjects firstObject];
    
    if (object) {
        [self.mutableObjects removeObject:object];
    }
    
    return object;
}

@end

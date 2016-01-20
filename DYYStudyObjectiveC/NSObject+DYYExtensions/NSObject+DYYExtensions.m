//
//  NSObject+DYYExtensions.m
//  DYYStudyCoding
//
//  Created by Yar on 1/20/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import "NSObject+DYYExtensions.h"

@implementation NSObject (DYYExtensions)

+ (instancetype)object {
    return [[[self alloc] init] autorelease];
}

+ (NSArray *)objectsWithCount:(NSUInteger)count {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:count];
    for (NSUInteger index = 0; index < count; index++) {
        [result addObject:[self object]];
    }
    
    return [[result copy] autorelease];
}

@end


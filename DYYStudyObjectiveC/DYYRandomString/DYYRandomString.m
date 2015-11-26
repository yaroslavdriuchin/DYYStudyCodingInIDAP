//
//  DYYRandomString.m
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYRandomString.h"

@implementation DYYRandomString

+ (NSString *)initRandomStringWithMaxCapacity:(uint16_t)capacity encoding:(NSStringEncoding)encoding {
    NSMutableString *string = [NSMutableString stringWithCapacity:capacity];
    for (uint16_t index = 0; index < capacity; index++) {
        [string appendFormat:@"%C", (unichar)('a' + arc4random_uniform(36))];
        }
    NSString *outputString = [NSString stringWithCString:(char *)string encoding:encoding];
    
    return outputString;
}

@end

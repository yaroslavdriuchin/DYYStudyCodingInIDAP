//
//  DYYRandomString.m
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYRandomString.h"

@implementation DYYRandomString

+ (NSString *)randomStringWithMaxCapacity:(uint16_t)capacity
                                   alphabet:(NSString *)alphabet {
    NSMutableString *string = [NSMutableString stringWithCapacity:capacity];
    for (uint16_t index = 0; index < capacity; index++) {
        [string appendFormat:@"%C", (unichar)([alphabet characterAtIndex:(NSUInteger)arc4random_uniform(alphabet.length)])];
        }
//    NSString *outputString = [NSString stringWithCString:(char *)string encoding:encoding];
    
    return string;
}

@end

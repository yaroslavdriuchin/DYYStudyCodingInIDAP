//
//  DYYRandomString.m
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "NSString+DYYExtensions.h"

@implementation NSString (DYYExtensions)

+ (id)alphanumericAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self allLettersAlphabet]];
    [result appendString:[self numericAlphabet]];
     
     return [self stringWithString:result];
}
//     
//+ (id)numericAlphabet {
//    
//}
//+ (id)lowercaseAlphabet {
//    
//}
//+ (id)capitalsAlphabet {
//    
//}
//
//+ (id)allLettersAlphabet {
//         
//}

+ (NSString *)randomStringWithMaxCapacity:(NSUInteger)capacity
                                 alphabet:(NSString *)alphabet {
    NSMutableString *string = [NSMutableString stringWithCapacity:capacity];
    for (uint16_t index = 0; index < capacity; index++) {
        [string appendFormat:@"%C", (unichar)([alphabet characterAtIndex:(NSUInteger)arc4random_uniform(alphabet.length)])];
        }
    
    return [self stringWithString:string];
}

+ (id)alphabetWithUnicodeRange:(NSRange)range {
    NSMutableString *result = [NSMutableString string];
    for (unichar character = range.location; character < NSMaxRange(range); character++) {
        [result appendFormat:@"%c", character];
    }
    
    return [self stringWithString:result];
}

@end

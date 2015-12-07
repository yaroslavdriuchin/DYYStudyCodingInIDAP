//
//  DYYRandomString.m
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "NSString+DYYExtensions.h"

@implementation NSString (DYYExtensions)

#pragma mark
#pragma mark - Public Methods

+ (instancetype)alphanumericAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self allLettersAlphabet]];
    [result appendString:[self numericAlphabet]];
    
    return [self stringWithString:result];
}

+ (instancetype)numericAlphabet {
    return [self alphabetWithUnicodeRange:NSMakeRange('0', '9' - '0' + 1)];
}
+ (instancetype)lowercaseAlphabet {
    return [self alphabetWithUnicodeRange:NSMakeRange('a', 'z' - 'a' + 1)];
}
+ (instancetype)capitalsAlphabet {
    return [self alphabetWithUnicodeRange:NSMakeRange('A', 'Z' - 'A' + 1)];
}

+ (instancetype)allLettersAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self lowercaseAlphabet]];
    [result appendString:[self capitalsAlphabet]];
    
    return [self stringWithString:result];
         
}

+ (NSString *)randomStringWithMaxCapacity:(NSUInteger)capacity
                                 alphabet:(NSString *)alphabet {
    NSMutableString *string = [NSMutableString stringWithCapacity:capacity];
    for (uint16_t index = 0; index < capacity; index++) {
        unichar resultChar = [alphabet characterAtIndex:(NSUInteger)arc4random_uniform((uint32_t)alphabet.length)];
        [string appendFormat:@"%c", resultChar];
        }
    
    return [self stringWithString:string];
}

+ (instancetype)alphabetWithUnicodeRange:(NSRange)range {
    NSMutableString *result = [NSMutableString string];
    for (unichar character = range.location; character < NSMaxRange(range); character++) {
        [result appendFormat:@"%c", character];
    }
    
    return [self stringWithString:result];
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id[])stackbuf
                                    count:(NSUInteger)len
{
    state->mutationsPtr = (unsigned long *)self;
    
    NSUInteger length = MIN(state->state + len, self.length);
    NSUInteger resultLength = length - state->state;
    
    if (0 != resultLength) {
        for (NSUInteger index = 0; index < resultLength; index++) {
            stackbuf[index] = [self characterAtIndex:index];
        }
    }
    state->itemsPtr = stackbuf;
    state->state +=resultLength;
    
    return resultLength;
}
@end

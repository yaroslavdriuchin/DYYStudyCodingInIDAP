//
//  DYYRandomString.h
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (DYYExtensions)

+ (instancetype)alphanumericAlphabet;
+ (instancetype)numericAlphabet;
+ (instancetype)lowercaseAlphabet;
+ (instancetype)capitalsAlphabet;
+ (instancetype)allLettersAlphabet;
+ (instancetype)alphabetWithUnicodeRange:(NSRange)range;

+ (NSString *)randomStringWithMaxCapacity:(NSUInteger)capacity
                                 alphabet:(NSString *)alphabet;

@end

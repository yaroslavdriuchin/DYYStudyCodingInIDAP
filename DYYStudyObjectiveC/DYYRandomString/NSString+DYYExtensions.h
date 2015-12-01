//
//  DYYRandomString.h
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (DYYExtensions)

+ (id)alphanumericAlphabet;
+ (id)numericAlphabet;
+ (id)lowercaseAlphabet;
+ (id)capitalsAlphabet;
+ (id)allLettersAlphabet;

+(id)alphabetWithUnicodeRange:(NSRange)range;

+ (NSString *)randomStringWithMaxCapacity:(NSUInteger)capacity
                                alphabet:(NSString *)alphabet;

@end

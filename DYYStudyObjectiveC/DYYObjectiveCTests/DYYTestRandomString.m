//
//  DYYTestRandomString.m
//  DYYStudyCoding
//
//  Created by Yar on 11/30/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYTestRandomString.h"

#import "NSString+DYYExtensions.h"

@implementation DYYTestRandomString

+ (void) DYYTestRandomStringOutput {
    
    //defining custom alphabet of letters and digits
    NSString *alphabetOne = [NSString alphanumericAlphabet];
    
    //generating string of given length using alphabet, checking with assertion zero responce from string and proper length
    NSString *randomStringOne = [NSString randomStringWithMaxCapacity:15 alphabet:alphabetOne];
    NSAssert (nil != randomStringOne, @"String is null, so bad");
    NSAssert ([randomStringOne length] == 15, @"String length is not as expected");
    
    //defining custom alphabet of letters only
    NSString *alphabetTwo = [NSString allLettersAlphabet];
    
    //generating string of given length using alphabet, checking with assertion zero responce from string and proper length
    NSString *randomStringTwo = [NSString randomStringWithMaxCapacity:10 alphabet:alphabetTwo];
    NSAssert (nil != randomStringTwo, @"String is null, so bad");
    NSAssert ([randomStringTwo length] == 10, @"String length is not as expected");
    
    //generating custom alphabet of digits
    NSString *alphabetThree = [NSString numericAlphabet];
    
    //generating string of given length using alphabet, checking with assertion zero responce from string and proper length
    NSString *randomStringThree = [NSString randomStringWithMaxCapacity:35 alphabet:alphabetThree];
    NSAssert (nil != randomStringThree, @"String is null, so bad");
    NSAssert ([randomStringThree length] == 35, @"String length is not as expected");
}

@end

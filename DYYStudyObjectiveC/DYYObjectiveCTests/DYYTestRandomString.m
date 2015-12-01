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
    
    //defining custom alphabet of letters, symbols and digits
    NSString *alphabet = @"qwertyiuop[]\afsdghjlk;'zxcvbnmm,../1234567890-=+_";
    
    //generating string of given length using alphabet, checking with assertion zero responce from string and proper length
    NSString *randomStringOne = [DYYRandomString randomStringWithMaxCapacity:15 alphabet:alphabet];
    NSAssert (nil != randomStringOne, @"String is null, so bad");
    NSAssert ([randomStringOne length] == 15, @"String length is not as expected");
    
    //defining custom alphabet of cyrillic letters
    NSString *alphabetCyrillic = @"йцукенгшщзхъфывапролджэячсмьбю";
    
    //generating string of given length using alphabet, checking with assertion zero responce from string and proper length
    NSString *randomStringTwo = [DYYRandomString randomStringWithMaxCapacity:10 alphabet:alphabetCyrillic];
    NSAssert (nil != randomStringTwo, @"String is null, so bad");
    NSAssert ([randomStringTwo length] == 10, @"String length is not as expected");
}

@end

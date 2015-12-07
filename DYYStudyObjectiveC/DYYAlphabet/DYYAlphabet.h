//
//  DYYAlphabet.h
//  DYYStudyCoding
//
//  Created by Yar on 12/2/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+DYYExtensions.h"

@interface DYYAlphabet : NSObject <NSFastEnumeration>

@property (nonatomic, assign) NSRange range;
@property (nonatomic, copy)   NSArray *alphabets;
@property (nonatomic, copy)   NSArray *strings;

+ (instancetype)rangeAlphabet:    (NSRange)   range;
+ (instancetype)stringsAlphabet:  (NSArray  *)strings;
+ (instancetype)alphabetsAlphabet:(NSArray  *)alphabets;

- (void)dealloc;
- (instancetype)initRangeAlphabet:    (NSRange)   range;
- (instancetype)initStringsAlphabet:  (NSArray  *)strings;
- (instancetype)initAlphabetsAlphabet:(NSArray  *)alphabets;


@end

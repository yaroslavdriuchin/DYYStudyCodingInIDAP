//
//  DYYAlphabet.m
//  DYYStudyCoding
//
//  Created by Yar on 12/2/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYAlphabet.h"

@implementation DYYAlphabet

#pragma mark
#pragma mark - Class Methods

+ (instancetype)rangeAlphabet:    (NSRange)   range {
    return nil;
    
}
+ (instancetype)stringsAlphabet:  (NSArray  *)strings {
    return nil;
    
}
+ (instancetype)alphabetsAlphabet:(NSArray  *)alphabets {
    return nil;
    
}

#pragma mark
#pragma mark - Iitializations And Deallocations

- (void)dealloc  {
    self.strings   = nil;
    self.alphabets = nil;
    
    [super dealloc];
}


- (instancetype)initRangeAlphabet:    (NSRange)   range {
    self = [super init];
    
    if (self) {
        self.range = range;
    }
    
    return self;
}

- (instancetype)initStringsAlphabet:  (NSArray  *)strings {
     self = [super init];
    
    if (self) {
        self.strings = strings;
    }
    
    return self;
}

- (instancetype)initAlphabetsAlphabet:(NSArray  *)alphabets {
    self = [super init];
    
    if (self) {
        self.alphabets = alphabets;
    }
    
    return self;
}

#pragma mark
#pragma mark - NSFastEnumeration

- (NSUInteger) countByEnumeratingWithState:(NSFastEnumerationState *)state
                                   objects:(id  _Nonnull *)buffer
                                     count:(NSUInteger)len {
    return 0;
    }

    
@end

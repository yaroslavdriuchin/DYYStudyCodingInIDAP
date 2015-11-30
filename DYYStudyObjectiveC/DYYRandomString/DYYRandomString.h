//
//  DYYRandomString.h
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYRandomString : NSMutableString

+ (NSString *)randomStringWithMaxCapacity:(uint16_t)capacity
                                alphabet:(NSString *)alphabet;

@end

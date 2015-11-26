//
//  DYYRandomString.h
//  DYYStudyCoding
//
//  Created by Yar on 11/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYRandomString : NSMutableString

+ (NSString *)initRandomStringWithMaxCapacity:(uint16_t)capacity encoding:(NSStringEncoding)encoding;

@end

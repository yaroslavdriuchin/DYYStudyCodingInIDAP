//
//  DYYQueue.h
//  DYYStudyCoding
//
//  Created by Yar on 1/21/16.
//  Copyright © 2016 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYQueue : NSObject

@property (nonatomic, readonly)   NSUInteger   count;

- (void)enqueue:(id)object;
- (id)dequeue;

@end

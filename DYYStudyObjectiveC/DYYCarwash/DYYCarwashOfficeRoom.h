//
//  DYYCarwashRoom.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYCarwashOfficeRoom : NSObject

@property (nonatomic, readonly, assign)  NSUInteger   employeesCapacity;
@property (nonatomic, retain)            NSArray      *employees;

- (void)addItem:(id)item;
- (void)removeItem:(id)item;

@end

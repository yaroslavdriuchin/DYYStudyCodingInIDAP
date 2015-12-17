//
//  DYYCarwashRoom.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DYYCarwashRoom : NSObject

@property (nonatomic, readonly, assign)    NSUInteger    employeesCapacity;
@property (nonatomic, retain)              NSArray       *employees;
@property (nonatomic, readonly, assign)    BOOL          isFull;

+ (instancetype)carwashRoomWithEmployeesCapacity:(NSUInteger)employeesCapacity;
- (instancetype)initRoomWithEmployeesCapacity:(NSUInteger)employeesCapacity;
- (void)addEmployee:(id)employee;
- (void)removeEmployee:(id)employee;

@end

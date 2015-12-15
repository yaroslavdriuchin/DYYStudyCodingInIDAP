//
//  DYYCarwashBuilding.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DYYCarwashRoom;

//@protocol DYYCarwashBuildingDelegate <NSObject>
//
//- (void)
//
//@end

@interface DYYCarwashBuilding : NSObject

@property (nonatomic, readonly, assign)    NSUInteger   roomsCapacity;
@property (nonatomic, retain)              NSArray      *rooms;
//@property (nonatomic, assign) id<DYYCarwashBuildingDelegate> delegate;

+ (instancetype)buildingWithRoom;
- (instancetype)initBuildingWithRoom;
- (NSArray *)rooms;
- (void)addRoomToBuilding:(DYYCarwashBuilding *)building;
- (instancetype)findFreeRoomOfClass:(Class)roomClass;

@end

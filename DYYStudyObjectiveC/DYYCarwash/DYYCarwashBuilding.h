//
//  DYYCarwashBuilding.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

//@protocol DYYCarwashBuildingDelegate <NSObject>
//
//- (void)
//
//@end


@interface DYYCarwashBuilding : NSObject

@property (nonatomic, readonly, assign)    NSUInteger   roomsCapacity;
@property (nonatomic, readonly, retain)    NSArray      *rooms;
//@property (nonatomic, assign) id<DYYCarwashBuildingDelegate> delegate;

+ (instancetype)buildingWithRoom;
- (instancetype)initBuildingWithRoom;
- addRoomToBuilding:(DYYCarwashBuilding *)building;
- removeRoomFromBuilding:(DYYCarwashBuilding *)building;

@end

//
//  DYYCarwashBuilding.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
@class DYYCarwashRoom;

typedef NS_ENUM (NSUInteger, DYYCarwashBuildingType) {
    kDYYCarwashBuildingBox = 0,
    kDYYCarwashBuildingOffice,
    dDYYCarwashBuildingUndefined
};

@interface DYYCarwashBuilding : NSObject

@property (nonatomic, readonly, assign) NSUInteger roomsCapacity;
@property (nonatomic, readonly, retain) NSArray    *rooms;

+ (instancetype)createBuildingOfType:(DYYCarwashBuildingType)buildingType;
- (instancetype)initWithBuildingType:(DYYCarwashBuildingType)buildingType;
- addRoomToBuilding:     (DYYCarwashBuilding *)building;
- removeRoomFromBuilding:(DYYCarwashBuilding *)building;

@end

//
//  DYYCarwashBuilding.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, DYYCarwashBuildingType) {
    kDYYCarwashBuilding = 0,
    kDYYCarwashTechnicalBuilding,
    kDYYCarwashBuildingUndefined
};

//@protocol DYYCarwashBuildingDelegate <NSObject>
//
//- (void)
//
//@end


@interface DYYCarwashBuilding : NSObject

@property (nonatomic, readonly, assign) NSUInteger roomsCapacity;
@property (nonatomic, readonly, retain) NSArray    *officeRooms;
//@property (nonatomic, assign) id<DYYCarwashBuildingDelegate> delegate;

+ (instancetype)buildingOfType:(DYYCarwashBuildingType)buildingType;
- (instancetype)initBuildingOfType:(DYYCarwashBuildingType)buildingType;
- addRoomToBuilding:(DYYCarwashBuilding *)building;
- removeRoomFromBuilding:(DYYCarwashBuilding *)building;

@end

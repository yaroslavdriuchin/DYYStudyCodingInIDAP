//
//  DYYCarwashEnterprise.m
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCarwashEnterprise.h"

@implementation DYYCarwashEnterprise

#pragma mark
#pragma mark - Public Methods

- (instancetype)buildCarwashBuilding {
    DYYCarwashBuilding *building = [[DYYCarwashBuilding alloc] initBuildingWithRoom];
    return building;
}


#pragma mark
#pragma mark - DYYCarwashWorker observer

- (void)setObservableWorker:(DYYCarwashWorker *)worker {
    if (_observableWorker != worker) {
        [_observableWorker removeObserver:self];
        [worker release];
        _observableWorker = [worker retain];
        [worker addObserver:self];
    }
}

@end

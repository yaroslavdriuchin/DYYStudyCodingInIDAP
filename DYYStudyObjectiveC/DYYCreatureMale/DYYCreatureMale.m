//
//  DYYCreatureMale.m
//  DYYStudyCoding
//
//  Created by Yar on 11/24/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import "DYYCreatureMale.h"

@implementation DYYCreatureMale

- (void)performGenderSpecificOperation {
    [self sendCreatureAtWar];
}

- (void)sendCreatureAtWar {
    NSLog(@"Male creature was sent to war to kill other creatures");
}
@end

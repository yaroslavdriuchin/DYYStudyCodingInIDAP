//
//  main.m
//  DYYStudyObjectiveC
//
//  Created by user on 11/19/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYYTestCreatureObjectiveC.h"
#import "DYYTestRandomString.h"
#import "DYYCarwashBasicTest.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        [DYYTestCreatureObjectiveC DYYTestCreature];
//        [DYYTestRandomString DYYTestRandomStringOutput];
        [DYYCarwashBasicTest runCarwashBasicTest];
        
    }
    return 0;
}

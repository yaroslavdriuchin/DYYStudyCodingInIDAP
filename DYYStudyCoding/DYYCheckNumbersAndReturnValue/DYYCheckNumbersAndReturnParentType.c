//
//  DYYCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.

#include "DYYCheckNumbersAndReturnParentType.h"
#include <stdio.h>

#pragma mark -
#pragma mark Private Declarations

static const int kCheckNumberOne   = 15;
static const int kCheckNumberTwo   =  5;
static const int kCheckNumberThree =  3;

#pragma mark -
#pragma mark Private Implementations

DYYParentType DYYCheckNumbersAndReturnParentType(int inputNumber) {

    DYYParentType outputValue = kDYYParentTypeUndefined;
    
    if (inputNumber == 0) {
        return outputValue;
    }
    else
        if (0 == inputNumber % kCheckNumberOne) {
            printf("MAMAPAPA");
            outputValue = kDYYParentTypeMamaPapa;
        }
        else
            if (0 == inputNumber % kCheckNumberTwo) {
                printf("PAPA");
                outputValue = kDYYParentTypePapa;
            }
            else
                if (0 == inputNumber % kCheckNumberThree) {
                    printf("MAMA");
                    outputValue = kDYYParentTypeMama;
                    
                }
    return outputValue;
}
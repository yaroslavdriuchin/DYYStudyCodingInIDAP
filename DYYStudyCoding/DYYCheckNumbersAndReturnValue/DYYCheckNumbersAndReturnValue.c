//
//  DYYCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.

#include "DYYCheckNumbersAndReturnValue.h"
#include <stdio.h>

#pragma mark -
#pragma mark Private Declarations

const int kCheckNumberOne = 15;
const int kCheckNumberTwo = 5;
const int kCheckNumberThree = 3;

#pragma mark -
#pragma mark Private Implementations

DYYParentType DYYCheckNumbers(int inputNumber)
{
    DYYParentType outputValue = kDYYParentTypeUndefined;
    if (inputNumber == 0) {
        return outputValue;
    }
    else
    if (inputNumber % kCheckNumberOne == 0 ) {
        printf("MAMAPAPA");
        outputValue = kDYYParentTypeMamaPapa;
        }
    else
    if ( inputNumber % kCheckNumberTwo == 0 ) {
        printf("PAPA");
        outputValue = kDYYParentTypePapa;
        }
    else
    if ( inputNumber % kCheckNumberThree == 0 ) {
        printf("MAMA");
        outputValue = kDYYParentTypeMama;
    
    }
        return outputValue;
}
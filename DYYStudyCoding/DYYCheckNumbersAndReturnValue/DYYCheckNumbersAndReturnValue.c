//
//  DYYCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.

#include "DYYCheckNumbersAndReturnValue.h"

#pragma mark -
#pragma mark Private Declarations

const int kCheckNumberOne = 15;
const int kCheckNumberTwo = 5;
const int kCheckNumberThree = 3;

#pragma mark -
#pragma mark Private Implementations

DYYParentType DYYCheckNumbers(int InputNumber)
{
    DYYParentType OutputValue = kDYYParentTypeUndefined;
   
    
    if (InputNumber % kCheckNumberOne == 0 ) {
        printf("MAMAPAPA");
        OutputValue = kDYYParentTypeMamaPapa;
        } else if ( InputNumber % kCheckNumberTwo == 0 ) {
        printf("PAPA");
        OutputValue = kDYYParentTypePapa;
        } else if ( InputNumber % kCheckNumberThree == 0 ) {
        printf("MAMA");
        OutputValue = kDYYParentTypeMama;
    }
    
        return OutputValue;
}
//
//  DYYCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.

#include "DYYCheckNumbersAndReturnValue.h"

DYYParentType DYYCheckNumbers(int InputNumber)
{
    DYYParentType OutputValue;
    const int a = 15;
    const int b = 5;
    const int c = 3;
    
    if (InputNumber % a == 0 ) {
        printf("MAMAPAPA");
        OutputValue = kDYYParentTypeMamaPapa;
        return OutputValue;
    }
else
    if ( InputNumber % b == 0 ) {
        printf("PAPA");
        OutputValue = kDYYParentTypePapa;
        return OutputValue;
    }
else
    if ( InputNumber % c == 0 ) {
        printf("MAMA");
        OutputValue = kDYYParentTypeMama;
        return OutputValue;
    }
else
    return OutputValue = kDYYParentTypeUndefined;
}
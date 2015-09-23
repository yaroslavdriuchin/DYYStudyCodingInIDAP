//
//  DYYStructureAlignment.c
//  DYYStudyCoding
//
//  Created by Yar on 9/23/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYStructureAlignment.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#pragma mark -
#pragma mark Private Declarations

// #pragma pack(1)

typedef struct randomOrder {
    bool boolData1;
    bool boolData2;
    bool boolData3;
    bool boolData4;
    bool boolData5;
    bool boolData6;
    float floatData1;
    int intData1;
    long long longLongData1;
    short shortData1;
    short shortData2;
    short shortData3;
    double doubleData1;
    char string[6];
}structRandom;

#pragma mark -
#pragma mark Private Implementations

void ReturnStructOffsetValue() {
    printf("\nSize of structure in bytes: %lu\n", sizeof(structRandom));
    printf("Offset of 'randomOrder.boolData1' is %lu", offsetof(structRandom, doubleData1));
    }
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
    float floatData1;
    bool boolData2;
    bool boolData3;
    bool boolData4;
    bool boolData5;
    double doubleData1;
    bool boolData6;
    int intData1;
    long long longLongData1;
    short shortData1;
    short shortData2;
    short shortData3;
    char string[6];
}structRandom;

typedef struct optimizedOrder {
    double doubleData1;
    long long longLongData1;
    char string[6];
    float floatData1;
    int intData1;
    short shortData1;
    short shortData2;
    short shortData3;
    bool boolData1;
    bool boolData2;
    bool boolData3;
    bool boolData4;
    bool boolData5;
    bool boolData6;
}structOptimized;

typedef struct optimizedBoolsUnionOrder {
    double doubleData1;
    long long longLongData1;
    char string[6];
    float floatData1;
    int intData1;
    short shortData1;
    short shortData2;
    short shortData3;
    union boolsUnion {
        bool boolData1;
        bool boolData2;
        bool boolData3;
        bool boolData4;
        bool boolData5;
        bool boolData6;
    };
}structOptimizedUnionBools;

#define DYYMacroSizeOutput(structName) printf("\nSize of " #structName " structure in bytes: %lu\n", sizeof(structName))
#define DYYMacroStructMemberOffset(structName, structMemberName) \
printf("\nOffset of " #structMemberName " in " #structName" structure is %lu", offsetof(structName, structMemberName));

#pragma mark -
#pragma mark Private Implementations

void DYYReturnStructSize() {
    DYYMacroSizeOutput(structRandom);
    DYYMacroSizeOutput(structOptimized);
    DYYMacroSizeOutput(structOptimizedUnionBools);
}

void DYYReturnStructOffsetValue() {
    DYYMacroStructMemberOffset(structRandom, boolData1);
    DYYMacroStructMemberOffset(structRandom, floatData1);
    DYYMacroStructMemberOffset(structRandom, boolData2);
    DYYMacroStructMemberOffset(structRandom, boolData3);
    DYYMacroStructMemberOffset(structRandom, boolData4);
    DYYMacroStructMemberOffset(structRandom, boolData5);
    DYYMacroStructMemberOffset(structRandom, doubleData1);
    DYYMacroStructMemberOffset(structRandom, boolData6);
    DYYMacroStructMemberOffset(structRandom, intData1);
    DYYMacroStructMemberOffset(structRandom, longLongData1);
    DYYMacroStructMemberOffset(structRandom, shortData1);
    DYYMacroStructMemberOffset(structRandom, shortData2);
    DYYMacroStructMemberOffset(structRandom, shortData3);
    DYYMacroStructMemberOffset(structRandom, string [6]);
    }
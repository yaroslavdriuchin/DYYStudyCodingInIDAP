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
#include <string.h>

#pragma mark -
#pragma mark Private Declarations

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
} DYYstructRandom;

typedef struct optimizedOrder {
    long long longLongData1;
    double doubleData1;
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
} DYYstructOptimized;

typedef struct optimizedBoolsUnionOrder {
    double doubleData1;
    long long longLongData1;
    char string[6];
    float floatData1;
    int intData1;
    short shortData1;
    short shortData2;
    short shortData3;
    union allBoolsUnion {
         struct {
                bool boolData1 : 1;
                bool boolData2 : 1;
                bool boolData3 : 1;
                bool boolData4 : 1;
                bool boolData5 : 1;
                bool boolData6 : 1;
         };
        char DYYAllBoolFlags;
    } allBoolsUnion;
} DYYstructOptimizedUnionBools;

#define DYYMacroSizeOutput(structName) printf("\nSize of " #structName " structure in bytes: %lu\n", sizeof(structName))

#define DYYMacroStructMemberOffset(structName, structMemberName) \
        printf("\nOffset of " #structMemberName " in " #structName" structure is %lu",\
                offsetof(structName, structMemberName));

#define DYYMacroStructRandomOffset(memberName) DYYMacroStructMemberOffset(DYYstructRandom, memberName);
#define DYYMacroStructOptimizedOffset(memberName) DYYMacroStructMemberOffset(DYYstructOptimized, memberName);
#define DYYMacroStructOptimizedBoolsOffset(memberName) DYYMacroStructMemberOffset(DYYstructOptimizedUnionBools, memberName);

#pragma mark -
#pragma mark Private Implementations

void DYYReturnStructSize() {
    DYYMacroSizeOutput(DYYstructRandom);
    DYYMacroSizeOutput(DYYstructOptimized);
    DYYMacroSizeOutput(DYYstructOptimizedUnionBools);
}

void DYYReturnStructOffsetValue() {
    DYYMacroStructRandomOffset(boolData1);
    DYYMacroStructRandomOffset(floatData1);
    DYYMacroStructRandomOffset(boolData2);
    DYYMacroStructRandomOffset(boolData3);
    DYYMacroStructRandomOffset(boolData4);
    DYYMacroStructRandomOffset(boolData5);
    DYYMacroStructRandomOffset(doubleData1);
    DYYMacroStructRandomOffset(boolData6);
    DYYMacroStructRandomOffset(intData1);
    DYYMacroStructRandomOffset(longLongData1);
    DYYMacroStructRandomOffset(shortData1);
    DYYMacroStructRandomOffset(shortData2);
    DYYMacroStructRandomOffset(shortData3);
    DYYMacroStructRandomOffset(string [6]);
    printf("\n");
    DYYMacroStructOptimizedOffset(longLongData1);
    DYYMacroStructOptimizedOffset(doubleData1);
    DYYMacroStructOptimizedOffset(string[6]);
    DYYMacroStructOptimizedOffset(floatData1);
    DYYMacroStructOptimizedOffset(intData1);
    DYYMacroStructOptimizedOffset(shortData1);
    DYYMacroStructOptimizedOffset(shortData2);
    DYYMacroStructOptimizedOffset(shortData3);
    DYYMacroStructOptimizedOffset(boolData1);
    DYYMacroStructOptimizedOffset(boolData2);
    DYYMacroStructOptimizedOffset(boolData3);
    DYYMacroStructOptimizedOffset(boolData4);
    DYYMacroStructOptimizedOffset(boolData5);
    DYYMacroStructOptimizedOffset(boolData6);
    printf("\n");
    DYYMacroStructOptimizedBoolsOffset(doubleData1);
    DYYMacroStructOptimizedBoolsOffset(longLongData1);
    DYYMacroStructOptimizedBoolsOffset(string[6]);
    DYYMacroStructOptimizedBoolsOffset(floatData1);
    DYYMacroStructOptimizedBoolsOffset(intData1);
    DYYMacroStructOptimizedBoolsOffset(shortData1);
    DYYMacroStructOptimizedBoolsOffset(shortData2);
    DYYMacroStructOptimizedBoolsOffset(shortData3);
    DYYMacroStructOptimizedBoolsOffset(allBoolsUnion);
}
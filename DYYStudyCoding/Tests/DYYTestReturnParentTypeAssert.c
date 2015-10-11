//
//  DYYTestCheckNumbersAssert.c
//  DYYStudyCoding
//
//  Created by Yar on 9/17/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//
//Testing DYYCheckNumbersAndReturnParentType functionality using assert command with custom input numbers and parent types

#include <stdio.h>
#include <assert.h>
#include "DYYTestReturnParentTypeAssert.h"
#include "DYYCheckNumbersAndReturnParentType.h"
//this macro performing DYYCheckNumbersAndReturnParentType method call and defining output value for certain parent type
#define DYYMacroTestParentTypeWithAssert(testNumber, parentType) DYYParentType returnValue##parentType = parentType;\
         returnValue##parentType = DYYCheckNumbersAndReturnParentType(testNumber);\
                    assert(kDYYParentTypeUndefined != returnValue##parentType);\
                                assert (parentType == returnValue##parentType)

void DYYTestReturnParentTypeAssert() {
printf ("\nRunning assert testing process\n");
//checking method functionality with value = 12 and corresponding kDYYParentTypeMama
        DYYMacroTestParentTypeWithAssert(12, kDYYParentTypeMama);
//checking method functionality with value = 25 and corresponding kDYYParentTypePapa
        DYYMacroTestParentTypeWithAssert(25, kDYYParentTypePapa);
//checking method functionality with value = 45 and corresponding kDYYParentTypeMamaPapa
        DYYMacroTestParentTypeWithAssert(45, kDYYParentTypeMamaPapa);
printf ("     Assert testing process passed");                          //if test passed confirm to console
    }





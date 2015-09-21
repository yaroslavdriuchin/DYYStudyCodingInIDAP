//
//  DYYTestCheckNumbersAssert.c
//  DYYStudyCoding
//
//  Created by Yar on 9/17/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//
//This is test for checking DYYCheckNumbers functionality using assert command and custom input number = 5

#include "DYYTestCheckNumbersAssert.h"

void DYYTestCheckNumbersAssert() {
printf ("Running assert testing process with argument = 5.....\n");
    DYYParentType ReturnValue = kDYYParentTypeUndefined;
    ReturnValue = DYYCheckNumbers(5);
    //running assert testing process....
    assert(kDYYParentTypeUndefined != ReturnValue);
    assert (kDYYParentTypePapa == ReturnValue );
    //if test passed confirm to console
printf ("     Assert testing process passed");
    }





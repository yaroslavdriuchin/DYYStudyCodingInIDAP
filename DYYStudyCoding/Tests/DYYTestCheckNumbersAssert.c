//
//  DYYTestCheckNumbersAssert.c
//  DYYStudyCoding
//
//  Created by Yar on 9/17/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//
//This is test for checking DYYCheckNumbers functionality using assert command and custom input number = 5

#include <stdio.h>
#include <assert.h>
#include "DYYTestCheckNumbersAssert.h"

/*using assert process for testing if output value of DYYCheckNumbers function with custom input
coincide with expected output*/
void DYYTestCheckNumbersAssert() {
printf ("\nRunning assert testing process with argument = 5.....\n");
    DYYParentType returnValue = kDYYParentTypeUndefined;      //defining returnValue as function output type and assigning a default value
    returnValue = DYYCheckNumbers(5);                         //checking DYYCheckNumbers with argument = 5
    assert(kDYYParentTypeUndefined != returnValue);           //checking if function output value not equal to preassigned value
    assert (kDYYParentTypePapa == returnValue );              //checking if function output value equal to expected value
printf ("     Assert testing process passed");                //if test passed confirm to console
    }





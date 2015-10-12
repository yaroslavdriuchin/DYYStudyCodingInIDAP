//
//  DYYTestCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/17/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//
//  Running 1000 iterations on input value of DYYTestCheckNumbersAndReturnParentType method, checking method output and printed values,
//  expected MAMA for all values %3, expected PAPA for all values %5, expected PAPAMAMA for all values %15,
//  0 output expected for the rest of input values

#include <stdio.h>
#include "DYYTestCheckNumbersAndReturnParentType.h"
#include "DYYCheckNumbersAndReturnParentType.h"

//This is test function for checking DYYCheckNumbers functionality with 1000 iterations incrementing input numbers
void DYYTestCheckNumbersAndReturnParentType(void) {
    int returnValue;
    for (int counter = 0; counter <= 1000; counter++)
    {
        printf ("Test input number: %d", counter);
        printf ("      Function printed output:  ");
        returnValue = DYYCheckNumbersAndReturnParentType(counter);                         //function output value is calculated for current counter
        printf ("      Function return value:  %d\n", returnValue);     //function output value is printed out 
    
    }
}
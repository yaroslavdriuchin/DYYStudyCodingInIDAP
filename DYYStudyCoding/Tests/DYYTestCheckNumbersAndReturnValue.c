//
//  DYYTestCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/17/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdio.h>
#include "DYYTestCheckNumbersAndReturnValue.h"
#include "DYYCheckNumbersAndReturnValue.h"

//This is test function for checking DYYCheckNumbers functionality with 1000 iterations incrementing input numbers
void DYYTestCheckNumbersAndReturnValue() {
    int returnValue;
    for (int counter = 0; counter <= 1000; counter++)
    {
        printf ("Test input number: %d", counter);
        printf ("      Function printed output:  ");
        returnValue = DYYCheckNumbers(counter);                         //function output value is calculated for current counter
        printf ("      Function return value:  %d\n", returnValue);     //function output value is printed out 
    
    }
}
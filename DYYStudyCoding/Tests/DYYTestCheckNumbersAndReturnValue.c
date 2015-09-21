//
//  DYYTestCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/17/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//
//This is test for checking DYYCheckNumbers function with 1000 iterations for changing input numbers 

#include "DYYTestCheckNumbersAndReturnValue.h"
#include "DYYCheckNumbersAndReturnValue.h"


void DYYTestCheckNumbersAndReturnValue()
{
    //defining function's return value
    int ReturnValue;
    
    for (int counter = 1; counter <= 1000; counter++)
    {
        printf ("Test input number: %d", counter);
        printf ("      Function printed output:  ");
        ReturnValue = DYYCheckNumbers(counter);
        printf ("      Function return value:  %d\n", ReturnValue);
    
    }
}
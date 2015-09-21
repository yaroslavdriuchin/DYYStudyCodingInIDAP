//
//  main.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include "DYYCheckNumbersAndReturnValue.h"
#include "DYYSizeOfCheck.h"
#include "DYYTestCheckNumbersAssert.h"

#pragma mark -
#pragma mark Private Declarations

int inputNumber;

#pragma mark -
#pragma mark Private Implementations

main(int argc, const char * argv[]) {
    printf("Starting with Sizeof command demonstration....""\n""\n");   // Introduction to program functionality
    sleep(1);
    SizeofCheckType ();
    printf("\n""Moving to part 2.....""\n""\n");    // First and second part of program separator
    sleep(1);
    printf("Please, input your number:\n");     //Inputting number to check for 3,5,15
    scanf("%d",&inputNumber);
    DYYCheckNumbers(inputNumber);               // My custom function for checking 3,5,15
    printf("\n""\n""Running 1000 iterations test.....""\n""\n");
    sleep(1);
    DYYTestCheckNumbersAndReturnValue();         //Running 1000 iterations test
    DYYTestCheckNumbersAssert();
    
    return 0;
    }

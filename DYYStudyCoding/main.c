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


void main()

{
    // Introduction to program functionality
    printf("Starting with Sizeof command demonstration....""\n""\n");
    
    sleep(1);
    
    SizeofCheckType ();
    
    // First and second part of program separator
    printf("\n""Moving to part 2.....""\n""\n");
    
    sleep(1);
    
    int MyInputNumber;
    
    //Inputting number to check for 3,5,15
    printf("Please, input your number:\n");
    
    scanf("%d",&MyInputNumber);
    
    DYYCheckNumbers(MyInputNumber);  // My custom function for checking 3,5,15
    
    printf("\n""\n""Running 1000 iterations test.....""\n""\n");
    
    sleep(2);

    //Running 1000 iterations test
    
    DYYTestCheckNumbersAndReturnValue();
    
    DYYTestCheckNumbersAssert();
    
}

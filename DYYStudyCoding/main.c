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


void main()

{
    printf("Starting with Sizeof command demonstration....""\n""\n"); // Introduction to program functionality
    
    sleep(1);
    
    SizeofCheckType ();
    
    printf("\n""Moving to part 2.....""\n""\n"); // First and second part of program separator
    
    sleep(1);
    
    int MyInputNumber;
    
    printf("Please, input your number:\n"); //Inputting number to check for 3,5,15
    
    scanf("%d",&MyInputNumber);
    
    DYYCheckNumbers(MyInputNumber);  // My custom function for checking 3,5,15
    
    
}

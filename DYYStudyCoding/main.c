//
//  main.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdio.h>
//#include <unistd.h>
//#include "DYYCheckNumbersAndReturnValue.h"
//#include "DYYTestCheckNumbersAndReturnValue.h"
//#include "DYYSizeOfCheck.h"
//#include "DYYTestCheckNumbersAssert.h"
//#include "DYYMacroMethodGenerator.h"
#include "DYYStructureAlignment.h"
#include "DYYDecimalToBinaryOutputTranslator.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

int main(int argc, const char * argv[]) {
    int inputNumber;
//    printf("Starting with Sizeof command demonstration....""\n""\n");
//    DYYSizeofCheckType ();                          //printing data type sizes using custom DYYSizeofCheckType function
////    printf("\n""Moving to part 2.....""\n""\n");
//    printf("Please, input your number:\n");
//    scanf("%d",&inputNumber);                       //Inputting number to check if it can be divided by 3,5,15 with remainder = 0
//    DYYCheckNumbers(inputNumber);                   //Checking input number with DYYCheckNumbers custom function
//    printf("\n""\n""Running 1000 iterations test.....""\n""\n");
//    DYYTestCheckNumbersAndReturnValue();            //Running 1000 iterations test for testing DYYCheckNumbers function
//    DYYTestCheckNumbersAssert();                     //Running assertion test for testing YYCheckNumbers function
//    DYYMacroMethodGenerator();
    DYYReturnStructSize();
    DYYReturnStructOffsetValue();
    DYYDecimalToBinaryTranslator(11, undefinedEndian);
    
    return 0;
    }

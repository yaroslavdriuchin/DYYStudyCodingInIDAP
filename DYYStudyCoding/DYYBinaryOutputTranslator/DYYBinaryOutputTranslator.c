//
//  DYYBinaryOutputTranslator.c
//  DYYStudyCoding
//
//  Created by Yar on 9/28/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYBinaryOutputTranslator.h"
#include <stdbool.h>

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Private Implementations

//Function takes input of any type and outputs corressponding binary value for that
void DYYDecimalToBinaryTranslator(void) {
    printf ("\n\n");
    int inputNumber = 115;
    bool bitorderSpecifier = false;                                       //flag of Little Endian or Big Endian bit order true=Big false=Little
    if (bitorderSpecifier == true) {
    printf ("Binary value of %d in Big Endian order is ", inputNumber);
    for (int count = sizeof(inputNumber) << 3; count > 0; count--) {
        if (((inputNumber >> (count-1)) & 1)!=0)                           //bytes of value are compared to 1 in descending order and outputs corresponding bit to console
            printf ("1");
            else
            printf("0");
    }
     printf ("\n");
}
    else {
        printf ("Binary value of %d in Little Endian order is ", inputNumber);
        for (int count = 0; count < sizeof(inputNumber)<<3; count++) {
            if ((inputNumber & (1 << count)) != 0)                           //1 number is moving in acsending order and being compared to bits of value input
                printf ("1");
            else
                printf("0");
        }
        printf ("\n");
    }
}
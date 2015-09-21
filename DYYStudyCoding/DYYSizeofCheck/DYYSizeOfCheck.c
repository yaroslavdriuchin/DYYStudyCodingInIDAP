//
//  DYYSizeOfCheck.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#pragma mark -
#pragma mark Private Declarations

int integer;
char character;
float floating;
unsigned long unsignedLong;
long double longDouble;

#pragma mark -
#pragma mark Private Implementations

void SizeofCheckType(void) {
    printf ("The lenght of Integer data type is %lu \n", sizeof(integer));
    printf ("The lenght of Char data type is %lu \n", sizeof(character));
    printf ("The lenght of Float data type is %lu\n", sizeof(floating));
    printf ("The lenght of Unsigned Long data type is %lu\n", sizeof(unsignedLong));
    printf ("The lenght of Long Double data type is %lu\n", sizeof(longDouble));
}
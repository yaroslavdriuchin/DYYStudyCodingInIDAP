//
//  DYYSizeOfCheck.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//
#include <stdio.h>

#pragma mark -
#pragma mark Private Declarations

#define DYYMacroSizeofCheckAndType(type) printf("Size of data type " #type" = %lu\n", sizeof(type))

#pragma mark -
#pragma mark Private Implementations

void DYYSizeofCheckType(void) {
    DYYMacroSizeofCheckAndType(int);
    DYYMacroSizeofCheckAndType(char);
    DYYMacroSizeofCheckAndType(float);
    DYYMacroSizeofCheckAndType(unsigned long);
    DYYMacroSizeofCheckAndType(double);
}
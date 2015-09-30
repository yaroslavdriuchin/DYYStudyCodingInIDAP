//
//  DYYMacroMethodGenerator.c
//  DYYStudyCoding
//
//  Created by Yar on 9/23/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdio.h>
#include "DYYMacroMethodGenerator.h"

#pragma mark -
#pragma mark Private Declarations

//Macro, generating method to print value of primitive data types
#define DYYMacroGenerateTypeMethod(type, specifier) \
void output_##type(type valueInput) { \
    printf("Value of type "#type " is "specifier "\n", valueInput);\
}

DYYMacroGenerateTypeMethod(char, "%c")
DYYMacroGenerateTypeMethod(int, "%i")
DYYMacroGenerateTypeMethod(float, "%f")

//Macro runs generated method for certain primitive data type
#define DYYMacroRunTypeMethod(type, value) output_##type(value)

#pragma mark -
#pragma mark Public Implementations

void DYYMacroMethodGenerator() {
    DYYMacroRunTypeMethod(char, 'v');
    DYYMacroRunTypeMethod(int, 56);
    DYYMacroRunTypeMethod(float, 5.67);
}
//
//  main.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdio.h>
//#include "DYYCheckNumbersAndReturnValue.h"
//#include "DYYTestCheckNumbersAndReturnValue.h"
#include "DYYStructureAlignment.h"
#include "DYYDecimalToBinaryOutputTranslator.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

int main(int argc, const char * argv[]) {
    DYYReturnStructSize();
    DYYReturnStructOffsetValue();
    DYYDecimalValueToBinaryOutputTranslator(151, DYYEndianTypeBig);
    
    return 0;
    }

//
//  DYYBinaryOutputTranslator.h
//  DYYStudyCoding
//
//  Created by Yar on 9/28/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYBinaryOutputTranslator_h
#define DYYBinaryOutputTranslator_h

#include <stdio.h>
typedef enum {
    DYYEndianTypeUndefined,
    DYYEndianTypeLittle,
    DYYEndianTypeBig,
} DYYEndianType;

//Decimal to binary translator takes decimal input and convert it to binary form using "littleEndian" flag for Little Endian representation,
//"bigEndian" flag for Big Endian
extern void DYYPrintDecimalValueToBinaryOutput(void *value, size_t sizeOfValue, DYYEndianType inputEndianTypeFlag);

#endif /* DYYBinaryOutputTranslator_h */
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
#endif /* DYYBinaryOutputTranslator_h */

typedef enum {
    kDYYLittleEndian=0,
    kDYYBigEndian,
    kDYYUndefinedEndian,
} DYYEndianType;

//Decimal to binary translator takes decimal input and convert it to binary form using 0 flag for Little endian representation,
//1 flag for Big Endian and ANY other value for both Endian types outputted at the same time
extern void DYYDecimalToBinaryTranslator(int value, DYYEndianType inputEndianTypeFlag);
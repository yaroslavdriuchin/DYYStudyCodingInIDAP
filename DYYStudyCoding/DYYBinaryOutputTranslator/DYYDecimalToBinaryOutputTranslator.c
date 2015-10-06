//
//  DYYBinaryOutputTranslator.c
//  DYYStudyCoding
//
//  Created by Yar on 9/28/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYDecimalToBinaryOutputTranslator.h"
#include <stdbool.h>

#pragma mark -
#pragma mark Private Declarations

static const int kDYYBitCount = 8;
static const int kDYYBitMask = 1;
static
void DYYByteToBitTranslator(uint8_t inputByte);

#define DYYTypecastValueAndTakePointer(value) void *valuePointer = &value;\
       uint8_t *bytePointer = ((uint8_t *)valuePointer)

#pragma mark -
#pragma mark Public Implementations$

//Decimal to binary translator takes decimal input and convert it to binary form using "DYYEndianTypeLittle" flag for Little Endian representation,
//"DYYEndianTypeBig" flag for Big Endian 
void DYYDecimalValueToBinaryOutputTranslator(int value, DYYEndianType inputEndianType) {
    printf("\nInput value in binary order is: ");
    if (DYYEndianTypeLittle == inputEndianType) {
        DYYTypecastValueAndTakePointer(value);
        for (size_t counter = 0; counter < sizeof(value); counter ++) {
            uint8_t currentByte = *(bytePointer + counter);
            DYYByteToBitTranslator(currentByte);
            printf (" ");
        }
    }
    else
    if (DYYEndianTypeBig == inputEndianType) {
        DYYTypecastValueAndTakePointer(value);
        for (size_t counter = 1; counter <= sizeof(value); counter ++) {
            uint8_t currentByte = *(bytePointer + sizeof(value) - counter);
            DYYByteToBitTranslator(currentByte);
            printf (" ");
            }
    }
    else {
        printf("\n\nPlease specify Endian type of output value");
    }
}

#pragma mark -
#pragma mark Private Implementations

//'1' is moving in acsending order and being added to bits of Input Byte resulting binary output for given byte
void DYYByteToBitTranslator(uint8_t inputByte) {
    for (int bitCount = 0; bitCount < (sizeof(inputByte) * kDYYBitCount); bitCount++) {
        printf("%d", ((inputByte & (kDYYBitMask << bitCount))) != 0 ? 1 : 0);
        }
}

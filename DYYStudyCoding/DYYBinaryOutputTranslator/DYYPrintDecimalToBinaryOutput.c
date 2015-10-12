//
//  DYYBinaryOutputTranslator.c
//  DYYStudyCoding
//
//  Created by Yar on 9/28/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYPrintDecimalToBinaryOutput.h"
#include <stdbool.h>

#pragma mark -
#pragma mark Private Declarations

static const int kDYYBitCount = 8;
static const int kDYYBitMask = 1;
static
void DYYByteToBitTranslator(uint8_t inputByte);

#pragma mark -
#pragma mark Public Implementations

//Decimal to binary translator takes decimal input and convert it to binary form using "DYYEndianTypeLittle" flag for Little Endian representation,
//"DYYEndianTypeBig" flag for Big Endian 
void DYYPrintDecimalValueToBinaryOutput(void *valuePointer, size_t sizeOfValue, DYYEndianType inputEndianTypeFlag) {
    printf("\nInput value in binary order is: ");
    if (DYYEndianTypeLittle == inputEndianTypeFlag) {
        uint8_t *bytePointer = ((uint8_t *)valuePointer);
        for (size_t counter = 0; counter < sizeOfValue; counter ++) {
            uint8_t currentByte = *(bytePointer + counter);
            DYYByteToBitTranslator(currentByte);
            printf (" ");
        }
    }
    else
    if (DYYEndianTypeBig == inputEndianTypeFlag) {
            uint8_t *bytePointer = ((uint8_t *)valuePointer);
        for (size_t counter = 1; counter <= sizeOfValue; counter ++) {
            uint8_t currentByte = *(bytePointer + sizeOfValue - counter);
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

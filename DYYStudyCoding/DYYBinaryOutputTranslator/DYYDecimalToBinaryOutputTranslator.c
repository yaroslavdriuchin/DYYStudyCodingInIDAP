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
void DYYDataBytesDecomposerLittleEndian(void *inputValue, size_t sizeOfValueType);
void DYYDataBytesDecomposerBigEndian(void *inputValue, size_t sizeOfValueType);
static
void DYYByteToBitTranslator(uint8_t inputByte);

#pragma mark -
#pragma mark Public Implementations

//Decimal to binary translator takes decimal input and convert it to binary form using "littleEndian" flag for Little Endian representation,
//"bigEndian" flag for Big Endian  and "undefinedEndian" or ANY other integer flag value for both Endian types outputted at the same time
void DYYDecimalToBinaryTranslator(int value, DYYEndianType inputEndianType) {
    if (inputEndianType == littleEndian) {
    printf("\n\nInput value in Little Endian binary order is: ");
    DYYDataBytesDecomposerLittleEndian(&value, sizeof(value));
        }
    else if (inputEndianType == bigEndian) {
    printf("\nInput value in Big Endian binary order is: ");
    DYYDataBytesDecomposerBigEndian(&value, sizeof(value));
    }
    else {
        printf("\n\nInput value in Little Endian binary order is: ");
        DYYDataBytesDecomposerLittleEndian(&value, sizeof(value));
        printf("\nInput value in Big Endian binary order is: ");
        DYYDataBytesDecomposerBigEndian(&value, sizeof(value));
    }
}

#pragma mark -
#pragma mark Private Implementations

//This function decomposes whole input value according to Little Endian order to its bytes and send them to Byte-to-Bit translator
void DYYDataBytesDecomposerLittleEndian(void *inputValue, size_t sizeOfValueType) {
    uint8_t *bytePointer = (uint8_t *)inputValue;
    for (size_t counter = 0; counter < sizeOfValueType; counter ++) {
        printf (" ");
    uint8_t currentByte = *(bytePointer + counter);
    DYYByteToBitTranslator(currentByte);
    }
}
//Function decomposes whole input value according to Big Endian order to its bytes and send them to Byte-to-Bit translator
void DYYDataBytesDecomposerBigEndian(void *inputValue, size_t sizeOfValueType) {
    uint8_t *bytePointer = (uint8_t *)inputValue;
    for (size_t counter = 1; counter <= sizeOfValueType; counter ++) {
        uint8_t currentByte = *(bytePointer + sizeOfValueType - counter);
        DYYByteToBitTranslator(currentByte);
        printf (" ");
    }
}
//'1' is moving in acsending order and being added to bits of Input Byte resulting binary output for given byte
void DYYByteToBitTranslator(uint8_t inputByte) {
    for (int bitCount = 0; bitCount < (sizeof(inputByte) * kDYYBitCount); bitCount++) {
        printf("%d", ((inputByte & (kDYYBitMask << bitCount))) != 0 ? 1 : 0);
        }
    }

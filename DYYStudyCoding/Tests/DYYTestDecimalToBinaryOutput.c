//
//  DYYTestDecimalToBinaryOutput.c
//  DYYStudyCoding
//
//  Created by Yar on 10/12/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
// Testing Decimal-to-Binary output method with different input values of different types,
// changing Endian type of output binary structure

#include "DYYTestDecimalToBinaryOutput.h"
//#define DYYMacroTestDecimalToBinaryOutput(testValue, type, endianType) type testValue##type = testValue; \
//           void *testValuePointer##type = &testValue##type\
//                   DYYPrintDecimalValueToBinaryOutput(testValuePointer##type, sizeof(testValue##type), endianType)

void DYYTestDecimalToBinaryOutput(void) {
//input value is 126 of Integer type with Little Endian byte order
        int inputValueInteger = 126;
        void *inputValuePointerInteger = &inputValueInteger;
        DYYPrintDecimalValueToBinaryOutput(inputValuePointerInteger, sizeof(inputValueInteger), DYYEndianTypeLittle);
//input value is 35281 of Long type with Big Endian byte order
        long inputValueLong = 35281;
        void *inputValuePointerLong = &inputValueLong;
        DYYPrintDecimalValueToBinaryOutput(inputValuePointerLong, sizeof(inputValueLong), DYYEndianTypeBig);
//input value is 'N' of Char type with Little Endian byte order
        char inputValueChar = 'N';
        void *inputValuePointerChar = &inputValueChar;
        DYYPrintDecimalValueToBinaryOutput(inputValuePointerChar, sizeof(inputValueChar), DYYEndianTypeLittle);
//input value is 2734 of Double Type with no defined byte order
        double inputValueDouble = 35281;
        void *inputValuePointerDouble = &inputValueDouble;
        DYYPrintDecimalValueToBinaryOutput(inputValuePointerDouble, sizeof(inputValueDouble), 123);
}
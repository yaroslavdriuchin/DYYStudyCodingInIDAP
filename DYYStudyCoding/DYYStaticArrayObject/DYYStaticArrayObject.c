//
//  DYYStaticArrayObject.c
//  DYYStudyCoding
//
//  Created by user on 10/29/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYStaticArrayObject.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Private Declarations

void DYYArraySetAllArrayNull(DYYArray *object);

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYArrayDeallocate(DYYArray *object) {
    DYYArraySetAllArrayNull(object);
    __DYYObjectDeallocate(object);
}

DYYArray *DYYArrayCreate(void) {
    DYYArray *arrayObject = DYYObjectCreateOfType(DYYArray);
    
    return arrayObject;
}

#pragma mark -
#pragma mark Accessors

void DYYArraySetValueAtCount(DYYArray *arrayObject, uint8_t count, void *value) {
    if (NULL != arrayObject && NULL != value) {
        DYYObjectRelease(arrayObject->_staticArray[count]);
        DYYObjectRetain(arrayObject->_staticArray[count]);
        arrayObject->_staticArray[count] = value;
    }
    
    if (NULL != arrayObject && NULL == value) {
        arrayObject->_staticArray[count] = NULL;
        DYYObjectRelease(arrayObject->_staticArray[count]);
    }
}

void *DYYArrayValueAtCount(DYYArray *arrayObject, uint8_t count) {
    if (NULL != arrayObject) {
        return arrayObject->_staticArray[count];
     }
    
    return NULL;
}

#pragma mark -
#pragma mark Private Implementations

void DYYArraySetAllArrayNull(DYYArray *object) {
    if (NULL != object) {
        for (uint8_t count = 0; count < kDYYArrayMaxCount; count++) {
            DYYArraySetValueAtCount(object, count, NULL);
         }
    }
}
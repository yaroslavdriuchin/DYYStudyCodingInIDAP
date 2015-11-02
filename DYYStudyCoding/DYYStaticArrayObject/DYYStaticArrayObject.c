//
//  DYYStaticArrayObject.c
//  DYYStudyCoding
//
//  Created by user on 10/29/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYStaticArrayObject.h"
#include "DYYMacro.h"
//#include "DYYHumanObject.h"
//#include "DYYObject.h"

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYArrayDeallocate(DYYArray *object) {
    for (uint8_t count = 0; count < kDYYArrayMaxCount; count++) {
        DYYArraySetValueAtCount(object, count, NULL);
    }
    
    __DYYObjectDeallocate(object);
}

DYYArray *DYYArrayCreate(void) {
    DYYArray *arrayObject = DYYObjectCreateOfType(DYYArray);
    
    return arrayObject;
}

#pragma mark -
#pragma mark Accessors

void DYYArraySetValueAtCount(DYYArray *arrayObject, uint8_t count, void *value) {
    if (arrayObject != NULL) {
        DYYObjectRelease(arrayObject->_staticArray[count]);
        arrayObject->_staticArray[count] = value;
        DYYObjectRetain(value);
    }
}

void *DYYArrayValueAtCount(DYYArray *arrayObject, uint8_t count) {
    if (NULL != arrayObject) {
        return arrayObject->_staticArray[count];
     }
    
    return NULL;
}

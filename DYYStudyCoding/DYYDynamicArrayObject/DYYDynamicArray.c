//
//  DYYDynamicArrayObject.c
//  DYYStudyCoding
//
//  Created by user on 11/3/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "DYYDynamicArray.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Private Declarations

static float kDYYArrayDecreaseThreshold = 0.7;

static int kDYYArrayIncreaseRate = 2;

static int kDYYArrayDecreaseRate = 2;

static uint16_t kDYYArrayInitialCapacity = 1;

static
void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint16_t capacity);

static
uint16_t DYYDynamicArrayCapacity(DYYDynamicArray *object);

static
uint16_t DYYDynamicArrayReturnNewCapacityForCount(DYYDynamicArray *object, uint16_t count);

static
void **DYYDynamicArrayObjects(DYYDynamicArray *object);

extern
void DYYDynamicArraySetElementAtIndex(DYYDynamicArray *object, uint16_t index, void *element);

extern
void *DYYDynamicArrayElementAtIndex(DYYDynamicArray *object, uint16_t index);

extern
uint16_t DYYDynamicArrayIndexOfElement(DYYDynamicArray *object, void *element);

extern
void DYYDynamicArraySearchAndRemoveElement(DYYDynamicArray *object, void *element);

extern
void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray *arrayObject, uint16_t index);

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYDynamicArrayDeallocate(DYYDynamicArray *object) {
    DYYDynamicArrayClearArray(object);
    __DYYObjectDeallocate(object);
}

DYYDynamicArray *DYYDynamicArrayCreate(void) {
    DYYDynamicArray *dynamicArray = DYYObjectCreateOfType(DYYDynamicArray);
    DYYDynamicArraySetCapacity(dynamicArray, kDYYArrayInitialCapacity);
    return dynamicArray;
}

#pragma mark -
#pragma mark Accessors

static
void **DYYDynamicArrayObjects(DYYDynamicArray *object) {
    if (NULL != object) {
        return object->_data;
    }  else  {
               return NULL;
              }
}

void DYYDynamicArraySetElementAtIndex(DYYDynamicArray *object, uint16_t index, void *element) {
    if (NULL != object && NULL == element) {
        DYYObjectRelease(object->_data[index]);
    }
    if (NULL != object) {
        assert(index < DYYDynamicArrayCapacity(object));
        DYYObjectRelease(object->_data[index]);
        object->_data[index] = DYYObjectRetain(element);
    }
}

void *DYYDynamicArrayElementAtIndex(DYYDynamicArray *object, uint16_t index) {
    if (NULL != object && index <= DYYDynamicArrayCapacity(object)) {
        assert(index <= DYYDynamicArrayAllElementsCount(object));
        
        return DYYDynamicArrayObjects(object)[index];
        }
    
        return NULL;
}

uint16_t DYYDynamicArrayIndexOfElement(DYYDynamicArray *object, void *element) {
    uint16_t elementIndex = 0;
    
    if (NULL != object && NULL != element) {
        for (uint16_t index = 0; index < DYYDynamicArrayAllElementsCount(object); index++) {
            if (element == DYYDynamicArrayElementAtIndex(object, index)) {
                return elementIndex = index;
            }
        }
    }
    
    return elementIndex;
}

uint16_t DYYDynamicArrayAllElementsCount(DYYDynamicArray *object) {
    if (NULL != object) {
        return object->_elementsCount;
    }
    
    return 0;
}

uint16_t DYYDynamicArrayCapacity(DYYDynamicArray *object) {
    if (NULL != object) {
        return object->_capacity;
    }
    
    return UINT16_MAX;
}

#pragma mark -
#pragma mark Private Implemetations

bool DYYDynamicArrayCheckArrayForElement(DYYDynamicArray *object, void *element) {
    if (NULL != object && NULL != element) {
        for (uint16_t index = 0; index < DYYDynamicArrayAllElementsCount(object); index++) {
            if (element == DYYDynamicArrayElementAtIndex(object, index)) {
                return true;
            }
        }
    }
    return false;
}

#pragma mark -
#pragma mark Private Implemetations

void DYYDynamicArrayAddElement(DYYDynamicArray *arrayObject, void *element) {
    if (DYYDynamicArrayCheckArrayForElement(arrayObject, element) == true)
    {
        return;
    }
    
    if (NULL != arrayObject && NULL != element) {
        uint16_t newCapacity = DYYDynamicArrayReturnNewCapacityForCount(arrayObject, DYYDynamicArrayAllElementsCount(arrayObject) + 1);
        DYYDynamicArraySetCapacity(arrayObject, newCapacity);
        for (uint16_t index = 0; index < newCapacity; index++) {
            if (0 == DYYDynamicArrayElementAtIndex(arrayObject, index)) {
            DYYDynamicArraySetElementAtIndex(arrayObject, index, element);
            arrayObject->_elementsCount++;
                
            break;
            }
     }
}
}

bool DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *element) {
    if (NULL != arrayObject && NULL != element) {
        DYYDynamicArrayRemoveElementAndShift(arrayObject, DYYDynamicArrayIndexOfElement(arrayObject, element));
        DYYDynamicArraySetCapacity(arrayObject, DYYDynamicArrayCapacity(arrayObject) - 1);
        arrayObject->_elementsCount--;
        
        return true;
    }
    
    return false;
}

void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint16_t capacity) {
    if (NULL != object && object->_capacity != capacity) {
        if (0 == capacity) {
            free(object->_data);
            object->_data = NULL;
        }
        else {
            object->_data = realloc(object->_data, capacity * sizeof(*object->_data));
            if (0 == object->_capacity) {
                memset(object->_data, 0 , capacity * sizeof(*object->_data));
            }
        }
        object->_capacity = capacity;
    }
}

void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray *arrayObject, uint16_t elementIndex) {
    if (NULL != arrayObject) {
        assert(elementIndex < DYYDynamicArrayAllElementsCount(arrayObject));
        DYYDynamicArraySetElementAtIndex(arrayObject, elementIndex, NULL);
        void **dynamicArray = DYYDynamicArrayObjects(arrayObject);
        size_t shiftElementsSize = ((DYYDynamicArrayAllElementsCount(arrayObject) - elementIndex) * sizeof(dynamicArray));
        memmove(&dynamicArray[elementIndex], &dynamicArray[elementIndex + 1], shiftElementsSize);
    }
}

uint16_t DYYDynamicArrayReturnNewCapacityForCount(DYYDynamicArray *object, uint16_t count) {
    if (NULL != object) {
        uint16_t newCapacity = 0;
        if (count > DYYDynamicArrayCapacity(object)) {
            return newCapacity = DYYDynamicArrayCapacity(object) * kDYYArrayIncreaseRate;
        }
        else if (count < DYYDynamicArrayCapacity(object) * kDYYArrayDecreaseThreshold) {
            return newCapacity = DYYDynamicArrayCapacity(object) * kDYYArrayDecreaseRate;
        }
        
        else  {
                return newCapacity = DYYDynamicArrayCapacity(object);
              }
    }
    
    return 0;
}


void DYYDynamicArrayClearArray(DYYDynamicArray *object) {
    if (NULL != object) {
        for (uint16_t index = 0; index < DYYDynamicArrayAllElementsCount(object); index++) {
            DYYDynamicArraySetElementAtIndex(object, index, NULL);
        }
    }
}

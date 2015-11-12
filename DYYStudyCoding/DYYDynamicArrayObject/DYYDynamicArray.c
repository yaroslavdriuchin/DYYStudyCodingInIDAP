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

typedef enum {
    kDYYArrayResizeToInitialize,
    kDYYArrayResizeIncrease,
    kDYYArrayResizeDecrease
} DYYArrayResizeParameter;

float kDYYArrayDecreaseThreshold = 0.7;

int kDYYArrayIncreaseRate = 2;

int kDYYArrayDecreaseRate = 2;

uint16_t kDYYArrayInitialCapacity = 2;

static
void **DYYDynamicArrayObjects(DYYDynamicArray *object) {
    if (NULL != object) {
        return object->_dynamicArrayObjects;
    }
    
    else return NULL;
}

static
void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint16_t proposedElementsCount);

static
uint16_t DYYDynamicArrayCapacity(DYYDynamicArray *object);

extern
void DYYDynamicArraySetElementAtCount(DYYDynamicArray *object, uint16_t count, void *elementPointer);

extern
void *DYYDynamicArrayElementAtCount(DYYDynamicArray *object, uint16_t count);

extern
uint16_t DYYDynamicArrayCountOfElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArraySearchAndRemoveElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray *arrayObject, uint16_t elementCount);

static
void DYYDynamicArrayResize(DYYDynamicArray *object, DYYArrayResizeParameter resizeParameter);
//
//static
//void DYYDynamicArrayAllocateInitialSizeArray(DYYDynamicArray *object);


#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYDynamicArrayDeallocate(DYYDynamicArray *object) {
    DYYDynamicArrayClearArray(object);
    __DYYObjectDeallocate(object);
}

DYYDynamicArray *DYYDynamicArrayCreate(void) {
    DYYDynamicArray *dynamicArray = DYYObjectCreateOfType(DYYDynamicArray);
//    DYYDynamicArrayAllocateInitialSizeArray(dynamicArray);
    DYYDynamicArraySetCapacity(dynamicArray, kDYYArrayInitialCapacity);
    return dynamicArray;
}

//void DYYDynamicArrayAllocateInitialSizeArray(DYYDynamicArray *dynamicArray) {
//    if (NULL != dynamicArray) {
//        void *dynamicArrayAllocator = calloc(1, sizeof(dynamicArray->_dynamicArrayObjects));
//        dynamicArray->_dynamicArrayObjects = dynamicArrayAllocator;
//    }
//}

#pragma mark -
#pragma mark Accessors

void DYYDynamicArraySetElementAtCount(DYYDynamicArray *object, uint16_t count, void *elementPointer) {
    if (NULL != object) {
        assert(count <= DYYDynamicArrayCapacity(object));
        object->_dynamicArrayObjects[count] = NULL;
        DYYObjectRelease(object->_dynamicArrayObjects[count]);
        object->_dynamicArrayObjects[count] = elementPointer;
        DYYObjectRetain(object->_dynamicArrayObjects[count]);
        }
}

void *DYYDynamicArrayElementAtCount(DYYDynamicArray *object, uint16_t count) {
    if (NULL != object && count <= DYYDynamicArrayCapacity(object)) {
        assert(count <= DYYDynamicArrayAllElementsCount(object));
        
        return DYYDynamicArrayObjects(object)[count];
        }
    
        return NULL;
}

uint16_t DYYDynamicArrayCountOfElement(DYYDynamicArray *object, void *elementPointer) {
    uint16_t elementCount = 0;
    
    if (NULL != object && NULL != elementPointer) {
        for (uint16_t counter = 0; counter < DYYDynamicArrayAllElementsCount(object); counter++) {
            if (elementPointer == DYYDynamicArrayElementAtCount(object, counter)) {
                return elementCount = counter;
            }
        }
    }
    
    return elementCount;
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

bool DYYDynamicArrayDetectElement(DYYDynamicArray *object, void *elementPointer) {
    if (NULL != object && NULL != elementPointer) {
        for (uint16_t counter = 0; counter < DYYDynamicArrayAllElementsCount(object); counter++) {
            if (elementPointer == DYYDynamicArrayElementAtCount(object, counter)) {
                return true;
            }
        }
    }
    return false;
}

#pragma mark -
#pragma mark Private Implemetations

void DYYDynamicArrayAddElement(DYYDynamicArray *arrayObject, void *elementPointer) {
    if (NULL != arrayObject && DYYDynamicArrayDetectElement(arrayObject, elementPointer) == true)
    {
        return;
    }
    
    if (NULL != arrayObject && NULL != elementPointer) {
        uint16_t proposedElementsCount = DYYDynamicArrayAllElementsCount(arrayObject) + 1;
        DYYDynamicArraySetCapacity(arrayObject, proposedElementsCount);
        DYYDynamicArraySetElementAtCount(arrayObject, proposedElementsCount, elementPointer);
        arrayObject->_elementsCount++;
    }
}

bool DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *elementPointer) {
    if (NULL != arrayObject && NULL != elementPointer) {
        uint16_t proposedElementsCount = DYYDynamicArrayAllElementsCount(arrayObject) - 1;
        uint16_t elementToRemoveCount = DYYDynamicArrayCountOfElement(arrayObject, elementPointer);
        DYYDynamicArrayRemoveElementAndShift(arrayObject, elementToRemoveCount);
        DYYDynamicArraySetCapacity(arrayObject, proposedElementsCount);
        arrayObject->_elementsCount--;
        
        return true;
    }
    
    return false;
}

void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint16_t proposedElementsCount)
{
    if (NULL!= object && 0 == proposedElementsCount) {
        DYYDynamicArrayClearArray(object);
        free(object);
    }
    
    if (NULL!= object && 1 == proposedElementsCount) {
        DYYDynamicArrayResize(object, kDYYArrayResizeToInitialize);
    }

    
    if (NULL != object && proposedElementsCount > DYYDynamicArrayCapacity(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeIncrease);
    }

    if (NULL != object
        && (kDYYArrayDecreaseThreshold * DYYDynamicArrayCapacity(object) <= proposedElementsCount <= DYYDynamicArrayCapacity(object))
        && proposedElementsCount < DYYDynamicArrayAllElementsCount(object)) {
            DYYDynamicArrayResize(object, 0);
    }
    
    if (NULL != object
        && proposedElementsCount < kDYYArrayDecreaseThreshold * DYYDynamicArrayCapacity(object)
        && proposedElementsCount < DYYDynamicArrayAllElementsCount(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeDecrease);
    }
}

void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray *arrayObject, uint16_t elementCount) {
    if (NULL != arrayObject) {
        assert(elementCount < DYYDynamicArrayAllElementsCount(arrayObject));
        DYYObjectRelease(arrayObject->_dynamicArrayObjects[elementCount]);
        DYYDynamicArraySetElementAtCount(arrayObject, elementCount, NULL);
        void **dynamicArray = DYYDynamicArrayObjects(arrayObject);
        size_t shiftElementsSize = ((DYYDynamicArrayAllElementsCount(arrayObject) - elementCount) * sizeof(dynamicArray));
        memmove(&dynamicArray[elementCount], &dynamicArray[elementCount + 1], shiftElementsSize);
    }
}

void DYYDynamicArrayResize(DYYDynamicArray *object, DYYArrayResizeParameter resizeParameter) {
    if (NULL != object) {
        void **dynamicArray = DYYDynamicArrayObjects(object);
        size_t elementSize = sizeof(dynamicArray);
        size_t dynamicArraySize = elementSize + DYYDynamicArrayCapacity(object) * elementSize;
        size_t allElementsSize = DYYDynamicArrayAllElementsCount(object) * elementSize;
        
        if (resizeParameter == kDYYArrayResizeToInitialize) {
            void *newCapacityArray = calloc(kDYYArrayInitialCapacity, elementSize);
            object->_dynamicArrayObjects = newCapacityArray;
            object->_capacity++;
        }
        
        if (resizeParameter == kDYYArrayResizeIncrease) {
            void *newCapacityArray = realloc(dynamicArray, elementSize + DYYDynamicArrayCapacity(object) * kDYYArrayIncreaseRate);
            dynamicArray = newCapacityArray;
            memset(dynamicArray + allElementsSize,
                   0,
                   dynamicArraySize - allElementsSize);
            object->_capacity++;
            
        } else if (resizeParameter == kDYYArrayResizeDecrease) {
            void *newCapacityArray = realloc(dynamicArray, DYYDynamicArrayCapacity(object) / kDYYArrayDecreaseRate);
            dynamicArray = newCapacityArray;
            object->_capacity--;
        }
        
        else return;
    }
}

void DYYDynamicArrayClearArray(DYYDynamicArray *object) {
    if (NULL != object) {
        for (uint16_t counter = 0; counter <= DYYDynamicArrayAllElementsCount(object); counter++) {
            DYYDynamicArraySetElementAtCount(object, counter, NULL);
            DYYObjectRelease(DYYDynamicArrayObjects(object)[counter]);
        }
    }
}

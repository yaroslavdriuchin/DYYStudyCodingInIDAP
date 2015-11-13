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

static float kDYYArrayDecreaseThreshold = 0.7;

static int kDYYArrayIncreaseRate = 2;

static int kDYYArrayDecreaseRate = 2;

static uint16_t kDYYArrayInitialCapacity = 2;


static
void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint16_t proposedElementsCount);

static
uint16_t DYYDynamicArrayCapacity(DYYDynamicArray *object);

static
void **DYYDynamicArrayObjects(DYYDynamicArray *object);

extern
void DYYDynamicArraySetElementAtIndex(DYYDynamicArray *object, uint16_t count, void *elementPointer);

extern
void *DYYDynamicArrayElementAtIndex(DYYDynamicArray *object, uint16_t count);

extern
uint16_t DYYDynamicArrayIndexOfElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArraySearchAndRemoveElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray *arrayObject, uint16_t elementIndex);

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

static
void **DYYDynamicArrayObjects(DYYDynamicArray *object) {
    if (NULL != object) {
        return object->_dynamicArrayObjects;
    }
    
    else return NULL;
}

void DYYDynamicArraySetElementAtIndex(DYYDynamicArray *object, uint16_t index, void *elementPointer) {
    if (NULL != object) {
        assert(index <= DYYDynamicArrayCapacity(object));
        object->_dynamicArrayObjects[index] = NULL;
        DYYObjectRelease(object->_dynamicArrayObjects[index]);
        object->_dynamicArrayObjects[index] = elementPointer;
        DYYObjectRetain(object->_dynamicArrayObjects[index]);
        }
}

void *DYYDynamicArrayElementAtIndex(DYYDynamicArray *object, uint16_t index) {
    if (NULL != object && index <= DYYDynamicArrayCapacity(object)) {
        assert(index <= DYYDynamicArrayAllElementsCount(object));
        
        return DYYDynamicArrayObjects(object)[index];
        }
    
        return NULL;
}

uint16_t DYYDynamicArrayIndexOfElement(DYYDynamicArray *object, void *elementPointer) {
    uint16_t elementIndex = 0;
    
    if (NULL != object && NULL != elementPointer) {
        for (uint16_t counter = 0; counter < DYYDynamicArrayAllElementsCount(object); counter++) {
            if (elementPointer == DYYDynamicArrayElementAtCount(object, counter)) {
                return elementIndex = counter;
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

bool DYYDynamicArrayDetectElement(DYYDynamicArray *object, void *elementPointer) {
    if (NULL != object && NULL != elementPointer) {
        for (uint16_t counter = 0; counter < DYYDynamicArrayAllElementsCount(object); counter++) {
            if (elementPointer == DYYDynamicArrayElementAtIndex(object, counter)) {
                return true;
            }
        }
    }
    return false;
}

#pragma mark -
#pragma mark Private Implemetations

void DYYDynamicArrayAddElement(DYYDynamicArray *arrayObject, void *elementPointer) {
    if (DYYDynamicArrayDetectElement(arrayObject, elementPointer) == true)
    {
        return;
    }
    
    if (NULL != arrayObject && NULL != elementPointer) {
        uint16_t proposedElementsCount = DYYDynamicArrayAllElementsCount(arrayObject) + 1;
        DYYDynamicArraySetCapacity(arrayObject, proposedElementsCount);
        arrayObject->_elementsCount++;
        DYYDynamicArraySetElementAtIndex(arrayObject, proposedElementsCount, elementPointer);
        
    }
}

bool DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *elementPointer) {
    if (NULL != arrayObject && NULL != elementPointer) {
        uint16_t proposedElementsCount = DYYDynamicArrayAllElementsCount(arrayObject) - 1;
        uint16_t elementToRemoveCount = DYYDynamicArrayIndexOfElement(arrayObject, elementPointer);
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

void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray *arrayObject, uint16_t elementIndex) {
    if (NULL != arrayObject) {
        assert(elementIndex < DYYDynamicArrayAllElementsCount(arrayObject));
        DYYObjectRelease(arrayObject->_dynamicArrayObjects[elementIndex]);
        DYYDynamicArraySetElementAtIndex(arrayObject, elementIndex, NULL);
        void **dynamicArray = DYYDynamicArrayObjects(arrayObject);
        size_t shiftElementsSize = ((DYYDynamicArrayAllElementsCount(arrayObject) - elementIndex) * sizeof(dynamicArray));
        memmove(&dynamicArray[elementIndex], &dynamicArray[elementIndex + 1], shiftElementsSize);
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
        for (uint16_t index = 0; index <= DYYDynamicArrayAllElementsCount(object); index++) {
            DYYDynamicArraySetElementAtIndex(object, index, NULL);
        }
    }
}

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
#include "DYYDynamicArray.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Private Declarations

typedef enum {
    kDYYArrayResizeNotNeeded,
    kDYYArrayResizeIncrease,
    kDYYArrayResizeDecrease
} DYYArrayResizeParameter;

float kDYYArrayDecreaseThreshold = 0.5;

float kDYYArrayIncreaseRate = 1.5;

float kDYYArrayDecreaseRate = 0.75;

uint16_t kDYYArrayInitialCapacity = 4;

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

static
uint16_t DYYDynamicArrayAllElementsCount(DYYDynamicArray *object);

extern
bool DYYDynamicArrayDetectElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArraySearchAndRemoveElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray arrayObject, void *elementPointer);

static
void DYYDynamicArrayResize(DYYDynamicArray *object, DYYArrayResizeParameter resizeParameter);

extern
void DYYDynamicArrayCleanOut(DYYDynamicArray *object);


#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYDynamicArrayDeallocate(DYYDynamicArray *object) {
    DYYDynamicArrayCleanOut(object);
    __DYYObjectDeallocate(object);
}

DYYDynamicArray *DYYDynamicArrayCreate(void) {
    return DYYObjectCreateOfType(DYYDynamicArray);
}

#pragma mark -
#pragma mark Accessors

void DYYDynamicArraySetElementAtCount(DYYDynamicArray *object, uint16_t count, void *elementPointer) {
    if (NULL != object && NULL != elementPointer) {
        assert(count < DYYDynamicArrayCapacity(object));
        DYYObjectRelease(object->_dynamicArrayObjects[count]);
        DYYDynamicArrayObjects(object)[count] = elementPointer;
        DYYObjectRetain(object->_dynamicArrayObjects[count]);
        }
}

void *DYYDynamicArrayElementAtCount(DYYDynamicArray *object, uint16_t count) {
    if (NULL != object && count < DYYDynamicArrayCapacity(object)) {
        assert(count > DYYDynamicArrayAllElementsCount(object));
        
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
    uint16_t counter = 0;
    
    if (NULL != object) {
        while (NULL != DYYDynamicArrayElementAtCount(object, counter)) {
            counter++;
        }
    }
            return counter;
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
    }
}

void DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *elementPointer) {
    if (NULL != arrayObject && NULL != elementPointer) {
        uint16_t proposedElementsCount = DYYDynamicArrayAllElementsCount(arrayObject) - 1;
        DYYDynamicArrayRemoveElementAndShift(arrayObject, elementPointer);
        DYYDynamicArraySetCapacity(arrayObject, proposedElementsCount);
    }
}

void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint16_t proposedElementsCount)
{
    if (NULL!= object && NULL == proposedElementsCount) {
            DYYObjectRelease(object);
    }
    
    if (NULL != object && proposedElementsCount > DYYDynamicArrayCapacity(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeIncrease);
    }

    if (NULL != object
        && (kDYYArrayDecreaseThreshold * DYYDynamicArrayCapacity(object) <= proposedElementsCount <= DYYDynamicArrayCapacity(object))
        && proposedElementsCount < DYYDynamicArrayAllElementsCount(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeNotNeeded);
    }
    
    if (NULL != object
        && proposedElementsCount < kDYYArrayDecreaseThreshold * DYYDynamicArrayCapacity(object)
        && proposedElementsCount < DYYDynamicArrayAllElementsCount(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeDecrease);
    }
}

void DYYDynamicArrayRemoveElementAndShift(DYYDynamicArray arrayObject, void *elementPointer) {
    
}

void DYYDynamicArrayResize(DYYDynamicArray *object, DYYArrayResizeParameter resizeParameter) {
    if (NULL != object) {
        void **dynamicArray = DYYDynamicArrayObjects(object);
        size_t elementSize = sizeof(dynamicArray);
        size_t dynamicArraySize = DYYDynamicArrayCapacity(object) * elementSize;
        size_t allElementsSize = DYYDynamicArrayAllElementsCount(object) * elementSize;
    
    if (resizeParameter == kDYYArrayResizeIncrease) {
        void *newCapacityArray = realloc(dynamicArray, DYYDynamicArrayCapacity(object) * kDYYArrayIncreaseRate);
        memset(dynamicArray + elementSize * kDYYArrayIncreaseRate,
               0,
               dynamicArray - elementSize * kDYYArrayIncreaseRate)
        dynamicArray = newCapacityArray;
    }
    }
}
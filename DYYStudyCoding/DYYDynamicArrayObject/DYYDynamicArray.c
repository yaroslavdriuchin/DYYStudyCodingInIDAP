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

float kDYYArrayDecreaseRate = 0.7;

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
void DYYDynamicArrayResize(DYYDynamicArray *object, DYYArrayResizeParameter resizeParameter);

static
uint64_t DYYDynamicArrayElementsCount(DYYDynamicArray *object);

static
uint64_t DYYDynamicArrayCapacity(DYYDynamicArray *object);

extern
void DYYDynamicArraySetElementAtCount(DYYDynamicArray *object, uint16_t count, void *elementPointer);

extern
void *DYYDynamicArrayElementAtCount(DYYDynamicArray *object, uint16_t count);

extern
uint16_t DYYDynamicArrayCountOfElement(DYYDynamicArray *object, void *elementPointer);

extern
bool DYYDynamicArrayDetectElement(DYYDynamicArray *object, void *elementPointer);

extern
void DYYDynamicArraySearchAndRemoveElement(DYYDynamicArray *object, void *elementPointer);


#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYDynamicArrayDeallocate(DYYDynamicArray *object) {
    DYYDynamicArraySetAllArrayNull(object);
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
        }
}

void *DYYDynamicArrayElementAtCount(DYYDynamicArray *object, uint16_t count) {
    if (NULL != object) {
        assert(count < DYYDynamicArrayCapacity(object));
        return DYYDynamicArrayObjects(object)[count];
        }
    
        return NULL;
}
           
uint16_t DYYDynamicArrayCountOfElement(DYYDynamicArray *object, void *elementPointer) {
    if (NULL != object && NULL != elementPointer) {
        for (uint16_t count = 0, count < DYYDynamicArrayElementsCount(object)) {
    }
    
    return 0;
}

static uint16_t DYYDynamicArrayElementsCount(DYYDynamicArray *object) {
    
}

static uint16_t DYYDynamicArrayCapacity(DYYDynamicArray *object) {
    
}

#pragma mark -
#pragma mark Private Implemetations

bool DYYDynamicArrayDetectElement(DYYDynamicArray *object, void *elementPointer) {
    
}

#pragma mark -
#pragma mark Private Implemetations

void DYYDynamicArrayAddElement(DYYDynamicArray *arrayObject, void *elementPointer) {
if (NULL != arrayObject && DYYDynamicArrayDetectElement(arrayObject) == true)
    {
      return;
    }
if (NULL != arrayObject && NULL != elementPointer) {
    uint16_t proposedElementsCount = DYYDynamicArrayElementsCount(arrayObject)++;
    DYYDynamicArraySetCapacity(arrayObject, proposedElementsCount);
    DYYDynamicArraySetValueAtCount(arrayObject, proposedElementsCount, elementPointer);
    }
}

void DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *elementPointer) {
if (NULL != arrayObject && NULL != elementPointer) {
    uint16_t proposedElementsCount = DYYDynamicArrayElementsCount(arrayObject)--;
    DYYDynamicArraySetCapacity(arrayObject, proposedElementsCount);
    DYYDynamicArrayRemoveElementAndShift(arrayObject, elementPointer);
    }
}

void DYYDynamicArraySetCapacity(DYYDynamicArray *object, uint64_t proposedElementsCount)
{
    if (NULL!= object && NULL == proposedElementsCount) {
            DYYObjectRelease(object);
    }
    
    if (NULL != object && proposedElementsCount > DYYDynamicArrayCapacity(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeIncrease);
    }

    if (NULL != object
        && (kDYYArrayDecreaseThreshold * DYYDynamicArrayCapacity(object) <= proposedElementsCount <= DYYDynamicArrayCapacity(object))
        && proposedElementsCount < DYYDynamicArrayElementsCount(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeNotNeeded);
    }
    
    if (NULL != object
        && proposedElementsCount < kDYYArrayDecreaseThreshold * DYYDynamicArrayCapacity(object)
        && proposedElementsCount < DYYDynamicArrayElementsCount(object)) {
            DYYDynamicArrayResize(object, kDYYArrayResizeDecrease);
    }
}
//
//  DYYDynamicArrayObject.h
//  DYYStudyCoding
//
//  Created by user on 11/3/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYDynamicArrayObject_h
#define DYYDynamicArrayObject_h

#include <stdio.h>
#include <stdlib.h>
#include "DYYObject.h"

//static const uint16_t kDYYDynamicArrayInitialCapacity = 3;

typedef struct DYYDynamicArray DYYDynamicArray;

struct DYYDynamicArray {
    DYYObject _super;
    void **_dynamicArrayObjects;
    uint16_t _elementsCount;
    uint16_t _capacity;
};

extern
void __DYYDynamicArrayDeallocate(DYYDynamicArray *object);

extern
DYYDynamicArray *DYYDynamicArrayCreate(void);

extern
void DYYDynamicArrayAddElement(DYYDynamicArray *arrayObject, void *elementPointer);

extern
bool DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *elementPointer);

extern
bool DYYDynamicArrayDetectElement(DYYDynamicArray *object, void *elementPointer);

extern
uint16_t DYYDynamicArrayAllElementsCount(DYYDynamicArray *object);

extern
void DYYDynamicArrayClearArray(DYYDynamicArray *object);


#endif /* DYYDynamicArrayObject_h */

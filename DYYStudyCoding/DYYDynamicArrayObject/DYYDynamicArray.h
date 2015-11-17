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

typedef struct DYYDynamicArray DYYDynamicArray;

struct DYYDynamicArray {
    DYYObject _super;
    void **_data;
    uint16_t _elementsCount;
    uint16_t _capacity;
};

extern
void __DYYDynamicArrayDeallocate(DYYDynamicArray *object);

extern
DYYDynamicArray *DYYDynamicArrayCreate(void);

extern
void DYYDynamicArraySetCount(DYYDynamicArray *object, uint16_t count);

extern
void DYYDynamicArrayAddElement(DYYDynamicArray *arrayObject, void *element);

extern
bool DYYDynamicArrayRemoveElement(DYYDynamicArray *arrayObject, void *element);

extern
bool DYYDynamicArrayCheckArrayForElement(DYYDynamicArray *object, void *element);

extern
uint16_t DYYDynamicArrayAllElementsCount(DYYDynamicArray *object);

extern
void DYYDynamicArrayClearArray(DYYDynamicArray *object);


#endif /* DYYDynamicArrayObject_h */

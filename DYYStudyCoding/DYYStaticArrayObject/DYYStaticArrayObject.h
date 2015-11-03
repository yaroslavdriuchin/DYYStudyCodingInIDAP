//
//  DYYStaticArrayObject.h
//  DYYStudyCoding
//
//  Created by user on 10/29/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYStaticArrayObject_h
#define DYYStaticArrayObject_h

#include <stdio.h>
#include <stdlib.h>
#include "DYYObject.h"

static const uint16_t kDYYArrayMaxCount = 20;

typedef struct DYYStaticArray DYYArray;

struct DYYStaticArray {
    DYYObject _super;
    void *_staticArray[kDYYArrayMaxCount];
};

extern
DYYArray *DYYArrayCreate(void);

extern
void __DYYArrayDeallocate(DYYArray *object);

extern
void DYYArraySetValueAtCount(DYYArray *object, uint8_t count, void *value);

extern
void *DYYArrayValueAtCount(DYYArray *object, uint8_t count);

#endif /* DYYStaticArrayObject_h */

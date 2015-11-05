//
//  DYYObject.h
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYObject_h
#define DYYObject_h

#include <stdio.h>
#include <stdlib.h>

typedef void(*DYYObjectDeallocator)(void *object);

typedef struct {
    uint _retainCount;
    DYYObjectDeallocator _deallocatorFunctionPointer;
} DYYObject;

extern
void *__DYYObjectCreate(size_t size, DYYObjectDeallocator);

extern
void __DYYObjectDeallocate(void *object);

extern
uint DYYObjectRetainCount(void *object);

extern
void DYYObjectRelease(void *object);

extern
void *DYYObjectRetain(void *object);

#endif /* DYYObject_h */

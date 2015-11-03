//
//  DYYObject.c
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include <assert.h>
#include "DYYObject.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Public Implementations

void __DYYObjectDeallocate(void *object) {
    if (NULL != object) {
        free(object);
    }
}

void *__DYYObjectCreate(size_t size, DYYObjectDeallocator deallocator) {
    assert(0 != size);
    assert(NULL != deallocator);
    
    DYYObject *object = calloc(1, size);
    assert(NULL != object);
    
    object->_retainCount = 1;
    object->_deallocatorFunctionPointer = deallocator;
    
    return object;
}

uint64_t DYYObjectRetainCount(void *object) {
    return object ? ((DYYObject *)object)->_retainCount : 0;
}

void DYYObjectRelease(void *object) {
    if (NULL != object) {
        DYYObject *releasedObject = (DYYObject *)object;
        if (0 == (releasedObject->_retainCount) - 1) {
            DYYObjectDeallocator deallocator = releasedObject->_deallocatorFunctionPointer;
            deallocator(object);
        }
    }
}

void *DYYObjectRetain(void *object) {
    if (NULL != object) {
        ((DYYObject*)object)->_retainCount++;
    }
    
    return object;
}
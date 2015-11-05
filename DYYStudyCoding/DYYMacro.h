//
//  DYYMacro.h
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYMacro_h
#define DYYMacro_h

#define DYYFreeAllocatedData(object, inputField) \
        if (NULL != object->inputField) { \
                free(object->inputField); \
                object->inputField = NULL; \
}

#define DYYObjectCreateOfType(type) __DYYObjectCreate(sizeof(type), (DYYObjectDeallocator)__ ##type ##Deallocate)

#define DYYCheckTwoObjectsNULL(objectOne, objectTwo) NULL != objectOne && NULL != objectTwo

#endif /* DYYMacro_h */

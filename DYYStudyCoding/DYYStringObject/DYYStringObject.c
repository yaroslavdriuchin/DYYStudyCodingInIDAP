//
//  DYYStringObject.c
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include <string.h>
#include "DYYStringObject.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYStringDeallocate(DYYString *stringObject) {
    DYYStringSetValue(stringObject, NULL);
    __DYYObjectDeallocate(stringObject);
}

void *DYYStringCreateWithValue(DYYString *value) {
    DYYString *stringObject = DYYObjectCreateOfType(DYYString);
    DYYStringSetValue(stringObject, value);
    
    return stringObject;
}

#pragma mark -
#pragma mark Accessors

void DYYStringSetValue(DYYString *stringObject, DYYString *value) {
    if (NULL != stringObject && DYYStringValue(stringObject) != value) {
    char *inputValue = ((char *)value);
    DYYFreeAllocatedData(stringObject, _string);
    stringObject->_string = strdup(inputValue);
        
    }
}

void *DYYStringValue(DYYString *stringObject)   {
    return NULL != stringObject ? stringObject->_string : NULL;
}
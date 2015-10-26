//
//  DYYStringObject.c
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYStringObject.h"
#include "DYYMacro.h"
#include <string.h>

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYStringDeallocate(DYYString *stringObject) {
    DYYStringSetValue(stringObject, NULL);
    __DYYObjectDeallocate(stringObject);
};

void *DYYStringCreate(char *value) {
    DYYString *stringObject = DYYObjectCreateOfType(DYYString);
    DYYStringSetValue(stringObject, value);
    
    return stringObject;
};

#pragma mark -
#pragma mark Accessors

void DYYStringSetValue(DYYString *stringObject, char *value) {
    if (NULL == stringObject) {
         return;
    }
    DYYFreeAllocatedData(stringObject, _string);
    stringObject->_string = strdup(value);
    
};

void *DYYStringValue(DYYString *stringObject) {
    return NULL != stringObject ? stringObject->_string : NULL;
    };
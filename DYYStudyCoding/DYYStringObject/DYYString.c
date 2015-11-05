//
//  DYYStringObject.c
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include <string.h>
#include <assert.h>
#include "DYYString.h"
#include "DYYMacro.h"


#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYStringDeallocate(DYYString *stringObject) {
    DYYStringSetValue(stringObject, NULL);
    __DYYObjectDeallocate(stringObject);
}

void *DYYStringCreateWithString(char *string) {
    DYYString *stringObject = DYYObjectCreateOfType(DYYString);
    DYYStringSetValue(stringObject, string);
    
    return stringObject;
}

#pragma mark -
#pragma mark Accessors

void DYYStringSetValue(DYYString *stringObject, char *string) {
    if (NULL != stringObject && stringObject->_string != string) {
        if (stringObject->_string) {
            free(stringObject->_string);
            stringObject->_string = NULL;
        }
        
        if (string) {
            char *copiedString = strdup(string);
            assert(NULL != copiedString);
            stringObject->_string = copiedString;
        }
    }
}

char *DYYStringValue(DYYString *stringObject) {
    if (NULL != stringObject) {
        return stringObject->_string;
    }
    
    return NULL;
}
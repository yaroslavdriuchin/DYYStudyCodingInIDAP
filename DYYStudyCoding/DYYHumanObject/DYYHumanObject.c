//
//  DYYHumanObject.c
//  DYYStudyCoding
//
//  Created by Yar on 10/6/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
#include "DYYHumanObject.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#pragma mark -
#pragma mark Private Declarations

static void DYYPersonSetName(DYYPersonData *personDataPointer, char *name);

#pragma mark -
#pragma mark Public Implementations

DYYPersonData *DYYPersonCreateWithNameAgeGender(char *inputPersonName,
                                                    unsigned int inputPersonAge,
                                                    DYYPersonGender inputPersonGender) {
    DYYPersonData *personDataObject;
    personDataObject = calloc(1, sizeof(DYYPersonData));
    assert(NULL != personDataObject);
    DYYPersonSetName(personDataObject, inputPersonName);
    
    return personDataObject;
}

#pragma mark -
#pragma mark Private Implementations
static void DYYPersonSetName(DYYPersonData *personDataPointer, char *name) {
    if (NULL != personDataPointer) {
        if (NULL != personDataPointer->_personName) {
            free(personDataPointer->_personName);
            personDataPointer->_personName = NULL;
        }
        if (name) {
            personDataPointer->_personName = strdup(name);
        }
    }
}

char *DYYPersonName(DYYPersonData *personDataPointer) {
    return NULL != personDataPointer ? personDataPointer->_personName : NULL;
}
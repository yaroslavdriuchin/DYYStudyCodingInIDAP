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
struct DYYPersonDataList {
    char *_personName;
    DYYPersonGender _personGender;
    void *_personPartner;
    void *_personParent;
    void *_personChildrenList[20];
    uint8_t _personChildrenTotalCount;
    uint8_t _personAge;
    bool _personMarriedStatus;
};

static void DYYPersonSetName(DYYPersonData *personDataPointer, char *name);
char DYYPersonName(DYYPersonData *personDataObject);

#pragma mark -
#pragma mark Public Implementations

DYYPersonData *DYYPersonCreateWithInitialParameters(char *inputPersonName, uint8_t inputPersonAge, DYYPersonGender inputPersonGender) {
    DYYPersonData *personDataObject;
    personDataObject = calloc(1, sizeof(DYYPersonData));
    assert(NULL != personDataObject);
    DYYPersonSetName(*personDataObject, *inputPersonName);
    
    
    return *personDataPointer;
}

#pragma mark -
#pragma mark Private Implementations
static void DYYPersonSetName(DYYPersonData *personDataPointer, char *name) {
    if (NULL != personDataPointer) {
        if (NULL != DYYPersonData->_personName) {
            free(DYYPersonData->_personName);
            DYYPersonData->_personName = NULL;
        }
        if (name) {
            DYYPersonData->_personName = strdup(name);
        }
    }
}

char DYYPersonName (DYYPersonData *personDataObject) {
    return NULL != *personDataPointer = 0 ? personDataObject->_personName : NULL;
}
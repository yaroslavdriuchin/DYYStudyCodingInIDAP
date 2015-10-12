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

#define DYYMacroCheckNullResponceAndClearDatafield(inputField) if (NULL != personDataPointer->inputField) \
                  { free(personDataPointer->inputField);    personDataPointer->inputField = NULL;  }

static void DYYPersonSetName(DYYPersonData *personDataPointer, char *name);
static void DYYPersonSetAge(DYYPersonData *personDataPointer, unsigned int age);
static void DYYPersonSetGender(DYYPersonData *personDataPointer, DYYPersonGender gender);
char *DYYPersonName(DYYPersonData *personDataObject);

#pragma mark -
#pragma mark Public Implementations

DYYPersonData *DYYPersonCreateWithNameAgeGender(char *inputPersonName,
                                                    unsigned int inputPersonAge,
                                                    DYYPersonGender inputPersonGender) {
        DYYPersonData *personDataObject;
        personDataObject = calloc(1, sizeof(DYYPersonData));
        assert(NULL != personDataObject);
        DYYPersonSetName(personDataObject, inputPersonName);
        DYYPersonSetAge(personDataObject, inputPersonAge);
        DYYPersonSetGender(personDataObject, inputPersonGender);
    
    return personDataObject;
}

#pragma mark -
#pragma mark Private Implementations
static void DYYPersonSetName(DYYPersonData *personDataPointer, char *name) {
    if (NULL != personDataPointer) {
        DYYMacroCheckNullResponceAndClearDatafield(_personName);
                if (name) {
                personDataPointer->_personName = strdup(name);
        }
    }
}
static void DYYPersonSetAge(DYYPersonData *personDataPointer, unsigned int age) {
    if (NULL != personDataPointer) {
    DYYMacroCheckNullResponceAndClearDatafield(_personAge);
        if (age) {
            personDataPointer->_personAge = age;
        }
    }
}
static void DYYPersonSetGender(DYYPersonData *personDataPointer, DYYPersonGender gender) {
    if (NULL != personDataPointer) {
        DYYMacroCheckNullResponceAndClearDatafield(_personGender);
        if (gender) {
            personDataPointer->_personGender = gender;
        }
    }
}

char *DYYPersonGetName(DYYPersonData *personDataPointer) {
    return NULL != personDataPointer ? personDataPointer->_personName : NULL;
}

unsigned int *DYYPersonGetAge(DYYPersonData *personDataPointer) {
    return NULL != personDataPointer ? personDataPointer->_personAge : NULL;
}

DYYPersonGender *DYYPersonGetGender(DYYPersonData *personDataPointer) {
    return NULL != personDataPointer ? personDataPointer->_personGender : NULL;
}
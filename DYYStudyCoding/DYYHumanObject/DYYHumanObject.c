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

#define DYYFreeAllocatedData(inputField) if (NULL != person->inputField) { \
                    free(person->inputField); \
                    person->inputField = NULL; \
                }

static
void DYYPersonSetName(DYYPerson *person, char *name);
static
void DYYPersonSetAge(DYYPerson *person, unsigned int age);
static
void DYYPersonSetGender(DYYPerson *person, DYYGender gender);
char *DYYPersonName(DYYPerson *person);
unsigned int DYYPersonAge(DYYPerson *person);
DYYGender DYYPersonGender(DYYPerson *person);
void DYYPersonSetMatureness(DYYPerson *person);

#pragma mark -
#pragma mark Public Implementations

DYYPerson *DYYPersonCreateWithNameAgeGender(char *name,
                                                    unsigned int age,
                                                    DYYGender gender)
{
        DYYPerson *personObject;
        personObject = calloc(1, sizeof(DYYPerson));
        assert(NULL != personObject);
        DYYPersonSetName(personObject, name);
        DYYPersonSetAge(personObject, age);
        DYYPersonSetGender(personObject, gender);
        DYYPersonSetMatureness(personObject);
    
    return personObject;
}

void DYYPersonSetMarriedWithPartner(void *person, void *personPartner) {
    if ((NULL != person) && (NULL != personPartner)) {
        
    }
}

#pragma mark -
#pragma mark Accessors
static void DYYPersonSetName(DYYPerson *person, char *name) {
    if (NULL != person) {
        DYYFreeAllocatedData(_name);
                if (name) {
                person->_name = strdup(name);
        }
    }
}

char *DYYPersonName(DYYPerson *person) {
    return NULL != person ? person->_name : NULL;
}

static void DYYPersonSetAge(DYYPerson *person, unsigned int age) {
    if (NULL != person) {
            person->_age = age;
    }
}

unsigned int DYYPersonAge(DYYPerson *person) {
    return NULL != person ? person->_age : NULL;
}

static void DYYPersonSetGender(DYYPerson *person, DYYGender gender) {
    if (NULL != person) {
            person->_gender = gender;
    }
}

DYYGender DYYPersonGender(DYYPerson *person) {
    return NULL != person ? person->_gender : NULL;
}

void DYYPersonSetMatureness(DYYPerson *person) {
    if (NULL != person) {
        person->_matureness = DYYMaturenessRank + 1;
    }

}
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
#include <limits.h>

#pragma mark -
#pragma mark Private Declarations

#define DYYFreeAllocatedData(person, inputField) if (NULL != person->inputField) { \
                    free(person->inputField); \
                    person->inputField = NULL; \
                }
static
void DYYPersonSetName(DYYPerson *person, char *name);
static
void DYYPersonSetAge(DYYPerson *person, uint8_t age);
static
void DYYPersonSetGender(DYYPerson *person, DYYGender gender);
char *DYYPersonName(DYYPerson *person);
uint8_t DYYPersonAge(DYYPerson *person);
DYYGender DYYPersonGender(DYYPerson *person);
static
void DYYPersonSetInitialRetainCount(DYYPerson *person);
static
void DYYPersonRetain(DYYPerson *person);
static
void DYYPersonRelease(DYYPerson *person);
static
unsigned int DYYPersonRetainCount(DYYPerson *person);
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
        DYYPersonSetInitialRetainCount(personObject);
    
    return personObject;
}

bool DYYPersonSetMarried(DYYPerson *person, DYYPerson *personPartner) {
    if (NULL != person && NULL != personPartner && person != personPartner) {
        DYYPersonSetDivorced(person);
        if (DYYPersonSetDivorced(person) == true && person->_gender != personPartner->_gender) {
                personPartner->_partner = person;
                person->_partner = personPartner;
                DYYPersonRetain(personPartner);
        }
        return true;
    }
    else
        return false;
}


bool DYYPersonSetDivorced(DYYPerson *person) {
    if (NULL != person) {
        DYYPerson *personPartner = person->_partner;
        DYYFreeAllocatedData(person, _partner)
        DYYFreeAllocatedData(personPartner, _partner)
        //            free(personPartner->_partner);
        //            free(person->_partner);
        DYYPersonRelease(personPartner);
        if (DYYPersonRetainCount(person) == 0) {
            DYYPersonDeallocate(person);
        }
        return true;
    }
    else
        return false;
}

bool DYYPersonDeallocate(DYYPerson *person) {
    if (DYYPersonRetainCount(person) == 1 && person->_partner == NULL) {
            DYYPersonSetName(person, NULL);
            free(person);
            return true;
        }
    else
           return false;
}

#pragma mark -
#pragma mark Accessors
static void DYYPersonSetName(DYYPerson *person, char *name) {
    if (NULL != person) {
        DYYFreeAllocatedData(person, _name);
                if (name) {
                person->_name = strdup(name);
        }
    }
}

char *DYYPersonName(DYYPerson *person) {
    return NULL != person ? person->_name : NULL;
}

static void DYYPersonSetAge(DYYPerson *person, uint8_t age) {
    if (NULL != person) {
            person->_age = age;
    }
}

uint8_t DYYPersonAge(DYYPerson *person) {
    return NULL != person ? person->_age : 0;
}

static void DYYPersonSetGender(DYYPerson *person, DYYGender gender) {
    if (NULL != person) {
            person->_gender = gender;
    }
}

DYYGender DYYPersonGender(DYYPerson *person) {
    return NULL != person ? person->_gender : 0;
}

void DYYPersonSetInitialRetainCount(DYYPerson *person) {
    if (NULL != person) {
        person->_retainCount = 1;
    }
}

void DYYPersonRetain(DYYPerson *person) {
    if (NULL != person) {
        person->_retainCount = person->_retainCount + 1;
    }
}

void DYYPersonRelease(DYYPerson *person) {
    if (NULL != person) {
        person->_retainCount = person->_retainCount - 1;
    }
    
}

unsigned int DYYPersonRetainCount(DYYPerson *person) {
    if (NULL!= person) {
        unsigned int retainCount = person->_retainCount;
        return retainCount;
        }
      else
          return UINT_MAX;
}

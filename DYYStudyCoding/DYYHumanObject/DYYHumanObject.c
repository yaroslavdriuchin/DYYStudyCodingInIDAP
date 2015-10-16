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
char *DYYPersonName(DYYPerson *person);
static
void DYYPersonSetAge(DYYPerson *person, uint8_t age);
static
uint8_t DYYPersonAge(DYYPerson *person);
static
void DYYPersonSetGender(DYYPerson *person, DYYGender gender);
static
DYYGender DYYPersonGender(DYYPerson *person);
static
char *DYYPersonName(DYYPerson *person);
static
void DYYPersonRetain(DYYPerson *person);
static
void DYYPersonRelease(DYYPerson *person);
static
unsigned int DYYPersonRetainCount(DYYPerson *person);
static
void DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child);

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
        personObject->_retainCount = 1;
    
    return personObject;
}

bool DYYPersonSetMarried(DYYPerson *person, DYYPerson *partner) {
    if (NULL != person
        && NULL != partner
        && person->_age > partner->_age
        && person->_gender != partner->_gender) {
                DYYPersonSetDivorced(person);
                DYYPersonSetDivorced(partner);
                partner->_partner = person;
                partner->_marriedStatus = true;
                person->_partner = partner;
                person->_marriedStatus = true;
                DYYPersonRetain(partner);
                return true;
                }
         else {
                return false;
              }
}

bool DYYPersonSetDivorced(DYYPerson *person) {
        DYYPerson *partner = person->_partner;
        if (NULL != person
            && NULL != partner
            && person->_partner != NULL
            && person->_age > partner->_age) {
            DYYFreeAllocatedData(person, _partner);
            person->_marriedStatus = false;
            DYYPersonRelease(partner);
            return true;
            }
            else {
                   return false;
                  }
}

bool DYYPersonDeallocate(DYYPerson *person) {
    if (person != NULL
        && DYYPersonRetainCount(person) <= 1 &&
        person->_partner == NULL) {
            DYYPersonSetName(person, NULL);
            DYYPersonSetDivorced(person);
            free(person);
            return true;
        }
        else {
               return false;
             }
}

DYYPerson *DYYPersonCreateChildOfFatherAndMother(char *name, uint8_t age, DYYGender gender, DYYPerson *father, DYYPerson *mother) {
    if (NULL != father
        && NULL != mother
        && father->_gender == DYYGenderMale
        && mother->_gender == DYYGenderFemale) {
            DYYPerson *child = DYYPersonCreateWithNameAgeGender(name, age, gender);
            DYYPersonSetAsParent(father, child);
            DYYPersonSetAsParent(mother, child);
            child->_father = father;
            child->_mother = mother;
            return child;
    }
    else  {
        return NULL;
          }
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

void DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child) {
    for (uint8_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (NULL == parent->_childrenList[counter]) {
            parent->_childrenList[counter] = child;
            DYYPersonRetain(child);
        }
    }
}
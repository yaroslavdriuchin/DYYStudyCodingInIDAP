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
#define DYYCheckTwoObjectsNULL(objectOne, objectTwo) NULL != objectOne && NULL != objectTwo

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
bool DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner);

static
void *DYYPersonPartner(DYYPerson *person);

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
bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child);

static
void DYYPersonRemoveChild (DYYPerson *parent, DYYPerson *child);

static
uint8_t DYYPersonCurrentChildrenCount(DYYPerson *parent);


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
    if (DYYCheckTwoObjectsNULL(person, partner)
        && DYYPersonAge(person) > DYYPersonAge(partner)
        && DYYPersonGender(person) != DYYPersonGender(partner)) {
                DYYPersonSetDivorced(person);
                DYYPersonSetDivorced(partner);
                DYYPersonSetPartner(partner, person);
                partner->_marriedStatus = true;
                DYYPersonSetPartner(person, partner);
                person->_marriedStatus  = true;
                DYYPersonRetain(partner);
        
                return true;
                }
                 else {
                        return false;
                      }
}

bool DYYPersonSetDivorced(DYYPerson *person) {
        DYYPerson *partner = person->_partner;
        if (DYYCheckTwoObjectsNULL(person, partner)
            && NULL != DYYPersonPartner(person)
            && DYYPersonAge(person) > DYYPersonAge(partner)) {
            DYYFreeAllocatedData(person, _partner);
            person->_marriedStatus = false;
            DYYPersonRelease(partner);
            
            return true;
            }
                else {
                       return false;
                      }
}

bool __DYYPersonDeallocate(DYYPerson *person) {
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
    if (DYYCheckTwoObjectsNULL(father, mother)
        && DYYPersonGender(father) == DYYGenderMale
        && DYYPersonGender(mother) == DYYGenderFemale
        && DYYPersonCurrentChildrenCount(mother) < kDYYChildrenMaxCount
        && DYYPersonCurrentChildrenCount(father) < kDYYChildrenMaxCount) {
                DYYPerson *child = DYYPersonCreateWithNameAgeGender(name, age, gender);
                DYYPersonSetAsParent(father, child);
                DYYPersonSetAsParent(mother, child);
                father->_childrenCount = DYYPersonCurrentChildrenCount(father);
                mother->_childrenCount = DYYPersonCurrentChildrenCount(father);
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

void DYYPersonSetName(DYYPerson *person, char *name) {
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

void DYYPersonSetAge(DYYPerson *person, uint8_t age) {
    if (NULL != person) {
            person->_age = age;
    }
}

uint8_t DYYPersonAge(DYYPerson *person) {
    return NULL != person ? person->_age : 0;
}

void DYYPersonSetGender(DYYPerson *person, DYYGender gender) {
    if (NULL != person) {
            person->_gender = gender;
    }
}

DYYGender DYYPersonGender(DYYPerson *person) {
    return NULL != person ? person->_gender : 0;
}

bool DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner) {
    if (DYYCheckTwoObjectsNULL(person, partner)) {
    person->_partner = partner;
        
    return true;
    }
      else  {
             return false;
            }
}

void *DYYPersonPartner(DYYPerson *person) {
    if (NULL != person) {
        DYYPerson *partner = person->_partner;
        
        return partner;
        }
          else {
                return NULL;
               }
}

void DYYPersonRetain(DYYPerson *person) {
    if (NULL != person) {
        person->_retainCount = person->_retainCount++;
    }
}

void DYYPersonRelease(DYYPerson *person) {
    if (NULL != person) {
        person->_retainCount = person->_retainCount--;
        if (person->_retainCount == 0) {
              __DYYPersonDeallocate(person);
        }
    }
    
}

unsigned int DYYPersonRetainCount(DYYPerson *person) {
    if (NULL!= person) {
        unsigned int retainCount = person->_retainCount;
        
        return retainCount;
        }
          else  {
                 return UINT_MAX;
                }
}

bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child) {
    if (parent != child) {
    for (uint8_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (NULL == parent->_childrenList[counter]) {
                    parent->_childrenList[counter] = child;
                    DYYPersonRetain(child);
            
                    break;
                    }
        }
        
        return true;
    }
    else  {
           return false;
          }
}

uint8_t DYYPersonCurrentChildrenCount(DYYPerson *parent) {
    uint8_t childrenCount = 0;
    if (parent != NULL) {
        for (uint8_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
            if (NULL != parent->_childrenList[counter]) {
                         childrenCount++;
                       }
                }
        
        } return childrenCount;
}

//bool DYYPersonRemoveChildOfFatherAndMother (DYYPerson *father, DYYPerson *mother, DYYPerson *child) {
//          if (DYYCheckTwoObjectsNULL(father, mother)
//              && child  ! = NULL
//              && father != child || mother != child || mother != father) {
//           
//          }
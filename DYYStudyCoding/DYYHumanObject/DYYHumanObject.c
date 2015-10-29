//
//  DYYHumanObject.c
//  DYYStudyCoding
//
//  Created by Yar on 10/6/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "DYYHumanObject.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Private Declarations

#define DYYCheckTwoObjectsNULL(objectOne, objectTwo) NULL != objectOne && NULL != objectTwo

static
void DYYPersonSetName(DYYPerson *person, DYYString *name);

static
void DYYPersonSetAge(DYYPerson *person, unsigned int age);

static
void DYYPersonSetGender(DYYPerson *person, DYYGender gender);

static
bool DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner);

static
bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child);

static
bool DYYPersonSetParent(DYYPerson *child, DYYPerson *parent);

static
void DYYPersonMarryStatus(DYYPerson *person, bool marriedStatus);

static
void DYYPersonSearchAndRemoveChild(DYYPerson *parent, DYYPerson *child);

static
void DYYPersonRemoveAllChildren(DYYPerson *parent);

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYPersonDeallocate(void *person) {
    if (person != NULL
        && DYYObjectRetainCount(person) <= 1) {
        DYYPersonSetName(person, NULL);
        DYYPersonDivorce(person);
        DYYPersonRemoveAllChildren(person);
        __DYYObjectDeallocate(person);
        
    }
}

DYYPerson *DYYPersonCreateWithNameAgeGender(DYYString *name,
                                            unsigned int age,
                                            DYYGender gender)    {
        DYYPerson *personObject = DYYObjectCreateOfType(DYYPerson);
        DYYPersonSetName(personObject, name);
        DYYPersonSetAge(personObject, age);
        DYYPersonSetGender(personObject, gender);
    
    return personObject;
}


DYYPerson *DYYPersonCreateChildOfFatherAndMother(DYYString *name, unsigned int age, DYYGender gender, DYYPerson *father, DYYPerson *mother) {
    if (DYYCheckTwoObjectsNULL(father, mother)
        && DYYPersonGender(father) == kDYYGenderMale
        && DYYPersonGender(mother) == kDYYGenderFemale
        && DYYPersonCurrentChildrenCount(mother) < kDYYChildrenMaxCount
        && DYYPersonCurrentChildrenCount(father) < kDYYChildrenMaxCount)
    {
        DYYPerson *child = DYYPersonCreateWithNameAgeGender(name, age, gender);
        DYYPersonSetAsParent(father, child);
        DYYPersonSetAsParent(mother, child);
        DYYPersonSetParent(child, father);
        DYYPersonSetParent(child, mother);
    
        return child;
    }
    
            return NULL;
}

#pragma mark -
#pragma mark Accessors

void DYYPersonSetName(DYYPerson *person, DYYString *name) {
    if (NULL != person && name != person->_name)  {
        DYYObjectRelease(person->_name);
        person->_name = DYYStringCreateWithValue(name);
        DYYObjectRetain(person->_name);
    }
}

DYYString *DYYPersonName(DYYPerson *person) {
    if (NULL == person) {
        return NULL;
    }
        return DYYStringValue(person->_name);
}

void DYYPersonSetAge(DYYPerson *person, unsigned int age) {
    if (NULL != person && person->_age != age) {
            person->_age = age;
    }
}

unsigned int DYYPersonAge(DYYPerson *person) {
    if (NULL != person) {
            return person->_age;
    }
    
    return 0;
}

void DYYPersonSetGender(DYYPerson *person, DYYGender gender) {
    if (NULL != person) {
            person->_gender = gender;
    }
}

DYYGender DYYPersonGender(DYYPerson *person) {
    if (NULL != person) {
           return person->_gender;
    }
    return 0;
}

bool DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner)  {
    if (person!= NULL && person != partner) {
        person->_partner = partner;
        
        return true;
    }
    
        return false;
}

void *DYYPersonPartner(DYYPerson *person) {
    if (NULL != person) {
           return person->_partner;
           }

    return NULL;
}

bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child) {
    if (parent != child) {
    for (uint16_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (NULL == parent->_childrenList[counter]) {
                    parent->_childrenList[counter] = child;
                    parent->_childrenCount = parent->_childrenCount++;
                    DYYObjectRetain(child);
            
                    break;
                    }
        }
        
        return true;
    }
    
        return false;
}

bool DYYPersonSetParent(DYYPerson *child, DYYPerson *parent) {
    if (NULL != child) {
        if (DYYPersonGender(parent) == kDYYGenderMale) {
                  child->_father = parent;
        }   else  {
                  child->_mother = parent;
                  }
        
    if (NULL == parent) {
            child->_father = NULL;
            child->_mother = NULL;
        }
        
    return true;
    }
    
    return false;
}

void DYYPersonMarryStatus(DYYPerson *person, bool marriedStatus) {
    if (NULL != person) {
            person->_marriedStatus = marriedStatus;
       }
}

bool DYYPersonMarriedStatus(DYYPerson *person) {
    if (NULL != person) {
           return person->_marriedStatus;
       }
    
    return false;
}

uint16_t DYYPersonCurrentChildrenCount(DYYPerson *parent) {
    uint16_t childrenCount = 0;
    if (parent != NULL) {
        for (uint16_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
            if (NULL != parent->_childrenList[counter]) {
                         childrenCount++;
                         }
                }
        
        } return childrenCount;
}

#pragma mark -
#pragma mark Public Implementations

bool DYYPersonMarry(DYYPerson *person, DYYPerson *partner) {
    if (DYYCheckTwoObjectsNULL(person, partner)
        && DYYPersonAge(person) > DYYPersonAge(partner)
        && DYYPersonGender(person) != DYYPersonGender(partner)) {
        DYYPersonDivorce(person);
        DYYPersonSetPartner(partner, person);
        DYYPersonMarryStatus(partner, true);
        DYYPersonSetPartner(person, partner);
        DYYPersonMarryStatus(person, true);
        DYYObjectRetain(partner);
        
        return true;
    }
    
        return false;
}

bool DYYPersonDivorce(DYYPerson *person) {
    DYYPerson *partner = DYYPersonPartner(person);
    
    if (DYYCheckTwoObjectsNULL(person, partner)
        && NULL != DYYPersonPartner(person)
        && DYYPersonAge(person) > DYYPersonAge(partner)) {
        DYYPersonMarryStatus(partner, false);
        DYYPersonSetPartner(partner, NULL);
        DYYPersonMarryStatus(person, false);
        DYYPersonSetPartner(person, NULL);
        DYYObjectRelease(partner);
        
        return true;
    }
    
        return false;
}

bool DYYPersonRemoveChildOfFatherAndMother(DYYPerson *father, DYYPerson *mother, DYYPerson *child) {
      if (DYYCheckTwoObjectsNULL(father, mother)
          && child  != NULL
          && (father != child || mother != child || mother != father)) {
                  DYYPersonSearchAndRemoveChild(father, child);
                  DYYPersonSearchAndRemoveChild(mother, child);
                  DYYPersonSetParent(child, NULL);
          
                  return true;
          }
    
          return false;
}

#pragma mark -
#pragma mark Private Implementations

void DYYPersonSearchAndRemoveChild(DYYPerson *parent, DYYPerson *child) {
    for (uint16_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (child == parent->_childrenList[counter]) {
            parent->_childrenList[counter] = NULL;
            parent->_childrenCount = parent->_childrenCount--;
            DYYObjectRelease(child);
            
            break;
            }
      }
}

void DYYPersonRemoveAllChildren(DYYPerson *parent) {
    for (uint16_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (parent->_childrenList[counter]) {
        DYYPerson *child = parent->_childrenList[counter];
        DYYObjectRelease(child);
        parent->_childrenList[counter] = NULL;
        parent->_childrenCount = parent->_childrenCount--;
  
        }
    }
}
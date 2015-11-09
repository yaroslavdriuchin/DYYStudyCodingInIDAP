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
#include "DYYHuman.h"
#include "DYYMacro.h"

#pragma mark -
#pragma mark Private Declarations

static
void DYYPersonSetName(DYYPerson *person, char *name);

static
void DYYPersonSetAge(DYYPerson *person, unsigned int age);

static
void DYYPersonSetGender(DYYPerson *person, DYYGender gender);

static
void DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner);

static
bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child);

static
bool DYYPersonSetParent(DYYPerson *child, DYYPerson *parent);

static
void DYYPersonSetChildrenArray(DYYPerson *person);

static
DYYArray *DYYPersonChildrenArray(DYYPerson *person);

static
void DYYPersonSearchAndRemoveChild(DYYPerson *parent, DYYPerson *child);

static
void DYYPersonRemoveAllChildren(DYYPerson *parent);

#pragma mark -
#pragma mark Initializations and Deallocators

void __DYYPersonDeallocate(void *person) {
        DYYPersonSetName(person, NULL);
        DYYPersonDivorce(person);
        DYYPersonRemoveAllChildren(person);
    
        __DYYObjectDeallocate(person);
}

DYYPerson *DYYPersonCreateWithNameAgeGender(char *name,
                                            unsigned int age,
                                            DYYGender gender)
{
        DYYPerson *personObject = DYYObjectCreateOfType(DYYPerson);
        DYYPersonSetName(personObject, name);
        DYYPersonSetAge(personObject, age);
        DYYPersonSetGender(personObject, gender);
        DYYPersonSetChildrenArray(personObject);
    
        return personObject;
}


DYYPerson *DYYPersonCreateChildOfFatherAndMother(char *name,
                                                 unsigned int age,
                                                 DYYGender gender,
                                                 DYYPerson *father,
                                                 DYYPerson *mother)
{
    if (NULL != father && NULL != mother
        && DYYPersonGender(father) == kDYYGenderMale
        && DYYPersonGender(mother) == kDYYGenderFemale
        && DYYPersonCurrentChildrenCount(mother) < kDYYArrayMaxCount
        && DYYPersonCurrentChildrenCount(father) < kDYYArrayMaxCount)
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

void DYYPersonSetName(DYYPerson *person, char *name) {
    if (NULL != person) {
        DYYString *stringObject = DYYStringCreateWithString(name);
        person->_name = stringObject;
        DYYObjectRetain(stringObject);
    }
    
    if (NULL != person && NULL == name) {
        DYYString *stringObject = person->_name;
        DYYStringSetValue(stringObject, NULL);
        DYYObjectRelease(stringObject);
    }
}

char *DYYPersonName(DYYPerson *person) {
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

void DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner)  {
    if (person!= NULL && person != partner) {
        person->_partner = partner;
        if (DYYPersonAge(person) > DYYPersonAge(partner)) {
            DYYObjectRetain(partner);
            }
     }
}

void *DYYPersonPartner(DYYPerson *person) {
    if (NULL != person) {
           return person->_partner;
           }

    return NULL;
}

bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child) {
    if (parent != NULL && parent != child) {
        for (uint16_t counter = 0; counter < kDYYArrayMaxCount; counter++) {
            if (child == DYYArrayValueAtCount(DYYPersonChildrenArray(parent), counter)) {
                return true;
            }
            
            if (NULL == DYYArrayValueAtCount(DYYPersonChildrenArray(parent), counter)) {
                DYYArraySetValueAtCount(DYYPersonChildrenArray(parent), counter, child);
                DYYObjectRetain(DYYPersonChildrenArray(parent));
                
                return true;
            }
        }
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

bool DYYPersonMarriedStatus(DYYPerson *person) {
    return NULL != DYYPersonPartner(person);
}

#pragma mark -
#pragma mark Public Implementations

uint16_t DYYPersonCurrentChildrenCount(DYYPerson *parent) {
               return DYYArrayCount(DYYPersonChildrenArray(parent));
}

bool DYYPersonMarry(DYYPerson *person, DYYPerson *partner) {
    if (DYYCheckTwoObjectsNULL(person, partner)
        && DYYPersonGender(person) != DYYPersonGender(partner)) {
        DYYPersonDivorce(person);
        DYYPersonDivorce(partner);
        DYYPersonSetPartner(partner, person);
        DYYPersonSetPartner(person, partner);
        
        return true;
    }
    
        return false;
}

bool DYYPersonDivorce(DYYPerson *person) {
    DYYPerson *partner = DYYPersonPartner(person);
    
    if (DYYCheckTwoObjectsNULL(person, partner)
        && NULL != DYYPersonPartner(person))
    {
        DYYPersonSetPartner(partner, NULL);
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

void DYYPersonSetChildrenArray(DYYPerson *person) {
    if (person != NULL) {
           person->_childrenArray = DYYArrayCreate();
    }
}

DYYArray *DYYPersonChildrenArray(DYYPerson *person) {
    if (person != NULL) {
        DYYArray *childrenArray = person->_childrenArray;
        
        return childrenArray;
        }  else  {
                   return NULL;
                 }
}


void DYYPersonSearchAndRemoveChild(DYYPerson *parent, DYYPerson *child) {
    for (uint16_t counter = 0; counter < kDYYArrayMaxCount; counter++) {
        if (child == DYYArrayValueAtCount(DYYPersonChildrenArray(parent), counter)) {
            DYYArraySetValueAtCount(DYYPersonChildrenArray(parent), counter, NULL);
            DYYObjectRelease(DYYPersonChildrenArray(parent));
            
            return;
            }
      }
}

void DYYPersonRemoveAllChildren(DYYPerson *parent) {
    for (uint16_t counter = 0; counter < kDYYArrayMaxCount; counter++) {
        if (DYYArrayValueAtCount(DYYPersonChildrenArray(parent), counter) != NULL) {
            DYYPerson *child = DYYArrayValueAtCount(DYYPersonChildrenArray(parent), counter);
            DYYObjectRelease(child);
            DYYArraySetValueAtCount(DYYPersonChildrenArray(parent), counter, NULL);
      
        }
    }
}
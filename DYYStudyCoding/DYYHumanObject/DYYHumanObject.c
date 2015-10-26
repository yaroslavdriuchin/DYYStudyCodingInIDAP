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
void DYYPersonSetAge(DYYPerson *person, uint8_t age);

static
void DYYPersonSetGender(DYYPerson *person, DYYGender gender);

static
bool DYYPersonSetPartner(DYYPerson *person, DYYPerson *partner);
//
//static
//void DYYPersonRetain(DYYPerson *person);

static
bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child);

static
bool DYYPersonSetParent(DYYPerson *child, DYYPerson *parent);

static
bool DYYPersonSetMarriedStatus(DYYPerson *person, bool marriedStatus);

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
        DYYPersonSetDivorced(person);
        DYYPersonRemoveAllChildren(person);
//        free(person);
        __DYYObjectDeallocate(person);
    }
}

DYYPerson *DYYPersonCreateWithNameAgeGender(char *name,
                                                    unsigned int age,
                                                    DYYGender gender)
{
    DYYPerson *personObject = DYYObjectCreateOfType(DYYPerson);
//        DYYPerson *personObject = calloc(1, sizeof(DYYPerson));
//        assert(NULL != personObject);
        DYYPersonSetName(personObject, name);
        DYYPersonSetAge(personObject, age);
        DYYPersonSetGender(personObject, gender);
//        personObject->_retainCount = 1;
    
    return personObject;
}


DYYPerson *DYYPersonCreateChildOfFatherAndMother(char *name, uint8_t age, DYYGender gender, DYYPerson *father, DYYPerson *mother) {
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
    if (NULL != person && person->_age != age) {
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
    if (DYYCheckTwoObjectsNULL(person, partner) && person != partner) {
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

//void DYYPersonRetain(DYYPerson *person) {
//    if (NULL != person) {
//        person->_retainCount = person->_retainCount + 1;
//    }
//}
//
//void DYYPersonRelease(DYYPerson *person) {
//    if (NULL != person) {
//        person->_retainCount--;
//        if (person->_retainCount == 0) {
//              __DYYPersonDeallocate(person);
//        }
//    }
//    
//}
//
//unsigned int DYYPersonRetainCount(DYYPerson *person) {
//    if (NULL != person) {
//        unsigned int retainCount = person->_retainCount;
//        
//        return retainCount;
//        }
//    
//    return UINT_MAX;
//}

bool DYYPersonSetAsParent(DYYPerson *parent, DYYPerson *child) {
    if (parent != child) {
    for (uint8_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (NULL == parent->_childrenList[counter]) {
                    parent->_childrenList[counter] = child;
                    parent->_childrenCount = parent->_childrenCount++;
                    DYYObjectRetain(child);
            
                    break;
                    }
        }
        
        return true;
    }
       else  {
               return false;
             }
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

bool DYYPersonSetMarriedStatus(DYYPerson *person, bool marriedStatus) {
    if (NULL != person) {
        person->_marriedStatus = marriedStatus;
        
        return true;
    }  else  {
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

#pragma mark -
#pragma mark Public Implementations


bool DYYPersonSetMarried(DYYPerson *person, DYYPerson *partner) {
    if (DYYCheckTwoObjectsNULL(person, partner)
        && DYYPersonAge(person) > DYYPersonAge(partner)
        && DYYPersonGender(person) != DYYPersonGender(partner)) {
        DYYPersonSetDivorced(person);
        DYYPersonSetPartner(partner, person);
        DYYPersonSetMarriedStatus(partner, true);
        DYYPersonSetPartner(person, partner);
        DYYPersonSetMarriedStatus(person, true);
        DYYObjectRetain(partner);
        
        return true;
    }
    else {
        return false;
    }
}

bool DYYPersonSetDivorced(DYYPerson *person) {
    DYYPerson *partner = DYYPersonPartner(person);
    
    if (DYYCheckTwoObjectsNULL(person, partner)
        && NULL != DYYPersonPartner(person)
        && DYYPersonAge(person) > DYYPersonAge(partner)) {
        DYYPersonSetMarriedStatus(partner, false);
        DYYFreeAllocatedData(partner, _partner);
        DYYPersonSetMarriedStatus(person, false);
        DYYFreeAllocatedData(person, _partner);
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
          } else     {
                      return false;
                     }
}

#pragma mark -
#pragma mark Private Implementations

void DYYPersonSearchAndRemoveChild(DYYPerson *parent, DYYPerson *child) {
    for (uint8_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (child == parent->_childrenList[counter]) {
            parent->_childrenList[counter] = NULL;
            parent->_childrenCount = parent->_childrenCount--;
            DYYObjectRelease(child);
            
            break;
            }
      }
}

void DYYPersonRemoveAllChildren(DYYPerson *parent) {
    for (uint8_t counter = 0; counter < kDYYChildrenMaxCount; counter++) {
        if (parent->_childrenList[counter]) {
        DYYPerson *child = parent->_childrenList[counter];
        DYYObjectRelease(child);
        parent->_childrenList[counter] = NULL;
        parent->_childrenCount = parent->_childrenCount--;
  
        }
    }
}
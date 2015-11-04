//
//  DYYHumanObject.h
//  DYYStudyCoding
//
//  Created by Yar on 10/6/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
#ifndef DYYHumanObject_h
#define DYYHumanObject_h

#include <stdbool.h>
#include <stdio.h>
#include "DYYObject.h"
#include "DYYStringObject.h"
#include "DYYStaticArrayObject.h"

typedef enum {
    kDYYGenderMale,
    kDYYGenderFemale,
} DYYGender;

typedef struct DYYPersonData DYYPerson;

struct DYYPersonData {
    DYYObject _super;
    DYYString *_name;
    DYYPerson *_partner;
    DYYPerson *_father;
    DYYPerson *_mother;
    DYYArray *_childrenArray;
    uint16_t _childrenCount;
    unsigned int _age;
    DYYGender _gender;
    bool _marriedStatus;
};

extern void __DYYPersonDeallocate(void *person);

extern DYYPerson *DYYPersonCreateWithNameAgeGender(DYYString *name, unsigned int age, DYYGender gender);

extern DYYPerson *DYYPersonCreateChildOfFatherAndMother(DYYString *name, unsigned int age, DYYGender gender, DYYPerson *father, DYYPerson *mother);

extern bool DYYPersonMarry(DYYPerson *person, DYYPerson *personPartner);

extern bool DYYPersonDivorce(DYYPerson *person);

extern bool DYYPersonRemoveChildOfFatherAndMother(DYYPerson *father, DYYPerson *mother, DYYPerson *child);

extern DYYString *DYYPersonName(DYYPerson *person);

extern unsigned int DYYPersonAge(DYYPerson *person);

extern DYYGender DYYPersonGender(DYYPerson *person);

extern void *DYYPersonPartner(DYYPerson *person);

extern bool DYYPersonMarriedStatus(DYYPerson *person);

extern uint16_t DYYPersonCurrentChildrenCount(DYYPerson *parent);

extern void DYYPersonRelease(DYYPerson *person);

#endif /* DYYHumanObject_h */

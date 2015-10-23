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

static const uint8_t kDYYChildrenMaxCount = 20;

typedef enum {
    kDYYGenderMale,
    kDYYGenderFemale,
} DYYGender;

typedef struct DYYPersonDataList DYYPerson;

struct DYYPersonDataList {
    char *_name;
    DYYGender _gender;
    DYYPerson *_partner;
    DYYPerson *_father;
    DYYPerson *_mother;
    DYYPerson *_childrenList[kDYYChildrenMaxCount];
    uint8_t _childrenCount;
    uint8_t _age;
    unsigned int _retainCount;
    bool _marriedStatus;
};

bool __DYYPersonDeallocate(DYYPerson *person);

extern DYYPerson *DYYPersonCreateWithNameAgeGender(char *name, unsigned int age, DYYGender gender);

extern DYYPerson *DYYPersonCreateChildOfFatherAndMother(char *name, uint8_t age, DYYGender gender, DYYPerson *father, DYYPerson *mother);

extern bool DYYPersonSetMarried(DYYPerson *person, DYYPerson *personPartner);

extern bool DYYPersonSetDivorced(DYYPerson *person);

extern bool DYYPersonRemoveChildOfFatherAndMother(DYYPerson *father, DYYPerson *mother, DYYPerson *child);

char *DYYPersonName(DYYPerson *person);

uint8_t DYYPersonAge(DYYPerson *person);

DYYGender DYYPersonGender(DYYPerson *person);

unsigned int DYYPersonRetainCount(DYYPerson *person);

void *DYYPersonPartner(DYYPerson *person);

uint8_t DYYPersonCurrentChildrenCount(DYYPerson *parent);

#endif /* DYYHumanObject_h */

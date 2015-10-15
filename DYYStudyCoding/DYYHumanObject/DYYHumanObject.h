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
    DYYGenderMale,
    DYYGenderFemale,
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

DYYPerson *DYYPersonCreateWithNameAgeGender(char *name, unsigned int age, DYYGender gender);

bool DYYPersonSetMarried(DYYPerson *person, DYYPerson *personPartner);
bool DYYPersonSetDivorced(DYYPerson *person);
void DYYPersonDeallocate(DYYPerson *person);
//void *DYYPersonCreateNewChildWithMotherFather (char *newChildName, DYYPersonGender newChildGender, void *newChildFather, void *newChildMother);
#endif /* DYYHumanObject_h */

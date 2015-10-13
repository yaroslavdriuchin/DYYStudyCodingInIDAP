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

//int kDYYChildrenMaxCount = 20;

typedef enum {
    DYYGenderMale,
    DYYGenderFemale,
} DYYGender;

struct DYYPersonDataList {
    char *_name;
    DYYGender _gender;
    void *_partner;
    void *_father;
    void *_mother;
    void *_childrenList[20];
    uint8_t _childrenCount;
    unsigned int _age;
    bool _marriedStatus;
    unsigned int _matureness;
};

unsigned int DYYMaturenessRank = 0;

typedef struct DYYPersonDataList DYYPerson;

DYYPerson *DYYPersonCreateWithNameAgeGender(char *name, unsigned int age, DYYGender gender);

void DYYPersonSetMarriedWithPartner(void *person, void *personPartner);
//void DYYPersonSetDivorcedWithPartner(void *personPartner);
//void *DYYPersonCreateNewChildWithMotherFather (char *newChildName, DYYPersonGender newChildGender, void *newChildFather, void *newChildMother);
#endif /* DYYHumanObject_h */

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

typedef enum {
    DYYPersonGenderMale,
    DYYPersonGenderFemale,
} DYYPersonGender;

struct DYYPersonDataList {
    char *_personName;
    DYYPersonGender _personGender;
    void *_personPartner;
    void *_personParent;
    void *_personChildrenList[20];
    uint8_t _personChildrenTotalCount;
    unsigned int _personAge;
    bool _personMarriedStatus;
};

typedef struct DYYPersonDataList DYYPersonData;

DYYPersonData *DYYPersonCreateWithNameAgeGender(char *inputPersonName, unsigned int inputPersonAge, DYYPersonGender inputPersonGender);

//void DYYPersonSetMarriedWithPartner(void *personPartner);
//void DYYPersonSetDivorcedWithPartner(void *personPartner);
//void *DYYPersonCreateNewChildWithMotherFather (char *newChildName, DYYPersonGender newChildGender, void *newChildFather, void *newChildMother);
#endif /* DYYHumanObject_h */

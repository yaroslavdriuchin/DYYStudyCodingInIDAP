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

char *DYYPersonName(DYYPersonData *personDataObject);

DYYPersonData *DYYPersonCreateWithNameAgeGender(char *inputPersonName, unsigned int inputPersonAge, DYYPersonGender inputPersonGender);

//void DYYMarryPersonSet(void *personPartner);
//
//void DYYDivorsePersonSet(void *personPartner);

#endif /* DYYHumanObject_h */

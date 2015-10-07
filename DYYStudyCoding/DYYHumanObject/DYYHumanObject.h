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
    DYYPersonGenderUndefined,
    DYYPersonGenderMale,
    DYYPersonGenderFemale,
} DYYPersonGender;

typedef struct DYYPersonDataList DYYPersonData;

DYYPersonData *DYYPersonCreateWithInitialParameters(char *inputPersonName, uint8_t inputPersonAge, DYYPersonGender inputPersonGender);

//void DYYMarryPersonSet(void *personPartner);
//
//void DYYDivorsePersonSet(void *personPartner);

#endif /* DYYHumanObject_h */

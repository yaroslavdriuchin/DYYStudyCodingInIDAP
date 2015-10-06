//
//  DYYHumanObject.h
//  DYYStudyCoding
//
//  Created by Yar on 10/6/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYHumanObject_h
#define DYYHumanObject_h

#include <stdio.h>

typedef enum {
       DYYPersonGenderUndefined,
       DYYPersonGenderMale,
       DYYPersonGenderFemale,
} DYYPersonGender;

void DYYPersonWithNameAgeGenderCreate (char _personName, uint8_t _personAge, DYYPersonGender _personGender);

void DYYMarryPersonSet (void *_personPartner);

void DYYDivorsePersonSet (void *_personPartner);

#endif /* DYYHumanObject_h */

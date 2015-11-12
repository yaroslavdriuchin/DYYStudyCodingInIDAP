//
//  DYYTestHumanWithDynamicArray.c
//  DYYStudyCoding
//
//  Created by user on 11/11/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYTestHumanWithDynamicArray.h"


#include "DYYTestHumanWithStaticArray.h"
#include "DYYHuman.h"
#include "DYYString.h"
#include "DYYObject.h"
#include <assert.h>

void DYYTestHumanWithDynamicArrayCreate(void) {
//creating test object with initial parameters of Name, Age, Gender
    DYYPerson *testObject = DYYPersonCreateWithNameAgeGender("Antonio Banderas", 45, kDYYGenderMale);

//expected not NULL with object pointer and person name
    assert(NULL != testObject);
    assert(NULL != DYYPersonName(testObject));

//expected retain count as 1 and given age and gender to pass assert process
//    assert(1 == DYYObjectRetainCount(testObject));
    assert(45 == DYYPersonAge(testObject));
    assert(kDYYGenderMale == DYYPersonGender(testObject));

//expected zero values with partner and children count parameters
    assert(NULL == DYYPersonPartner(testObject));
    assert(0 == DYYPersonCurrentChildrenCount(testObject));

    DYYObjectRelease(testObject);
    printf("Test object was created, assert tests were passed\n");

}


void DYYTestHumanWithDynamicArray(void) {
//creating 2 test objects of different gender and parameters
    DYYPerson *testObjectMalvina = DYYPersonCreateWithNameAgeGender("Malvina Frankenstein", 16, kDYYGenderFemale);
    DYYPerson *testObjectVitalik = DYYPersonCreateWithNameAgeGender("Vitalik S Shulyavki", 24, kDYYGenderMale);
    
//creating new child of objects with different genders and checking record
    DYYPerson *testObjectBob = DYYPersonCreateChildOfFatherAndMother("Gubka Bob",
                                                                      1,
                                                                      kDYYGenderMale,
                                                                      testObjectVitalik,
                                                                      testObjectMalvina);
    
//checking children count of parent with new child, expected 1, checking retain count of new child, expected 2
    printf("Name of the child is %s\n", DYYPersonName(testObjectBob));

    assert(1 == DYYPersonCurrentChildrenCount(testObjectMalvina));
    printf("Assert test succeded, children count of parent is: %u\n", DYYPersonCurrentChildrenCount(testObjectMalvina));

}


//
//  DYYTestHumanObjectCreateMethod.c
//  DYYStudyCoding
//
//  Created by Yar on 10/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
//As a software developer I want to test the functionality of the Human Object with corresponding methods
//for setting Married and Divorce statuses and Creating New Child Method 
#include "DYYTestHumanObjectCreateMethod.h"
#include "DYYHumanObject.h"
#include <assert.h>

void DYYTestHumanObjectCreateMethod(void) {
//creating test object with initial parameters
    DYYPerson *testObject = DYYPersonCreateWithNameAgeGender("Antonio Banderas", 45, kDYYGenderMale);
//expected not NULL with object pointer and person name
    assert(NULL != testObject);
    assert(NULL != DYYPersonName(testObject));
//expected retain count as 1 and given age and gender to pass assert process
    assert(1 == DYYPersonRetainCount(testObject));
    assert(45 == DYYPersonAge(testObject));
    assert(kDYYGenderMale == DYYPersonGender(testObject));
//expected zero values with partner and children count parameters
    assert(NULL == DYYPersonPartner(testObject));
    assert(0 == DYYPersonCurrentChildrenCount(testObject));
}


void DYYTestHumanObjectMethod(void) {
//creating 3 test objects of different gender and parameters
    DYYPerson *testObjectRamzan = DYYPersonCreateWithNameAgeGender("Ramzan Abdurahmanov", 104, kDYYGenderMale);
    DYYPerson *testObjectMalvina = DYYPersonCreateWithNameAgeGender("Malvina Frankenstein", 16, kDYYGenderFemale);
    DYYPerson *testObjectVitalik = DYYPersonCreateWithNameAgeGender("Vitalik S Shulyavki", 24, kDYYGenderMale);
//marry 2 objects and checking method output of success and retain count of weak object
    bool resultMarry = DYYPersonSetMarried(testObjectRamzan, testObjectMalvina);
    printf("Result of marriage %d\n", resultMarry);
    printf("Retain count is %d\n", DYYPersonRetainCount(testObjectMalvina));
//trying to deallocate object 1, expected 0 output for attempt
    bool resultDealloc = __DYYPersonDeallocate(testObjectRamzan);
    printf("Result of deallocation try 1: %d\n", resultDealloc);
//divorcing object 1 with its current partner
    bool resultDivorce = DYYPersonSetDivorced(testObjectRamzan);
    printf("Result of divorce %d\n", resultDivorce);
    printf("Retain count %d\n", DYYPersonRetainCount(testObjectMalvina));

//creating new child of objects with different genders and checking record
    DYYPerson *testObjectBob = DYYPersonCreateChildOfFatherAndMother("Gubka Bob",
                                                                      1,
                                                                      kDYYGenderMale,
                                                                      testObjectVitalik,
                                                                      testObjectMalvina);
    char *gubkaName = DYYPersonName(testObjectBob);
    printf("Name of the child is %s\n", gubkaName);
    printf("Children count of parent is: %d\n", DYYPersonCurrentChildrenCount(testObjectVitalik));
    
}
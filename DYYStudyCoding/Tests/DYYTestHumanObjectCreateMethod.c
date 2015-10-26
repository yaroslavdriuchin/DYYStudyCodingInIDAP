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
    printf("Result of marriage %d\n", DYYPersonSetMarried(testObjectRamzan, testObjectMalvina));
    printf("Retain count is %d\n", DYYPersonRetainCount(testObjectMalvina));

//creating new child of objects with different genders and checking record
    DYYPerson *testObjectBob = DYYPersonCreateChildOfFatherAndMother("Gubka Bob",
                                                                      1,
                                                                      kDYYGenderMale,
                                                                      testObjectVitalik,
                                                                      testObjectMalvina);
    printf("Name of the child is %s\n", DYYPersonName(testObjectBob));
    printf("Children count of parent is: %d\n", DYYPersonCurrentChildrenCount(testObjectMalvina));
    
//Adding second child to mother array with different partner, children count expected to increase +1
    DYYPerson *testObjectBritney = DYYPersonCreateChildOfFatherAndMother("Britney Spears",
                                                                     1,
                                                                     kDYYGenderFemale,
                                                                     testObjectRamzan,
                                                                     testObjectMalvina);
    printf("Name of the child is %s\n", DYYPersonName(testObjectBritney));
    printf("Children count of parent is: %d\n", DYYPersonCurrentChildrenCount(testObjectMalvina));
    
//divorcing object 1 with its current partner, expected result of divorse = true = 1
    printf("Result of divorce %d\n", DYYPersonSetDivorced(testObjectRamzan));
    
//sending release message to object with RetainCount = 1, expected it to deallocate, checking it
//    DYYPersonRelease(testObjectRamzan);
    
//
}
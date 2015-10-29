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
#include "DYYStringObject.h"
#include "DYYObject.h"
#include <assert.h>

void DYYTestHumanObjectCreateMethod(void) {
//creating test object with initial parameters
    DYYPerson *testObject = DYYPersonCreateWithNameAgeGender("Antonio Banderas", 45, kDYYGenderMale);
//expected not NULL with object pointer and person name
    assert(NULL != testObject);
    assert(NULL != DYYPersonName(testObject));
//expected retain count as 1 and given age and gender to pass assert process
    assert(1 == DYYObjectRetainCount(testObject));
    assert(45 == DYYPersonAge(testObject));
    assert(kDYYGenderMale == DYYPersonGender(testObject));
//expected zero values with partner and children count parameters
    assert(NULL == DYYPersonPartner(testObject));
    assert(0 == DYYPersonCurrentChildrenCount(testObject));
    printf("Test object was created, assert tests were passed\n");
}


void DYYTestHumanObjectMethod(void) {
//creating 3 test objects of different gender and parameters
    DYYPerson *testObjectRamzan = DYYPersonCreateWithNameAgeGender("Ramzan Abdurahmanov", 104, kDYYGenderMale);
    DYYPerson *testObjectMalvina = DYYPersonCreateWithNameAgeGender("Malvina Frankenstein", 16, kDYYGenderFemale);
    DYYPerson *testObjectVitalik = DYYPersonCreateWithNameAgeGender("Vitalik S Shulyavki", 24, kDYYGenderMale);
    
//marry 2 objects and checking method output of success and retain count of weak object
    printf("Result of marriage %d\n", DYYPersonMarry(testObjectMalvina, testObjectRamzan));
    printf("Retain count of Bride is %u\n", DYYObjectRetainCount(testObjectMalvina));

//creating new child of objects with different genders and checking record
    DYYPerson *testObjectBob = DYYPersonCreateChildOfFatherAndMother("Gubka Bob",
                                                                      1,
                                                                      kDYYGenderMale,
                                                                      testObjectVitalik,
                                                                      testObjectMalvina);
    
//checking children count of parent with new child, expected 1, checking retain count of new child, expected 3
    printf("Name of the child is %s\n", DYYPersonName(testObjectBob));
    printf("Children count of parent is: %u\n", DYYPersonCurrentChildrenCount(testObjectMalvina));
    printf("Retain count of 1st child is %u\n", DYYObjectRetainCount(testObjectBob));
    
//Adding second child to mother array with different partner
    DYYPerson *testObjectBritney = DYYPersonCreateChildOfFatherAndMother("Britney Spears",
                                                                     1,
                                                                     kDYYGenderFemale,
                                                                     testObjectRamzan,
                                                                     testObjectMalvina);
    
//checking children count of parent with new child, expected 2, checking retain count of new child, expected 3
    printf("Name of the child is %s\n", DYYPersonName(testObjectBritney));
    printf("Children count of parent is: %u\n", DYYPersonCurrentChildrenCount(testObjectMalvina));
    printf("Retain count of 2nd child is %u\n", DYYObjectRetainCount(testObjectBritney));
    
//divorcing object 1 with its current partner, expected result of divorse = true = 1
    printf("Result of divorce %d\n", DYYPersonDivorce(testObjectRamzan));
    
//sending release message to object with RetainCount = 1, expected it to deallocate, checking it
    DYYObjectRelease(testObjectRamzan);
    printf("Force Release and Deallocation of created object was successful\n");
    
}
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

void DYYTestHumanObjectCreateMethod(void) {
//creating 3 test objects of different gender and parameters
    DYYPerson *testObjectRamzan = DYYPersonCreateWithNameAgeGender("Ramzan Abdurahmanov", 104, DYYGenderMale);
    DYYPerson *testObjectMalvina = DYYPersonCreateWithNameAgeGender("Malvina Frankenstein", 16, DYYGenderFemale);
    DYYPerson *testObjectVitalik = DYYPersonCreateWithNameAgeGender("Vitalik S Shulyavki", 24, DYYGenderMale);
//marry 2 objects and checking method output of success and retain count of weak object
    bool resultMarry = DYYPersonSetMarried(testObjectRamzan, testObjectMalvina);
    printf("Result of marriage %d\n", resultMarry);
    printf("Retain count is %d\n", testObjectMalvina->_retainCount);
//trying to deallocate object 1, expected 0 output for attempt
    bool resultDealloc = __DYYPersonDeallocate(testObjectRamzan);
    printf("Result of deallocation try 1: %d\n", resultDealloc);
//divorcing object 1 with its current partner
    bool resultDivorce = DYYPersonSetDivorced(testObjectRamzan);
    printf("Result of divorce %d\n", resultDivorce);
    printf("Retain count %d\n", testObjectMalvina->_retainCount);
//    bool resultDeallocTwo = __DYYPersonDeallocate(testObjectVitalik);
//    printf("Result of deallocation try 2: %d\n", resultDeallocTwo);
    
//creating new child of objects with different genders and checking record
    DYYPerson *testObjectBob = DYYPersonCreateChildOfFatherAndMother("Gubka Bob",
                                                                      1,
                                                                      DYYGenderMale,
                                                                      testObjectVitalik,
                                                                      testObjectMalvina);
    printf("%s\n", testObjectBob->_name);
}
//
//  DYYTestHumanObjectCreateMethod.c
//  DYYStudyCoding
//
//  Created by Yar on 10/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
//As a software developer I want to test the functionality of the DYYPersonCreateWithInitialParameters method with random input values

#include "DYYTestHumanObjectCreateMethod.h"
#include "DYYHumanObject.h"

void DYYTestHumanObjectCreateMethod(void) {
    char *testName = "Ramzan Abdurahmanov";
    uint8_t testAge = 103;
    DYYGender testGender = DYYGenderMale;
    DYYPerson *testCreatedObject = DYYPersonCreateWithNameAgeGender(testName, testAge, testGender);
//    printf("%s\n", testCreatedObject->_name);
//    printf("%d\n", testCreatedObject->_age);
//    if(testGender == testCreatedObject->_gender) printf("Male\n");
//           else printf("Female\n");
    char *testNameTwo = "Malvina Frankenstein";
    uint8_t testAgeTwo = 16;
    DYYGender testGenderTwo = DYYGenderFemale;
    DYYPerson *testCreatedObjectTwo = DYYPersonCreateWithNameAgeGender(testNameTwo, testAgeTwo, testGenderTwo);
    
    char *testNameThree = "Vitalik Kisliy";
    uint8_t testAgeThree = 24;
    DYYGender testGenderThree = DYYGenderMale;
    DYYPerson *testCreatedObjectThree = DYYPersonCreateWithNameAgeGender(testNameThree, testAgeThree, testGenderThree);
    bool resultMarry = DYYPersonSetMarried(testCreatedObjectTwo, testCreatedObject);
    printf("%d\n", resultMarry);
    printf("%d\n", testCreatedObjectTwo->_retainCount);
    bool resultDivorce = DYYPersonSetDivorced(testCreatedObjectTwo);
    printf("%d\n", resultMarry);
    printf("%d\n", testCreatedObjectTwo->_retainCount);
}
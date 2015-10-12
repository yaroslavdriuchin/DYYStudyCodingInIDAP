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
    unsigned int testAge = 103;
    DYYPersonGender testGender = DYYPersonGenderMale;
    DYYPersonData *testCreatedObject = DYYPersonCreateWithNameAgeGender(testName, testAge, testGender);
    printf("%s\n", testCreatedObject->_personName);
    printf("%d\n", testCreatedObject->_personAge);
//    printf("%\n", testCreatedObject->_personGender);
}
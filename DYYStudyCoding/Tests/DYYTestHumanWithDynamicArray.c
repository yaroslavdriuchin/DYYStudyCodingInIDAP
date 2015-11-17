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
//creating 3 test objects of different gender and parameters
    DYYPerson *testObjectRamzan = DYYPersonCreateWithNameAgeGender("Ramzan Abdurahmanov", 104, kDYYGenderMale);
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

//Adding second child to mother array with different partner
    DYYPerson *testObjectBritney = DYYPersonCreateChildOfFatherAndMother("Britney Spears",
                                                                     1,
                                                                     kDYYGenderFemale,
                                                                     testObjectRamzan,
                                                                     testObjectMalvina);

//checking children count of parent with new child, expected 2, checking retain count of new child, expected 3
    printf("Name of the child is %s\n", DYYPersonName(testObjectBritney));

    assert(2 == DYYPersonCurrentChildrenCount(testObjectMalvina));
    printf("Children count of parent is: %u\n", DYYPersonCurrentChildrenCount(testObjectMalvina));

    assert(3 == DYYObjectRetainCount(testObjectMalvina->_childrenArray));
    printf("Retain count of parent children array with 2nd child is %u\n", DYYObjectRetainCount(testObjectMalvina->_childrenArray));

//divorcing object 1 with its current partner, expected result of divorse = true = 1
    printf("Result of divorce %d\n", DYYPersonDivorce(testObjectRamzan));

//removing child of 2 objects, expecting result =1, checking children count of mother of two after deleting one, expecting = 1
    printf("Result of removing child of father and mother is %d \n", DYYPersonRemoveChildOfFatherAndMother(testObjectRamzan,
                                                                                                                   testObjectMalvina,
                                                                                                                   testObjectBritney));
    printf("Children count of parent after deleting 1 child is: %u\n", DYYPersonCurrentChildrenCount(testObjectMalvina));

//sending release message to object with RetainCount = 1, expected it to deallocate
    DYYObjectRelease(testObjectRamzan);
    printf("Force Release and Deallocation of created object was successful\n");
    
}


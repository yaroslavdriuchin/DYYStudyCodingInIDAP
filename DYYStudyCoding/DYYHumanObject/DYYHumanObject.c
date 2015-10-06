//
//  DYYHumanObject.c
//  DYYStudyCoding
//
//  Created by Yar on 10/6/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#include "DYYHumanObject.h"
#include <stdbool.h>

#pragma mark -
#pragma mark Private Declarations

typedef struct DYYPersonInformation {
        char *_personName;
        uint8_t _personAge;
        DYYPersonGender _personGender;
        uint8_t _personChildrenTotalCount;
        bool _personMarriedStatus;
        void *_personPartner;
        void *_personParent;
        void *_personChildrenList[20];
    } DYYPersonInformationStructure;

#pragma mark -
#pragma mark Private Implementations
void DYYPersonWithNameAgeGenderCreate(char _personName, uint8_t _personAge, DYYPersonGender _personGender) {

}
}
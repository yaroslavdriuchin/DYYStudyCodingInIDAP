//
//  DYYStringObject.h
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYStringObject_h
#define DYYStringObject_h

#include <stdio.h>
#include <stdlib.h>
#include "DYYObject.h"

typedef struct {
    DYYObject _super;
    char *_string;
} DYYString;

extern
void __DYYStringDeallocate(DYYString *stringObject);

extern
void *DYYStringCreateWithValue(DYYString *value);

extern
void DYYStringSetValue(DYYString *stringObject, DYYString *value);

extern
void *DYYStringValue(DYYString *stringObject);

#endif /* DYYStringObject_h */

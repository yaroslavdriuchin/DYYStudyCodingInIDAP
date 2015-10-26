//
//  DYYMacro.h
//  DYYStudyCoding
//
//  Created by user on 10/26/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYMacro_h
#define DYYMacro_h

#define DYYFreeAllocatedData(person, inputField) if (NULL != person->inputField) { \
free(person->inputField); \
person->inputField = NULL; \
}

#endif /* DYYMacro_h */

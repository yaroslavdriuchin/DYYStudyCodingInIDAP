//
//  DYYCheckNumbersAndReturnValue.h
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef __DYYStudyCoding__DYYCheckNumbersAndReturnValue__
#define __DYYStudyCoding__DYYCheckNumbersAndReturnValue__

//declaration of Parent data type with predefined values
typedef enum {
    kDYYParentTypeUndefined = 0,
    kDYYParentTypeMama,
    kDYYParentTypePapa,
    kDYYParentTypeMamaPapa
} DYYParentType;

extern DYYParentType DYYCheckNumbersAndReturnParentType(int);

#endif /* defined(__DYYStudyCoding__DYYCheckNumbersAndReturnValue__) */

//
//  DYYSizeOfCheck.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//


void SizeofCheckType(void)
{
    int a;
    char b;
    float c;
    unsigned long d;
    long double e;
    

    printf ("The lenght of Integer data type is %lu \n", sizeof(a));
    printf ("The lenght of Char data type is %lu \n", sizeof(b));
    printf ("The lenght of Float data type is %lu\n", sizeof(c));
    printf ("The lenght of Unsigned Long data type is %lu\n", sizeof(d));
    printf ("The lenght of Long Double data type is %lu\n", sizeof(e));

}
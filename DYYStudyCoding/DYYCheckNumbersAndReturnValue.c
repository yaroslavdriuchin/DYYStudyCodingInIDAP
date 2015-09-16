//
//  DYYCheckNumbersAndReturnValue.c
//  DYYStudyCoding
//
//  Created by Yar on 9/16/15.
//  Copyright (c) 2015 Yaroslav Driuchin. All rights reserved.
//

int DYYCheckNumbers(int InputNumber)
{
    
    int a =15;
    int b = 5;
    int c = 3;
    
    if ( InputNumber % a == 0 ) {
        printf("MAMAPAPA\n");
    return a;
    }
else
    if ( InputNumber % b == 0 ) {
    printf("PAPA\n");
    return b;
    }
else
    if ( InputNumber % c == 0 ) {
    printf("MAMA\n");
    return c;
    }
else
    return 0;
}
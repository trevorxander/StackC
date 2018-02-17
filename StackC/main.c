//
//  main.c
//  StackC
//
//  Created by Trevor Xander on 2/17/17.
//  
//

#include <stdio.h>
#include "StackC.h"

int main (){
    
    
    stackC test;
    StackNew( &test, sizeof(int));
    int testInput = 100;
    StackPush(&test, &testInput);
    
    int testResult = -1;
    StackPop(&test, &testResult);
    StackDispose(&test);
    
    
    printf("%d\n",testResult);
    
}


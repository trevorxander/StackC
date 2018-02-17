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
    
    int const TEST_SIZE = 15;
    stackC test;
    stackConstruct( &test, sizeof(int));
    
    for (int testInput = 1; testInput <= TEST_SIZE; testInput++){
        stackPush(&test, &testInput);
    }
   
    int testResult;
    for (int iterator = 0; iterator < TEST_SIZE; iterator++){
        stackPop(&test, &testResult);
        printf("%d\n",testResult);
    }
    
    stackDestruct(&test);
    
    return 0;
}


//
//  test.c
//  StackC
//
//  Created by Trevor Xander on 2/17/17.
//  
//

#include <stdio.h>
#include "StackC.h"



int main (){
    
    
    int const TEST_SIZE = 10000;
    
    
    //Test stack
    stackC test;
    
    //Constructs stack
    stackConstruct( &test, sizeof(int));
    
    //Pushing test elements into stack
    for (int testInput = 1; testInput <= TEST_SIZE; testInput++){
        stackPush(&test, &testInput);
    }
   
    int testResult;
    //Popping test elements from stack
    for (int iterator = 0; iterator < TEST_SIZE; iterator++){
        stackPop(&test, &testResult);
        printf("%d\n",testResult);
    }
    
    //Freeing memory
    stackDestruct(&test);
    
    return 0;
}


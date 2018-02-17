//
//  StackC.h
//  StackC
//
//  Created by Trevor Xander on 2/17/17.
//
//

#ifndef StackC_h
#define StackC_h

#include <stdbool.h>
#include <stdlib.h>
#include "assert.h"
#include <string.h>

typedef struct {
    void *elements;
    int elemSize;
    int realLength;
    int allocLength;
}stackC;


void stackConstruct (stackC *stackObj, int typeSize);
void stackDestruct (stackC *stackObj);
bool isStackEmpty (const stackC *stackObj);
void stackPush (stackC *stackObj, const void *elemAddr);
void stackPop (stackC *stackObj, void *elemAddr);


#endif /* StackC_h */

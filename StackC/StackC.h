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


void StackNew(stackC *s, int typeSize);
void StackDispose(stackC *s);
bool StackEmpty(const stackC *s);
void StackPush(stackC *s, const void *elemAddr);
void StackPop(stackC*s, void *elemAddr);


#endif /* StackC_h */

//
//  main.c
//  StackC
//
//  Created by Trevor Xander on 2/17/17.
//  
//


#include "StackC.h"

#define ALLOC_SIZE 4

void stackConstruct(stackC *s,int typeSize) {

    assert (typeSize > 0);
    s->elemSize = typeSize;
    s->realLength = 0;
    s->allocLength = ALLOC_SIZE;
    s->elements = malloc (ALLOC_SIZE * typeSize);
    assert(s->elements!= NULL);
}

void stackDestruct (stackC *stackObj) {
    free (stackObj->elements);
}

bool isStackEmpty (const stackC *stackObj) {
    return stackObj->realLength == 0;
}

void stackPush(stackC *stackObj, const void* elemAddr) {

    void *destAddr;
    if(stackObj->realLength == stackObj->allocLength){
        stackObj->allocLength = stackObj->allocLength * 2;
        
        void *newAlloc = malloc(stackObj->allocLength * stackObj->elemSize);
        memcpy(newAlloc, stackObj->elements, (stackObj->elemSize * stackObj->realLength) );
        free(stackObj->elements);
        stackObj->elements = newAlloc;
        assert(stackObj->elements!= NULL);
    }
    destAddr = (char *)stackObj->elements + (stackObj->realLength * stackObj->elemSize);
    memcpy (destAddr, elemAddr, stackObj->elemSize);
    stackObj->realLength++;
}

void stackPop(stackC *stackObj, void *elemAddr) {
    const void *sourceAddr;
    assert (!isStackEmpty(stackObj));
    stackObj->realLength--;
    sourceAddr = (const char *) stackObj->elements + stackObj->realLength * stackObj->elemSize;
    memcpy (elemAddr, sourceAddr, stackObj->elemSize);
    
}


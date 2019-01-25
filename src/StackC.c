//
//  StackC.c
//  StackC
//
//  Created by Trevor Xander on 2/17/17.
//  
//


#include "StackC.h"

#define ALLOC_SIZE 4


//Factor by which allocation size is increased
#define ALLOC_FACTOR 2

void stackConstruct(stackC *s,int typeSize) {

    assert (typeSize > 0);
    s->elemSize = typeSize;
    s->realLength = 0;
    s->allocLength = ALLOC_SIZE;
    
    //Allocates initial memory
    s->elements = malloc (ALLOC_SIZE * typeSize);
    assert(s->elements!= NULL);
}

void stackDestruct (stackC *stackObj) {
    free (stackObj->elements);
}


bool isStackEmpty (const stackC *stackObj) {
    return (stackObj->realLength == 0);
}

void stackPush(stackC *stackObj, const void* elemAddr) {
    
    //Reallocates memory if more memory is required
    if(stackObj->realLength == stackObj->allocLength){
        
        stackObj->allocLength = stackObj->allocLength * ALLOC_FACTOR;
        
        //Allocates new memory
        void *newAlloc = malloc(stackObj->allocLength * stackObj->elemSize);
        
        //Copy elements from old location to newly allocated space
        memcpy(newAlloc, stackObj->elements, (stackObj->elemSize * stackObj->realLength) );
        
        //Free old location
        free(stackObj->elements);
        
        stackObj->elements = newAlloc;
        assert(stackObj->elements!= NULL);
    }
    
    void *destAddr;
    //Computes address where new element needs to be stored
    destAddr = (char *)stackObj->elements + (stackObj->realLength * stackObj->elemSize);
    
    //Stores new element in stack
    memcpy (destAddr, elemAddr, stackObj->elemSize);
    stackObj->realLength++;
}

void stackPop(stackC *stackObj, void *elemAddr) {
    
    assert (!isStackEmpty(stackObj));
    stackObj->realLength--;
    
    const void *sourceAddr;
    //Computes address of last added element
    sourceAddr = (const char *) stackObj->elements + stackObj->realLength * stackObj->elemSize;
    
    memcpy (elemAddr, sourceAddr, stackObj->elemSize);
    
}


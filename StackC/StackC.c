//
//  main.c
//  StackC
//
//  Created by Trevor Xander on 2/17/17.
//  Copyright © 2018 Trevor Xander. All rights reserved.
//


#include "StackC.h"

#define kInitialAlocationSize 4

void StackNew(stackC *s,int typeSize) {

    assert (typeSize > 0);
    s->elemSize = typeSize;
    s->realLength = 0;
    s->allocLength = kInitialAlocationSize;
    s->elements = malloc (kInitialAlocationSize * typeSize);
    assert(s->elements!= NULL);
}

void StackDispose (stackC *s) {
    free (s->elements);
}

bool StackEmpty (const stackC *s) {
    return s->realLength == 0;
}

void StackPush(stackC *s, const void* elemAddr) {

    void *destAddr;
    if(s->realLength == s->allocLength){
        s->allocLength *= 2;
        s->elements = realloc(s->elements, s->realLength * s->elemSize);
        assert(s->elements!= NULL);
    }
    destAddr = (char *)s->elements + (s->realLength * s->elemSize);
    memcpy (destAddr, elemAddr, s->elemSize);
    s->realLength++;
}

void StackPop(stackC *s, void *elemAddr) {
    const void *sourceAddr;
    assert (!StackEmpty(s));
    s->realLength--;
    sourceAddr = (const char *) s->elements + s->realLength * s->elemSize;
    memcpy (elemAddr, sourceAddr, s->elemSize);
    
}


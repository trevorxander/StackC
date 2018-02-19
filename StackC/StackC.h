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


//
typedef struct {
    void *elements;
    int elemSize;
    int realLength;
    int allocLength;
}stackC;


/**
 *   Allocates initial memory for the stackC object
 *
 *   @param stackObj reference to an object of type stackC
 *   @param typeSize size of the element in the stack (in bytes)
 */
void stackConstruct (stackC *stackObj, int typeSize);


/**
 *   Free memory allocated for the elements in stackC
 *
 *   @param stackObj reference to an object of type stackC
 */
void stackDestruct (stackC *stackObj);


/**
 *   Returns true if stack is empty
 *
 *   @param stackObj reference to an object of type stackC
 */
bool isStackEmpty (const stackC *stackObj);


/**
 *   Pushes element into stack
 *
 *   @param stackObj reference to an object of type stackC
 *   @param elemAddr reference to element that needs to be pushed
 */
void stackPush (stackC *stackObj, const void *elemAddr);


/**
 *   Pops and returns element from stack
 *
 *   @param stackObj reference to an object of type stackC
 *   @param elemAddr reference to where element needs to returned (shifting ownership to client)
 */
void stackPop (stackC *stackObj, void *elemAddr);


#endif /* StackC_h */

//
//  Header.h
//  c_stack
//
//  Created by 小川 秀典 on 2015/04/21.
//  Copyright (c) 2015年 小川 秀典. All rights reserved.
//

#ifndef c_stack_Header_h
#define c_stack_Header_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char StackItem;

typedef struct StackNode {
    StackItem item;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    size_t count;
    StackNode *head;
} Stack;

Stack *stackCreate();
StackItem stackTop(Stack *stack);
StackItem stackPop(Stack *stack);
bool stackPush(Stack *stack, StackItem item);
bool stackIsEmpty(Stack *stack);
void printStack(Stack *stack);
size_t stackSize(Stack *stack);
void stackDestory(Stack *stack);
void stackClean(Stack *stack);

#endif

//
//  stack.c
//  c_stack
//
//  Created by 小川 秀典 on 2015/04/21.
//  Copyright (c) 2015年 小川 秀典. All rights reserved.
//

#include "stack.h"

Stack *stackCreate()
{
    Stack* stack = malloc(sizeof(Stack));
    
    if (!stack) {
        perror("stackCreate");
        return NULL;
    }
    
    stack->count = 0;
    stack->head = NULL;
    
    return stack;
}

StackItem stackTop(Stack *stack)
{
    if (!stack) {
        perror("stackTop: stack is null.");
        return 0;
    }
    if (!stack->head) {
        perror("stackTop: head of stack is null.");
        return 0;
    }
    return stack->head->item;
}

StackItem stackPop(Stack *stack)
{
    if (!stack) {
        return 0;
    }
    
    StackNode *head = stack->head;
    
    if (!head) {
        return 0;
    }
    
    StackItem item = head->item;
    stack->head = head->next;
    
    free(head);
    head = NULL;
    
    stack->count -= 1;
    return item;
    
}

bool stackPush(Stack *stack, StackItem item)
{
    StackNode *newHead = malloc(sizeof(StackNode));
    
    if (!newHead) {
        perror("stackPush");
        return false;
    }
    
    newHead->item = item;
    newHead->next = stack->head;
    stack->head = newHead;
    
    stack->count += 1;
    return true;
}

bool stackIsEmpty(Stack *stack)
{
    return stack->head == NULL ? true : false;
}

void printStack(Stack *stack)
{
    StackNode *stackNode = stack->head;
    
    while (stackNode) {
        printf("%c->", stackNode->item);
        stackNode = stackNode->next;
    }
    printf("\n");
}

size_t stackSize(Stack *stack)
{
    return stack->count;
}

void stackClean(Stack *stack)
{
    while (!stackIsEmpty(stack)) {
        stackPop(stack);
    }
}

void stackDestory(Stack *stack)
{
    stackClean(stack);
    free(stack);
    stack = NULL;
}

//
//  main.c
//  c_stack
//
//  Created by 小川 秀典 on 2015/04/21.
//  Copyright (c) 2015年 小川 秀典. All rights reserved.
//

#include "stack.h"

void testStack() {
    Stack *stack = stackCreate();
    stackPush(stack, 'a');
    printf("size %zd\n", stackSize(stack));
    stackPush(stack, 'b');
    printf("size %zd\n", stackSize(stack));
    stackPush(stack, 'c');
    printf("size %zd\n", stackSize(stack));
    printStack(stack);
    printf("top %c\n", stackTop(stack));
    printf("size %zd\n", stackSize(stack));
    printStack(stack);
    printf("pop %c\n", stackPop(stack));
    printf("size %zd\n", stackSize(stack));
    printStack(stack);
    stackDestory(stack);
}

int main(int argc, const char * argv[]) {
    testStack();
    return 0;
}

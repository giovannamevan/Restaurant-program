#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "structs.h"


Stack* createStack();
void destroyStack(struct stack *S);
bool emptyStack(struct stack *S);
bool fullStack(struct stack *S);
bool push(struct stack *S,char *X);
void pop(struct stack *S, char *X);

#endif
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


Stack * createStack()
{
  Stack *S;
  S = (Stack *) malloc(sizeof(Stack));
  S->top = -1;    
  return S;
}

void destroyStack(Stack *S)
{
    //(*S).top = -1
    S->top = -1;
}

bool emptyStack(Stack *S)
{
    if (S->top == -1) return true;
    else return false;
}

bool fullStack(Stack *S)
{
    if (S->top == (20 - 1)) return true;
    else return false;

    // 20 eh o total de elements (no caso, 10)
    // o top vai de -1 (empty) a 9 (cheia)
    // entao, eh cheia se top == 20 - 1
}

bool push(Stack *S, char *chocolate)
{
    bool worked;

    if (fullStack(S) == true) {
        worked = false;
        return worked;
    } else {
      S->top++;
      strcpy(S->elements[S->top], chocolate);      
        worked = true;
        return worked;
    }
}

void pop(Stack *S, char*chocolate)
{
    bool worked;
    if (emptyStack(S) == true) {
        return;
    } else {
        strcpy(chocolate, S->elements[S->top]);
        S->top--;
        worked = true;
        return;
    }

}


#ifndef QUEUE_H
#define QUEUE_H
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "structs.h"

Line *createLine();
void destroyLine(Line *L);
bool emptyLine(Line *L);
bool fullLine(Line *L);
bool queue(Line *L, Client newClient);
Client dequeue(Line *L);


#endif
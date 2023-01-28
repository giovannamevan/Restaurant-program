#include<stdlib.h>
#include<stdio.h>	
#include<stdbool.h>	
#include "structs.h"


Line *createLine()
{
	Line *L;
	
	L = (Line *) malloc(sizeof(Line));
	if (L != NULL) { 
		 true;
		L->numberOfElements = 0;
		L->first = 0;
		L->last = 0;
	} 
	
	return L;
}

void destroyLine(Line *L)
{
    if (L != NULL) free(L);
}

bool emptyLine(Line *L)
{
    if (L->numberOfElements == 0){
      return true;
      }
    else return false;
}

bool fullLine(Line *L)
{
    if (L->numberOfElements == 20) return true;
    else return false;
}

bool queue(Line *L, Client newClient)
{
	
	if (fullLine(L) == true) {
    return false;
	}
	
	L->clientLine[ L->last ] = newClient;
	L->numberOfElements = L->numberOfElements + 1;
	
	if (L->last == (20-1)) L->last = 0;
	else L->last = L->last + 1;
  return true;
	
}

Client dequeue(Line *L) 
{

	if (emptyLine(L) == true) {
    Client nullClient;
    nullClient.clientIndex = -1; //vai ser checado na main se o clientIndex é -1, se for o caso, manda uma mensagem dizendo que não tem mais clientes na fila.
    return nullClient;
	}
  Client clientToDequeue;
	clientToDequeue = L->clientLine[ L->first ];
	L->numberOfElements = L->numberOfElements - 1;

	if (L->first == (20 - 1)) L->first = 0;
	else L->first = L->first + 1;
  return clientToDequeue;
}
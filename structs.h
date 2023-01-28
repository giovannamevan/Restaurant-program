#ifndef STRUCTS_H
#define STRUCTS_H
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

/*-----------------------------structs--------------------------*/
struct menuItem {
    int itemId;
    char productName[20];
    float price;

}; typedef struct menuItem MenuItem;

struct menu{
    MenuItem fullMenu[15];
    int posToAddNewItem;
    int newItemId;

}; typedef struct menu Menu;

struct client {

    int clientIndex;
    char recivedChocolate[20];
    int quantityOfOrders;
    MenuItem orders[15]; //15 é o limite máximo, pode ser que ele tenha menos pedidos, pra isso tem a quantidade de pedidos dentro de cada cliente

}; typedef struct client Client;


struct line {
    Client clientLine[20];  
    int numberOfElements;
    int first;	 
    int last;		
}; typedef struct line Line;



struct stack {
    char elements[20][20]; //é necessário ser uma matriz porque cada chocolate tem um nome, que é um vetor de elementos, logo, em cada posição das 20 da pilha, tem um array de char
    int top;  
}; typedef struct stack Stack;



#endif
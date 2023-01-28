#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "structs.h"

/*-----------------------------functions--------------------------*/
// as funções dentro dessa delimitação são as que vão pegar e inserir coisas tanto na lista quanto na pilha, elas só vao printar os documentos dentro das estruturas TAD quando os documentos estiverem ao acesso delas, . As funções estão organizadas na ordem de: Funções que se referem ao cardápio, Funções que se referem aos clientes, Funções que se referem à pilha, Funções que se referem à fila

/*------------------funções do menu----------------*/

Menu* createMenu(Menu *menuPointer){
    menuPointer = malloc(sizeof(Menu));
    menuPointer->posToAddNewItem = 1;
    menuPointer->newItemId = 1;
    return menuPointer;
}
void printMenu(Menu *menuToPrint) {
    for (int i = 1; i < menuToPrint->posToAddNewItem; i++){
        printf("------------Produto %d--------------\n", i);
        printf("Id: %d\n", menuToPrint->fullMenu[i].itemId);
        printf("Nome: %s", menuToPrint->fullMenu[i].productName);  
        printf("Preco: %.2f\n", menuToPrint->fullMenu[i].price);  
        printf("------------------------------------\n");
    }
    return;
}
void addItemToTheMenu(Menu *menuToAdd){
    
    MenuItem newItemToTheMenu;
    printf("Insira o nome do novo item:\n");
    setbuf(stdin,NULL);
    fgets(newItemToTheMenu.productName,20,stdin);
    printf("Insira o preco do novo item:\n");
    scanf(" %f%*c", &newItemToTheMenu.price);
    newItemToTheMenu.itemId = menuToAdd->newItemId;
    menuToAdd->fullMenu[menuToAdd->posToAddNewItem].itemId = newItemToTheMenu.itemId;
    strcpy(menuToAdd->fullMenu[menuToAdd->posToAddNewItem].productName,newItemToTheMenu.productName); 
    menuToAdd->fullMenu[menuToAdd->posToAddNewItem].price = newItemToTheMenu.price;
    menuToAdd->posToAddNewItem++;
    menuToAdd->newItemId++;
    return;
}
/*------------------------------------------------------*/

/*----------------------funções dos clientes-------------------------*/

Client* createClient(int actualClientIndex){
  Client *client;
    actualClientIndex++;
    client = malloc(sizeof(Client));

    client->clientIndex = actualClientIndex;
    client->quantityOfOrders = 0;
    return client;
}

void ordersOf( Client *client){
    float amountToPay = 0;
for (int i = 1; i <= client->quantityOfOrders; i++){
    
    printf("Order[%d]: %s\n", i, client->orders[i].productName);
    printf("Price: %.2f\n\n", client->orders[i].price);
    amountToPay = client->orders[i].price + amountToPay;

    if (i == client->quantityOfOrders) {
    printf("Total: %.2f\n", amountToPay);
    }
  }
    printf("Bonus: %s\n", client->recivedChocolate);
    return;
}

void addOrderToClient(Menu menuOfTheDay,Client* clientToAdd) {
    int selectedItemId;
    printf("-----------------------Menu-------------------------\n");
    printMenu(&menuOfTheDay);
    printf("----------------------------------------------------\n");
    printf("Insira o Id do item escolhido pelo cliente\n");
    scanf("%d", &selectedItemId);
    while (selectedItemId < 0 || selectedItemId > menuOfTheDay.newItemId) {
      printf("Selecione um Id de item existente\n");
      scanf("%d", &selectedItemId);
  }
  for (int i = 0; i < menuOfTheDay.posToAddNewItem; i++) {
  
    if(menuOfTheDay.fullMenu[i].itemId == selectedItemId){
      clientToAdd->quantityOfOrders++;
      MenuItem rightItem = menuOfTheDay.fullMenu[i];
      clientToAdd->orders[clientToAdd->quantityOfOrders] = rightItem;
      printf(" quantidade de pedidos cliente = %d\n", clientToAdd->quantityOfOrders);

    }
  }
}
/*------------------------------------------------------*/

/*--------------------funções para pilha---------------------*/

void printStack (Stack *actualChocolateJar) {
  int chocolatePos = 0;
  for (int i = actualChocolateJar->top; i > -1; i--) { //fizemos o for dessa maneira para imprimir os chocolates na ordem na qual eles serão retirados da pilha 
    chocolatePos++; //para falar primeiro, segundo.. chocolate
    
    printf("--------%d° chocolate--------\n", chocolatePos );
    printf("%s", actualChocolateJar->elements[i]);
    printf("----------------------------\n");
  }
  return;
}

/*------------------------------------------------------*/

/*--------------------funções para fila---------------------*/

void printLine(Line *actualClientLine) {
  for (int i = 0; i < actualClientLine->numberOfElements; i++) {
    printf("-----Cliente %d-----\n", actualClientLine->clientLine[i].clientIndex-1);
    ordersOf(&actualClientLine->clientLine[i]);
    printf("--------------------\n");
  }
  return;
}




/*-----------------------------functions--------------------------*/



void cleanScreen() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  return;
}

int main()
{
  
/*essas variáveis tem que ser iniciadas sempre antes do início do programa, já que basicamente ele gira em torno delas*/
  
    Line *clientLine; //fila de clientes
  
    Stack *chocolateJar; //pilha de chocolates
  
    Menu *menuOfTheDay; //o menu do dia
    menuOfTheDay = createMenu(menuOfTheDay);
    chocolateJar = createStack();
    clientLine = createLine();
  
    int actualClientIndex = 0; //para saber qual o index do cliente que será atendido, no final da pra saber quantos clientes no dia foram atendidos
  
    int optionSelector = -1; //variável para fazer as funções no while
  
    bool worked; //booleano de checagem nas funções que utilizam a pilha e a fila
  
    char doesClientWantsAnotherOrder; //variável para o cliente pedir mais itens
  
    int clientsOfTheDay = 0; // quantidade de clientes atendidos no dia, também vai ser util para por de parametro no vetor que armazena todos eles
  
    Client allClientsAttended[50]; // todos os clientes atendidos no dia, fixado numa quantidade alta pois não é possivel ter certeza da quantidade final

    
while (optionSelector != 0 && clientsOfTheDay < 51) //esse while fica ativo até o usuário pressionar 0, assim o programa fica rodando, até o máximo de clientes que cabe na variável allClientsAttender, ou quando o usuário apertar 0
    {
        printf("0 = Fechar pelo Dia\n1 = Imprimir o Menu\n2 = Adicionar item ao Menu\n3 = Imprimir a Fila\n4 = Imprimir a pilha\n5 = Adicionar chocolate na pilha\n6 = Criar novo cliente\n7 = Atender Cliente\n8 = Limpar Tela\n\n");
        printf("\nInsira o numero para o comando desejado\n");
        scanf("%d", &optionSelector);
        char newChocolate[20];
        Client *newClient;
        switch (optionSelector){
        case 1: printMenu(menuOfTheDay); break; 
        case 2: addItemToTheMenu(menuOfTheDay); break;
        case 3: printLine(clientLine); break;
        case 4: printStack(chocolateJar); break;
        case 5: printf("Digite o nome do chocolate a ser inserido\n");
        setbuf(stdin,NULL);
        fgets(newChocolate,20,stdin);
        bool worked = push(chocolateJar,newChocolate);
          if(worked == 0) {
            printf("A pilha esta cheia, remova alguns chocolates e tente novamente\n\n");
            break;
            }
          printf("Chocolate inserido com sucesso\n\n");
        break;
        case 6:worked = fullLine(clientLine);
              if (worked == true) {
                printf("A fila esta cheia, atenda algum cliente primeiro\n");
                break;
              }
              if (menuOfTheDay->posToAddNewItem == 1){ //caso não tenha nenhum item no cardápio ainda
                printf("Antes de adicionar um cliente, cire um item no menu do dia\n");
                break;
                
              }
              actualClientIndex++;
              newClient = createClient(actualClientIndex);
              addOrderToClient(*menuOfTheDay, newClient);
              printf("Ele deseja outro pedido?, Y/N");
              scanf(" %c", &doesClientWantsAnotherOrder);
            while(doesClientWantsAnotherOrder == 'Y' && newClient->quantityOfOrders < 16 ) {
              addOrderToClient(*menuOfTheDay,newClient);
              printf("Ele deseja outro pedido?, Y/N\n"); 
              scanf(" %c", &doesClientWantsAnotherOrder);
              if(doesClientWantsAnotherOrder != 'Y' && doesClientWantsAnotherOrder != 'N' ) {
                printf("Insira um caracter valido, Y/N\n");
                scanf(" %c", &doesClientWantsAnotherOrder);
              }
            }
          worked = queue(clientLine,*newClient); //apos os pedidos, ele é enfileirado
          break;
          case 7: worked = emptyStack(chocolateJar);
          if (worked == true) {
            printf("A pilha de chocolates está vazia, adicione um antes de atender o cliente\n\n");
            break;
          }
          worked = emptyLine(clientLine);
          if (worked == true) {
            printf("Nao ha clientes para atender\n");
            break;
          }
          char newChocolate[20];
          pop(chocolateJar, newChocolate);
          Client dequeuedClient = dequeue(clientLine); 
          strcpy(dequeuedClient.recivedChocolate, newChocolate);
          allClientsAttended[clientsOfTheDay] = dequeuedClient;
          clientsOfTheDay++;
          break;
          case 8: cleanScreen();
        } //fim do switch 
    }

  for (int i = 0; i < clientsOfTheDay; i++) {
    ordersOf(&allClientsAttended[i]);
  }
  
  printf("Clientes atendidos no dia: %d\n", clientsOfTheDay);

  printf("Finalizou\n");
system("pause");
  
    return 0;
}
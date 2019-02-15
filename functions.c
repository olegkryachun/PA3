#include <stdio.h>
#include <stdlib.h>
#include "stuff.h"


struct node *init(){

//Initialize stack and queue sentinel nodes
  struct node *temp = malloc(sizeof(struct node));
  temp->data = 98662;
  temp->next = NULL;

  return temp;  //return memory address of sentinel node
}


void startStack(struct node *stack, struct node *queue){

  char userInput[10], input;
  int num, type = 1, validNum;

  displayInstruction();

  while(1==1){
    printf("> ");

    fgets(userInput,10,stdin);

    validNum = sscanf(userInput,"%d",&num);  //store input as number

    if(validNum == 1)
      push(type,num,stack,queue);    //If only a number is entered, send it to push function

    else{  //if the value input by user wasnt a number, check if it's valid character

      sscanf(userInput,"%c",&input);

    //If Q then free all nodes and exit program
      if(input == 'Q'){
        freeMem(stack,queue);
        break;
      }

      if(input == '?')
        displayInstruction();

      if(input == 'q'){  //change to queue mode and call print function
        printf("Queue Mode\n");
        type = 0;
        printList(type,stack,queue);
      }

      if(input == 's'){  //change to stack mode and call print fucntion
        printf("Stack Mode\n");
        type = 1;
        printList(type,stack,queue);
      }

      if(input == 'p'){ //call pop function if p is entered

        int check = pop(type,stack,queue);
        if(check == 0 && type ==1)
          printf("ERROR Stack is Empty\n");
        if(check == 0 && type == 0)
          printf("ERROR Queue is Empty\n");
      }

      if(isValid(input) == 0)  //if character is invalid, display instructions
        displayInstruction();
      }
   }
}



void displayInstruction(){
  printf("Usage:\n");
  printf("#     insert # into stack or queue\n");
  printf("s     select STACK mode and display stack\n");
  printf("q     select QUEUE mode and display queue\n");
  printf("p     remove top of stack/head of queue and display\n");
  printf("Q     Quit\n");
  printf("?     Display help\n");

}


int push(int type, int num, Node *stack, Node *queue){

//Stack mode
  if(type == 1){
    Node *temp = malloc(sizeof(Node));
    Node *second = stack->next;

    temp->data = num;  //assign number to new node
    stack->next = temp;  //point sentinel node to new node
    temp->next = second;  //point new node to previous first node
 }

//Queue mode
  if(type == 0){
    Node *temp = queue;

    while(temp->next != NULL) //find the list node in the list
      temp = temp->next;

    temp->next = malloc(sizeof(Node));  //last node point to new node
    temp->next->next = NULL;  //new node points to NULL
    temp->next->data = num;  //new node data assigned to number
  }
}


int pop(int type, Node *stack, Node *queue){

//Stack mode
  if(type == 1){

    if(stack->next == NULL)
      return 0;

    Node *temp = stack->next;  //temp is set equal to first node

    printf("> %d\n", stack->next->data);

    stack->next = stack->next->next;  //change the first node to second node
    free(temp);  //delete first node

    return 1;
   }

//Queue mode
  if(type == 0){

    if(queue->next == NULL)
      return 0;

   Node *temp = queue->next;  //temp is set equal to first node

   printf("> %d\n", queue->next->data);

   queue->next = queue->next->next;  //Change the first node to second node
   free(temp);  //free first node

   return 1;
  }

}

int isValid(char input){

//check if input by user is valid
  if(input == '?' || input == 's' || input == 'q' || input == 'p' || input == 'Q')
    return 1;
  return 0;
}


void printList(int type, Node *stack, Node *queue){


//Stack mode
  if(type == 1){

    Node *temp = stack->next;

    if(temp == NULL){  //if stack is empty
      printf("Stack is Empty\n");
      return;
    }

   printf("TOS--> ");

    while(temp != NULL){
      printf("%d ", temp->data);
      temp = temp->next;
    }

   printf("\n");

  }


//Queue mode
  if(type == 0){

    Node * temp = queue->next;

    if(temp == NULL){  //if queue is empty
      printf("Queue is Empty\n");
      return;
    }

    printf("Head--> ");

    while(temp != NULL){
      printf("%d ", temp->data);
      temp = temp->next;
    }

    printf(" <--TAIL\n");
  }
}


void freeMem(Node *stack, Node *queue){

  Node *temp2;
  Node *temp = stack->next;

//Go through stack and free every node after the sentinel
  while(temp != NULL){
    temp2 = temp;
    temp = temp->next;
    free(temp2);
  }

//free last and first node
  free(temp);
  free(stack);


  temp = queue->next;

//Go through queue and free every node after the sentinel
  while(temp != NULL){
    temp2 = temp;
    temp = temp->next;
    free(temp2);
  }

//free first and last node
  free(temp);
  free(queue);
}

/*
Creator: Oleg Kryachun
Date: 02/14/2019
Programming Assignment 3
CSE 222

Summary: This program implements a stack and queue with linked lists. The user can switch between stacks and queue,
they can push, pop, or print numbers from the stack and queue. At the end of the program the memory is freed and program exits.
*/


#include <stdio.h>
#include <stdlib.h>
#include "stuff.h"

int main(){

  struct node *stack, *queue;

//Initialize stack and queue
  queue = init();
  stack = init();

//Start the program
  startStack(stack,queue);


}

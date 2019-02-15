typedef struct node Node;

typedef struct node{
  int data;
  Node *next;
}Node;


Node *init();

void startStack(Node *, Node *);

void displayInstruction();

int push(int, int, Node *, Node *);

int pop(int, Node *, Node *);

int isValid(char);

void printList(int, Node *, Node *);

void freeMem(Node *, Node *);

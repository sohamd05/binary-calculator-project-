#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node* next;
} node;

typedef node* list;
typedef struct snode{
	list data;
	struct snode* next;
}snode;
//typedef node* list;

typedef struct stack{
    snode* top;
}stack;   

void initList(list *l);
node* createnode(int data);
void append(list *l,int data);
void push(list *l ,int data);
void createLL(list *l,long number);
void display(list l);
int reverse(list *l);
long listToNumber(list *l);
void assignTheValueToNullList(list l1 , list *l2);
int countList(list l);
int compareList(list, list);
void push_sign(list *l ,char sign);
list subtractList(list *l1,list *l2);
list addList(list *l1 , list *l2);
list multiplyList(list l1,list l2);
list divideList(list *l1 ,list *l2);
list mod(list l1 ,list l2);

void init_stack(stack *s);
int isEmpty(stack s);
void push_stack(stack *s, list data);
list pop_stack(stack *s);
void display_stack(stack s);
list peek(stack s);


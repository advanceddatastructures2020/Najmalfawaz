#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
#define capacity 1000
struct stack
{
int data;
struct stack *next;
} *top;
int size=0;
void push(int element);
int pop();

void main()
{
int choice, data;
while(1)
{
printf("---------------------\n");
printf("    STACK IMPLEMENTATION PROGRAM     \n");
printf("---------------------\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Size\n");
printf("4. Exit\n");
printf("---------------------\n");
printf("enter your choice:");

scanf("%d", &choice);
switch(choice)
{
case 1:
printf("enter data to push into stack:");
scanf("%d", &data);

push(data);
break;
case 2:
data = pop();
if(data!= INT_MIN)
printf("Data=>%d\n", data);
break;
case 3:
printf("Stack size: %d\n", size);
break;
case 4:
printf("exiting from app.\n");
exit(0);
break;
default:
printf("invalid choice, please try again.\n");
}
printf("\n\n");
}
getch();
}
void push(int element)
{
struct stack * newNode=(struct stack *)malloc(sizeof(struct stack));
if(size >= capacity)
{
printf("stack overflow, cant add more element to stack.\n");
return;
}

newNode->data = element;
newNode->next = top;
top = newNode;
size++;
printf("data pushed to stack.\n");
}
int pop()
{
int data = 0;
struct stack * topnode;

if(size<=0 || !top)
{
printf("stack is empty.\n");
return INT_MIN;
}

	  topnode=top;
	  data = top->data;
	  top = top->next;
	  free(topnode);
	  size--;
	  return data;
	  }




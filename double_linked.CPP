#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
struct node *next;
int data;
};
struct node *head;
void insertion_begining();
void insertion_last();
void insertion_specified();
void display();
void search();
void main()
{
int choice=0;
clrscr();
while(choice!=6)
{
printf("\n**********Main Menu*******\n");
printf("n choose one option from the following list..\n");
printf("\n==================\n");
printf("\n1.insert in begining\n2.insert at last\n3.insert at any random location\n4.search\n5.show\n6.exit\n");
printf("enter your choice :\n");
scanf("\n%d",&choice);
switch(choice)
{
case 1:
insertion_begining();
break;
case 2:
insertion_last();
break;
case 3:
insertion_specified();
break;
case 4:
search();
break;
case 5:
display();
break;
case 6:
exit(0);
break;
defualt:
printf("please enter valid choice:");
}
}
getch();
}
void insertion_begining()
{
struct node *ptr;
int item;
ptr = (struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("\n Enter item value:");
scanf("%d",&item);

if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
ptr->data=item;
ptr->prev=NULL;
ptr->next=head;
head->prev=ptr;
head=ptr;
}
printf("\nNode inserted\n");
}
}
void insertion_last()
{
struct node *ptr,*temp;
int item;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("\nEnter value");
scanf("%d",&item);
ptr->data=item;
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
head = ptr;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->prev=temp;
ptr->next=NULL;
}
}
printf("\n node inserted\n");
}
void insertion_specified()
{
struct node *ptr,*temp;
int item,loc,i;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOVERFLOW");
}
else
{
temp=head;
printf("Enter the location");
scanf("%d",&loc);
for(i=0;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("\n There are less than %d elements",loc);
return;
}
}
printf("Enter value");
scanf("%d",&item);
ptr->data=item;
ptr->next=temp->next;
ptr->prev=temp;
ptr->next=ptr;
ptr->next->prev=ptr;
printf("\n node inserted\n");
}
}
void display()
{
struct node *ptr;
printf("\n printing values...\n");
ptr=head;
while(ptr !=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr=head;
if(ptr==NULL)
{
printf("\n Empty List\n");
}
else
{
printf("\n Enter the element you want to search:\n");
scanf("%d",&item);
while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("\n item found at location %d",i++);
flag=0;
break;
}
else
{
flag=1;
}
i++;
ptr=ptr->next;
}
if(flag==1)
{
printf("\n item not found\n");
}
}
}



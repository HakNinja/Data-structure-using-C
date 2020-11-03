
#include<stdio.h>
#include<stdlib.h>
#define max 5
void add(int);
void del();
void display();
void quit();
typedef struct queue
	{
	int data;
	struct node*next;
	}node;	
node*front=NULL;
node*rear=NULL;
int main()
{
int item;
char choice;
while(1)
{printf("\n___________________________\n");
printf("\t\tMENU:");
printf("\nPress i,ADD");	
printf("\nPress d,DELETE");
printf("\nPress o,DISPLAY");	
printf("\nPress q,QUIT\n");
printf("\nInput our choice:");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{case 'i':
case 'I':printf("enter number to be added=");
scanf("%d",&item);
      add(item);
printf("\n\t-------VALUE IS INSERTED-------\n");
break;
case 'd':
case 'D':del();
break;
case 'o':
case 'O':display();
break;
case 'q':
case 'Q':quit();
default:printf("Invalid input!!!"); 	
}
}
return 0;
}
void add(int item)
{	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=item;
	if(front==NULL)
	{
		front=rear=temp;
		temp->next=NULL;
	}
	else
	{
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
}
void del()
{node*temp;
    if(front==NULL)
    {
    	printf("\n\tQueue is empty\n");
    	return;
	}
	temp=front;
	if(front->next==NULL)
	{
		front=rear=NULL;
	}
	else
	{
	front=front->next;
		}
		free (temp);
	}
void display()
{
	node *q;
   if(front==NULL)
   {
   	printf("\n\tQueue is empty\n");
    	return;
   }
   q=front;
   while(q!=NULL)
   {
   	printf("\t%d",q->data);
   	q=q->next;
   }
}
void quit()
{char d;
printf("\nYou really want to exit[y]:");
fflush(stdin);
scanf("%c",&d);
if(d=='y')
exit(0);
}



#include<stdio.h>
#include<stdlib.h>
void addf(int);
void delf();
void addr(int);
void delr();
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
printf("\nPress a,ADDITION FROM REAR");
printf("\nPress b,ADDITION FROM FRONT");
printf("\nPress c,DELETE FROM REAR");	
printf("\nPress d,DELETE FROM FRONT");
printf("\nPress o,DISPLAY");	
printf("\nPress q,QUIT\n");
printf("\nInput our choice:");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{case 'a':
case 'A':printf("enter number to be added=");
scanf("%d",&item);
      addr(item);
printf("\n\t-------VALUE IS INSERTED-------\n");
break;
case 'b':
case 'B':printf("enter number to be added=");
scanf("%d",&item);
      addf(item);
printf("\n\t-------VALUE IS INSERTED-------\n");
break;
case 'c':
case 'C':delr();
break;
case 'd':
case 'D':delf();
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
void addr(int item)
{	node*temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=item;
	if(front==NULL)
	{
		front=rear=temp;
		temp->next=temp;
	}
	else
	{
		rear->next=temp;
		temp->next=front;
		rear=temp;
	}
}

void addf(int item)
{	node*temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=item;
	if(front==NULL)
	{
		front=rear=temp;
		temp->next=front;
	}
	else
	{
		rear->next=temp;
		temp->next=front;
		front=temp;
	}
}


void delf()
{node*temp;
    if(front==NULL)
    {
    	printf("queue is empty");
    	return;
	}
	temp=front;
	if(front->next==front)
	{
		front=rear=NULL;
	}
	else
	{
	front=front->next;
			rear->next=front;
		}
		free (temp);
	}
	
	void delr()
{node*temp,*r,*q;
    if(front==NULL)
    {
    	printf("queue is empty");
    	return;
	}
	temp=rear;
	if(rear->next==rear)
	{
		front=rear=NULL;
	}
	else
	{
	r=front;
	q=front->next;
	do
	{
	r=q;
	q=q->next;
	}while(r->next!=rear);
	r->next=front;
	rear=r;
	}
	free (temp);
	}
void display()
{
	node *q;
   if(front==NULL)
   {
   	printf("queue is empty");
    	return;
   }
   q=front;
   do
   {
   	printf("\t%d",q->data);
   	q=q->next;
   }while(q!=front);
}
void quit()
{char d;
printf("\nYou really want to exit[y]:");
fflush(stdin);
scanf("%c",&d);
if(d=='y')
exit(0);
}


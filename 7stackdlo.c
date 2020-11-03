
#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
void quit();
struct node
{
int data;
struct node *link;	
};
struct node *top=NULL;
int main()
{int item;
char c;
while(1)
{printf("\n____________________________________________\n");
printf("\t\tMENU:");
printf("\nPress i,push");	
printf("\nPress a,pop");
printf("\nPress o,OUTPUT");
printf("\nPress q,QUIT\n");
printf("\nInput:");
fflush(stdin);
scanf("%c",&c);
switch(c)
{case 'i':
case 'I':
printf("Enter element to add:");
scanf("%d",&item);
push(item);
break;
case 'o':
case 'O':display();
break;
case 'a':
case 'A':
pop();
break;
case 'q':
case 'Q':quit();
default:printf("Invalid input!!!"); 	
}
}
}
void push(int item)
{struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Memory is not allocated");
return;
}
temp->data=item;
if(top==NULL)
{
temp->link=NULL;
top=temp;	
}
else
{
temp->link=top;
top=temp;
}
}
void pop()
{struct node*temp;
if(top==NULL)
{printf("UNDERFLOW");
return;
}
temp=top;
top=top->link;
printf("%d is deleted",*temp);
free(temp);
}
void display()
{struct node *q;
if(top==NULL)
{
printf("STACK IS EMPTY");
return;
}
else
{
	q=top;
	while(q!=NULL)
	{
	printf("\t%d",q->data);
	q=q->link;
    }
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


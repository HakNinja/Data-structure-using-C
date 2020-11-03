
#include<stdio.h>
#include<stdlib.h>
void addbeg(int);
void display();
void addend(int);
void delbeg();
void delend();
void quit();
struct node
{struct node *next;
int data;
};
struct node *last=NULL;
int main()
{int item,pos;
char c;
while(1)
{printf("\n__________________________________\n");
printf("\t\tMENU:");
printf("\nPress a,ADD AT Start");
printf("\nPress b,ADD AT End");
printf("\nPress s,DELETE FROM START");
printf("\nPress e,DELETE FROM END");
printf("\nPress o,DISPLAY");
printf("\nPress q,QUIT\n");
printf("\nInput:");
fflush(stdin);
scanf("%c",&c);
switch(c)
{case 'a':
case 'A':
printf("Enter element to add:");
scanf("%d",&item);
addbeg(item);
break;
case 'b':
case 'B':
printf("Enter element to add:");
scanf("%d",&item);
addend(item);
break;
case 's':
case 'S':
delbeg();
break;
case 'e':
case 'E':
delend();
break;
case 'O':
case 'o':
printf("OUTPUT=\n\t");
display();
break;
case 'q':
case 'Q':quit();
default:printf("Invalid input!!!");
}
}
return 0;
}
void addbeg(int item)
{struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Memory is not allocated");
return;
}
temp->data=item;
if(last==NULL)
{
temp->next=temp;
last=temp;
}
else
{
temp->next=last->next;
last->next=temp;
}
}

void addend(int item)
{struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Memory is not allocated");
return;
}
temp->data=item;
if(last==NULL)
{temp->next=temp;
last=temp;
}
else{
temp->next=last->next;
last->next=temp;
last=temp;
}
}

void delbeg()
{struct node*temp;
if(last==NULL)
{printf("  EMPTY\tEMPTY\tEMPTY");
return;
}
temp=last;
if (last->next==last)
{
last=NULL;
}
else
{
temp=last->next;
last->next=(last->next)->next;
}
free(temp);
}

void delend()
{struct node*temp,*q,*Q;
if(last==NULL)
{printf("  EMPTY\tEMPTY\tEMPTY");
return;
}
if(last->next==last)
{
temp=last;
last=NULL;
}
else
{
Q=q=last->next;
do
{
q=q->next;
} while (q->next!=last);
temp=last;
q->next=Q;
last=q;
}
free(temp);
}

void display()
{struct node *q;
if(last==NULL)
{
printf("LINKED LIST IS EMPTY");
return;
}
	q=last->next;
	do
  {
    printf("%d\t",q->data);
    q=q->next;
  } while (q!=last->next);
}
void quit()
{char d;
printf("\nYou really want to exit[y]:");
fflush(stdin);
scanf("%c",&d);
if(d=='y')
exit(0);
}


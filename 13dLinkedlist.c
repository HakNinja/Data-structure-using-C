#include<stdio.h>
#include<stdlib.h>
void addbeg(int);
void displaybeg();
void displayend();
void addend(int);
void addpos(int,int);
void delbeg();
void delend();
void delpos(int);
void delitem(int);
void quit();
struct node
{struct node *prev;	
int data;
struct node *next;	
};
struct node *start=NULL;
int main()
{int item,pos;
char c;
while(1)
{printf("\n__________________________________\n");
printf("\t\tMENU:");
printf("\nPress a,ADD AT Start");	
printf("\nPress b,ADD AT End");
printf("\nPress m,ADD AT any position");
printf("\nPress s,DELETE FROM START");
printf("\nPress e,DELETE FROM END");
printf("\nPress d,DELETE any position");
printf("\nPress f,DELETE any element");
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
case 'm':
case 'M':
printf("Enter element to add:");
scanf("%d",&item);
printf("Enter position to add:");
scanf("%d",&pos);
addpos(item,pos);
break;
case 's':
case 'S':
delbeg();
break;
case 'e':
case 'E':
delend();
break;
case 'D':
case 'd':
printf("Enter any position to delete");
scanf("%d",&pos);
delpos(pos);
break;
case 'f':
case 'F':
printf("Enter any element to delete");
scanf("%d",&item);
delitem(item);
break;
case 'O':
case 'o':
printf("OUTPUT=\n\t");
displaybeg();
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
if(start==NULL)
{temp->prev=NULL;
temp->next=NULL;
start=temp;	
}
else
{temp->prev=NULL;
temp->next=start;
start=temp;
}
}
void addend(int item)
{struct node *temp,*q;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Memory is not allocated");
return;
}
temp->data=item;
temp->next=NULL;
if(start==NULL)
{temp->prev=NULL;
start=temp;	
}
else
{q=start;
while(q->next!=NULL)
{
q=q->next;
}
temp->prev=q->prev;
q->next=temp;
}
}
void addpos(int item,int pos)
{int i;
struct node *temp,*q;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Memory is not allocated");
return;
}
temp->data=item;
if(pos==1)
{
addbeg(item);
return ;
}
q=start;
for (i=1;i<=pos-2;i++)
{
	q=q->next;
}
temp->prev=
temp->next=q->next;
q->next=temp;
}
void delbeg()
{struct node*temp;
if(start==NULL)
{printf("  EMPTY\tEMPTY\tEMPTY");
return;
}
temp=start;
start=start->next;
free(temp);
}
void delend()
{struct node*temp,*q,*r;
if(start==NULL)
{printf("  EMPTY\tEMPTY\tEMPTY");
return;
}
temp=start;
q=start->next;
while(q->next!=NULL)
{temp=q;
q=q->next;
}
r=q;
temp->next=NULL;
free(r);
}
void delpos(int pos)
{int i;
struct node*temp,*q1,*q2;
if(start==NULL)
{printf("  EMPTY\tEMPTY\tEMPTY");
return;
}
if (pos==1)
{
	delbeg(pos);
	return;
}
q1=start;
q2=start->next;
for (i=1;i<=pos-2;i++)
{   q1=q2;
	q2=q2->next;
}
if(q2==NULL)
{
	delend();
	return;
}
temp=q2;
q1->next=q2->next;
free(temp);
}
void delitem(int item)
{int i;
struct node*temp,*q,*r;
if(start==NULL)
{printf("  EMPTY\tEMPTY\tEMPTY");
return;
}
if (item==start->data)
{
q=start;
start=start->next;
free(q);
return;
}
q=start;
r=start->next;
while(r!=NULL)
 {
 if (r->data==item)
       {
		  break;
	}
	q=r;
	r=r->next;
}
if(r==NULL)
{printf ("\n\tElement not find!\n");
return;
}
if(r->next==NULL)
{q->next=NULL;
}
else
{
q->next=r->next;
}
free(r);
}
void displaybeg()
{struct node *q;
if(start==NULL)
{
printf("LINKED LIST IS EMPTY");
return;
}
else
{
	q=start;
	while(q!=NULL)
	{
	printf("\t%d",q->data);
	q=q->next;
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


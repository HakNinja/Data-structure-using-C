
#include<stdio.h>
#include<stdlib.h>
#define max 5
void addf(int*,int*,int*,int);
void delr(int*,int*,int*);
void add(int*,int*,int*,int);
void del(int*,int*,int*);
void output(int*,int,int);
void quit();
int main()
{
int queue[max],item;
int front=-1,rear=-1;
char c;
while(1)
{printf("\n____________________________________________\n");
printf("\t\tMENU:");
printf("\nPress i,ADD from front");	
printf("\nPress a,DEL from rear");
printf("\nPress j,ADD from rear");	
printf("\nPress k,DEL from front");
printf("\nPress o,OUTPUT");
printf("\nPress q,QUIT\n");
printf("\nInput:");
fflush(stdin);
scanf("%c",&c);
switch(c)
{case 'i':
case 'I':
printf("Enter Element to be add:");
scanf("%d",&item);	
addf(queue,&front,&rear,item);
break;
case 'o':
case 'O':output(queue,front,rear);
break;
case 'a':
case 'A':
delr(queue,&front,&rear);
break;
case 'K':
case 'k':
del(queue,&front,&rear);
break;
case 'J':
case 'j':
printf("Enter Element to be add:");
scanf("%d",&item);	
add(queue,&front,&rear,item);
break;
case 'q':
case 'Q':
quit();
break;
default:printf("Invalid input!!!"); 	
}
}
return 0;
}
void addf(int *q,int *f,int *r,int item)
{
if((*f==0&&*r==max-1)||(*f==*r+1))
{
printf("\n\tQueue is full\n");
return; 
}
if(*f==-1)
*f=*r=0;
else if(*f==0)
*f=max-1;
else
*f=*f-1;
q[*f]=item;
}
void delr(int *q,int *f,int *r)
{int item;
if(*f==-1)
{
printf("\n\tQueue is empty\n");
return;
}
item=q[*r];
if(*f==*r)
*f=*r=-1;
else if(*r==0)
*r=max-1;
else
(*r)--;
printf("\n%d is deleted",item);
}
void add(int *q,int *f,int *r,int item)
{int i;
if(*r==max-1)
{
printf("\n\tQueue is full\n");
return; 
}
if(*f==-1)
*f=*r=0;
else
*r=*r+1;
q[*r]=item;
}
void del(int *q,int *f,int *r)
{int i,item;
if(*f==-1)
{
printf("\n\tQueue is empty\n");
return;
}
item=q[*f];
if(*f==*r)
*f=*r=-1;
else
(*f)++;
printf("\n%d is deleted",item);
}

void output(int *q,int f,int r)
{int i;
if(f==-1)
printf("\n\t-------QUEUE IS EMPTY------\n");
if (f<=r)
{
for(i=f;i<=r;i++)
printf("\t%d",q[i]);
}
else if(f>r)
{
for(i=f;i<=max-1;i++)
printf("\t%d",q[i]);
for(i=0;i<=r;i++)
printf("\t%d",q[i]);
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


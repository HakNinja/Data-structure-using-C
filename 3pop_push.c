

#include<stdio.h>
#include<stdlib.h>
#define max 5
int push(int*,int,int);
int pop (int*,int);
void output(int*,int);
void quit();
int main()
{
int stack[max],item;
int top=-1;
char c;
while(1)
{printf("_______________________________\n");
printf("\t\tMENU:");
printf("\nPress i,PUSH");	
printf("\nPress a,POP");
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
top=push(stack,top,item);
break;
case 'o':
case 'O':output(stack,top);
break;
case 'a':
case 'A':
top=pop(stack,top);
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
int push(int *stack,int top,int item)
{int i;
if(top==max-1)
printf("OVERFLOW\n");
else
{
top=top+1;
stack[top]=item;
}
return top;
}
int pop(int *stack,int top)
{int i,item;
item=stack[top];
if(top==-1)
printf("UNDERFLOW\n");
else
{
item=stack[top];
top=top-1;
}
return top;
}
void output(int *stack,int top)
{int i;
if(top==-1)
printf("-------STACK IS EMPTY------\n");
else
{
for(i=0;i<=top;i++)
{
printf("\t%d",stack[i]);
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


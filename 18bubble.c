
#include<stdio.h>
#include<stdlib.h>
#define max 40
void input(int *,int);
void output(int *,int);
void sort(int*,int);
int main()
{int n,arr[max],s;
char c;
printf("Enter array size:");
scanf("%d",&n);
while(1)
{printf("_______________________________________\n");
printf("\n\t\tMENU:");
printf("\nPress i,INPUT");	
printf("\nPress o,OUTPUT");
printf("\nPress a,sort");	
printf("\nPress q,QUIT\n");
printf("\nInput:");
fflush(stdin);
scanf("%c",&c);
switch(c)
{case 'i':
case 'I':input(arr,n);
break;
case 'o':
case 'O':output(arr,n);
break;
case 'a':
case 'A':sort(arr,n);
break;	
case 'q':
case 'Q':
exit(0);
default:printf("Invalid input!!!"); 	
}
printf("---------------------------------------\n");
}
return 0;
}
void input(int *ar,int n)
{int i;
printf("\nEnter %d array element:",n);
for (i=0;i<n;i++)
{scanf("%d",ar+i);
}
}
void output(int *p,int n)
{int i;
printf("%d array element:",n);
printf("\n");
for (i=0;i<n;i++)
{printf("%d\t",*(p+i));
}
printf("\n");
}
void sort(int*ar,int n)
{int i,j,temp;
for(i=1;i<n;i++)
{
for(j=0;j<n-i;j++)
{ if (ar[j]>ar[j+1])
	{temp=ar[j];
	ar[j]=ar[j+1];
	ar[j+1]=temp;
	}
	}
}
}


#include<stdio.h>
#include<stdlib.h>
#define max 40
void input(int *,int);
void output(int *,int);
int search(int*,int,int,int*);
int main()
{int n,arr[max],s,k=0;
char c;
printf("Enter array size:");
scanf("%d",&n);
while(1)
{printf("_______________________________________\n");
printf("\n\t\tMENU:");
printf("\nPress i,INPUT");
printf("\nPress o,OUTPUT");
printf("\nPress s,search");
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
case 's':
case 'S':
printf("Enter element to be search:");
scanf("%d",&s);
s=search(arr,n,s,&k);
if(k==0)
printf("The number is not found.\n");
else
printf("The number is found at position %d\n",s+1);
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

int search(int*a,int n,int m,int *k)
{
int l,u,mid;
l=0,u=n-1;
    while(l<=u)
		{
         mid=(l+u)/2;
         if(m==a[mid])
			{
             *k=1;
             break;
         }
         else if(m<a[mid])
			{
             u=mid-1;
         }
         else
             l=mid+1;
    }
	return mid;
}


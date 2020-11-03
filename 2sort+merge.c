
#include<stdio.h>
#include<stdlib.h>
#define max 100
void input(int *,int*,int ,int);
void merge(int *,int*,int*,int,int);
void sort(int *,int);
void output(int *,int);
int main()
{int n,m,l,arr1[max],arr2[max],arr3[2*max];
char c;
printf("Enter array1 size:");
scanf("%d",&n);
printf("Enter array2 size:");
scanf("%d",&m);
while(1)
{printf("___________________________\n");
printf("\t\tMENU:");
printf("\nPress i,Enter array");	
printf("\nPress m,merge_sort");
printf("\nPress o,OUTPUT");	
printf("\nPress q,QUIT\n");
printf("\nInput:");
fflush(stdin);
scanf("%c",&c);
switch(c)
{case 'i':
case 'I':
input(arr1,arr2,n,m);
printf("-------ALL VALUE ARE ENTERED--------\n");
break;
case 'm':
case 'M':
sort(arr1,n);
sort(arr2,m);
printf("-------ARRAY IS SORTED--------\n");
merge(arr1,arr2,arr3,n,m);
break;
case 'o':
case 'O':
l=m+n;
output(arr3,l);
break;
case 'q':
case 'Q':exit(0);
default:printf("Invalid input!!!"); 	
}
}
return 0;
}
void input(int *ar,int *arr,int n,int m)
{int i;
printf("\nEnter %d array element:",n);
for (i=0;i<n;i++)
{scanf("%d",ar+i);
}
printf("\nEnter %d array element:",m);
for (i=0;i<m;i++)
{scanf("%d",arr+i);
}
}
void sort(int *a,int n)
{int i,j,temp;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{if(a[i]>a[j])
{temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
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
void merge(int *a,int*b,int*c,int n,int m)
{int i=0,j=0,k=0;
while(i<n&&j<m)
{
if(a[i]>b[j])
{c[k]=b[j];
j++;
k++;	
}
else if(a[i]<b[j])
{c[k]=a[i];
i++;
k++;	
}
else if(a[i]==b[j])
{
c[k++]=a[i++];
c[k++]=b[j++];	
}
} 
if(i==n)
{
while(j<m)	
{c[k]=b[j];
j++;
k++;
}
}
else if(j==m)
{
while(i<n)
{
c[k]=a[i];
i++;
k++;
}
}
}


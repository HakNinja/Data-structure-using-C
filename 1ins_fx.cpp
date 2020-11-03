
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void input_array(int*,int);
void output_array(int*,int);
int insert_array(int*,int,int,int);
int delete_array(int*,int,int);
void quit();
int main()
{
	int array[MAX],n,pos,item;
	char choice;
	printf("\nENTER SIZE OF ARRAY:");
	scanf("%d",&n);
	hello:
		fflush(stdin);
		printf("\nInput:-i");
		printf("\nDisplay:-d");
		printf("\nInsert an element:-s");
		printf("\nWant to quit:-y");
		printf("\nEnter your choice:");
		choice=getchar();
		switch(choice)
		{	
		    case'i':
			case'I':
			input_array(array,n);
			break;
			case'd':
			case'D':
			output_array(array,n);
			break;
			case's':
			case'S':
			printf("\nEnter the position at which you want to insert the number\n");
			scanf("%d",&pos);
			printf("\nEnter the element to be inserted\n");
			scanf("%d",&item);
			n=insert_array(array,n,item,pos);
			break;	
			case'y':
			case'Y':
			quit();
			break;
			default:
			printf("\nInvalid Entry..........Try Again>>>>>>>>>-----\n");
			break;
		}
		goto hello;
	return(0);
}
void input_array(int*a,int n)
{
	int i;
	printf("\nEnter %d Element\n",n);
	for(i=0;i<n;i++)
	{	
		scanf("%d",a+i);
	}
}
void output_array(int*p, int n)
{
	int i;
	printf("\n The Elements are:----\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",*(p+i));
	}
}
int insert_array(int*arr, int n, int item, int pos)
{
	int i;
	for(i=n-1;i>=pos-1;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[pos-1]=item;
	n=n+1;
	return(n);
}
void quit()
{
	exit(0);
}

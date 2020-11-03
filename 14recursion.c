
#include<stdio.h>
int fact(int);
int main()
{
	int value,n;
	printf("enter any number=");
	scanf("%d",&n);
	if(n<0)
	{
		printf("couldn't find out for negative number ");
	}
	else if(n==0)
	{
		printf("the factorial of %d in 1",n);
	}
	else
	{
		value=fact(n);
		printf("the factorial of %d is %d",n,value);
	}
	return(0);
}
int fact (int n)
{
	int f=1;
	if(n>1)
	{
		f=n*fact(n-1);
	}
	return(f);
}


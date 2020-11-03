
#include<stdio.h>
int fact(int,int);
int main()
{
	int value,n;
	printf("enter any number=");
	scanf("%d",&n);
	if(n<0)
	{
		printf("couldn't find out negative number=");
		return(0);
	}
	else if(n==0)
	{
		printf("the factorial of %d in 1",n);
	}
	else
	{
		value=fact(n,1);
		printf("the fact of %d is %d",n,value);
	}
	return(0);
}
int fact (int n,int f)
{
	if (n==1)
	return f;
	else
	return (fact(n-1,n*f));
	}



#include <stdio.h> 
int recursiveFib (int);
int main ()
{
    int n;
    printf("Enter terms");
    scanf("%d",&n);
    printf ("%dth fibonacci number is %d\n", n, recursiveFib(n));
}
 
int recursiveFib (int n)
{
    if (n <= 1) 
        return n;
    return recursiveFib(n-1) + recursiveFib (n - 2);
}



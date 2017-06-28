#include <stdio.h>

int func(int a,int b)
{
	return a + b;
}

int main()
{
	int c;
	c = func(6,9);
	printf("%d\n",c);
	return c;
}
#include<stdio.h>
int main()
{
	int a = 1 , b = 0 , c = 0;
	int i;
	for(i=1;i<=10;i++)
	{
		c = c + b;
		printf("%d  ",c);
		b = a;
		a = c;
	}
}

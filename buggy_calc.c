#include<stdio.h>
#include<math.h>

int main()
{
	int a;//first input
	int b;//second input
	int n;
	int i=0;
	int p=0;
	int r=0 , ss=0, sum=0;
	
	
	printf("\n Enter first element");
	scanf("%d",&a);
	
	printf("\n Enter second element");
	scanf("%d",&b);
	
	printf("\n Values of a and b");
	printf("%d \t %d",a,b);
	
	while(a!=0 || b!=0)
	{
		p=a%10;
		r=b%10;
		sum=p+r;
		ss=ss+((sum%10)*pow(10,i));
		a=a/10;
		b=b/10;
		i+=1;
	}
	
	printf("\n %d",ss);


	return 0;
}

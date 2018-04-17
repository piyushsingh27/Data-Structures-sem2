#include<stdio.h>

int main()
{
	int index;
	int j = 0;
    int n;
    int a[10],b[10],c[10];
    
    printf("\n Size of array:");
    scanf("%d",&n);
    
    printf("\n Elements entered:");
    for(index = 0;index < n;index += 1)
    {
    	scanf("%d",&a[index]);
	}
	
	j = 0;
	for(index = 0;index < n; index += 1)
	{
		if(a[index] >= 0)
		{
			b[j] = a[index];
			j += 1;
		}
	}
	
	for(index = 0;index < n; index += 1)
	{
		if(a[index] < 0)
		{
			b[j] = a[index];
			j += 1;
		}
	}
	
	printf("\n Answer");
	for(index = 0;index < j;index += 1)
	{
		printf("%d",b[index]);
	}
	return 0;
}

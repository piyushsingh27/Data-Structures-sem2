#define MAX 50

#include<stdio.h>

void binary_search(int x,int ar[MAX])
{
	int mid;
	int first;
	int last;
    int n;
    int index;
    
    printf("\n Enter the size of array");
    scanf("%d",&n);
    
    printf("\n Enter the elements in array by user");
    for(index = 0;index < n;index += 1)
    {
    	scanf("%d",&ar[index]);
	}
	
	printf("\n Enter the element to search for in the array:");
	scanf("%d",&x);
	
	first = 0;
	last = n-1;
	mid = (first + last)/2;
	
	while(first <= last)
	{
		if(ar[mid] < x)
		{
			first = mid + 1;
			printf("%d found at %d",x,first);
			break;
		}
		
		else if(ar[mid] == x)
		{
			printf("%d found at position %d",x,mid+1);
			break;
		}
		
		else
		{
			last = mid - 1;
			printf("%d found at position %d",x,last);
			break;
		}
	}
	
	if(first > last)
	{
		printf("%d not found!!!!",x);
	}
		
	
}  

int main()
{
	int y;
	int arr[MAX];
	binary_search(y,arr);
}

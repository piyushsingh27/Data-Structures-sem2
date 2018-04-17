#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 10
int count;
void binary(int [MAX],int);
void linear(int [MAX],int);

int main()
{
	int array[MAX],choice;
	char ans,ans2;
	int index2,index,element, flag =0;
	do
	{
		printf("***********SEARCH************\n");
		printf("Enter the size of the array\n");
		scanf("%d",&count);
		if(count <= MAX)
		{
			printf("Enter the array:\n");
			for(index = 0; index < count; index += 1)
			{
				scanf("%d",&array[index]);
			}
		}
		else
		{
			printf("Array size is too large");
			exit(0);
		}	
	
		do
		{
			printf("\nEnter the Element to be found:\n");
			scanf("%d",&element);
			printf("Choose the search method:\n1. Linear Search\n2. Binary Search\n");
			scanf("%d",&choice);
			printf("Hello");
			switch(choice)
			{
				case 1:
					printf("Hello");
					linear(array,element);
					break;
				case 2:
					//sort(array);
					binary(array,element);
					break;
				default:
					printf("Please enter the correct choice");
					break;
			}
			
			printf("Do you wish to find another element?(Y/N)");
			getchar();
			scanf("%c",&ans2);
		}
		while(ans2 == 'y' || ans2 == 'Y');
		printf("Do you wish to continue?(Y/N)");
		getchar();
		scanf("%c",&ans);
	}
	while(ans == 'Y' || ans == 'y');
}

void linear(int array[], int element)
{
	int index, flag = 0;
	char ans2;
	for(index = 0; index < count; index += 1)
	{
		if(array[index] == element)
		{
			printf("\nThe element was found at index position %d\n",index);
			flag = 1;
		}
	}
	
	if(flag == 0)
	{
		printf("\nThe element was not found in the array\n");
	}
	return;
}


void binary(int array[],  int element)
{
	int index, index2, first, last, mid,flag=0;
	first = 0;
	last = count-1;
	
	
	do
	{
		mid = (first + last)/2;
		if(array[mid] < element)
		{
			first = mid;
		}
		else if(array[mid] > element)
		{
			last = mid;
		}
		else if(array[mid] == element)
		{
			printf("Element found at position %d\n",mid+1);
			flag = 1;
			break;
		}
		
		if((first+1) == last)
		{
			mid = first + 1;
			if(array[mid] == element)
			{
				printf("Element found atblagposition %d\n",mid+1);
				flag = 1;
				break;
			}
		}
	}while(first < last);
	return;
}

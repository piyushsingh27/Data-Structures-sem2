#define MAX 50

#include<stdio.h>
#include<stdlib.h>

void merge(float A[],int l,int r,int mid)
{
	int i; 
	int j;
	int k;
	int nL = mid - l + 1;
	int nR = r - mid;
	float L[nL], R[nR];
	
	for(i = 0;i < nL; i += 1)
	{
			L[i] = A[l + i];
	}
	
	for(j = 0;j < nR;j += 1)
	{
			R[j] = A[mid + 1 + j];
	}
	
	i = j = 0;
	k = l;
	
	while(i < nL && j < nR)
	{
		if(L[i] >= R[j])
		{
			A[k] = L[i];
			i += 1;
		}
		else
		{
			A[k] = R[j];
			j += 1;
		}
		k += 1;
	} 
	
	while(i < nL)
	{
		A[k] = L[i];
		i += 1;
		k += 1;
	}
	
	while(j < nR)
	{
		A[k] = R[j];
		j += 1;
		k += 1;
	}
}

void mergeSort(float A[],int l,int r)
{
	int mid;
	
		
		if(l < r)
		{
			mid = l + (r - l)/2;
		    mergeSort(A,l,mid);
		    mergeSort(A,mid+1,r);
		    merge(A,l,r,mid);
		}
}
	
	

int main()
{
	int index;
	int count;
	float arr_profit[MAX];
	float arr_weight[MAX];
	float pbyw[MAX];
	int capacity;
	int items;
	int i; 
	int gain = 0;
	
	printf("\n Enter the count of values:");
	scanf("%d",&count);
	
	printf("\n Enter profit and weight of elements of array:");
	for(index = 0;index < count;index += 1)
	{
		scanf("%f%f",&arr_profit[index],&arr_weight[index]);
	}
	
	printf("\n Profit of elements and its corresponding weight values:");
	for(index = 0;index < count;index += 1)
	{
		printf("%f \t %f",arr_profit[index],arr_weight[index]);
		printf("\n");
	}
	
	printf("\n Array formed of profit by weight:");
	for(index = 0;index < count;index += 1)
	{
		pbyw[index] = arr_profit[index] / arr_weight[index];
		printf("%f \t",pbyw[index]);
	}
	
	mergeSort(pbyw,0,count-1);
	
	printf("\n Array after sorting of values:");
	for(index = 0;index < count;index += 1)
	{
		printf("%f \t",pbyw[index]);
	}
	

	
	printf("\n Enter the maximum capacity of sack:");
	scanf("%d",&capacity);
	
	printf("\n Enter items(should be less than count) :");
	scanf("%d",&items);
	
	
	index = 0;
	while(capacity > 0 && index < items)
	{
		for(index = 0;index < count;index += 1)
		{
			if(arr_weight[(int)index] <= capacity)
			{
				gain += arr_profit[(int)index];
				capacity -= arr_weight[(int)index];
			}
			else
			{
				gain += (capacity * pbyw[index]);
				capacity = 0;
			}
		}
		index += 1;
	}
	
	printf("\n Profit is :%f",gain);
	return 0;
	
}



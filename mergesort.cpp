#define MAX 20

#include<stdio.h>


void merge(int A[],int l,int r,int mid)
{
	int i; 
	int j;
	int k;
	int nL = mid - l + 1;
	int nR = r - mid;
	int L[nL], R[nR];
	
	for(i = 0;i < nL; i += 1)
	{
		scanf("%d",&L[l + i]);
	}
	
	for(j = 0;j < nR;j += 1)
	{
		scanf("%d",&R[mid + 1 + j]);
	}
	
	i = j = 0;
	k = l;
	
	while(i < nL && j < nR)
	{
		if(L[i] <= R[j])
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

void mergeSort(int A[],int l,int r)
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
	int n;
	int i;
	int ar[MAX];
	
	printf("\n Enter the size of the array");
	scanf("%d",&n);
	
	printf("\n Enter array:");
	for(i = 0;i < n;i += 1)
	{
		scanf("%d",&ar[i]);
	}
	
	printf("\n Array entered is:");
	for(i = 0;i < n;i += 1)
	{
		printf("%d",ar[i]);
	}
	
	mergeSort(ar,0,n-1);
	
	printf("\n Array after sorting of values:");
	for(i = 0;i < n;i += 1)
	{
		printf("%d",ar[i]);
	}
	return 0;
}

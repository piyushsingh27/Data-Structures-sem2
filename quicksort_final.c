/* C implementation QuickSort */
#define MAX 20

#include<stdio.h>


typedef struct
{
	char book_name[MAX];
	int year_publish;
	char publisher[MAX];
    //int book_count;
	//int books[SIZE];
	int book_price;
} books;

 
// A function to swap two elements
void swap(books* a, books* b)
{
    books t = *a;
    *a = *b;
    *b = t;
}

char *partition_name(books b_arr[],int low,int high)
{
	books pivot;
	
	pivot = b_arr[high];
	int i = (low - 1);
	int j;
	
	for ( j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if(strcmp (b_arr[j].book_price , pivot.book_price) <= 0)
        {
            i++;    // increment index of smaller element
            swap(&b_arr[i], &b_arr[j]);
        }
    }
    swap(&b_arr[i + 1], &b_arr[high]);
    return (i + 1);
}
	

 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (books b_arr[], int low, int high)
{
	books pivot;
	
    pivot = b_arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
 
    for ( j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (b_arr[j].book_price <= pivot.book_price)
        {
            i++;    // increment index of smaller element
            swap(&b_arr[i], &b_arr[j]);
        }
    }
    swap(&b_arr[i + 1], &b_arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(books b_arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(b_arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(b_arr, low, pi - 1);
        quickSort(b_arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(books b_arr[], int book_count)
{
	int index;
    printf("\n The array sorted is");
	for(index=0;index<book_count;index+=1)
	{
		printf("\n Book name:");
		printf("%s",b_arr[index].book_name);
		printf("\t");
		
		printf("Book price:");
		printf("%d",b_arr[index].book_price);
		printf("\t");
		
		printf("Book publisher:");
		printf("%s",b_arr[index].publisher);
		printf("\t");
		
		printf("Year published:");
		printf("%d",b_arr[index].year_publish);
		printf("\n");
	}
}
 
// Driver program to test above functions
int main()
{
    int book_count;//number of books
    books book_array[MAX];//array of structure
    int index;//index value used in for loop
    int choice;//choice to be entered by the user for sorting choice
    char ch;
    
    printf("\n Enter the number of books taken by the user:");
    scanf("%d",&book_count);
    
    printf("\n !!!!!!!!!Books data!!!!!!!!!");
    for(index = 0; index < book_count; index += 1)
    {
    	printf("\n Book name:");
    	scanf("%s",book_array[index].book_name);
    	
    	printf("\n Book price");
    	scanf("%d",&(book_array[index].book_price));
    	
    	printf("\n Book publisher");
    	scanf("%s",book_array[index].publisher);
    	
    	printf("\n Year published");
    	scanf("%d",&(book_array[index].year_publish));
    	
    	printf("\n");
	}
	
	printf("\n The array entered is");
	for(index=0;index<book_count;index+=1)
	{
		printf("\n Book name:");
		printf("%s",book_array[index].book_name);
		printf("\t");
		
		printf("Book price:");
		printf("%d",book_array[index].book_price);
		printf("\t");
		
		printf("Book publisher:");
		printf("%s",book_array[index].publisher);
		printf("\t");
		
		printf("Year published:");
		printf("%d",book_array[index].year_publish);
		printf("\n");
	}
	do
	{
	
	
	do
	{
		printf("\n QUICKSORT MENU");
		printf("\n 1.sort by bookname");
		printf("\n 2.sort by bookprice");
		printf("\n 3.exit");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n Chosen sorting by book name");
			        quickSort(book_array, 0, book_count-1);
                    printf("Sorted array: n");
                    printArray(book_array, book_count);
			        break;
			        
			case 2: printf("\n Chosen sorting by book price");
			        quickSort(book_array, 0, book_count-1);
                    printf("Sorted array: n");
                    printArray(book_array, book_count);
			        break;        
			        
            default: printf("\n !!!!!!Wrong choice!!!!!!!");
			         break;			        
		}
	}
	while(choice!=3);
	printf("\n Do you wish to continue");
	getchar();
	scanf("%c",&ch);
 }
 
 while(ch == 'y' || ch == 'y');
}

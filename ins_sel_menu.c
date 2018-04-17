#define MAX 20
#define SIZE 10

#include<stdio.h>
#include<conio.h>
#include<string.h>



typedef struct
{
	char book_name[MAX];
	int year_publish;
	char publisher[MAX];
    //int book_count;
	//int books[SIZE];
	int book_price;
} books;


void sel_name_sort(books [],int );
void sel_price_sort(books [],int );
void ins_name_sort(books [],int );
void ins_price_sort(books [],int );

int main()
{
	printf("===============================================Implementation of structures=============================================");
	printf("\n");
	
	books book_array[SIZE];
    
    int index,ch,choice;
    
    int book_count;
    
    printf("\n Count of the books taken by the user:");
    scanf("%d",&book_count);
    
    printf("Array of structures");
    for(index=0;index<book_count;index+=1)
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
		printf("\n MAIN MENU");
		printf("\n 1. Selection Sort");
		printf("\n 2.Insertion Sort");
		printf("\n 3.exit");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("\n Selection sort chosen");
			       do
	               {
		                printf("\n SELECTION SORT MENU");
		                printf("\n 1.sort by book name");
		                printf("\n 2.sort by book price");
		                printf("\n 3.exit");
		                printf("\n Enter your choice:");
		                scanf("%d",&ch);
		
		                switch(ch)
		                {
			                 case 1: printf("\n Sorting by book name");
			                 sel_name_sort(book_array,book_count);
			                 break;
			        
			                 case 2: printf("\n Sorting by book price");
			                 sel_price_sort(book_array,book_count);
					         break;
					
		                     default: printf("\n Wrong choice");
			                 break;			        
		                }
	                }
	                while(ch!=3);
	                
	                break;
	
	        case 2:printf("\n Insertion sort chosen");
			       do
	               {
		                printf("\n INSERTION SORT MENU");
		                printf("\n 1.sort by book name");
		                printf("\n 2.sort by book price");
		                printf("\n 3.exit");
		                printf("\n Enter your choice:");
		                scanf("%d",&ch);
		
		                switch(ch)
		                {
			                case 1: printf("\n Sorting by book name");
			                ins_name_sort(book_array,book_count);
			                break;
			        
			                case 2: printf("\n Sorting by book price");
			                ins_price_sort(book_array,book_count);
					        break;
					
		                    default: printf("\n Wrong choice");
			                break;			        
		                }
	                }
	                while(ch!=3);        
	                
	                break;
	                
	        default : printf("\n !!!!Wrong choice!!!!!");
			          break;        
		}
		
	}
	while(choice != 3);
	
	return 0;
}

void sel_name_sort(books b_array[],int book_count)
{
	int i , j , min , index ;
	books temp;
	for( i = 0 ; i <  book_count - 1 ; i++ )
	{
		min = i;
		for( j = i + 1 ; j < book_count ; j++ )
		{
			if( strcmp( b_array[j].book_name , b_array[min].book_name ) < 0 )
			{
				min = j;
			}
		}
		if( min != i )
		{
			temp = b_array[i];
			b_array[i] = b_array[min];
			b_array[min] = temp;
		}
	}
	
	printf("\n The array sorted is");
		for(index=0;index<book_count;index+=1)
	{
		printf("\n Book name:");
		printf("%s",b_array[index].book_name);
		printf("\t");
		
		printf("Book price:");
		printf("%d",b_array[index].book_price);
		printf("\t");
		
		printf("Book publisher:");
		printf("%s",b_array[index].publisher);
		printf("\t");
		
		printf("Year published:");
		printf("%d",b_array[index].year_publish);
		printf("\n");
	}
}

void sel_price_sort(books b_array[],int book_count)
{
	int i , j , min , index ;
	books temp;
	for( i = 0 ; i <  book_count - 1 ; i++ )
	{
		min = i;
		for( j = i + 1 ; j < book_count ; j++ )
		{
			if( b_array[j].book_price < b_array[min].book_price )
			{
				min = j;
			}
		}
		if( min != i )
		{
			temp = b_array[i];
			b_array[i] = b_array[min];
			b_array[min] = temp;
		}
	}
	
	printf("\n The array sorted is");
		for(index=0;index<book_count;index+=1)
	{
		printf("\n Book name:");
		printf("%s",b_array[index].book_name);
		printf("\t");
		
		printf("Book price:");
		printf("%d",b_array[index].book_price);
		printf("\t");
		
		printf("Book publisher:");
		printf("%s",b_array[index].publisher);
		printf("\t");
		
		printf("Year published:");
		printf("%d",b_array[index].year_publish);
		printf("\n");
	}
}

void ins_name_sort(books b_arrayins[],int book_count)
{
	int i , j ;
	books key;
	
	for(i = 1; i < book_count; i+=1)
	{
		key = b_arrayins[i];
		j = i - 1;
		
		while( (strcmp(b_arrayins[j].book_name , key.book_name) > 0) && j >= 0)
		{
			b_arrayins[j+1] = b_arrayins[j];
			j = j-1 ;
		}
		
		b_arrayins[j+1] = key;
		
	}
	
	printf("\n The array sorted is");
		for(i=0;i<book_count;i+=1)
	{
		printf("\n Book name:");
		printf("%s",b_arrayins[i].book_name);
		printf("\t");
		
		printf("Book price:");
		printf("%d",b_arrayins[i].book_price);
		printf("\t");
		
		printf("Book publisher:");
		printf("%s",b_arrayins[i].publisher);
		printf("\t");
		
		printf("Year published:");
		printf("%d",b_arrayins[i].year_publish);
		printf("\n");
	}
}

void ins_price_sort(books b_arrayins[],int book_count)
{
	int i , j ;
	books key;
	
	for(i = 1; i < book_count; i+=1)
	{
		key = b_arrayins[i];
		j = i - 1;
		
		while(j >= 0 && b_arrayins[j].book_price > key.book_price)
		{
			b_arrayins[j+1] = b_arrayins[j];
			j = j-1 ;
		}
		
		b_arrayins[j+1] = key;
    }
    
    	printf("\n The array sorted is");
		for(i=0;i<book_count;i+=1)
	{
		printf("\n Book name:");
		printf("%s",b_arrayins[i].book_name);
		printf("\t");
		
		printf("Book price:");
		printf("%d",b_arrayins[i].book_price);
		printf("\t");
		
		printf("Book publisher:");
		printf("%s",b_arrayins[i].publisher);
		printf("\t");
		
		printf("Year published:");
		printf("%d",b_arrayins[i].year_publish);
		printf("\n");
	}
}
    

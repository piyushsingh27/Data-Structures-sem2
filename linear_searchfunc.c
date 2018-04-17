#define MAX 30

#include<stdio.h>

void linear_search(int x)
{
	int index;// for loop index for traversing array
	int ar[MAX];//array declaration
	int n;//size of the array to be entered
	
	/* size of the array taken from the user */
	printf("\n Enter the size of the array");
	scanf("%d",&n);
	
	/* array values being input from the user */
	printf("\n Enter the values in an array:");
	for(index = 0; index < n; index += 1)
    {
    	scanf("%d",&ar[index]);
	 } 
	 
	 /* input of the variable to be searched taken from the user */
	 printf("\n Enter the variable to be searched");
	 scanf("%d",&x);
	 
	 for(index = 0; index < n; index += 1)
	 {
	 	if(x == ar[index]) //if element found
	 	{
	 		printf("\n Element found at:");
	 		printf("%d",index+=1);
	 		break;
		 }
		 
		 else //if element not foundgfds
		 {
		 	printf("\n Element not found!!!!");
		 	break;
		 }
	 }
}
	 
	  main()
	 {
	 	int y;
	 	linear_search(y);
	 }




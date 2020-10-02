//dynamic memory allocation for array using malloc
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 

	int* ptr; //pointer that holds address to the memory block
	int n, i; 

	//Get the number of elements for the array 
	printf("Enter number of elements:"); 
	scanf("%d",&n);

	// Dynamically allocate memory using malloc() 
	ptr = (int*)malloc(n * sizeof(int)); 


	if (ptr == NULL) //If memory allocation is unsuccessfull the ptr will hold NULL
	{ 
		printf("Memory not allocated.\n"); 
		exit(0); 
	} 
	else 
	{ 
		printf("Enter Input elements\n"); 

		for (i = 0; i < n; ++i) 
		{ 
			scanf("%d",&ptr[i]);
		} 

		// Print the elements of the array 
		printf("\nThe elements of the array are: "); 
		for (i = 0; i < n; ++i) { 
			printf("%d, ", ptr[i]); 
		} 
	} 
	
	free(ptr);

	return 0; 
} 

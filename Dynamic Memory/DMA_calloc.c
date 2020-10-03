#include <stdio.h>  
#include <stdlib.h> 

int main() 
{ 
    int* ptr; 	// This pointer will hold the base address of the block created 
	int n, i; 
 
	printf("Enter umber of elements: "); 
	scanf("%d",&n);

	// Dynamically allocate memory using calloc() 
	ptr = (int*)calloc(n, sizeof(int)); 

	// Check if the memory has been successfully 
	// allocated by calloc or not 
	if (ptr == NULL) 
	{ 
		printf("\nMemory not allocated.\n"); 
		exit(0); 
	} 
	else { 
		// Memory has been successfully allocated 
		printf("\nThe elements of the array before: "); 
		for (i = 0; i < n; ++i) { 
			printf("%d ", ptr[i]); 
		} 
		
		printf("\n\nInput the elements : \n"); 

		// Get the elements of the array 
		for (i = 0; i < n; ++i) 
		{ 
			scanf("%d",&ptr[i]);
		} 

		// Print the elements of the array 
		printf("\nThe elements of the array after: "); 
		for (i = 0; i < n; ++i) { 
			printf("%d ", ptr[i]); 
		} 
	} 

	return 0; 
} 

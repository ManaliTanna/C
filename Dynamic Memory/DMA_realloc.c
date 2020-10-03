//Reallocating memory usnig realloc()
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
	int *ptr = (int *)malloc(sizeof(int)*2); //ptr points to a block that can hold 2 integers
	int i; 
	int *ptr_new; 
	
	*ptr = 10; //First integer in the block is 10
	*(ptr + 1) = 20; //Second integer in the block is 20
	
	ptr_new = (int *)realloc(ptr, sizeof(int)*3); //ptr_new points to anew block that can hold 3 integers. The first 2 integers are 12,20
	
	*(ptr_new + 2) = 30; //Third integer in the block is 20
	
	for(i = 0; i < 3; i++) 
		printf("%d ", *(ptr_new + i)); 
	
	printf("\nPress Enter to Exit\n");

	getchar(); 
	return 0; 
} 

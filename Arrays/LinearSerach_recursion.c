#include<stdio.h> 

/* Recursive function to search x in arr[l..r] */
int recSearch(int arr[], int l, int r, int x) 
{ 
	if (r < l) 
		return -1; 
	if (arr[l] == x) 
		return l; 
	if (arr[r] == x) 
		return r; 
	return recSearch(arr, l+1, r-1, x); 
} 

int main() 
{ 
	int arr[] = {1,2,3,4,5,6,7,8,9,10}, i; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int x;
	printf("\nArray : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nInput element to search : ");
	scanf("%d",&x);
	int index = recSearch(arr, 0, n-1, x); 
	if (index != -1) 
		printf("Element %d is present at index %d\n", x, index); 
	else
		printf("Element %d is not present\n", x); 
	return 0; 
} 

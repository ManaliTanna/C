//Recursion is an application of Stack
//Tower of Hanoi 
#include<stdio.h>
#include<conio.h>

//Move n disk from source to destination using auxillary
void TOH(int n,char source,char auxillary,char destination)
{
	//base case
	if(n==1)
	{
		printf("Move a disc from tower %c to tower %c\n",source,destination);
	}
	else //recursive cases...n>1
	{
	
		//STEP 1: move n-1 disk from source to auxillary using destination
		TOH(n-1,source,destination,auxillary);
	
		//STEP 2: move 1 disk from source to destinaton
		TOH(1,source,auxillary,destination);
	
		//STEP 3: move n-1 disk from auxillary using source to destination
		TOH(n-1,auxillary,source,destination);
	
	}
}

int main()
{
	int n;
	printf("Enter number of dics : ");
	scanf("%d",&n);
	
	char source='A',auxillary='B',destination='C';
	
	TOH(n,source,auxillary,destination); //initial call
	
	printf("Press enter to exit\n");
	getche();
}



//for 3 disks: 
//10 - function calls
//7 -  disc moves















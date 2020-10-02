//Stack Array Implementation - Static Memeory Allocation
//Physical deletion of memory not possible
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 5
int top=-1,stack[MAX];

void push(int element)
{
	if(top>=MAX-1)
		printf("STACK FULL \n");
	else
		stack[++top]=element;
}

void pop()
{
	if(top==-1)
		printf("STACK EMPTY \n");
	else
		printf("Popped : %d\n",stack[top--]);
}

void display()
{
	int i;
	if(top == -1)
		printf("STACK EMPTY \n");
	else
	{
		printf("Stack is : \n");
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);
	}
}

int main()
{
	printf("\tStack Array Implementation : Static\n");
	int choice,ans,element;
	do{
		printf("------");
		printf("\nMENU\n");
		printf("------\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("\nInput element to push : ");
			scanf("%d",&element);
			push(element);
			break;
			
			case 2:
			pop();
			break;
			
			case 3:
			display();
			break;
			
			case 4:
			exit(0);
			
			default:
			printf("\nInvalid choice!\n");
		}
      
		printf("\nDo You want To Continue?(Y/N) :");
		ans = getche();
    } while (ans == 'Y' || ans == 'y');
	return 0;
}

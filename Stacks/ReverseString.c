//Reverse string using stacks
//LinkedList implementation of a stack

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node{ 
	char data;
	struct node *next;
};
typedef struct node node;//node is a dataype that contains an int element and a pointer of type node that points to the next node in the list

struct stack{ 
	node *top;
};

typedef struct stack stack;//stack is a data type that hold a pointer of type node..this pointer points to top of stack



void push(char x, stack *s) //s is pointer to the stack entity, as top is changed, pass by reference
{
	node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node)); //allocate memory for a new node
	new_node -> data = x;
	new_node -> next = s -> top; //insert at the front of list
	s -> top = new_node; //make top as the new top node
}

char pop(stack *s)//as top is changed, pass by reference
{
	char x;
	node *temp; //Node for traversal, no need to allocate memory
	if(s -> top == NULL)
	{
		printf("ERROR! UNDERFLOW!\n");
		return -1;
	}
	else
	{
		temp = s -> top;
		x = temp -> data; //store the current top of stack
		s -> top = temp -> next;//change the top of stack in order to pop
		free(temp); //free the memory inside temp that is the prev top of stack
		temp = NULL; 
		return(x); //return the value that was popped
	}
}


int main()
{
	stack s; //s is the stack entity that contains TOS
	s.top=NULL;
	
	int i;
	
	char str[100];
	printf("Input a string : ");
	scanf("%s",str); //CAN ONLY TAKE ONE WORD, NO SPACES
	
	for(i=0;i<=strlen(str);i++)
	{
		push(str[i],&s); //PUSH EACH CHARACTER
	}
	
	printf("The reverse string is :");
	for(i=0;i<=strlen(str);i++)
		printf("%c",pop(&s)); //POP EACH CHARACTER 
	
}
	


//LinkedList implementation of a stack i.e the stack is made of nodes
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{ 
	int data;
	struct node *next;
};
typedef struct node node;//node is a dataype that contains an int element and a pointer of type node that points to the next node in the list

struct stack{ 
	node *top;
};

typedef struct stack stack;//stack is a data type that hold a pointer of type node..this pointer points to top of stack



void push(int x, stack *s) //s is pointer to the stack entity, as top is changed, pass by reference
{
	node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node)); //allocate memory for a new node
	new_node -> data = x;
	new_node -> next = s -> top; //insert at the front of list
	s -> top = new_node; //make top as the new top node
}

int pop(stack *s)//as top is changed, pass by reference
{
	int x;
	node *temp; //Node for traversal, no need to allocate memory
	if(s -> top == NULL)
	{
		printf("EMPTY STACK! UNDERFLOW!\n");
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

void display(stack *s)
{
	node *temp; //node for traversal so that we don't change the top of the stack
	if(s -> top == NULL)
		printf("EMPTY STACK! UNDERFLOW!\n");
	else
	{
		printf("The current stack is : \n");
		temp = s -> top;
		while(temp!=NULL)
		{
			printf("%d \n",temp->data);;
			temp = temp -> next;
		}
	}
}

int main()
{
	stack s; //s is the stack entity that contains TOS
	s.top=NULL;
	
	int ele,choice,ans;
	
	printf("\n\tLinked List Implementation Of Stack ");
	do {
	  printf("\n----------");
      printf("\nMain Menu");
	  printf("\n----------");
      printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
      printf("\nEnter Your Choice : ");
      scanf("%d", &choice);
      switch (choice) 
	  {
		  
      case 1:
			printf("\nEnter The item to be pushed : ");
			scanf("%d", &ele);
			push(ele,&s);
			break;
		 
      case 2:
			ele = pop(&s);
			if(ele!=-1)  //if not error code
				printf("\nThe popped element is %d", ele);
			break;
		 
      case 3:
			display(&s);
			break;
		 
	  case 4:
			exit(0);
			break;
		
		default:
			printf("Invalid choice!!\n");
		 
      }
	  
      printf("\nDo You want To Continue?(Y/N) : ");
      ans = getche(); //don't wait for enter key after input 
   } while (ans == 'Y' || ans == 'y');
    return 0;
}
	


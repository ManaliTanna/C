#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct stack {
	int size; //max no of elements
	int top; //index to access elements, it points to most recently inserted element
    int *s; //points to block allocated using DMA
};

typedef struct stack stack;

//Use DMA to create block pointed to by s which is of the size pt_st->size
void *createStack(stack *p_st)  //p_st is pointer to st
{
	p_st -> s = malloc(sizeof(int) * p_st -> size); //allocationg the memory block pointed by *s
	p_st -> top = -1;
}

int isFull(stack st)
{
	if(st.top == st.size-1)
		return 1;
	else
		return 0;
}

int isEmpty(stack st)
{
	if(st.top == -1)
		return 1;
	else
		return 0;
}

void push(stack *p_st,int ele)//as we are changing the value of top use pass by reference
{
	if(isFull(*p_st))//pass the value stored at pointer p_st that is the stack itself
		printf("STACK IS FULL! OVERFLOW\n");
	else{
		p_st -> top++; //increase position of top
		p_st -> s[p_st -> top] = ele; //assigning ele to top
	}
}


int pop(stack *p_st) //as we are changing the value of top use pass by reference
{
	if(isEmpty(*p_st))
	{
		printf("STACK IS EMPTY! UNDERFLOW\n");
		return(-999999);
	}
	else
	{
		int ele = p_st -> s[p_st -> top];
		p_st -> top--;
		return(ele);
	}
}


void display(stack st) //just see content, not change any member, hence pass by value thats member to member copy or shallow copy
{
	if(isEmpty(st))
		printf("Empty!\n");
	else{
	int i;
	printf("\n\tStack is : \n");
	//Since we are not returning and doing pass by reference we can change top OTHERWISE DON'T CHANGE TOP.
	//while(st.top > -1) printf("%d \n",st.s[st.top--]);
	for(i=st.top;i>=0;i--) 
	{
		printf("%d \n",st.s[i]);
	}
	}
}

void clear(stack *p_st)
{
	p_st -> top=-1;
	printf("\nCleared Successfully!");
}


void destroyStack(stack *p_st)//release back the memory that was allocated dynamically that's the block pointed to by s
{ 
	//free memory and make pointer null or else it will give junk
	free(p_st -> s); //s is pointer to DMA block
	p_st -> s = NULL; //order of statement is IMPORTANT or else memory leak
	p_st -> size = 0;
	p_st -> top = -1;
	free(p_st);
	p_st=NULL;
	printf("\nDestroyed Stack and exited program!!");
}


int main() 
{
    stack *p_st ; //SMA to hold the stack entity
	p_st = malloc(sizeof(stack)); //DMA for the stack entity
	p_st -> s = NULL;
	int ele,item,choice,ans;
	
	printf("\n\tArray Implementation Of Stack : Dynamic stack, Dynamic stack entity");
	do {
	  printf("\n----------");
      printf("\nMain Menu");
	  printf("\n----------");
      printf("\n1.create\n2.Push \n3.Pop \n4.Display \n5.Clear\n6.Destroy\n7.Exit");
      printf("\nEnter Your Choice : ");
      scanf("%d", &choice);
      switch (choice) 
	  {
		  
      case 1:
         printf("Enter the size of the stack to be created : ");
         scanf("%d",&p_st->size);
         createStack(p_st);
         break;  
		 
      case 2:
		if(p_st -> s==NULL)
			printf("Stack not created yet!!!\n");
		else{
			printf("\nEnter The item to be pushed : ");
			scanf("%d", &ele);
			push(p_st,ele);
		}
         break;
		 
      case 3:
			if(p_st -> s==NULL)
				printf("Stack not created yet!!!\n");
			else{
				item = pop(p_st);
				if(item!=-999999)  //if not error code
					printf("\nThe popped element is %d", item);
			}
         break;
		 
      case 4:
		if(p_st -> s==NULL)
			printf("Stack not created yet!!!\n");
		else{
         display(*p_st);
		}
         break;
		 
	  case 5:
		if(p_st -> s==NULL)
			printf("Stack not created yet!!!\n");
		else{
          clear(p_st);
		}
         break;
		 
      case 6:
          destroyStack(p_st);
         break;
		 
	  case 7:
		exit(0);
		 break;
		
		default:
		printf("Invalid choice!!\n");
		 
      }
      printf("\nDo You want To Continue?(Y/N) : ");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');
    destroyStack(p_st);
    return 0;
}
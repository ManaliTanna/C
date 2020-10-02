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
	s_st -> top = -1;
}

void push(stack *p_st,int ele)//as we are changing the value of top use pass by reference
{
	if(p_st -> top == p_st -> size-1)
		printf("STACK IS FULL\n");
	else{
		p_st -> top++; //increase position of top
		p_st -> s[p_st -> top] = ele; //assigning ele to top
	}
}


int pop(stack *p_st) //as we are changing the value of top use pass by reference
{
	if(p_st - > top == -1)
		return(-999999); //error code can be anything
	
	int ele = p_st -> s[p_St -> top];
	p_st -> top--;
	return(ele);
}


void display(stack st) //just see content, not change any member, hence pass by value thats member to member copy or shallow copy
{
	int i;
	printf("\n\tStack is : \n");
	//Since we are not returning and doing pass by reference we can change top OTHERWISE DON'T CHANGE TOP.
	//while(st.top > -1) printf("%d \n",st.s[st.top--]);
	for(i=st.top;i>=0;i--) 
	{
		printf("%d \n",st.s[i]);
	}
}

void clear(stack *p_st)
{
	p_st->top=-1;
}


void destroyStack()//release back the memory that was allocated dynamically that's the block pointed to by s
{ 
	
}


int main() 
{
    Stack st ; //SMA
	int ele;
	
	printf("\n\tImplementation Of Stack : Dynamic array, Dynamic stack entity");
	do {
      printf("\nMain Menu");
      printf("\n1.create\n 2.Push \n3.Pop \n4.Display \n5.Clear\n6.Destroy\n7.Exit");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice) 
	  {
		  
      case 1:
         printf("Enter the capacity of the stack to be created : ");
         scanf("%d",&st.size);
         createStack(&st);
         break;  
		 
      case 2:
         printf("\nEnter The item to be pushed : ");
         scanf("%d", &item);
         push(&st,item);
         break;
		 
      case 3:
         if (isEmpty(st))
            printf("\nEmpty stack! Underflow !!");
         else 
		 {
            item = pop(&st);
            if(item!=-999999)  //if not error code
				printf("\nThe popped element is %d", item);
         }
         break;
		 
      case 4:
         display(st);
         break;
		 
	  case 5:
          clear(&st);
         break;
		 
      case 6:
          destroyStack(&st);
         break;
		 
	  case 7:
		exit(0);
		break;
		
		default:
		printf("Invalid choice!!\n");
		 
      }
      printf("\nDo You want To Continue?(Y/N)");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');

    return 0;
}
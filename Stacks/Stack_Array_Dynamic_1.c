#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct stack { //stck entity
   int *s;
   int top;
};

typedef struct stack stack;

int* create(int size) //allocating memory of size
{
	return(malloc(sizeof(int)*size));
}

int stfull(stack st,int size) //using the stack entity itself
{
   if (st.top >= size - 1)
      return 1;
   else
      return 0;
}
int stempty(stack st) 
{
   if (st.top == -1)
      return 1;
   else
      return 0;
}

void push(stack *p_st,int element)  //using pointer to the stack entity
{
   p_st -> top++;
   p_st -> s[p_st -> top] = element;
}


int pop(stack *p_st) 
{
   int popped;
   popped = p_st -> s[p_st -> top];
   p_st -> top--;
   return (popped); //return the element that was popped of the stack
}

void display(stack st) 
{
   int i;
   if (stempty(st))
      printf("\nStack Is Empty!");
   else 
   {
      for (i = st.top; i >= 0; i--)
         printf("\n%d", st.s[i]);
   }
}

int main()
{
   int item, choice,size;
   char ans;
   stack st;
   

   printf("\n\tImplementation Of Stack : Dynamic array, Static stack entity");
   do {
      printf("\nMain Menu\n");
      printf("\n1.create\n .Push\n3.Pop\n4.Display\n5.exit\n");
      printf("\nEnter Your Choice : ");
      scanf("%d", &choice);
      switch (choice) 
	  {
      case 1:
         printf("\nEnter the size of the stack to be created : ");
         scanf("%d",&size);
         st.s=create(size);
         if(st.s==NULL)
         {printf("Stack can not be created !!\n");
         exit(1);} 
         st.top=-1;
         break;   
		 
      case 2:
         printf("\nEnter The item to be pushed : ");
         scanf("%d", &item);
         if (stfull(st,size))
            printf("\nStack is Full !!\n");
         else
            push(&st,item);
         break;
		 
      case 3:
         if (stempty(st))
            printf("\nEmpty stack!Underflow !!\n");
         else {
            item = pop(&st);
            printf("\nThe popped element is %d\n", item);
         }
         break;
		 
      case 4:
         display(st);
         break;
		 
      case 5:
         exit(0);
      }
      printf("\nDo You want To Continue?(Y/N) : ");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');

return 0;
}
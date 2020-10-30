//Infix to postfix - operator stack
//Evaluation of postfix - operand stack

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

//evaluation of postfix expression (single digit operand binary operators)
struct stack{
	unsigned int size; //MAX ELEMENTS
	int top; //index to access TOS
	int *s; //Points to block allocated by DMA --> integer stack
};
typedef struct stack stack;

void createstack(stack *p_st) //p_st is pointer to st
{
	int size=p_st->size;
	p_st -> s = malloc(size * sizeof(int));
	p_st -> top = -1;
}

int isfull(stack st)//returns 1 if stack is ful otherwise 0
{
	if(st.top == st.size-1)
		return 1;
	else
		return 0;
}

void push(stack *p_st,int ele)
{
	if(isfull(*p_st))
		printf("STACK IS FULL\n");
	else
		p_st -> s[++(p_st->top)] = ele;
}

int pop(stack *p_st)
{
	int ele;
	if(p_st -> top == -1)
		return(-99999);
	else
	{
		ele = p_st -> s[p_st -> top]; 
		p_st -> top--;
		return ele;
	}
}

void display(stack st)
{
	int i;
	for(i=st.top;i>0;i--)
	{
		printf("%d",st.s[i]);
	}
}

void destroy(stack *p_st)
{
	free(p_st -> s); //free the internal stack
	p_st -> s = NULL; //make the internal stack pointer point to null
	p_st -> top = -1;
	p_st -> size = 0;
}

int evaluate(char x,int op1, int op2)
{
	if(x=='+')
		return(op1+op2);
	if(x=='-')
		return(op1-op2);
	if(x=='*')
		return(op1*op2);
	if(x=='/')
		return(op1/op2);
	if(x=='%')
		return(op1%op2);
}

void main()
{
	stack st;
	
	char exp[100];
	char token;
	int val;
	int op1,op2;
	int k=0;
	
	printf("Enter the postfix expression where each operand is single digit :- \n");
	scanf("%s",exp);

	
	st.size = strlen(exp);

	
	createstack(&st);
	
	token = exp[k]; 
	while(token!='\0')
	{ 
		if(isdigit(token)) //check for digit character
			push(&st,token-'0'); // -48 to remove the affect of ASCII as its an integer stack
		else //not an operand
		{
			op2 = pop(&st); //returns int value
			op1 = pop(&st);
			val = evaluate(token,op1,op2);
			printf("%d %c %d = %d\n",op1,token,op2,val);
			push(&st,val);
		}
		token = exp[++k];
	}
	val = pop(&st);
	printf("ANSWER : %d\n",val);
	destroy(&st);
	getche();
}


/*Postfix Evaluation Algorithm
1) Create a operand stack
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a operand, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. op2 and then op1. 
		Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer*/


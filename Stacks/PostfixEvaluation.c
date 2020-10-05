//Infix to postfix - operator stack
//Evaluation of postfix - operand stack

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

//evaluation of postfix expression (single digit operand binary operators
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
	printf("ele is %d\n",ele);
	if(isfull(*p_st))
		printf("STACK IS FULL\n");
	else{
		//p_st -> top++;
		//p_st -> ++top;
		p_st -> s[++(p_st->top)] = ele;
		printf("Pushed: %d\n",p_st -> s[p_st -> top]);
	}
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
		printf("Popped %d\n",ele);
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
	printf("Expression is : %s\n",exp);
	
	st.size = strlen(exp);
	//printf("%u\n",st.size);
	//printf("%d\n",strlen(exp));
	
	createstack(&st);
	
	token = exp[k]; 
	while(token!='\0')
	{ 
		printf("Token is %c\n",token);
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
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tnode
{
	char data;
	struct tnode *left;
	struct tnode *right;
};
typedef struct tnode tnode;

void push(tnode **stack,int *top,tnode *value)
{
	++*top;
	stack[*top]=value;
}

tnode *pop(tnode **stack,int *top)
{
	tnode *temp;
	temp = stack[*top];
	--*top;
	return temp; //returns address of a tnode thats popped
}

void inorder(tnode *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr -> left);
		printf("%c",ptr -> data);
		inorder(ptr -> right);
	}
	return;
}

void preorder(tnode *ptr)
{
	if(ptr!=NULL)
	{
		printf("%c",ptr -> data);
		preorder(ptr -> left);
		preorder(ptr -> right);
	}
	return;
}

tnode *createExpTree(char *exp)
{
	tnode *new_node; //create a new node for the tree
	tnode *stack[100];//stack is an array holding pointers of type tnode
	int top=-1; //initially top is -1
	
	int i=0;
	char token; //to traverse the expression char by char
	
	while(exp[i]!='\0')
	{
		token = exp[i];
		new_node = (tnode*)malloc(sizeof(tnode)); //allocate and create a new node for the tree
		
		new_node -> data = token;
		new_node -> left = NULL;
		new_node -> right = NULL;
		 
		if(token=='+' || token=='-' || token=='*' || token=='/' || token=='%') //if its operator
		{
			new_node -> right = pop(stack,&top); //right subtree is first popped value
			new_node -> left = pop(stack,&top); //left subtree is second popped value
			push(stack,&top,new_node); //push the new tree back to stack
		}
		else //if its an operand
		{
			push(stack,&top,new_node); //push the operand as a new tree to the stack
		}
	    i++;
	}
	printf("\nExpression Tree Created!\n");
	return (pop(stack,&top)); //the TOS holds the address to the root of the expression tree
} 

int evaluate(tnode *ptr)
{
	if(ptr!=NULL)
	{
		int x;
		switch(ptr->data)
		{
			case '+': 
				return(evaluate(ptr->left) + evaluate(ptr->right));
				break;
			case '-':
				return(evaluate(ptr->left) - evaluate(ptr->right));
				break;
			case '*':
				return(evaluate(ptr->left) * evaluate(ptr->right));
				break;
			case '/':
				return(evaluate(ptr->left) / evaluate(ptr->right));
				break;
			case '%':
				return(evaluate(ptr->left) % evaluate(ptr->right));
				break;
			default:
				printf("\nInput %c :",ptr -> data);
				scanf("%d",&x);
				return x;
		}
	}
}

void main()
{
	tnode *root;
	char exp[100];
	root = NULL;
	
	printf("Enter the postfix form of the expression : ");
	scanf("%s",exp);
	
	root=createExpTree(exp);
	
	printf("\nInfix expression  : ");
	inorder(root); //pass by value
	printf("\nprefix expression  : ");
	preorder(root);
	
	int ans;
	ans = evaluate(root);
	printf("\nANSWER AFTER EVALUATION : %d\n",ans);
	
	
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

node *create()
{
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	
	int x;
	
	printf("Enter data value (-1 for NULL) :   ");
	scanf("%d",&x);
	
	if(x == -1)
		return NULL;
		
	//STEP 1
	new_node -> data = x;
	
	//STEP 2
	printf("Left Child : "); //Recursive to create left subtree
	new_node -> left = create();
	
	//STEP 3
	printf("Right Child : "); //Recursive to create right subtree
	new_node -> right = create();
	
	//STEP 4
	return new_node; //to store corresponding address
	
}

void inorder(node *ptr)// intitially pointer ptr will hold address of root node
{
	if(ptr!=NULL)
	{
		inorder(ptr -> left); //Recursively finish left subree
		printf("%d ",ptr -> data);//Print data only after full left is done
		inorder(ptr -> right);//Recursively finish left subree
	}
	return; //go back to function call
}

void preorder(node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr -> data);
		preorder(ptr -> left);
		preorder(ptr -> right);
	}
	return;
}

void postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr -> left);
		postorder(ptr -> right);
		printf("%d ",ptr -> data);
	}
	return;
}

int main()
{
	node* root = create();
	int choice;
	do{
		printf("\n\nMenu\n");
		printf("1. Inorder\n2. Preorder \n3. Postorder\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				inorder(root);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				postorder(root);
				break;
	}
	printf("Press Y to continue !! ");
	getche(ans)
	}while(ans=='y'| ans=='Y')
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node* left; //address of root of left subtree
	struct node* right; //address of root of right subtree
};

typedef struct node bst_node;

//create node allocating memory and setting data
bst_node* getNode(int element)
{
	bst_node *new_node = (bst_node*)malloc(sizeof(bst_node));
	new_node -> data = element;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}


void insert_iterative(bst_node** p_root,element)
{
	bst_node *current=NULL; //to traverse to the position
	bst_node *previous=NULL; //keep track of where to insert
	bst_node* new_node = getNode(element);
	if(*p_root == NULL) //if tree is empty
		*p_root = new_node;
	else
	{
		current = *p_root;
		while(current!=NULL) //traverse unitl a node's left child or right child  is NULL
		{
			previous = current; //keep track of the previous node before moving to next node
			if(new_node -> data > current -> data)//if value is greater, move to right subtree
				current = current -> right;
			else
				current = current -> left; //else move to left subtree 
		}
		//insertion takes place after correct position is found
		if(new_node -> data > previous -> data)
			previous -> right = new_node;
		else
			previous -> left = new_node; //duplicates will be in the left side
	}	
}


bst_node* insert_recursive(bst_node* root,int element)
{
	bst_node* new_node;
	if(root == NULL) //if node is empty
	{
		new_node = getNode(element);
		root = new_node;
		return root;
	}
	else
	{
		//do insertion in the subtree and return the address to the left/right of the node as well
		if (element > root -> data)
			root -> right = insert_recursive(root -> right,element);
		else
			root -> left = insert_recursive(root -> left,element); 
	}
}

//delete key for bst
void delete(bst_node** p_root,int key)//pass by address
{
	bst_node *current,*previous,*successor,*replacement;
	current = *p_root;
	if(*p_root == NULL)//if tree is empty
	{
		printf("Binary Search Tree is empty\n");
		return 0;
	else //not empty - Search for key
	{

		while(current!=NULL)
		{
			previous = current;
			if(key==current -> data)
			{
				break;
			}
			else if(key > current->data) //move right
			{
				current = current -> right;
			}
			else //move left
			{
				current = current -> left;
			}
		}
		if(current == NULL)
			printf("key not found \n");
		else //key is found. now delete
		{
			//CASE 1: no left child, no right child
			if(current -> left == NULL && current -> right == NULL)
			{
				replacement = NULL;
			}
			//CASE 2: no right child, ONLY LEFT CHILD
			else if(current -> left != NULL && current -> right == NULL)
			{
				replacement = current -> left;
			}
			//CASE 3: no left child, ONLY RIGHT CHILD
			else if(current -> left == NULL && current -> right != NULL)
			{
				replacement = current -> right;	
			}
			//CASE 4: both left and right child exist - reduce to case 1 or 3
			else if(current -> left != NULL && current -> right 1= NULL)
			{
				//replace with successor, take a right then left until end
				successor = current -> right;
				while(successor -> left != NULL)
				{
					previous = successor;
					succcessor = successor -> left;
				}
				current -> data = successor -> data; //or swap
				current = successor;
				replacement = current -> right; //left doesnt exist, right may or may not be null
		}
		if(current == *p_root) //root node
			*p_root = replacement;
		else //internal node
		{
			if(current == previous -> left)
				previous -> left = replacement;
			else 
				previous -> right = replacement;
		}
		free(current);
		current = NULL;
	}
}

int height(bst_node *t)
{
	int l,r;
	if(t!=NULL)//empty tree height is 0
	{
		l=height(t -> left); //height of left subtree
		r=height(t -> right);//height of right subtree
		if(l>r) //whichever is maximum
			return(l+1); 
		else
			return(r+1);
	}//return (max(height(t->left),height(t->right))+1)
	return 0;
}


int no_of_leaf(bst_node *t) //recursive
{
	if(t!=NULL)
	{
		if((t->left == NULL)&&(t -> right == NULL))
			return 1;
		return (no_of_leaf(t->left)+no_of_leaf(t->right));
	}
	return 0;//if tree is empty
}


void mirror(node *ptr) //swap to make tree as mirror
{
    node *temp1;
    if (ptr == NULL)
        return;
    temp1 = ptr->left;
    ptr->left = ptr->right;
    ptr->right = temp1;
    mirror(ptr->left);
    mirror(ptr->right);
}

void mirrorify(node* root, node** mirror)  //original,new tree
{ 
    if (root == NULL) 
	{ 
        mirror = NULL; 
        return; 
    } 
  
    // Create new mirror node from original tree node 
    *mirror = createNode(root->data); 
    mirrorify(root->left, &((*mirror)->right));  //value on left goes to right
    mirrorify(root->right, &((*mirror)->left));  //vice versa
} 
  

int main()
{
	bst_node* root = NULL; //root holds address of root node
	int element;
	int choice;
	do{
		printf("\n\nMenu\n");
		printf("1. Insert Iterative\n2 Insert Iterative\n3. Delete\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Input : ");
				scanf("%d",&element);
				insert_iterative(&root,element); //pass by reference
				break;
			case 2:
				root = insert_recursive(root,element);
				break;
			case 3:
				printf("Input : ");
				scanf("%d",&element);
				delete(&root,element);
				break;
	}
	printf("Press Y to continue !! ");
	getche(ans)
	}while(ans!='y'| ans!='Y')
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	int lthread;
	int rthread;
};

typedef struct node node;

			
	
node *insert(node *root,int key)
{ 
	//searching for node with given value
	node *cur = root;
	node *prev = NULL; //parent of the key to be inserted
	while( cur!=NULL)
	{
		if(key == cur->data) //if key exists return
		{
			printf("Duplicate Key\n");
			return root;
		}
		
		prev = cur; //update the parent
		
		/*----------find position to insert------------*/
		if(key < cur -> info) //left subtree
		{
			if(!cur -> lthread)//lthread==0
				cur = cur -> left;
			else
				break;
		}
		else //right subtree
		{
			if(!cur -> rthread)//rthread==0
				cur = cur -> right;
			else
				break;
		}
	}
	
	/*----------INSERTION------------*/
	node *new_node =(node*)malloc(sizeof(struct node));
	new_node -> data = key;
	new_node -> lthread = 1;
	new_node -> rthread = 1; 
	
	if(prev == NULL) //empty tree
	{
		root = new_node;
		new_node -> left = NULL;
		new_node -> right = NULL;
	}
	
	else if(key < prev->info)) //insert left child
	{
		new_node -> left = prev -> left;  //new_node -> left is thread not actual link
		new_node -> right = prev;
		prev -> lthread = 0; //now prev has child and not a thread. so update
		prev -> left = new_node; //attach the child to the left link
	}
	
	else //insert right child
	{
		new_node -> left = prev; //left of new node threads to its parent. inorder predesssor
		new_node -> right = prev -> right;  //right of new node points to whatever the right of its parent was pointing to
		prev -> rthread = 0;
		prev -> right = new_node;
	}
	
	return root;
}

node *inorderSuccessor(node *ptr) //method to find successor
{
	//if rthread is set,get inorder successor 
	if(ptr->rthread == 1)
		return ptr -> right;
	
	else //if rthread is not set : find leftmost of right subtree
	{
		ptr = ptr ->right; //take one right
		while(ptr -> left == 0) //go fulll left 
		{
			ptr = ptr -> left;
		}
		return ptr; //return the leftmost which will be the inorder successor 
	}
}

void inorder(node *root)
{
	if(root==NULL)
		printf("EMPTY TREE\n");
	
	else //reach leftmost node
	{
		node *ptr = root;
		
		while(ptr -> left != NULL) //!ptr->lthread //ptr -> lthread ==0
			ptr = ptr -> left;
			
		//one by one print successor	
		while (ptr != NULL) 
		{
			printf("%d",ptr -> data);
			ptr = inorderSuccessor(ptr); //find successor and print that	
		}
	}
}
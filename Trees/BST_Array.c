#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//indexing from 0

void insert(int *t,int x)
{
	//take care of size here
	int i;
	i=0; //Traversal starts from 0 i.e root
	while(t[i]!=-1) //while not null
	{
		if(x<t[i]) //lesser - go to left child
			i=2*i+1;
		else //greater - go to right childe
			i=2*i+2;
	}
	t[i] = x; //insert at position i
}


void preorder(int *t,int i) //Recursively
{
	if(t[i]!=-1)
	{
		printf("%d ",t[i]); //print at root
		preorder(t,2*i+1); //left subtree
		preorder(t,2*i+2); //right subtree
	}	
}

void postorder(int *t,int i) //Recursively
{
	if(t[i]!=-1)
	{
		postorder(t,2*i+1); //left
		postorder(t,2*i+2); //right
		printf("%d ",t[i]); //root
	}	
}

void inorder(int *t,int i) //Recursively
{
	if(t[i]!=-1)
	{
		inorder(t,2*i+1); //left
		printf("%d ",t[i]); //root
		inorder(t,2*i+2); //right
	}	
}

int minimum(int *t) //left
{
	int i=0;
	while(t[2*i+1] != -1)//check first if left is empty  
		i= 2*i + 1; //if not then move to left child
	return(t[i]);
}

int maximum(int *t) //right
{
	int i=0;
	while(t[2*i+2] != -1)
		i= 2*i + 2;
	return(t[i]);
}



int main()
{
	int t[100];  //t hold all data - maximumm is 100
	int ch,num,k,i;
	
	for(i=0;i<100;i++)
		t[i]=-1; //-1 basically means NULL
	
	char ans='y';
	do
	{
		printf("\nMENU : BINARY TREE ARRAY IMPLEMENTATION\n");
		printf("\n1.Insert");
		printf("\n2.Preorder ");
		printf("\n3.Postorder");
		printf("\n4.Inorder");
		printf("\n5.Minimum");
		printf("\n6.Maximum");
		printf("\n7.Exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: //repeated insertion
			printf("Enter the element : ");
			scanf("%d",&num);
			insert(t,num);  //pass the tree(t) we know root is t[0]
			break; 
			
			case 2:
			if(t[0]==-1)
			{
				printf("\nEmpty!\n");
				break;
			}
			else
			{
				printf("PREORDER : ");
				preorder(t,0); //pass tree,index of root
			}
			break;
			
			case 3:
			if(t[0]==-1)
			{
				printf("\nEmpty!\n");
				break;
			}
			else
			{
				printf("POSTORDER : ");
				postorder(t,0);
			}
			break;
			
			case 4:
			if(t[0]==-1)
			{
				printf("\nEmpty!\n");
				break;
			}
			else
			{
				printf("INORDER : ");
				inorder(t,0);
			}
			break;
			
			case 5:
			if(t[0]==-1)
			{
				printf("\nEmpty!\n");
				break;
			}
			k=minimum(t);
			printf("\nThe smallest number is %d\n",k);
			break;
			
			case 6:
			if(t[0]==-1)
			{
				printf("\nEmpty!\n");
				break;
			}
			k=maximum(t);
			printf("\nThe largest number is %d\n",k);
			break;
			
			case 7:
			exit(0);
			
			default:
			printf("\nInvalid choice\n");
		}
		printf("\nDo you want to continue (y/n): ");
		ans = getche();
	}while(ans=='y'| ans=='Y');
	return 0;
}
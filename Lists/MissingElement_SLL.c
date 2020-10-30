#include<stdio.h>
#include<stdlib.h>


//Node of the linked list
struct Node 
{
	int data;
	struct Node *link; //pointer that holds a value of type Node
};

typedef struct Node Node;

//Handle of the list. Its head points to the first node in the list. It also stores the total no of node in the list
typedef struct List 
{
	Node *head;
	int number_of_nodes;
} List;

List* list_initialize() 
{
	List* list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->number_of_nodes = 0;
	return list;
}

void list_print(List* list)
{
	Node *p;
	p=list->head;
	if(p == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	while (p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}

	printf("\n");
}


void list_destroy (List *list)
{
	Node *t, *u=NULL;
	t=list->head;
	while (t!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(list);
}

void insert_at_end(List *list, int data) {
	Node *new_node;  //node to be inserted
	Node *temp; //temporary node used for traversal
	new_node = (Node*)malloc(sizeof(Node)); //allocating memory for new node
	new_node->data=data; //assigning data given by user to the new node
	new_node->link=NULL; //initially new node's link points to null
	list->number_of_nodes = list->number_of_nodes + 1; //increase no. of nodes in the list
	if(list->head==NULL)//if the list is empty
	{
		list->head=new_node;//head of the list points to new node i.e list has one node now
	}
	else
	{	temp=list->head; //initially temp points to the head of the list
		while(temp->link!=NULL)//traversal of the list until the end
		{
			temp=temp->link;
		}
		temp->link=new_node;//make the last node of the list point to the new node
	}
}



void missing_element(List* list)
{
	Node *temp;
	int i;
	int sum=0,actual_sum=0;
	int diff;
	temp=list->head;
	if(temp == NULL)
	{
		printf("EMPTY!\n");
		return;
	}
	while (temp!=NULL)
	{
		sum=sum+temp->data; //sum of the values inside the list
		temp=temp->link;
	}
	//number_of_nodes starts from 0. but for us n=1
	actual_sum=(list->number_of_nodes+1)*(list->number_of_nodes+2)/2; //sum of n natural numbers
	diff=actual_sum - sum; //sum of n natural number - sum calculated = missing natural number
	printf("Missing element is : %d\n",diff);
}

int main() {
	int choice;
	List* list = list_initialize();
	do {
		printf("\nMENU\n");
		printf("1. Insert at end\n");
		printf("2. display list\n");
		printf("3. Find Missing element\n");
		printf("4. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
			int element, index;
			case 1:
				/*Insert element at the End of the list*/
				printf("Input the element :");
				scanf("%d", &element);
				insert_at_end(list, element);
				break;
			case 2:
				/* Print list contents */
				list_print(list);
				break;
			case 3:
				/*Reverses the elements of the list*/
				missing_element(list);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid\n");
		}
	} while(choice != 0);
	list_destroy(list);
	return 0;
}


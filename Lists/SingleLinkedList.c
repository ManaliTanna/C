#include<stdio.h>
#include<stdlib.h>


//Node of the linked list
typedef struct Node {
	int data;
	struct Node *link; //pointer that holds a value of type Node
};

typedef struct Node node;

//Handle of the list. Its head points to the first node in the list. It also stores the total no of node in the list
typedef struct List {
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

void list_delete_front(List* list) {
    Node *temp; //temporary node used for traversal
	temp=list->head; //initially temp points to the head of the list
	list->head=list->head->link;//make head point to the address stored in link i.e next node
	free(temp); //free the first node
	list->number_of_nodes=list->number_of_nodes-1;//decrease no. of nodes in the list
}

void list_insert_at (List *list, int data, int position)
{
	//put extra thing saying increment only if valid position
	Node *new_node; //node to be inserted
	Node *temp; //temporary node used for traversal
	Node *prev = NULL; //to keep track of the prev node
	
	new_node = (Node*)malloc(sizeof(Node)); //allocate memory to new node
	
	new_node->data=data;//initialize data of the new node
	new_node->link=NULL;//initially it will point to null
	list->number_of_nodes = list->number_of_nodes + 1;//increase no of nodes in the list
	
	if(list->head==NULL)//if the list is empty
	{
		list->head=new_node;//as the first node is the new node
	}
	else if(position == 0)//if insertion as to be done at front
	{
		new_node->link=list->head;//make new node point to the first node of the list using its head
		list->head=new_node;//make head point to the new node
	}
	else
	{
		temp=list->head;
		while(temp->link!=NULL && position > 0) //traverse list until we reach position
		{
			prev=temp;//for the iteration, storing the previous node
			temp=temp->link; //traversal
			--position; //decrease position, when position is reached it will become 0
		}
		if (temp->link == NULL)//if the end of list is reached
		{
			temp->link = new_node;
		}
		else//if its not the end of the list
		{
			new_node->link = temp;//make the link of the new node point to next node
			prev->link = new_node;//make the link of the previous node point to new node
		}
	}
}

void list_reverse(List* list)
{
    //the previous as well as current node need to be stored
  	Node *prev= NULL;
	Node *pres;
	Node *temp;

	if (list->head == NULL)//if list is empty
	{
		return;
	}
	pres=list->head;//store first node as previous node
	temp=pres->link;//temp will hold the address of the next node
	while(temp != NULL)//traverse the list
	{
		pres->link=prev;//make the current node's link point to previous node
		prev=pres;//make the previous node equal to current node
		pres=temp;//make the current node equal to the next node
		temp=temp->link;//move on to the next node
	}
	pres->link=prev; //make present node's link point to previous node
	list->head=pres;//now head is last node
}

int main() {
	int choice;
	List* list = list_initialize();
	do {
		printf("\nMENU\n");
		printf("1.Insert at end\n");
		printf("2.display list\n");
		printf("3.Delete at front\n");
		printf("4.Insert at index\n");
		printf("5.Reverse List\n");
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
				/* Remove front element */
				list_delete_front(list);
				break;
			case 4:
				/* Insert elements at specified positions */
				printf("Input the element and index :");
				scanf("%d%d", &element, &index);
				list_insert_at(list, element, index);
				break;
			case 5:
				/*Reverses the elements of the list*/
				list_reverse(list);
				break;
		}
	} while(choice != 0);
	list_destroy(list);
	return 0;
}


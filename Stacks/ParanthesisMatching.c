#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Node Node;

struct List {
	Node *head;
	int number_of_nodes;
};

struct Node {
	int data;
	Node *link;
};

/* initializes a linked List with default values*/
void List_initialize(List* list)
{
    list -> head = NULL;
    list -> number_of_nodes = 0;
}

void List_insert_front(List* list, int data) //list is basically the *ptr_list present inside struct stack. it points to the struct list
{
    Node* temp = (Node*)malloc(sizeof(Node)); //allocate memory for the new node
    temp -> data = data; //assign data
    temp -> link = list->head; //insert at front
    list -> head = temp; //make the new top as the new node
    list -> number_of_nodes++; //increase no of nodes 
	printf("Pushed : %c\n",data);
}


void List_delete_front(List* list) //list is basically the *ptr_list present inside struct stack. it points to the struct list
{
    Node* temp = list->head; //temp node 
    if(temp == NULL) 
	{//if list is empty exit //list->head==NULL exit
		printf("ERROR\n");
		return;
	}
    list->head = temp->link; //change the TOS
	printf("Popped : %c\n",temp->data);
    free(temp); //free the popped node
    list->number_of_nodes--; //decrease no of nodes

}


Node* List_get(List *List, int index);

/* Returns the element that (*Node_ptr) contains */
const int Node_get_data(Node* Node_ptr);


/* deallocates resources held by the List */
void List_destroy(List* list)
{
    Node* p = list->head; //for traversal
    Node* q = NULL;
    while(p!=NULL) //for freeing each node
    {
        q = p->link; //q holds the next node
        free(p); //free current node
        p = q; //make current node as the next node...repeat
    }
    free(list); //free the list i.e head and no of nodes
}


typedef struct {
	List *ptr_List; 
} stack;
//stack contains a pointer the list. list contains head and no of nodes. each node contains data and link to next node

void stack_initialize(stack* s)
{
    s -> ptr_List = (List*)malloc(sizeof(List)); //creating memory for the List i.e head & no_of_nodes
    List_initialize(s -> ptr_List); //initialising it with default values
}

void stack_push(stack* ptr_stack, int data)
{
    List_insert_front(ptr_stack->ptr_List, data);
}

void stack_pop(stack* ptr_stack)
{
    List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(stack* ptr_stack)
{
    return ptr_stack->ptr_List->head == NULL;
}

const int stack_peek(stack* ptr_stack) //return the data at the top of stack
{
    return ptr_stack->ptr_List->head->data;
}


void stack_destroy(stack* ptr_stack)
{
    List_destroy(ptr_stack->ptr_List);
    free(ptr_stack);
}



/* Returns 1 if the parenthesis sequence is well formed, else returns 0 */
int match_parenthesis(const char * string)
{
    stack *s = (stack*)malloc(sizeof(stack)); //allocate memory for a stack 
    stack_initialize(s); 
    int flag = 1;
    for(int i=0; string[i] != '\0' && flag==1; ++i)
    {
        if(string[i]=='(' || string[i]=='{' || string[i]=='[') //push for opening bracket
            stack_push(s, string[i]);
        else if(string[i] == ')') //closing )
        {
            printf("Incoming Symbol : ) and Top Of Stack : %c\n",stack_peek(s));
            if(!stack_is_empty(s) && stack_peek(s) == '(') //if not empty and the TOS is (
                stack_pop(s);
            else
                flag=0; //invalid - mismatch
        }
        else if(string[i] == ']')
        {
            printf("Incoming Symbol : ] and Top Of Stack: %c\n",stack_peek(s));
            if(!stack_is_empty(s) && stack_peek(s) == '[')
                stack_pop(s);
            else
                flag=0; //invalid - mismatch
        }
        else if(string[i] == '}')
        {
		printf("Incoming Symbol : } and Top Of Stack : %c\n",stack_peek(s));
            if(!stack_is_empty(s) && stack_peek(s) == '{')
                stack_pop(s);
            else
                flag=0; //invalid - mismach
        }
    }
    return (flag && stack_is_empty(s)); //if flag is 0(mismatch) 							   - return 0
}                                       //if flag is 1 and stack is empty                      - return 1
										//if flag is 1 and stack is not empty(missing bracket) - return 0

/* TODO:
 * Provide suitable implementation for the above function declaration,
namely, match_parenthesis()
 */

int main() 
{
	char parenthesis_sequence[100];
	int number_of_inputs = 0;
	
	scanf("%d", &number_of_inputs);
	
	for(int counter = 0; counter < number_of_inputs; ++ counter) 
	{
		scanf("%s", parenthesis_sequence);
		printf("\n%d\n", match_parenthesis(parenthesis_sequence));
	}
return 0;
}

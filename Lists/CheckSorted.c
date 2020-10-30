// C program to recursively check Linked List 
// is sorted in descending order or not 
#include <stdio.h> 
#include<stdlib.h>


/* Linked list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// function to Check Linked List is 
// sorted in descending order or not 
bool isSortedDesc(struct Node *head) 
{ 
	// Base cases 
	if (head == NULL || head->next == NULL) 
		return true; 
	
	// Check first two nodes and recursively 
	// check remaining. 
	return (head->data > head->next->data && 
		isSortedDesc(head->next)); 
} 

Node *newNode(int data) 
{ 
	Node *temp = (Node*)malloc(sizeof(Node)); 
	temp->next = NULL; 
	temp->data = data; 
} 

// Driver program to test above 
int main() 
{ 
	struct Node *head = newNode(7); 
	head->next = newNode(5); 
	head->next->next = newNode(4); 
	head->next->next->next = newNode(3); 
		
	isSortedDesc(head) ? printf("Yes") : 
						printf("No"); 
	
	return 0; 
} 

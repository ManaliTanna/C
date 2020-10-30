/*
 * C Program to Check whether 2 Lists are exactly Same  : value and position
 */
#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int info;
    struct node *next;
}node;
 
void feedmember(node **);
int compare (node *,node *);
void release(node **);
 
int main()
{
    struct node *p = NULL; //list 1
    struct node *q = NULL; //list 2
    int result;
 
    printf("Enter data into first list\n");
    feedmember(&p);
    printf("Enter data into second list\n");
    feedmember(&q);
    result = compare(p, q);
    if (result == 1)
    {
        printf("The 2 list are equal.\n");
    }
    else
    {
        printf("The 2 lists are unequal.\n");
    }
    release (&p);
    release (&q);
 
    return 0;
}
 
int compare ( *list1,node *list2)
{
    while (list1 != NULL && list2 != NULL) //both lists finish at the same time
    {
        if (list1->num != list2-> num) //if at any time the values at same position are unequal
        {
            return 0;
        }
        else //traverse both at same time
        {
            list1 = list1->next;
            list2 = list2->next;
        }
    }
    if (list1 != NULL || list2 != NULL) //if after completeing 1 list, the other list in not empty
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
 
void feedmember (struct node **head)
{
    int c, ch;
    struct node *temp;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = *head;
        *head = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    }while (ch != 0);
    printf("\n");
}
 
void release (struct node **head)
{
    struct node *temp = *head;
 
    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}
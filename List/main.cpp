#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* Create_Node (int value);
Node* Insert_Node (Node* cur, int value);
Node* Search_Node (Node* cur, int value);
int   Index_Node (Node* cur);
void  Print_Node (Node* list_ptr);
void  Delete_Node (Node* cur);
void  Swap_Node (Node* ptr1, Node* ptr2);



int main()
{
Node* list_ptr = Create_Node (4);
Node* cur = list_ptr;
int k = 0;
printf("Number of nodes ");
scanf("%d", &k);

for (int i = 0; i < k; i++)
{
    int num = 0;
    printf("a[%d] = ",i);
    scanf("%d", &num);
    cur = Insert_Node(cur, num);
}

int a = 0;
printf("Search ");
scanf("%d", &a);

Node* searches = Search_Node (list_ptr, a);
cur = searches;
if (cur == NULL) printf("EMPTY!\n");
int index = Index_Node (cur);
if (index != 0)
    printf("index = %d\n", index);

Node* tmp = list_ptr -> next;
//Swap_Node (cur, tmp);

Delete_Node (tmp);
printf("list: ");
Print_Node (list_ptr);

free (list_ptr);
return 0;
}

Node* Create_Node (int value)
{
      Node* list_ptr = new Node;

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;

return list_ptr;
}

Node* Insert_Node(Node* cur, int value)
{
    Node* new_node = new Node;

    new_node -> data = value;
    new_node -> next = cur -> next;
    new_node -> prev = cur;
    cur   -> next = new_node;
    if (new_node -> next == NULL) return new_node;
    (new_node -> next) -> prev = new_node;

return new_node;
}

Node* Search_Node (Node* list_ptr, int value)
{
    Node* cur = list_ptr;

    while(cur != NULL)
    {
        if(cur -> data == value) return cur;
        cur = (cur -> next);
    }

return NULL;
}

int   Index_Node (Node* cur)
{
    if (cur == NULL) return 0;
    Node* tmp = cur;
    int counter = 0;

    while (cur -> prev != NULL)
    {
        counter ++;
        cur = (cur -> prev);
    }
if (counter == 0)
    printf("Sorry!There is no such element\n");
return counter;
}

void Print_Node (Node* list_ptr)
{
    Node* p = list_ptr;

    printf("%d  ", p -> data);
    p = p -> next;
    while (p != NULL)
    {
    printf("%d ", p -> data);
    p = p -> next;
    }
}

void  Swap_Node (Node* ptr1, Node* ptr2)
{
    if ((ptr1 != NULL)&& (ptr2 != NULL))
{
      Node* tmp = new Node;

    (tmp -> prev) = (ptr1 -> prev);
    (tmp -> next) = (ptr1 -> next);
    (tmp -> data) = (ptr1 -> data);

    if (ptr1 -> prev != NULL)
        (ptr1 -> prev) -> next = ptr2;
    if (ptr2 -> next != NULL)
        (ptr2 -> next) -> prev = ptr1;

    (ptr1 -> prev) = (ptr2 -> prev);
    (ptr1 -> next) = (ptr2 -> next);
    (ptr1 -> data) = (ptr2 -> data);

    (ptr2 -> prev) = (tmp -> prev);
    (ptr2 -> next) = (tmp -> next);
    (ptr2 -> data) = (tmp -> data);
}
}

void Delete_Node(Node* cur)
{
    (cur -> prev) -> next = (cur -> next);
    (cur -> next) -> prev = (cur -> prev);
free (cur);
}

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* Create_Node (int value);
Node* Insert_Node (Node* cur, int value);
Node* Search_Node (Node* cur, int value);
int   Indexx_Node (Node* cur, Node* list_ptr);
void  Printf_Node (Node* list_ptr);
void  Delete_Node (Node* cur);
void  Swap___Node (Node* ptr1, Node* ptr2);



int main()
{
printf(" Hey ");

int k = 0, head = 0;
printf("Number of nodes ");
scanf("%d", &k);
printf("Head ");
scanf("%d", &head);

Node* list_ptr = Create_Node (head);
Node* cur = list_ptr;
for (int i = 1; i < k; i++)
{
    int num = 0;
    printf("a = ");
    scanf("%d", &num);
    cur = Insert_Node(cur, num);
}

int a = 0;
printf("Search ");
scanf("%d", &a);
Node* searches = Search_Node (list_ptr, a);
if (searches == NULL) printf("~Sorry!There is no such element~\n");

cur = searches;
int index = Indexx_Node (cur, list_ptr);
if (index != 0)
    printf("index = %d\n", index);

Node* tmp = list_ptr -> next;
Swap___Node (cur, tmp);

//Delete_Node (tmp);
printf("list: ");
Printf_Node (list_ptr);

free (list_ptr);
return 0;
}

Node* Create_Node (int value)
{
    Node* list_ptr = (Node*) calloc (1, sizeof(Node));

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;

return list_ptr;
}

Node* Insert_Node(Node* cur, int value)
{
    if (cur == NULL) 
    {
	printf ("Error in Insert_Node");
	return NULL;
    }
    Node* new_n = (Node*) calloc (1, sizeof(Node));

    new_n -> data = value;
    new_n -> next = cur -> next;
    new_n -> prev = cur;
    cur   -> next = new_n;
    if (new_n -> next == NULL) return new_n;
    (new_n -> next) -> prev = new_n;

return new_n;
}

Node* Search_Node (Node* list_ptr, int value)
{
    if (list_ptr == NULL) 
    {
	printf ("Error in Search_Node");
	return NULL;
    }
    if (list_ptr -> data == value) {return list_ptr;}
    Node* cur = list_ptr;
    
    while(cur != NULL)
    {
        if(cur -> data == value) return cur;
        cur = (cur -> next);
    }

return NULL;
}

int   Indexx_Node (Node* cur, Node* list_ptr)
{
    if (cur == list_ptr) {return 1;}
    if (cur == NULL) return -1;
    Node* tmp = cur;
    int counter = 0;
    
    while (cur -> prev != NULL)
    {
        counter ++;
        cur = (cur -> prev);
    }
if (counter == 0)
    printf("Sorry!There is no such element meow\n");
return counter;
}

void Printf_Node (Node* list_ptr)
{
    if (list_ptr == NULL) 
    {
	printf ("Error in Printf_Node");
    }
    Node* p = list_ptr;

    printf("%d  ", p -> data);
    p = p -> next;
    while (p != NULL)
    {
    printf("%d ", p -> data);
    p = p -> next;
    }
}

void  Swap___Node (Node* ptr1, Node* ptr2)
{
    if ((ptr1 != NULL)&& (ptr2 != NULL))
{

    Node* tmp = (Node*) calloc (1, sizeof(Node));

    (tmp -> data) = (ptr1 -> data);
    (ptr1 -> data) = (ptr2 -> data);
    (ptr2 -> data) = (tmp -> data);

}
}

void Delete_Node(Node* cur)
{
    if (cur == NULL) 
    {
	printf ("Error in Delete_Node");
    }
    (cur -> prev) -> next = (cur -> next);
    (cur -> next) -> prev = (cur -> prev);
free (cur);
}

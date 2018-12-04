#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


const int can_begin = 8022001;
const int can_end = 1002208;

struct Node
{
    int can_begin;
    int data;
    Node* next;
    Node* prev;
    double checksum;
    int can_end;
};

Node* Create_Node (int value);
Node* Insert_Node (Node* cur, int value);
Node* Search_Node (Node* cur, int value);
Node* Ptr_index_Node (Node* list_ptr, int index);
int   Index_Node (Node* cur, Node* list_ptr);
int   OK_Node (Node* ptr);
void  Delete_Node (Node* cur);
void  Swap_Node (Node* ptr1, Node* ptr2);
void  checksum (Node* ptr);
void  Print_Node (Node* list_ptr);
void  Delete_List (Node* list_ptr);



int main()
{
int number = 0, head = 0;
printf("Number of nodes ");
scanf("%d", &number);
if (number <= 0)
    {
        printf("invalid input");
        return -1;
    }

printf("Head ");
if (scanf("%d", &head) != 1)
    {
        printf("invalid input");
        return -1;
    }

Node* list_ptr = Create_Node (head);
Node* cur = list_ptr;
for (int i = 1; i < number; i++)
{
    int num = 0;
    printf("a = ");
    if (scanf("%d", &num) != 1)
    {
        printf("invalid input");
        return -1;
    }
    cur = Insert_Node(cur, num);
}
int value = 0;
printf("Search ");
if (scanf("%d", &value) != 1)
{
    printf("invalid input");
    return -1;
}
Node* searches = Search_Node (list_ptr, value);

cur = searches;
int index = Index_Node (cur, list_ptr);
if (index > 0)
    printf("index = %d\n", index-1);

printf("enter two indexes\n");
int ind1 = 0, ind2 = 0;
scanf("%d %d", &ind1, &ind2);
Node* pr1 = Ptr_index_Node(list_ptr, ind1);
Node* pr2 = Ptr_index_Node(list_ptr, ind2);
Swap_Node (pr1, pr2);

printf("enter the index for the node to be removed\n");
int indel;
scanf("%d", &indel);
cur = Ptr_index_Node(list_ptr, indel);
if (cur == list_ptr)
    list_ptr = cur -> next;
Delete_Node (cur);

printf("\nlist: ");
Print_Node (list_ptr);

Delete_List(list_ptr);

return 0;
}


int OK_Node(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("ptr \n");
        return -21;
    }

    if ( ptr -> checksum != ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% 12978 ))
    {
        printf("CHKSUM\n");
        return -22;
    }
    if ( ptr -> can_begin != can_begin )
    {
        printf("can_begin\n");
        return -23;
    }

    if ( ptr -> can_end != can_end)
    {
        printf("can_end\n");
        return -24;
    }

return 1;
}

void checksum(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("NULL ptr chksum ");
       return;
    }

    ptr -> checksum = ( ((unsigned long long) (ptr -> next) + (unsigned long long)(ptr -> prev ) )% 12978 );
}

Node* Create_Node (int value)
{
    Node* list_ptr = (Node*) calloc (1, sizeof(Node));

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;
    list_ptr -> can_begin = can_begin;
    list_ptr -> can_end = can_end;

    checksum(list_ptr);
    if (OK_Node(list_ptr) < 0)
    {
      printf ("ERROR in Create_Node");
      return NULL;
    }

return list_ptr;
}

Node* Insert_Node(Node* cur, int value)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Insert_Node");
        return NULL;
    }
    Node* new_n = (Node*) calloc (1, sizeof(Node));

    new_n -> data = value;
    new_n -> next = cur -> next;
    new_n -> prev = cur;
    cur   -> next = new_n;
    new_n -> can_begin = can_begin;
    new_n -> can_end = can_end;
    checksum(new_n);
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }
    if (new_n -> next == NULL)
        return new_n;

    (new_n -> next) -> prev = new_n;
    new_n  -> can_begin = can_begin;
    new_n  -> can_end = can_end;
    
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }

return new_n;
}

Node* Search_Node (Node* list_ptr, int value)
{
    checksum(list_ptr);
    if (OK_Node(list_ptr) < 0)
    {
        printf ("ERROR in Search_Node\n");
        return NULL;
    }

    if (list_ptr -> data == value)
        return list_ptr;


    Node* cur = list_ptr;

    while(cur != NULL)
    {
        checksum(cur);
        if (OK_Node(cur) < 0)
        {
           printf ("ERROR search\n");
           return NULL;
        }

        if(cur -> data == value)
            return cur;
        cur = (cur -> next);
    }
    printf("Sorry!There is no such element \n");
return NULL;
}

int Index_Node (Node* cur, Node* list_ptr)
{
    if (cur == list_ptr)
        return 1;
    if (cur == NULL)
        return -1;
    Node* tmp = cur;
    int counter = 1;

    while (cur -> prev != NULL)
    {
        counter ++;
        cur = (cur -> prev);
    }
    if (counter == 1)
        printf("Sorry!There is no such element\n");
return counter;
}

void Print_Node (Node* list_ptr)
{
    if (list_ptr == NULL)
    {
        printf ("Error in Print_Node/The list is empty");
        return;
    }
    Node* p = list_ptr;

    printf("%d ", p -> data);
    p = p -> next;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
    free(p);
    p = NULL;
}

void Swap_Node (Node* ptr1, Node* ptr2)
{
    if ((ptr1 != NULL)&& (ptr2 != NULL))
    {
        int tmp;
        tmp = (ptr1 -> data);
        (ptr1 -> data) = (ptr2 -> data);
        (ptr2 -> data) = tmp;
        checksum(ptr1);
        checksum(ptr2);
        if (OK_Node(ptr1) < 0)
            printf ("ERROR ptr \n");
        if (OK_Node(ptr2) < 0)
            printf ("ERROR ptr \n");

    }
}

void Delete_Node(Node* cur)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Delete_Node");
        return;
    }

    if (cur -> prev == NULL)
    {
        if (cur -> next == NULL)
        {
            free (cur);
            cur = NULL;
            return ;
        }
    }

    if (cur -> prev == NULL)
    {
        (cur -> next) -> prev = NULL;
        free (cur);
        cur = NULL;
        return;
    }
    if (cur -> next == NULL)
    {
        (cur -> prev) -> next = NULL;
        free (cur);
        cur = NULL;
        return;
    }
    (cur -> prev) -> next = (cur -> next);
    (cur -> next) -> prev = (cur -> prev);

    free (cur);
    cur = NULL;
}


void  Delete_List (Node* list_ptr)
{
    if (list_ptr == NULL)
    {
        printf ("Error in Delete_List/The list is empty");
        return;
    }
    Node* tmp = list_ptr;
    while (list_ptr != NULL)
    {
        tmp = list_ptr;
        list_ptr = list_ptr -> next;
        free(tmp);
        tmp -> next = NULL;
        tmp = NULL;
    }
}


Node* Ptr_index_Node (Node* list_ptr, int index)
{
    if (OK_Node(list_ptr) < 0)
    {
        printf ("Error in Ptr_index_Node");
        return NULL;
    }

    for(int i = 0; i < index; i++)
    {
        list_ptr = list_ptr -> next;
    }
    checksum(list_ptr);

return list_ptr;
}

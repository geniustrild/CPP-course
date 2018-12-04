#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


struct Node
{
    #ifndef FAST_LIST
        int can_begin;
    #endif
    int data;
    Node* prev;
    Node* next;
    #ifndef FAST_LIST
        int checksum;
        int can_end;
    #endif
};

const int CAN_BEGIN_NUMBER = 8022001;
const int CAN_END_NUMBER = 1002208;
const int NODE_SIZE = 1;


Node* Create_Node (int value);
Node* Insert_after_Node (Node* cur, int value);
Node* Insert_before_Node (Node* cur, int value);
Node* Search_Node (Node* cur, int value);
int Index_Node (Node* cur);
int Print_Node (Node* list_ptr);
int Delete_Node (Node* cur);
int Swap_Node (Node* ptr1, Node* ptr2);

//_______________________________________________________________________
int main ()
{
    Node* Current_node = NULL;
    srand(time(NULL));
    Current_node = Create_Node(666);
    printf("node %u\ncan_begin %d\ndata %d\nprev %u\nnext %u\ncan_end %d\n\n",Current_node, Current_node -> can_begin, Current_node -> data, Current_node -> prev, Current_node -> next, Current_node -> can_end);
    //Delete_Node(Current_node);
    if (Current_node -> data == NULL) printf("GOOD\n");
    for (int i = 2; i <= 10; i++)
    {
        Current_node = Insert_after_Node(Current_node, i);
        printf("node %u\ncan_begin %d\ndata %d\nprev %u\nnext %u\ncan_end %d\n\n",Current_node, Current_node -> can_begin, Current_node -> data, Current_node -> prev, Current_node -> next, Current_node -> can_end);
    }
    Current_node = Insert_before_Node(Current_node, 11);
    printf("node %u\ncan_begin %d\ndata %d\nprev %u\nnext %u\ncan_end %d\n\n",Current_node, Current_node -> can_begin, Current_node -> data, Current_node -> prev, Current_node -> next, Current_node -> can_end);
}

//_______________________________________________________________________

Node* Create_Node(int value)
{
  Node* new_node = (Node*) calloc (1, sizeof (Node));
  new_node -> can_begin = CAN_BEGIN_NUMBER;
  new_node -> data = value;
  new_node -> prev = NULL;
  new_node -> next = NULL;
  new_node -> can_end = CAN_END_NUMBER;

  return new_node;
}

//_______________________________________________________________________

Node* Search_Node (Node* cur, int value)
{

}

//_______________________________________________________________________
Node* Insert_after_Node (Node* cur, int value)
{
  Node* new_node = Create_Node(value);
  new_node -> next = cur -> next;
  new_node -> prev = cur;
  cur -> next = new_node;
  printf("!!!!!%u\n",cur -> next );
  return new_node;
}
//_______________________________________________________________________

Node* Insert_before_Node (Node* cur, int value)
{
  Node* new_node = Create_Node(value);
  new_node -> next = cur;
  cur -> prev = new_node;
}
//_______________________________________________________________________
int  Delete_Node (Node* cur)
{
    Node* prev_node = cur -> prev;
    prev_node -> next = cur -> next;
    Node* next_node = cur -> next;
    next_node -> prev = prev_node;
    free(cur);
    return 0;
}


//_______________________________________________________________________

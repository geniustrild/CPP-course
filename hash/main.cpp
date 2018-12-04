#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    char* data;
    Node* prev;
    Node* next;
};

struct List
{
  Node* header;
  int size;
};

const int CAN_BEGIN_NUMBER = 8022001;
const int CAN_END_NUMBER = 1002208;
const int LIST_SIZE = 11;
char created[] = "Already created";
char good[] = "new GOOD!";
char nothing[] = "nothing";
char empty[] = "empty";


Node* Create_Node (char* str);
Node* Insert_after_Node (Node* cur, char* str);
Node* Insert_before_Node (Node* cur, char* str);
Node* Search_Node (Node* cur, char* str);
int Delete_Node (Node* cur);


char* FindAndAdd_List(List* listArray, char* str, int num);

//_______________________________________________________________________
int main ()
{
    Node* Current_node = NULL;
    char string1[] = "TEST STRING1";
    char string2[] = "TEST STRING2";
    char string3[] = "TEST STRING3";
    char string4[] = "TEST STRING4";
    char string5[] = "TEST STRING5";
    char str[] = "TEST STR";
    List listArray[LIST_SIZE];
    listArray[0].size =
    printf("1 %p\n", listArray[0].header);
    printf("2 %s\n", FindAndAdd_List(listArray, string1, 0) );
    printf("3 %s\n", FindAndAdd_List(listArray, string2, 0) );
    printf("4%s\n", FindAndAdd_List(listArray, string3, 0) );
    printf("5 %s\n", listArray[0].header ->  data );
    //Current_node = Create_Node(string3);
    //Current_node = Insert_before_Node(Current_node, string2);
    //Current_node = Insert_before_Node(Current_node, string1);
    //delete []Current_node -> data;
    //delete []Current_node;
}

//_______________________________________________________________________

Node* Create_Node (char* str)
{
  Node* new_node = new Node;
  int len = strlen(str) + 1;
  new_node -> data = new char[len];
  new_node -> data[len] = '\0';
  strcpy (new_node -> data, str);
  new_node -> prev = NULL;
  new_node -> next = NULL;
  printf ("new_node\t%p\t%s\n", new_node ,new_node -> data);
  return new_node;
}
//_______________________________________________________________________
Node* Insert_before_Node (Node* cur, char* str)
{
  Node* new_node = Create_Node(str);
  if (cur != NULL)
  {
  	cur->prev = new_node;
  	new_node->next = cur;
  }
  return new_node;
}
//_______________________________________________________________________
Node* Search_Node (Node* cur, char* str)
{
  for (;;)
    {
      if (strcmp(cur -> data, str) != 0)
        if (cur -> next != NULL)
          cur = cur -> next;
        else return NULL;
      else return cur;
    }
}
//_______________________________________________________________________
char* FindAndAdd_List(List* listArray , char* str, int num)
{

  Node* cur = listArray[num].header;
  if (listArray[num].header == NULL)
    {
      Node* cur = Create_Node(str);
      listArray[num].size++;
      return good;
    }
    if (Search_Node(cur, str) != NULL)
      {
        return created;
      }
    cur = Insert_before_Node (listArray[num].header, str);
    printf("!!!%d\n", listArray[num].size++);
    return good;
}

//_______________________________________________________________________
/*char* FindAndDel_List(List* listArray , char* str, int num)
{

  Node* cur = listArray[num].header;
  if (listArray[num].header == NULL)
    {
      return nothing;
    }
    printf("???????????\n");
    if (Search_Node(cur, str) != NULL)
      {
        return empty;
      }
    printf("???????????\n");
    cur = Delete_Node (listArray[num].header, str);
    listArray[num].size++;
    return good;
}*/

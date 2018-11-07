#include <stdio.h>
struct Node
{
  int data;
  Node * next;
  Node * prev;
  void myfunction();//класс это структура с фунцией
};

Node n={7, NULL, NULL};//инициализировали указатели
Node *n_ptr = (Node *) calloc(1, sizeof(Node));//Инициаллизировали структуру динамически

// поменять 7 на 8
n.data = 7;

(*n_ptr).data эквивалентно n_ptr->data1
n_pptr->data = 8;
free(n_ptr);

//Функция создания узла
Node * CreateAndLink(Node* next, Node* prev, int data_to_fill)
{
  Node* new_node = (Node*) calloc (1, sizeof(Node));
  new_node -> data = data_to_fill;
  new_node -> next = next;
  new_node -> prev = prev;
  next -> prev = new_node;
  prev -> next = new_node;
  return new_node;
}
_______________________________________________________________________
//Функция поиска по списку
Node* SearchNode(int x, Node* begin_search)
{
  Node* cur_ptr = begin_search;
  while(!cur_ptr)
    {
      if (cur_ptr -> data == x) return cur_ptr;
      cur_ptr = cur_ptr -> next;
    }
  return NULL;
}
_______________________________________________________________________
//Функция удаления
void DeleteNode(Node* ptr);
_______________________________________________________________________
//Функция создания списка
//Функция распечатка!!!!!!!!!!!!!
//Функция swap

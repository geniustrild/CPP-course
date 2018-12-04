#include "list.h"

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

  printf("Node 1 data: ");
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
      printf("Node %d data: ", i+1);
      if (scanf("%d", &num) != 1)
      {
          printf("invalid input");
          return -1;
      }
      cur = Insert_Node(cur, num);
  }

  Print_Node (list_ptr);


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
  Node* pr1 = Index_ptr_Node(list_ptr, ind1);
  Node* pr2 = Index_ptr_Node(list_ptr, ind2);
  Swap_Node (pr1, pr2);

  printf("enter the index for the node to be removed\n");
  int indel;
  scanf("%d", &indel);
  cur = Index_ptr_Node(list_ptr, indel);
  if (cur == list_ptr)
      list_ptr = cur -> next;
  Delete_Node (cur);

  printf("\nlist: ");
  Print_Node (list_ptr);

  Delete_List(list_ptr);

  return 0;
}

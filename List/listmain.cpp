#include "list.h"

int main()
{
  int input = 0;
  int data = 0;
  Node* list_ptr = NULL;
  Node* cur = list_ptr;
  int i1 = 0, i2 = 0, index = 0;;
  Node* ptr1 = Index_ptr_Node(list_ptr, i1);
  Node* ptr2 = Index_ptr_Node(list_ptr, i2);

  while (input != 99)
    {
      menu();
      scanf("%d", &input);
      switch ( input )
      {
        case 1:
            printf("\nInput Node data (int)\n");
            if (scanf("%d", &data) != 1)
              {
                  printf("invalid input");
                  return -1;
              }
            list_ptr = Create_Node (data);
            cur = list_ptr;
            Print_Node (list_ptr);
            break;
        case 2:
            printf("\nInput Node data (int)\n");
            if (scanf("%d", &data) != 1)
              {
                printf("invalid input");
                return -1;
              }
            cur = Insert_after_Node(cur, data);
            Print_Node (list_ptr);
            break;
        case 3:
            printf("\nInput Node data (int)\n");
            if (scanf("%d", &data) != 1)
              {
                printf("invalid input");
                return -1;
              }
            cur = Insert_before_Node(cur, data);
            Print_Node (list_ptr);
            break;
          case 4:
            index = Index_Node (cur, list_ptr);
            if (index > 0)
                printf("index = %d\n", index);
            Print_Node (list_ptr);
            break;
        case 5:

            printf("\nSearch ");
            if (scanf("%d", &data) != 1)
              {
                  printf("invalid input");
                  return -1;
              }
            cur = Search_Node (list_ptr, data);
            if (cur == NULL) break;
            printf("%d\n",cur -> data);
            Print_Node (list_ptr);
            break;
        // case 6:
        //     printf("enter two index\n");
        //     scanf("%d %d", &i1, &i2);
        //     ptr1 = Index_ptr_Node(list_ptr, i1);
        //     ptr2 = Index_ptr_Node(list_ptr, i2);
        //     Swap_Node (ptr1, ptr2);
        //     Print_Node (list_ptr);
        //     break;
        case 6:
            Delete_Node (cur);
            Print_Node (list_ptr);
            break;
        case 7:
            Print_Node (list_ptr);
            break;
        default:
            printf("!!!!!!!!!!!!!!!!!!\n");
            break;
      }
    }
  Delete_List(list_ptr);
  return 0;
}

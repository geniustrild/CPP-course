int OK_Node(Node* ptr)
{
    if (ptr == NULL)
    {
        return PTR_ERROR;
    }
  #ifndef FAST_LIST
    if ( ptr -> checksum != ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% CHECKSUM_NUMBER ))
    {
        return CHECKSUM_ERROR;
    }
    if ( ptr -> CAN_BEGIN != CAN_BEGIN)
    {
        return CAN_BEGIN_ERROR;
    }

    if ( ptr -> CAN_END != CAN_END)
    {
        return CAN_END_ERROR;
    }
  #endif
return OKK;
}

#ifndef FAST_LIST
void checksum(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("NULL ptr checksum\n");
       return;
    }

    ptr -> checksum = ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% CHECKSUM_NUMBER );
}
#endif
Node* Create_Node (int value)
{
    Node* list_ptr = new Node;

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;
  #ifndef FAST_LIST
    list_ptr -> CAN_BEGIN = CAN_BEGIN;
    list_ptr -> CAN_END = CAN_END;

    checksum(list_ptr);
  #endif
    if (OK_Node(list_ptr) < 0)
    {
      printf ("ERROR in Create_Node\n");
      return NULL;
    }

return list_ptr;
}

Node* Insert_after_Node(Node* cur, int value)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Insert_after_Node\n");
        return NULL;
    }
    Node* new_n = new Node;

    new_n -> data = value;
    new_n -> next = cur -> next;
    new_n -> prev = cur;
    cur   -> next = new_n;
  #ifndef FAST_LIST
    new_n -> CAN_BEGIN = CAN_BEGIN;
    new_n -> CAN_END = CAN_END;
    checksum(new_n);
  #endif
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }
    if (new_n -> next == NULL)
        return new_n;

    (new_n -> next) -> prev = new_n;
  #ifndef FAST_LIST
    new_n  -> CAN_BEGIN = CAN_BEGIN;
    new_n  -> CAN_END = CAN_END;
  #endif
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }

return new_n;
}

Node* Insert_before_Node(Node* cur, int value)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Insert_before_Node\n");
        return NULL;
    }
    Node* new_n = new Node;

    new_n -> data = value;
    new_n -> prev = cur -> prev;
    new_n -> next = cur;
    cur -> prev -> next = new_n;
  #ifndef FAST_LIST
    new_n -> CAN_BEGIN = CAN_BEGIN;
    new_n -> CAN_END = CAN_END;
    checksum(new_n);
  #endif
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }
    if (new_n -> next == NULL)
        return new_n;

    (new_n -> next) -> prev = new_n;
  #ifndef FAST_LIST
    new_n  -> CAN_BEGIN = CAN_BEGIN;
    new_n  -> CAN_END = CAN_END;
  #endif
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }

return new_n;
}

Node* Search_Node (Node* list_ptr, int value)
{
  #ifndef FAST_LIST
    checksum(list_ptr);
  #endif
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
	#ifndef FAST_LIST
        checksum(cur);
	#endif
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
    printf("Current List: ");
    if (list_ptr == NULL)
    {
        printf ("Error in Print_Node/The list is empty\n");
        return;
    }
    Node* cur = list_ptr;
    //
    // printf("%d ", cur -> data);
    // cur = cur -> next;
    while (cur != NULL)
    {
        printf("%d ", cur -> data);
        cur = cur -> next;
    }
    cur = NULL;
    printf("\n");
}

void Swap_Node (Node* ptr1, Node* ptr2)
{
    if ((ptr1 != NULL) && (ptr2 != NULL))
    {
        int tmp;
        tmp = (ptr1 -> data);
        (ptr1 -> data) = (ptr2 -> data);
        (ptr2 -> data) = tmp;
	#ifndef FAST_LIST
        checksum(ptr1);
        checksum(ptr2);
	#endif
        if (OK_Node(ptr1) < 0)
            printf ("ERROR ptr \n");
        if (OK_Node(ptr2) < 0)
            printf ("ERROR ptr \n");
    }
    else
    {
	printf("PtrError in Swap\n ");
	return;
    }
}

void Delete_Node(Node* cur)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Delete_Node\n");
        return;
    }

    if (cur -> prev == NULL)
    {
        if (cur -> next == NULL)
        {
            delete cur;
            cur = NULL;
            return ;
        }
      cur -> next -> prev = NULL;
      delete cur;
      cur = NULL;
      return;
    }

    if (cur -> next == NULL)
    {
        cur -> prev -> next = NULL;
        delete cur;
        cur = NULL;
        return;
    }
    cur -> prev -> next = cur -> next;
    cur -> next -> prev = cur -> prev;

    delete cur;
    cur = NULL;
}


void  Delete_List (Node* list_ptr)
{
    if (list_ptr == NULL)
    {
        printf ("Error in Delete_List/The list is empty\n");
        return;
    }
    Node* tmp = list_ptr;
    while (list_ptr != NULL)
    {
        tmp = list_ptr;
        list_ptr = list_ptr -> next;
        tmp -> next = NULL;
        tmp = NULL;
    }
  printf("List cleared\n");
}


Node* Index_ptr_Node (Node* list_ptr, int index)
{
    if (OK_Node(list_ptr) < 0)
    {
        printf ("Error in Index_ptr_Node\n");
        return NULL;
    }
    for(int i = 0; i < index; i++)
    {
	if (list_ptr -> next == NULL)
	{
		return NULL;
	}
        list_ptr = list_ptr -> next;
    }
    #ifndef FAST_LIST
    checksum(list_ptr);
    #endif
return list_ptr;
}

void menu()
{
  printf("\n\n");
  printf("1 - Create new Node\n");
  printf("2 - Insert Node after current\n");
  printf("3 - Insert Node before current\n");
  printf("4 - Index current Node\n");
  printf("5 - Search Node\n");
  //printf("6 - Swap Node\n");
  printf("6 - Delete current Node\n");
  printf("7 - Print list\n");
  printf("99 - Clear list end exit\n");
}

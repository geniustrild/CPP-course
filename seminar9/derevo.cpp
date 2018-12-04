#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void Ask (Node * node)
  {
    while (node != NULL)
      {
        printf("%s", node -> data);
        int answer = getchar();
        if (answer == 'n') node = node -> left;
        else node = node -> right;
      }
  }
//_______________________________________________________________________
void Print (const Node * node)
  {
    if (!node) return;
    Tab++;
    printf ("%*s{ ", 4 * Tab, "");
    printf ("%s\n", node -> data);
    Print (node -> right);
    Print (node -> left);
    printf("%*s}\n", 4 * Tab, "");
    Tab--;
  }
//_______________________________________________________________________
node * Read()
  {
    
  }

#ifndef LIST_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


const int CAN_BEGIN = 8022001;
const int CAN_END = 1002208;
const int CHECKSUM_NUMBER = 12041975;
const int OKK = 1;
const int PTR_ERROR = -2018;
const int CHECKSUM_ERROR   = -2019;
const int CAN_BEGIN_ERROR = -2020;
const int CAN_END_ERROR   = -2021;


struct Node
{
    #ifndef List_Fast
      int CAN_BEGIN;
    #endif
    int data;
    Node* next;
    Node* prev;
    #ifndef List_Fast
      double checksum;
      int CAN_END;
    #endif
};

Node* Create_Node (int value);
Node* Insert_before_Node(Node* cur, int value);
Node* Insert_after_Node(Node* cur, int value);
Node* Search_Node (Node* cur, int value);
Node* Index_ptr_Node (Node* list_ptr, int index);
int   Index_Node (Node* cur, Node* list_ptr);
int   OK_Node (Node* ptr);
void  Delete_Node (Node* cur);
void  Swap_Node (Node* ptr1, Node* ptr2);
void  checksum (Node* ptr);
void  Print_Node (Node* list_ptr);
void  Delete_List (Node* list_ptr);
void  menu();

#include "function.cpp"

#endif

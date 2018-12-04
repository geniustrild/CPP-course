Препроцессор первый этап компилляции
_______________________________________________________________________
#define A . - директивы пропроцессора (меняет А на .)
#include "...h" - вставляет код из файла

Файл List.cpp
_______________________________________________________________________
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
    прототипы
    констатнты
    #include ".cpp"
    ...
#endif

#pragma once - аналог define guard


struct Node
{
    int data;
    Node* prev;
    Node* next;
};

int Ok(Node* node)
{
    if (!node)return errorNULL;
    if (node -> can_begin != CAN_BEGIN_NUMBER || node -> can_begin != CAN_BEGIN_NUMBER ) return errorCAN;
}

#define FAST_LIST


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

_______________________________________________________________________
//main.cpp
#define FAST_LIST
#include "List.h"

int main()
{
    Node n={};
}

_______________________________________________________________________
int Ok(Node* node)
{
    if (!node)return errorNULL;
    #ifndef FAST_LIST
    if (node -> can_begin != CAN_BEGIN_NUMBER || node -> can_begin != CAN_BEGIN_NUMBER ) return errorCAN;
    ...
    #endif
    return SUCCESS;
}
_______________________________________________________________________
List.h

#include <stdio.h>
const int ErrorNull = 17;
const int ErrorCan = 18;

#define E(x, name) const int Error##name = x;
E(17, Null);
E(18, Can);

_______________________________________________________________________
_______________________________________________________________________
_______________________________________________________________________


создать массив int
int* data = (int*) malloc(sizeof(int)*100);     //C
int* data = new int[100];                      //CPP

int* elem = new int;
delete []data;
delete elem;





//

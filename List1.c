#include "List1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int Data;
    Position next;
};

List MakeEmpty(List L, int len)
{
    Position P;
    Position Temp;
    L = (List)malloc(sizeof(struct Node));
    L->next = NULL;
    for (int i = 0; i < len; ++i) {
        P = (Position)malloc(sizeof(struct Node));
        P->Data = i;
        if (L->next == NULL) {
            L->next = P;
            L->next->next = NULL;
        } else {
            Temp->next = P;
        }
        Temp = P;
    }
    Temp->next = NULL;
    
    return L;
}

int IsLast(Position P, List L)
{
    return P->next == NULL;
}

int IsEmpty(List L)
{
    return L->next == NULL;
}

Position MallocNode(Position P)
{
    P = (Position)malloc(sizeof(struct Node));
    return P;
}

Position Find(int x, List L)
{
    Position P = L->next;
    while (P != NULL && P->Data != x) {
        P = P->next;
    }

    return P;
}

Position FindPrevious(int x, List L)
{
    Position P = L->next;
    while (P->next != NULL && P->next->Data != x) {
        P = P->next;
    }

    return P;
}

int Delete(int x, List L)
{
    Position P;
    Position PP;
    if (!(P = Find(x, L))) {
        return -1;
    }
    PP = FindPrevious(x, L);
    if (IsLast(P, L)) {
        PP->next = NULL;
    } else {
        PP->next = P->next;
    }
    free(P);

    return 0;
}

Position Last(List L)
{
    Position P = L->next;
    while (P->next != NULL) {
        P = P->next;
    }

    return P;
}

void InsertLast(Position P, List L)
{
    Position LastP;
    LastP = Last(L);
    LastP->next = P;
    LastP->next->next = NULL;
}

int Insert(int x, Position P, List L)
{
    Position PP;
    Position Temp;
    if (!(PP = Find(x, L))) {
        return -1;
    }
    Temp = FindPrevious(x, L);
    Temp->next = P;
    Temp->next->next = PP;

    return 0;
}

void DeleteList(List L)
{
    Position P = L;
    while (L != NULL) {
        L = L->next;
        free(P);
        P = L;
    }
}


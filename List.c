#include "List.h"

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    Position next;
};

List MakeEmpty(List L)
{
    if ( IsEmpty(L) ) {
        L = (List)malloc(sizeof(struct Node));
        L->next = NULL;
    } 

    return L;
}

int IsEmpty(List L)
{
    return L == NULL;
}

int IsHead(Position P, List L)
{
    return P == L;
}

int IsLast(Position P, List L) 
{
    return P->next == NULL;
}

Position Find(int x, List L)
{
    Position P = L;
    while (P != NULL && P->Data != x) {
        P = P->next;
    }
    
    return P;
}

Position FindPrevious(int x, List L) 
{
    Position P = L;
    while (P->next != NULL && P->next->Data != x) {
        P = P->next;
    }
    if (P->next != NULL) {
        return P;
    } else {
        return NULL;
    }
}

int Delete(int x, List L)
{
    Position P, PP;
    if (!(P = Find(x, L))) {
        return 0;
    }
    PP = FindPrevious(x, L);
    if (IsHead(P, L)) {
        free(L);
        return 1;
    }
    if (IsLast(P, L)) {
        P->next = NULL;
    } else {
        PP->next = P->next;
    }
    free(P);

    return 1;
}

int Insert(int x, Position P, List L) 
{
    Position Findx, PP;
    if (!(Findx = Find(x, L))) {
        return 0;
    }
    if (IsHead(Findx, L)) {
        P->next = L;
        L = P;
    } else {
        PP = FindPrevious(x, L);
        PP->next = P;
        P->next = Findx;
    }

    return 0;
}

Position FindLast(List L)
{
    Position P = L;
    while (P->next != NULL) {
        P = P->next;
    }

    return P;
}

void InsertLast(Position P, List L) 
{
    Position LastP;
    if (!(LastP = FindLast(L))) {
        L = P;
        L->next = NULL;
    } else {
        LastP->next = P;
        LastP->next->next = NULL;
    }
}

Position MallocNode(Position P)
{
    P = (Position)malloc(sizeof(struct Node));
}

void DeleteList(List L)
{
    Position P;
    while (L != NULL) {
        P = L;
        L = L->next;
        free(P);
    }
}

#include <stdio.h>
#include "List1.h"

struct Node {
    int Data;
    Position next;
};


int main()
{
    List L;
    Position P;
    L = MakeEmpty(L, 3);
    P = L->next;
    while (P != NULL) {
        printf("%d\n", P->Data);
        P = P->next;
    }
    P = Last(L);
    printf("%d\n", P->Data);
    if (!IsEmpty(L)) {
        printf("isemptyok!!\n");
    }
    Delete(2, L);
    P = L->next;
    while (P != NULL) {
        printf("%d\n", P->Data);
        P = P->next;
    }
}

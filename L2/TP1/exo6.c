#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

void deletenodeX(Node *list1, Node *p)
{
    Node *tmp1 = NULL;
    Node *tmp2 = NULL;
    tmp1 = list1;
    if (list1->next != p)
    {
        deletenodeX(list1->next, p);
    }
    tmp2 = p;
    p = p->next;
    tmp1->next = p;
    tmp2->next = NULL;
    free(tmp2);
}

int main()
{

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

bool comparelists(Node *list1, Node *list2)
{
    Node *p1 = list1;
    Node *p2 = list2;
    int p1_count = 0, p2_count = 0;
    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL)
        {
            p1_count++;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            p2_count++;
            p2 = p2->next;
        }
    }

    if (p1_count != 2 * p2_count)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    return 0;
}
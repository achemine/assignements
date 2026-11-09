#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char letter;
    struct Node *next;
} Node;

//==========================================
Node *create_node(char letter)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->letter = letter;
    p->next = NULL;
    return p;
}
//-------
void Display(Node *h)
{
    Node *p = h;
    do
    {
        printf("%c", p->letter);
        p = p->next;
    } while (p != h && p != NULL);

    printf("\n");
}
//--------

void alterCircular(Node *h, Node *tail, char val)
{
    Node *q = create_node(val);
    q->next = h;
    tail->next = q;
    tail = q;
}
//-----------
void TrackEvolution(int n)
{
    if (n < 0)
        return;

    // starting with a circular list containing only 'A'
    Node *h = create_node('A');
    h->next = h;
    printf("Etape 0 : ");
    Display(h);

    // ==========================
    for (int i = 1; i <= n; i++)
    {
        Node *L_next = NULL;
        Node *tail_next = NULL;
        Node *p = h;

        do
        {
            if (p->letter == 'A')
            {

                alterCircular(&L_next, &tail_next, 'B');
                alterCircular(&L_next, &tail_next, 'A');
                alterCircular(&L_next, &tail_next, 'C');
            }
            else if (p->letter == 'B')
            {
                alterCircular(&L_next, &tail_next, 'C');
                alterCircular(&L_next, &tail_next, 'A');
                alterCircular(&L_next, &tail_next, 'B');
            }
            else if (p->letter == 'C')
            {
            }
            p = p->next;
        } while (p != h);

        // Libérer la mémoire de l'ancienne liste
        Node *curr = h;
        do
        {
            Node *nextNode = curr->next;
            free(curr);
            curr = nextNode;
        } while (curr != h);

        // Passer à la nouvelle génération
        h = L_next;

        printf("Etape %d : ", i);
        Display(h);
    }
}

int main()
{
    int n;
    printf("Enter nbr of steps : ");
    if (scanf("%d", &n) == 1)
    {
        TrackEvolution(n);
    }
    return 0;
}
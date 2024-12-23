#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *ptr, *start2 = NULL, *start = NULL, *new1;
void display(node*);

void concatenate()
{
    printf("Concatenating Lists\n");
    if(start == NULL && start2 == NULL)
    {
        printf("Linked Lists are empty\n");
        return;
    }
    if(start == NULL)
    {
        start = start2;
        display(start);
        return;
    }
    if(start2 == NULL)
    {
        display(start);
        return;
    }
    ptr = start;
    for(ptr = start; ptr->link != NULL; ptr = ptr->link){}
    ptr->link = start2;
    start2 = NULL;
    display(start);
}

void reverse()
{
    printf("Reversing the list\n");
    node *a = start, *b = NULL, *c = NULL;
    while(a != NULL)
    {
        c = b;
        b = a;
        a = a->link;
        b->link = c;
    }
    start = b;
    display(start);
}

node *curr;

void createA()
{
    int c = 1;
    while(c == 1)
    {
        new1 = (node *) malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &new1->data);
        if(start == NULL)
        {
            start = new1;
            curr = new1;
        }
        else
        {
            curr->link = new1;
            curr = new1;
        }
        printf("Create another element?(1: Yes) ");
        scanf("%d",&c);
    }
    curr->link = NULL;
}

void sort()
{
    printf("Sorting the list\n");
    int len = 0, itr = 0, swapped;
    for(ptr = start; ptr != NULL; ptr = ptr->link)
    {
        len++;
    }
    while (itr < len)
    {
        node *traverse = start;
        node *prev = start;
        swapped = 0;
        while (traverse->link != NULL)
        {
            ptr = traverse->link;
            if (traverse->data > ptr->data)
            {
                swapped = 1;
                if (traverse == start)
                {
                    traverse->link = ptr->link;
                    ptr->link = traverse;
                    prev = ptr;
                    start = prev;
                }
                else
                {
                    traverse->link = ptr->link;
                    ptr->link = traverse;
                    prev->link = ptr;
                    prev = ptr;
                }
                continue;
            }
            prev = traverse;
            traverse = traverse->link;
        }
        if (!swapped)
            break;
        ++itr;
    }
    display(start);
}

void display(node *startTemp)
{
    if(startTemp == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    for(ptr = startTemp; ptr != NULL; ptr = ptr->link)
        printf("%d\n", ptr->data);
}

void main()
{
    printf("Create Linked List:\n");
    createA();
    while(1){
        int ch;
        printf("Select:\n1. Sort\n2. Reverse\n3. Concatenate\n4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: sort(); break;
            case 2: reverse(); break;
            case 3: printf("\n\nCreate List 2:\n");createA();concatenate(); break;
            case 4: exit(0); break;
        }
    }
}

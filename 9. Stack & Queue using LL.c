#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node Node;
Node *ptr, *start = NULL, *new1, *curr;

void create(){
    int c = 1;
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter first value: ");
    scanf("%d", &new1->data);
    if(start == NULL){
        start = new1;
        curr = new1;
        }
    else{
        curr->link = new1;
        curr = new1;
    }
    curr->link = NULL;
}

void display()
{
    if(start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    for(ptr = start; ptr != NULL; ptr = ptr->link)
        printf("%d\n", ptr->data);
}

void push() //insert_beg()
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        start = new1;
        new1->link = NULL;
    }
    new1->link = start;
    start = new1;
}

void insert() //insert_end
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        start = new1;
        new1->link = NULL;
    }
    ptr = start;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    //for(ptr = start; ptr->link != NULL; ptr = ptr->link){}
    ptr->link = new1;
    new1->link = NULL;
}

void pop() //delete_beg
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    ptr = start;
    start = start->link;
    free(ptr);
    printf("Deleted Succefully.\n");
}

void delete() //delete_end
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if(start->link == NULL)
    {
        free(start);
        return;
    }
    Node *ptr2 = start;
    for(ptr = start->link; ptr->link != NULL; ptr = ptr->link){
        ptr2 = ptr2->link;
    }
    free(ptr);
    ptr2->link = NULL;
}

void main()
{
    int ch, ds_ch, pos;
    error:
    printf("Select Data Structure:\n1.Stack\n2.Queue\n");
    scanf("%d", &ds_ch);
    create();
    while(1){
        if(ds_ch==1){
            printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
            scanf("%d", &ch);
            switch(ch){
                case 1: push(); break;
                case 2: pop(); break;
                case 3: display(); break;
                case 4: exit(0); break;
            }
        }
        else if(ds_ch==2){
            printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
            scanf("%d", &ch);
            switch(ch){
                case 1: insert(); break;
                case 2: pop(); break;
                case 3: display(); break;
                case 4: exit(0); break;
            }
        }
        else{
            printf("Please enter the correct value!\n");
            goto error;
        }
    }
}
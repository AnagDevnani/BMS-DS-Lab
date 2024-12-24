#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;
node *ptr, *start = NULL, *new1, *curr;

void create()
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
    curr->link = start;
}

void display()
{
    if(start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    ptr=start;
    while(ptr->link!=start){
        printf("%d\n", ptr->data);
        ptr=ptr->link;
    }
    printf("%d\n", ptr->data);
}

void insert_beg(){
    new1 = (node *) malloc(sizeof(node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        start = new1;
        new1->link = NULL;
        return;
    }
    else{
        while(ptr->link!=start){
            ptr=ptr->link;
        }
        ptr->link=new1;
        new1->link = start;
        start = new1;
        ptr=start;
    }
}

void insert_end()
{
    new1 = (node *) malloc(sizeof(node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        start = new1;
        new1->link = start;
    }
    ptr = start;
    while(ptr->link != start)
    {
        ptr = ptr->link;
    }
    //for(ptr = start; ptr->link != NULL; ptr = ptr->link){}
    ptr->link = new1;
    new1->link = start;
}

void insert_pos(int pos)
{
    new1 = (node *) malloc(sizeof(node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if (start == NULL){
        printf("The Linked List is empty, cannot insert at position %d\n", pos);
        return;
    }
// assuming first index is 0
    if (pos == 0){
        new1->link = start;
        start = new1;
    }
    else{
        node* ptr=start;
        int index_num = 0;
        while(ptr->link!=start && index_num !=pos-1){
            index_num++;
            ptr=ptr->link;
        }
        if(ptr->link==start){
            printf("Index out of range");
            return;
        }
        else if (index_num == pos-1){
            //meaning ptr is the element 1 before the point we want to insert at
            new1->link=ptr->link;
            ptr->link=new1;
        }
    }
}

void delete_beg()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    ptr = start;
    while(ptr->link!=start){
        ptr=ptr->link;
    }
    ptr->link=start->link;
    ptr=start;
    start = start->link;
    free(ptr);
}

void delete_end()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if(start->link == start)
    {
        free(start);
        start=NULL;
        return;
    }
    while(ptr->link->link!=start){
        ptr=ptr->link;
    }
    free(ptr->link);
    ptr->link=start;
}

void delete_pos(int pos)
{
    if(start == NULL){
        printf("Linked List is empty\n");
        return;
    }

    int i = 0;
    for(ptr = start; ptr->link != start && i != pos - 1; ptr = ptr->link){
        i++;
    }

    if(ptr->link == start){
        printf("Entered position is greater than number of elements\n");
        return;
    }
    node* temp = ptr->link;
    ptr->link=ptr->link->link;
    free(temp);
}

void main()
{
    int ch, ch1, pos;
    printf("1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\n");
    while(1)
    {
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: printf("1. Beginning\n2. End\n3. At position\n");
                    scanf("%d", &ch1);
                    switch(ch1)
                    {
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: printf("Enter Position: ");
                                scanf("%d", &pos);
                                insert_pos(pos);
                                break;

                    }
                    break;
            case 3: printf("1. Beginning\n2. End\n3. At position\n");
                    scanf("%d", &ch1);
                    switch(ch1)
                    {
                        case 1: delete_beg();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: printf("Enter Position: ");
                                scanf("%d", &pos);
                                delete_pos(pos);
                                break;

                    }
                    break;
            case 4: display();
                    break;
            default:exit(0);
        }
    }
}
// Program to implement Circular Queue
# include <stdio.h>
# include <stdlib.h>
# define queueSize 3
int first=-1, last=-1, item;
int c_queue[queueSize];

void display(){
    if (first==-1 && last==-1){
        printf("Queue is Empty");
        return;
    }
    printf("\nQueue is:\n");
    if (first<=last){
        for(int i=first;i<=last;i++){
            printf("%d\n",c_queue[i]);
        }
    }
    else if(first>last){
        for (int i = first;i<queueSize;i++){
            printf("%d\n", c_queue[i]);
        }
        for (int i=0;i<=last;i++){
            printf("%d\n", c_queue[i]);
        }
    }
    printf("\n");
}

void insert(){
    if(first==(last+1)%queueSize){
        printf("Queue overflow\n\n");
        return;
    }
    printf("\nEnter Value to insert: ");
    scanf("%d", &item);
    if(first==-1 && last == -1){
        first=0;
        last=0;
    }
    else{
        last=(last+1)%queueSize;
    }
    c_queue[last]=item;
    printf("item inserted\n\n");
    return;
}

int delete(){
    if(first==-1 && last == -1){
        printf("Queue is Empty\n");
        return -1;
    }
    item=c_queue[first];
    if(first==last){
        first=-1;
        last=-1;
    }
    else{
        first = (first + 1)%queueSize;
    }
    printf("\nItem deleted\n\n");
    return item;
}

void main(){
    int choice;
    printf("Please choose option\n");
    while(1){
        printf("1.Insert\n2.Delete\n3.Diplay\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}
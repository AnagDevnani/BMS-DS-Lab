// Program to implement queue by Anag Devnani
# include <stdio.h>
# include <stdlib.h>
# define max 5

int queue[max], front=-1, rear=-1, item;



void add(){
    if (rear == max){
        printf("Queue is full\n");
        return;
    }
    else{
        printf("Enter the value to be inserted\n");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
        printf("%d",queue[rear]);
        return;
    }
}

int delete(){
    if (front==-1){
        printf("Queue is empty\n");
        return 0;
    }
    else{
        printf("hello");
        item = queue[front];
        if (front==rear){
            front=-1;
            rear=-1;
        }
        front++;
        return item;
    }
}
void display(){
    int i;
    if (rear==-1){
        printf("The queue is empty");
        return;
    }
    for(i=front+1;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
        
    }
    return;
}

int main(){
    while (1){
        printf("Enter option:\n1.Add\n2.Delete\n3.Display\n4.Exit\n");
        int option;
        scanf("%d", &option);
        switch(option){
            case(1):
                add();
                break;
            case(2):
                delete();
                break;
            case(3):
                display();
                break;
            case(4):
                exit(0);
                break;
        }
        printf("\nPress any key to continue\n");
        char enter;
        scanf("%c", &enter);
    }
}

# include <stdio.h>

int factorial(int num){
    if (num == 1 || num==0){
        return 1;
    }
    else{
        return (num*factorial(num-1));
    }
}

int fibonacci(int num){
    if(num==1){
        return 0;
    }
    else if(num==2){
        return 1;
    }
    else{
        return fibonacci(num-1)+ fibonacci(num-2);
    }
}

void toh(int n,char s,char t,char d){
    if (n == 1) {
        printf("Move %d disk from %c to %c\n",n,s,d);
        return;
    }
    else{

    toh(n-1,s,d,t);
    printf("Move %d disk from %c to %c\n", n,s,d);
    toh(n - 1,t,s,d);
    }
}


void main(){
    printf("%d", factorial(5));
    printf("%d", fibonacci(5));
    toh(3,'s','t','d');
}
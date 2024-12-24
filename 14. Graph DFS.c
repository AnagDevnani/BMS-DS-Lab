//DFS
#include <stdio.h>

#define MAX 100


int graph[MAX][MAX];  
int visited[MAX];      
int n;                


void dfs(int v) {
    visited[v] = 1;  

   
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);  
        }
    }
}


int isConnected() {
   
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

   
    dfs(0);

   
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;  
        }
    }
    return 1;  
}


int main() {
    int i, j;

   
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

   
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

   
    if (isConnected()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}


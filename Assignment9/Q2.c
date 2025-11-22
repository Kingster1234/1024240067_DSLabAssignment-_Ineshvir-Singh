#include <stdio.h>

#define MAX 100

void dfsUtil(int graph[][MAX], int V, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    for(int i=0;i<V;i++) {
        if(graph[node][i] && !visited[i]) {
            dfsUtil(graph, V, i, visited);
        }
    }
}

void dfs(int graph[][MAX], int V, int start) {
    int visited[V];
    for(int i=0;i<V;i++) visited[i]=0;

    printf("DFS: ");
    dfsUtil(graph, V, start, visited);
}

int main() {
    int V = 4;
    int graph[MAX][MAX] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,0},
        {0,1,0,0}
    };

    dfs(graph, V, 0);
}

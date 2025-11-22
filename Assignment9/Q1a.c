#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int graph[MAX][MAX];

void dfs(int node, int V) {
    visited[node] = 1;

    for(int i = 0; i < V; i++) {
        if(graph[node][i] && !visited[i])
            dfs(i, V);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            graph[i][j] = 0;

    for(int i=0;i<E;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int components = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            components++;
            dfs(i, V);
        }
    }

    printf("%d\n", components);
    return 0;
}

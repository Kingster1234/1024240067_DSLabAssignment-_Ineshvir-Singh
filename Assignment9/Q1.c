#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;
void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

void bfs(int graph[][MAX], int V, int start) {
    int visited[V];
    for(int i=0;i<V;i++) visited[i]=0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS: ");

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i=0;i<V;i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int V = 4;
    int graph[MAX][MAX] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,0},
        {0,1,0,0}
    };

    bfs(graph, V, 0);
    return 0;
}

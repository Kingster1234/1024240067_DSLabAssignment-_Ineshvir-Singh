#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSet(struct Subset subsets[], int x, int y) {
    int rx = find(subsets, x);
    int ry = find(subsets, y);

    if (subsets[rx].rank < subsets[ry].rank)
        subsets[rx].parent = ry;
    else if (subsets[rx].rank > subsets[ry].rank)
        subsets[ry].parent = rx;
    else {
        subsets[ry].parent = rx;
        subsets[rx].rank++;
    }
}

int cmp(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void kruskal(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(struct Edge), cmp);

    struct Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int total = 0;
    printf("Kruskal MST:\n");

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(subsets, u) != find(subsets, v)) {
            printf("%d -- %d == %d\n", u, v, edges[i].w);
            total += edges[i].w;
            unionSet(subsets, u, v);
        }
    }

    printf("Total weight: %d\n", total);
}

int main() {
    int V = 4, E = 5;

    struct Edge edges[] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    kruskal(edges, V, E);
}

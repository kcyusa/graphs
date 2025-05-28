#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];

void DFS(int vertex, int adj[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[vertex][i] && !visited[i]) {
            DFS(i, adj, vertices);
        }
    }
}

int main() {
    int vertices = 5;
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};

    // edges
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    printf("DFS Traversal: ");
    DFS(0, adj, vertices);

    return 0;
}

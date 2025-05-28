#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = 0, rear = 0;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

void BFS(int start, int adj[MAX_VERTICES][MAX_VERTICES], int vertices) {
    visited[start] = 1;
    enqueue(start);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
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

    printf("BFS Traversal: ");
    BFS(0, adj, vertices);

    return 0;
}

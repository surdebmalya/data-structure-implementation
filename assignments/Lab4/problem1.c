#include <stdio.h>
#include <stdbool.h>
#define N 6

int queue[100];
int front=0, rear=-1;
int count=0;
void enqueue(int val) {
    rear++;
    queue[rear]=val;
    count++;
}

int top() {
    return queue[front];
}

void dequeue() {
    front++;
    count--;
}

void bfs(int graph[N][N], bool visited[], int starting) {
    enqueue(starting);
    while(count>0) {
        int currNode = top();
        dequeue();
        for(int j=0; j<N; j++) {
            if(graph[currNode][j]==1 && visited[j]==false) enqueue(j);
        }
        printf("%d ", currNode);
        visited[currNode]=true;
    }
}

int main() {
    int graph[N][N] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    bool visited[N];
    for(int i=0; i<N; i++) {
        visited[i] = false;
    }
    
    bfs(graph, visited, 0);

    return 0;
}

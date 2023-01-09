#include <stdio.h>
#include <stdbool.h>
#define N 4

void dfs(int graph[N][N], bool visited[N]) {
    for(int i=0; i<N; i++) {
        int currNode = i;
        if(visited[currNode] == false) {
            // if the node is not explored
            visited[currNode] = true;
            for(int j=0; j<N; j++) {
                if(graph[currNode][j]==1) {
                    dfs(graph, visited);
                }
            }
            printf("%d ", currNode);
        }
    }
}

int main() {
    int graph[N][N] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };
    
    bool visited[N];
    for(int i=0; i<N; i++) {
        visited[i] = false;
    }
    
    dfs(graph, visited);

    return 0;
}

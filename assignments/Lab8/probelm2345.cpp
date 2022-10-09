#include <bits/stdc++.h>
#define V 5
using namespace std;

// bool isCycle(vector<vector<int>> graph) {

// }

// int numberOfComponents(vector<vector<int>> graph) {
    
// }

// bool isBipartite(vector<vector<int>> graph) {
    
// }

string bfs;
void BFS(vector<vector<int>> graph) {
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(0);
    visited[0] = true;
    bfs+=to_string(0);
    while (q.size()!=0) {
        int currNode = q.front();
        q.pop();
        for(int i=0; i<graph[currNode].size(); i++) {
            if(graph[currNode][i]==1 and visited[i]==false) {
                q.push(i);
                visited[i]=true;
                bfs+=to_string(i);
            }
        }
    }
}

string dfs;
void DFS(vector<vector<int>> graph, int currNode, vector<bool> &visited) {
    visited[currNode]=true;
    dfs+=to_string(currNode);
    for(int i=0; i<graph[currNode].size(); i++) {
        if(graph[currNode][i]==1 and visited[i]==false) {
            DFS(graph, i, visited);
        }
    }
}

int dp[V+1][V+1];
int lcs(string a, string b, int n, int m) {
    if(n==0 or m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(a[n-1]==b[m-1]) return dp[n][m]=1+lcs(a, b, n-1, m-1);
    else return dp[n][m]=max(lcs(a, b, n-1, m), lcs(a, b, n, m-1));
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };
    BFS(graph);
    cout << "BFS Sequence: " << bfs << endl;

    vector<bool> visited(V, false);
    DFS(graph, 0, visited);
    cout << "DFS Sequence: " << dfs << endl;
    
    memset(dp, -1, sizeof(dp));
    cout << "Length of LCS of BFS sequence and DFS sequence: " << lcs(bfs, dfs, bfs.size(), dfs.size()) << endl;

    return 0;
}
class Solution {
public:
    int dfs(vector<int> adj[], vector<bool> &hasApple, int node, int parent) {
        int distance = 0;
        for(auto i:adj[node]) {
            if(i!=parent) {
                int temp=dfs(adj, hasApple, i, node);
                if(hasApple[i]) {
                    distance+=(2+temp);
                    hasApple[node]=true;
                }
            }
        }
        return distance;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj, hasApple, 0, 0);
    }
};
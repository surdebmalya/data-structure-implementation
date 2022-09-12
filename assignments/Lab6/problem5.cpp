class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int> dist(n, 1e8);
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (auto v : edges) {
                if (dist[v[1]] > dist[v[0]] + v[2]) {
                    dist[v[1]] = dist[v[0]] + v[2];
                }
            }
        }
        for (auto v : edges) {
            if (dist[v[0]] + v[2] < dist[v[1]])
                return 1;
        }
        return 0;
    }
};
// https://leetcode.com/problems/network-delay-time/

// Medium

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        if (n == 1) {
            return 0;
        }
        // build the adjacency graph
        unordered_map<int, vector<pair<int, int>>> graph; // node: [(node, wt),...]
        for (int i = 1; i <= n; i++) {
            vector<pair<int, int>> temp;
            graph[i] = temp;
        }

        for (int i = 0; i < times.size(); i++) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> resultArr;
        for (int index = 1; index <= n; index++) {
            resultArr.push_back(-1);
        }

        unordered_set<int> visited;
        vector<pair<int, int>> wts; // <wt, node>
        wts.push_back({0, k});
        resultArr[k - 1] = 0;
        while (!(wts.empty())) {
            auto curr = wts[0];
            wts.erase(wts.begin()); // popping the front
            if (visited.find(curr.second) == visited.end()) {
                for (int index = 0; index < graph[curr.second].size(); index++) {
                    if (visited.find(graph[curr.second][index].first) == visited.end()) {
                        if (resultArr[graph[curr.second][index].first - 1] == -1 or resultArr[graph[curr.second][index].first - 1] > graph[curr.second][index].second + curr.first) {
                            resultArr[graph[curr.second][index].first - 1] = graph[curr.second][index].second + curr.first;
                        }
                        wts.push_back({resultArr[graph[curr.second][index].first - 1], graph[curr.second][index].first});
                    }
                }
                visited.insert(curr.second);
                sort(wts.begin(), wts.end());
            }
        }

        if (visited.size() != n)
            return -1;

        int result = INT_MIN;
        for (int index = 0; index < resultArr.size(); index++) {
            if (result < resultArr[index])
                result = resultArr[index];
        }
        return result;
    }
};
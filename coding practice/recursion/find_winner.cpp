// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int remain(vector<int> players, int remainings, int k, int curr_index) {
        if (remainings == 1) {
            return players[0];
        }
        int index_to_be_removed = (curr_index + k - 1) % remainings;
        players.erase(players.begin() + index_to_be_removed);
        return remain(players, remainings - 1, k, index_to_be_removed);
    }

public:
    int findTheWinner(int n, int k) {
        vector<int> players;
        for (int i = 1; i <= n; i++) {
            players.push_back(i);
        }
        return remain(players, n, k, 0);
    }
};
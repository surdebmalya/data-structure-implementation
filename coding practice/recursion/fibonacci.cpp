/*
https://leetcode.com/problems/fibonacci-number/

Easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0 or n == 1) {
            return n;
        }
        vector<int> fibbo;
        fibbo.push_back(0);
        fibbo.push_back(1);
        for (int i = 2; i <= n; i++) {
            int temp = fibbo[i - 1] + fibbo[i - 2];
            fibbo.push_back(temp);
        }
        return fibbo[n];
    }
};
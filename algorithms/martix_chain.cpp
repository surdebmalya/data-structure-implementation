#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int minimum_multiplication(vector<int> dim) {
    int n = dim.size(); // 4
    int dp[n][n];
    for (int a = 0; a < n + 1; a++) {
        for (int b = 0; b < n + 1; b++) {
            dp[a][b] = INT_MAX;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (i == 1) {
                dp[j][j] = 0;
            } else {
                for (int k = j; k < j + i - 1; k++) {
                    int curr_mul = dp[j][k] + dp[k + 1][j + i - 1] + (dim[j - 1] * dim[j + i - 1] * dim[k]);
                    if (curr_mul < dp[j][j + i - 1]) {
                        dp[j][j + i - 1] = curr_mul;
                    }
                }
            }
        }
    }
    // print dp table
    for (int row = 1; row < n; row++) {
        for (int col = 1; col < n; col++) {
            if (col < row) {
                cout << "  ";
            } else {
                cout << dp[row][col] << " ";
            }
        }
        cout << endl;
    }
    return dp[1][n - 1];
}

int main() {
    // vector<int> dimensions = {1, 2, 3, 4}; // answer: 18
    vector<int> dimensions = {10, 100, 20, 5, 80}; // answer: 19000
    int min_mul = minimum_multiplication(dimensions);
    cout << "Number of minimum multiplications needed: " << min_mul << endl;

    return 0;
}
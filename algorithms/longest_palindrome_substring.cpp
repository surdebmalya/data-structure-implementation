#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int longest_palindrome_substring(char str_arg[]) {
    int n = strlen(str_arg); // 8
    string str = "0" + (string)str_arg;
    cout << "Final String: " << str << endl;
    int dp[n + 1][n + 1];
    int maxsize = -1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            if (i == 1) {
                dp[j][j] = i;
                if (i > maxsize) {
                    maxsize = i;
                }
            } else if (i == 2) {
                if (str[j] == str[j + i - 1]) {
                    dp[j][j + i - 1] = i;
                    if (i > maxsize) {
                        maxsize = i;
                    }
                } else {
                    dp[j][j + i - 1] = 0;
                }
            } else {
                if (str[j] == str[j + i - 1]) {
                    if (dp[j + 1][j + i - 2] > 0) {
                        dp[j][j + i - 1] = i;
                        if (i > maxsize) {
                            maxsize = i;
                        }
                    } else {
                        dp[j][j + i - 1] = 0;
                    }
                } else {
                    dp[j][j + i - 1] = 0;
                }
            }
        }
    }
    // printing the dp table
    for (int a = 1; a < n + 1; a++) {
        for (int b = 1; b < n + 1; b++) {
            if (b < a) {
                cout << 0 << " ";
            } else {
                cout << dp[a][b] << " ";
            }
        }
        cout << endl;
    }
    return maxsize;
}

int main() {
    char a[] = "ababbbaa";
    cout << "Longest Palindrome Substring Length: " << longest_palindrome_substring(a) << endl;

    return 0;
}
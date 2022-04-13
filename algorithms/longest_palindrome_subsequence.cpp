#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int longest_palindrome_subsequence(string str, int start_index, int end_index) {
    if (start_index <= end_index) {
        if (str[start_index] == str[end_index]) {
            if (start_index != end_index)
                return 2 + longest_palindrome_subsequence(str, start_index + 1, end_index - 1);
            else
                return 1 + longest_palindrome_subsequence(str, start_index + 1, end_index - 1);
        } else {
            return max(longest_palindrome_subsequence(str, start_index + 1, end_index), longest_palindrome_subsequence(str, start_index, end_index - 1));
        }
    } else {
        return 0;
    }
}

int main() {
    string str = "geeksforgeeks";
    cout << "Length of longest Palindromic Subsequence: " << longest_palindrome_subsequence(str, 0, str.size() - 1) << endl;

    return 0;
}
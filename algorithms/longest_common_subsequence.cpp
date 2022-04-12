#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int LCS(char a[], char b[], int indexa, int indexb, int lengtha, int lengthb) {
    if (indexa >= lengtha or indexb >= lengthb) {
        return 0;
    }
    if (a[indexa] == b[indexb]) {
        return 1 + LCS(a, b, indexa + 1, indexb + 1, lengtha, lengthb);
    } else {
        return max(LCS(a, b, indexa + 1, indexb, lengtha, lengthb), LCS(a, b, indexa, indexb + 1, lengtha, lengthb));
    }
}

int main() {
    char a[] = "ababababab";
    char b[] = "abbababaab";
    int str_len_a = strlen(a);
    int str_len_b = strlen(b);
    cout << "Length of LCS is: " << LCS(a, b, 0, 0, str_len_a, str_len_b) << endl;

    return 0;
}
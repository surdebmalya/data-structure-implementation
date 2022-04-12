#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long int fact(int num) {
    return (num < 0) ? -1 : ((num == 0 or num == 1) ? 1 : num * fact(num - 1));
}

long long int permutation(int n, int r) {
    return (fact(n)/fact(n-r));
}

long long int combination(int n, int r) {
    return (fact(n)/(fact(n-r)*fact(r)));
}

int main() {
    cout << "Factorial of 5: " << fact(5) << endl;
    cout << "5P2: " << permutation(5, 2) << endl;
    cout << "5C2: " << combination(5, 2) << endl;

    return 0;
}
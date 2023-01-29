// Find the private and public keys for both alice and bob when p=23 and g=9

#include <iostream>
#include <math.h>
using namespace std;

long power(int a, int b, int n) {
    long ans = 1;
    for (int j = 1; j <= b; j++) {
        ans = (ans * a) % n;
    }

    return ans;
}

int findMinX(int num[], int rem[], int k) {
    int x = 1;

    while (true) {

        int j;
        for (j = 0; j < k; j++)
            if (x % num[j] != rem[j])
                break;

        if (j == k)
            return x;

        x++;
    }

    return x;
}

bool isprime(int a) {
    for (int i = 2; i < sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int p, q;
    cout << "enter value of p and q" << endl;
    cin >> p >> q;

    if (p == q) {
        cout << "error" << endl;
        return 0;
    }

    if (!isprime(p)) {
        cout << "error" << endl;
        return 0;
    }
    if (!isprime(q)) {
        cout << "error" << endl;
        return 0;
    }
    int n = p * q;
    int e = 2;
    int m = 24;

    cout << "value of m is " << endl;
    cin >> m;
    int c = power(m, 2, n);
    cout << "value of c is " << c << endl;

    long long int a1, a2, b1, b2;

    a1 = (power(c, (p + 1) / 4, p));
    a2 = p - a1;

    b1 = (power(c, (q + 1) / 4, q));
    b2 = q - b1;

    cout << "a1 " << a1 << endl;
    cout << "a2 " << a2 << endl;
    cout << "b1 " << b1 << endl;
    cout << "b2 " << b2 << endl;

    int num[] = {p, q};
    int rem[] = {a1, b1};
    int k = 2;
    cout << "x is " << findMinX(num, rem, k) << endl;
    rem[0] = a1;
    rem[1] = b2;
    cout << "x is " << findMinX(num, rem, k) << endl;
    rem[0] = a2;
    rem[1] = b1;
    cout << "x is " << findMinX(num, rem, k) << endl;
    rem[0] = a2;
    rem[1] = b2;
    cout << "x is " << findMinX(num, rem, k) << endl;
    return 0;
}
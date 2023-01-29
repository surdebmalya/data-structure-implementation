// Find the private and public keys for both alice and bob when p=53 and g=11

#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int b) {
    int t;
    while (1) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}
int main() {

    double p, q, message;
    cout << "Enter the value of p= ";
    cin >> p;
    cout << "Enter the value of q= ";
    cin >> q;
    double n = p * q;
    double track;
    double phi = (p - 1) * (q - 1);
    double e;
    cout << "Enter the value of e= ";
    cin >> e;
    while (e < phi) {
        track = gcd(e, phi);
        if (track == 1)
            break;
        else
            e++;
    }
    double d1 = 1 / e;
    double d = fmod(d1, phi);
    cout << "Enter the message= ";
    cin >> message;
    double c = pow(message, e);
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);
    cout << "Original Message = " << message;
    cout << "\n" << "Encrypted message = " << c;
    cout << "\n" << "Decrypted message = " << m;
    return 0;
}
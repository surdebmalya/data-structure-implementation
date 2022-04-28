// https://en.wikipedia.org/wiki/Tower_of_Hanoi

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void TOH(int n, string src, string dest, string aux, int *steps) {
    if (n == 1) {
        *steps += 1;
    } else {
        TOH (n-1, src, aux, dest, steps);
        *steps += 1;
        TOH (n-1, aux, dest, src, steps);
    }
}

int main() {
    int steps = 0;
    int n = 3;
    TOH(n, "source", "destination", "auxiliary", &steps);
    cout << "Number of steps needed: " << steps << endl;

    return 0;
}
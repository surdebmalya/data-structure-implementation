/*
Qn1: You are given an integer, a process is applied to that integer
such that it multiply integer's digits together and get the product,
repeat this process untill you get a single digit number, return the
minimum number of times you are required to apply this process?

ex: given integer → 1236
1 time→ 36
2 times →18
3 times → 8 (single digit return 3)
2598
1→720
2→0 (single digit return 2)
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int time_to_be_in_single_digit(int number) {
    int times = 0;
    while (number > 9) {
        int mul = 1;
        while (number > 0) {
            mul *= number % 10;
            number /= 10;
        }
        number = mul;
        times++;
    }
    return times;
}

int main() {
    int number;
    cin >> number;
    cout << "The time will be: " << time_to_be_in_single_digit(number) << endl;

    return 0;
}
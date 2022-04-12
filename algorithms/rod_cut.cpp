#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int max_rod_cut_price(vector<int> prices, int remaining_length, int current_length) {
    if (remaining_length == 0 or current_length > remaining_length or current_length > prices.size()) {
        return 0;
    }
    return max(
        prices[current_length - 1] + max_rod_cut_price(prices, remaining_length - current_length, current_length),
        max_rod_cut_price(prices, remaining_length, current_length + 1));
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int given_rod_length = 11;
    cout << "Maximum Price of The Cutted Pieces Is: " << max_rod_cut_price(prices, given_rod_length, 1) << endl;

    return 0;
}
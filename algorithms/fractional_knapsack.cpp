#include <algorithm> // to use sort()
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

float fractional_knapsack(vector<int> &val, vector<int> &wt, int W) {
    int size = val.size();
    int sum = 0;
    for (int index = 0; index < size; index++) {
        sum += wt[index];
    }
    if (sum < W) {
        return sum;
    } else {
        map<float, vector<pair<int, int>>> pricePerWt;
        for (int i = 0; i < size; i++) {
            float pPw = -((float)val[i] / (float)wt[i]);
            if (pricePerWt.find(pPw) != pricePerWt.end()) {
                pricePerWt[pPw].push_back(make_pair(val[i], wt[i])); // <price, weight>
            } else {
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(val[i], wt[i]));
                pricePerWt[pPw] = temp;
            }
        }
        float total_price = 0.0;
        auto it = pricePerWt.begin();
        while (it != pricePerWt.end()) {
            auto it_inner = pricePerWt[it->first].begin();
            while (it_inner != pricePerWt[it->first].end()) {
                int price_temp = it_inner->first;
                int weight_temp = it_inner->second;
                if (W > 0) {
                    if (W-weight_temp>=0) {
                        total_price += price_temp;
                        W -= weight_temp;
                    }
                    else {
                        total_price += ((float)W / (float)weight_temp) * price_temp;
                        return total_price;
                    }
                } else {
                    return total_price;
                }
                it_inner++;
            }
            pricePerWt.erase(it->first);
            it++;
        }
    }
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << fractional_knapsack(val, wt, W) << endl;

    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> &arr) {
    auto it = arr.begin();
    while (it != arr.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

vector<int> counting_sort(vector<int> &arr) {
    int size = arr.size();

    int max_ele = -1;
    auto it1 = arr.begin();
    while (it1 != arr.end()) {
        if (*it1 > max_ele) {
            max_ele = *it1;
        }
        it1++;
    }

    int temp_array[max_ele + 1];
    vector<int> secondary_array;

    for (int i = 0; i < size; i++) {
        secondary_array.push_back(0);
    }

    for (int i = 0; i < max_ele + 1; i++) {
        temp_array[i] = 0;
    }

    auto it2 = arr.begin();
    while (it2 != arr.end()) {
        temp_array[*it2]++;
        it2++;
    }

    for (int i = 1; i < max_ele + 1; i++) {
        temp_array[i] = temp_array[i] + temp_array[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        secondary_array[temp_array[arr[i]] - 1] = arr[i];
        temp_array[arr[i]]--;
    }

    return secondary_array;
}

int main() {
    vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};
    cout << "Before Sorting: ";
    print_arr(arr);

    vector<int> sorted_array = counting_sort(arr);
    cout << "After Sorting: ";
    print_arr(sorted_array);

    return 0;
}
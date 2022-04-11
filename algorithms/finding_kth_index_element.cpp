#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int find_kth_index(vector<int> numbers, int index, int start, int end) {
    if (index >= numbers.size()) {
        return -1;
    } else if (numbers.size() == 1) {
        return numbers[0];
    }
    while (start <= end) {
        // select pivot
        int pivot = numbers[start];

        // do partitioning & calculation
        int first_greater_ele_index = start + 1;
        for (int i = start + 1; i < numbers.size(); i++) {
            if (numbers[i] < pivot) {
                swap(numbers[i], numbers[first_greater_ele_index]);
                first_greater_ele_index++;
            }
        }
        if ((first_greater_ele_index - 1) != start) {
            swap(numbers[first_greater_ele_index - 1], numbers[start]);
        }
        int final_index = first_greater_ele_index - 1;
        if (final_index == index) {
            return numbers[final_index];
        } else if (final_index < index) {
            start = final_index + 1;
        } else {
            end = final_index - 1;
        }
    }
}

int main() {
    vector<int> numbers = {5, 2, 9, 4, 10, 0, 1, 5, 8, 3, 7};
    int kth_index = 9;
    cout << kth_index << "th Indexed Element Is: " << find_kth_index(numbers, kth_index, 0, numbers.size() - 1) << endl;

    return 0;
}
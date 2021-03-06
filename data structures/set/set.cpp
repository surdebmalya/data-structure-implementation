/*
Ordered set: https://www.geeksforgeeks.org/set-in-cpp-stl/
Unoredered set: https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
*/

#include <algorithm>
#include <iostream>
#include <set> // ordered set
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    cout << "=============== UNORDERED SET ===============" << endl;
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);
    us.insert(7);
    if (us.find(5) == us.end()) {
        cout << "Element not present" << endl;
    } else {
        cout << "Element present" << endl;
    }
    cout << "Size of the unordered set: " << us.size() << endl;
    cout << "Elements of the unordered set: ";
    auto it = us.begin();
    while (it != us.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    // UNION of 2 SETs
    unordered_set<int> us1 = {1, 9, 7};
    unordered_set<int> result_us = us;
    result_us.insert(us1.begin(), us1.end());
    auto show_result = result_us.begin();
    while (show_result != result_us.end()) {
        cout << *show_result << " ";
        show_result++;
    }
    cout << endl;

    // INTERSECTION of 2 SETs
    unordered_set<int> us2 = {1, 9, 7};
    unordered_set<int> result_us2 = us;
    auto it_intersection = us2.begin();
    while (it_intersection != us2.end()) {
        if (result_us2.find(*it_intersection) != result_us2.end()) {
            result_us2.erase(*it_intersection);
        }
        it_intersection++;
    }
    auto show_result2 = result_us2.begin();
    while (show_result2 != result_us2.end()) {
        cout << *show_result2 << " ";
        show_result2++;
    }
    cout << endl;

    cout << "=============== ORDERED SET ===============" << endl;
    set<int> os;
    os.insert(7);
    os.insert(1);
    os.insert(3);
    os.insert(2);
    cout << "Till now, elements of the ordered set: ";
    auto itos1 = os.begin();
    while (itos1 != os.end()) {
        cout << *itos1 << " ";
        itos1++;
    }
    cout << endl;
    os.insert(5);
    os.insert(4);
    cout << "Elements of the ordered set: ";
    auto itos2 = os.begin();
    while (itos2 != os.end()) {
        cout << *itos2 << " ";
        itos2++;
    }
    cout << endl;

    if (os.find(8) == os.end()) {
        cout << "Element not present" << endl;
    } else {
        cout << "Element present" << endl;
    }
    cout << "Size of the ordered set: " << os.size() << endl;

    return 0;
}
/*
Unordered map: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
Ordered map: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    cout << "=============== UNORDERED MAP ===============" << endl;
    unordered_map <int, char> um;
    um.insert(make_pair(2, 'B'));
    um.insert(make_pair(1, 'A'));
    um.insert(make_pair(4, 'D'));
    um.insert(make_pair(5, 'E'));
    um.insert(make_pair(3, 'C'));

    cout << "Unordered map: " << endl;
    auto itum1 = um.begin();
    while (itum1 != um.end()) {
        cout << itum1->first << " : " << itum1->second << endl;
        itum1++;
    }

    if (um.find(5)==um.end()) {
        cout << "Element Not present" << endl;
    }
    else {
        cout << "Element present" << endl;
    }

    // clear to delete whole map
    // erase to delete one entry

    vector <int> keys;
    vector <char> values;
    auto itum2 = um.begin();
    while (itum2 != um.end()) {
        keys.push_back(itum2->first);
        values.push_back(itum2->second);
        itum2++;
    }
    cout << "All keys: ";
    for (int index1=0; index1<keys.size(); index1++) {
        cout << keys[index1] << " ";
    }
    cout << endl;

    cout << "All values: ";
    for (int index2=0; index2<values.size(); index2++) {
        cout << values[index2] << " ";
    }
    cout << endl;

    cout << "=============== ORDERED MAP ===============" << endl;
    map <int, char> om;
    om.insert(make_pair(2, 'B'));
    om.insert(make_pair(1, 'A'));
    om.insert(make_pair(4, 'D'));
    om.insert(make_pair(5, 'E'));
    om.insert(make_pair(3, 'C'));

    cout << "Ordered map: " << endl;
    auto itom = om.begin();
    while (itom != om.end()) {
        cout << itom->first << " : " << itom->second << endl;
        itom++;
    }

    return 0;
}
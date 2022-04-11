#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

template<typename T>
void print_container(T container) {
    auto it = container.begin();
    while (it != container.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void sort_on_key(unordered_map <char, int> & container) {
    map <char, int> sorted_map;
    auto it = container.begin();
    while (it != container.end()) {
        sorted_map.insert(make_pair(it->first, it->second));
        it++;
    }

    auto itp = sorted_map.begin();
    while (itp != sorted_map.end()) {
        cout << "[" << itp->first << "] : " << itp->second << endl;
        itp++;
    }
}

void sort_on_value(unordered_map <char, int> & container) {
    map <int, char> sorted_map;
    auto it = container.begin();
    while (it != container.end()) {
        sorted_map.insert(make_pair(it->second, it->first));
        it++;
    }

    auto itp = sorted_map.begin();
    while (itp != sorted_map.end()) {
        cout << "[" << itp->second << "] : " << itp->first << endl;
        itp++;
    }
}

int main() {
    vector<int> numbers = {2, 4, 5, 10, 6, 73, 8, 1, 9};
    // numbers.erase(numbers.begin()+2, numbers.begin()+5); // erase all elements from 3rd to 5th element
    print_container(numbers);
    sort(numbers.begin(), numbers.end());
    print_container(numbers);
    // sort decending order
    sort(numbers.begin(), numbers.end(), greater<int> ());
    print_container(numbers);

    vector<char> characters = {'g', 'b', 'y', 'a', 't', 'm', 'f', 'z', 'c'};
    print_container(characters);
    // partial sort
    sort(characters.begin(), characters.begin()+3);
    print_container(characters);

    unordered_map <char, int> um;
    um.insert(make_pair('B', 2));
    um.insert(make_pair('C', 1));
    um.insert(make_pair('A', 3));
    cout << "Sort on KEY: " << endl;
    sort_on_key(um);

    cout << "Sort on VALUE: " << endl;
    sort_on_value(um);

    return 0;
}
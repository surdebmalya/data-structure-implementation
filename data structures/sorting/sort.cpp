#include <algorithm>
#include <iostream>
#include <vector>

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

    return 0;
}
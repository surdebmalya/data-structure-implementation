#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 5},
        {0, 3, 6},
        {0, 2, 4, 6},
        {3},
        {},
        {2, 3}
    };

    cout << "Adjacent vertices of vertex 3: ";
    auto it = graph[3].begin();
    while (it!=graph[3].end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    return 0;
}
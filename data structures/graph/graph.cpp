#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set> // in <set> => stored in sorted order

using namespace std;

class FIFO {
    list <int> queue;
    int size = 0;
public:
    bool isEmpty() {
        return size==0;
    }

    void enqueue (int value) {
        queue.push_back(value);
        size++;
    }

    int dequeue () {
        int ele = queue.front();
        queue.pop_front();
        size--;
        return ele;
    }
};

void bfs(vector <vector <int>> graph, int root) {
    // root should be given
    FIFO queue;
    unordered_set <int> visited;
    queue.enqueue(root);
    visited.insert(root);
    while (not(queue.isEmpty())) {
        int ele = queue.dequeue();
        cout << ele << " ";
        auto it = graph[ele].begin();
        while (it != graph[ele].end()) {
            if (visited.find(*it) == visited.end()) {
                queue.enqueue(*it);
                visited.insert(*it);
            }
            it++;
        }
    }
    cout << endl;
}

void call_dfs (vector <vector <int>> graph, int node, unordered_set <int> &visited) {
    if (visited.find(node) == visited.end()) {
        cout << node << " ";
        visited.insert(node);
        auto it = graph[node].begin();
        while (it != graph[node].end()) {
            call_dfs (graph, *it, visited);
            it++;
        }
    }
}

void dfs (vector <vector <int>> graph, int root) {
    // assuming connected graph, thus root is given
    unordered_set <int> visited;
    call_dfs (graph, root, visited);
    cout << endl;
}

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

    cout << "BFS Traversal: ";
    bfs(graph, 0);

    cout << "DFS Traversal: ";
    dfs(graph, 0);

    return 0;
}
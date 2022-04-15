/*
Question Statement: https://i.ibb.co/HTW05RQ/problem-statement.png
*/

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, char> initialize_color(unordered_map<int, vector<int>> &graph) {
    unordered_map<int, char> result;
    auto it = graph.begin();
    while (it != graph.end()) {
        result.insert(make_pair(it->first, 'W'));
        it++;
    }
    return result;
}

void call_dfs(int curr_node, unordered_map<int, vector<int>> &graph, unordered_map<int, char> &color, int *cycle_or_not) {
    auto it_adjacency = graph[curr_node].begin();
    while (it_adjacency != graph[curr_node].end()) {
        if (color[*it_adjacency] == 'G') {
            *cycle_or_not = 1; // Grey -> Grey: back edge
        } else if (color[*it_adjacency] == 'W') {
            color[*it_adjacency] = 'G';
            call_dfs(*it_adjacency, graph, color, cycle_or_not);
        }
        it_adjacency++;
    }
    color[curr_node] = 'B';
}

int dfs(unordered_map<int, vector<int>> &graph, unordered_set<int> &nodes) {
    unordered_map<int, char> color = initialize_color(graph);
    int cycle_or_not = 0;
    auto it_node = nodes.begin();
    while (it_node != nodes.end()) { // loop for every nodes of the graph
        int curr_node = *it_node;
        if (color[curr_node] == 'W') {
            color[curr_node] = 'G';
            call_dfs(curr_node, graph, color, &cycle_or_not);
            if (cycle_or_not != 0) {
                return 1; // cycle exists
            }
        }
        it_node++;
    }
    return 0;
}

unordered_set<int> all_nodes(unordered_map<int, vector<int>> &graph) {
    unordered_set<int> nodes;
    auto it = graph.begin();
    while (it != graph.end()) {
        nodes.insert(it->first);
        it++;
    }
    return nodes;
}

void print_graph(unordered_map<int, vector<int>> &graph) {
    auto it = graph.begin();
    while (it != graph.end()) {
        cout << it->first << " : ";
        for (int index = 0; index < (it->second).size(); index++) {
            cout << (it->second)[index] << " ";
        }
        cout << endl;
        it++;
    }
}

int main() {
    unordered_map<int, vector<int>> graph;
    int source, destination;
    string arrow;
    while (cin >> source >> arrow >> destination) {
        if (graph.find(source) != graph.end()) {
            graph[source].push_back(destination);
        } else {
            vector<int> temp_vector;
            temp_vector.push_back(destination);
            graph[source] = temp_vector;
        }
        if (graph.find(destination) == graph.end()) {
            vector<int> temp_vector = {};
            graph[destination] = temp_vector;
        }
    }

    // print_graph(graph);

    unordered_set<int> keys = all_nodes(graph);
    cout << dfs(graph, keys) << endl;

    return 0;
}
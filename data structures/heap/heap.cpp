#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int left_child_index(int i) {
    return 2*i+1;
}

int right_child_index(int i) {
    return 2*i+2;
}

void max_heapify(vector <int> &heap, int index, int size) {
    int lindex = left_child_index(index);
    int rindex = right_child_index(index);
    int largestindex = index;
    if (lindex<size and heap[lindex]>heap[largestindex]) {
        largestindex = lindex;
    }
    if (rindex<size and heap[rindex]>heap[largestindex]) {
        largestindex = rindex;
    }
    if (largestindex!=index){
        // swap(heap[largestindex], heap[index]);
        int temp = heap[largestindex];
        heap[largestindex] = heap[index];
        heap[index] = temp;

        max_heapify(heap, largestindex, size);
    }
}

void build_max_heap(vector <int> &heap, int size) {
    // time complexity: O(n)
    for (int index=floor(size/2) - 1; index>=0; index--) {
        max_heapify(heap, index, size);
    }
}

void pop_top(vector <int> &heap) {
    int temp = heap[heap.size()-1];
    heap[heap.size()-1] = heap[0];
    heap[0] = temp;

    heap.pop_back();

    max_heapify(heap, 0, heap.size());
}

int peek_heap(vector<int> heap) {
    return heap[0];
}

int find_parent(vector <int> heap, int index) {
    return floor((index-1)/2);
}

void insert_into_max_heap(vector <int> &heap, int value) {
    heap.push_back(value);
    int index = heap.size()-1;
    do {
        int parent_index = find_parent(heap, index);
        max_heapify(heap, parent_index, heap.size());
        index = parent_index;
    } while (index!=0);
}

void heap_sort(vector <int> &heap) {
    // time complexity: O(n log n)
    int size = heap.size();
    while (size!=1) {
        swap(heap[0], heap[size-1]);
        max_heapify(heap, 0, size-1);
        size--;
    }
}

void print_heap(vector <int> heap) {
    for (int i=0; i<heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    vector <int> h;
    h.push_back(1);
    h.push_back(2);
    h.push_back(3);
    h.push_back(4);
    h.push_back(5);
    h.push_back(6);
    h.push_back(7);

    print_heap(h);

    build_max_heap(h, h.size());

    print_heap(h);

    pop_top(h);

    print_heap(h);

    insert_into_max_heap(h, 11);

    print_heap(h);

    heap_sort(h);

    print_heap(h);

    return 0;
}
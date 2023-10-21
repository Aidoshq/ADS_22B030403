#include <iostream>
#include <vector>

using namespace std;

struct MaxHeap {
    vector <int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMax() {
        if(heap.size() == 0) return 0;
        if(heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int greatest = i;
        if(l < heap.size() && heap[l] > heap[greatest]) {
            greatest = l;
        }
        if(r < heap.size() && heap[r] > heap[greatest]) {
            greatest = r;
        }
        if(greatest != i) {
            swap(heap[greatest], heap[i]);
            heapify(greatest);
        }
    }

    int getSize() {
        return heap.size();
    }
};

int main() {
    int n, k; 
    cin >> n >> k;
    MaxHeap *heap = new MaxHeap();
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        heap->insert(x);
    }

    long long sum = 0;
    while(k--) {
        int row = heap->extractMax();
        sum += row;
        row--;
        heap->insert(row);
    }
    cout << sum << "\n";

    return 0;
}
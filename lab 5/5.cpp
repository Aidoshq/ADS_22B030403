#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MinHeap {
    vector <int> heap;
    long long sum;

    MinHeap() {
        this->sum = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int value, int k) {
        heap.push_back(value);
        this->sum += value;
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        if(heap.size() > k) {
            this->sum -= extractMin();
        }
    }

    int extractMin() {
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
        int l = this->left(i);
        int r = this->right(i);
        int greatest = i;
        if(l < heap.size() && heap[l] < heap[i]) {
            greatest = l;
        }
        if(r < heap.size() && heap[r] < heap[greatest]) {
            greatest = r;
        }
        if(greatest != i) {
            swap(heap[i], heap[greatest]);
            heapify(greatest);
        }
    }

    long long getSum() {
        return this->sum;
    }

    bool isEmpty() {
        return heap.size() == 0;
    }
};

int main() {
    int q, k; 
    cin >> q >> k;
    MinHeap *heap = new MinHeap();
    while(q--) {
        string s; cin >> s;
        if(s == "print") {
            if(heap->heap.size() == 0) {
                cout << 0 << "\n";
            } else {
                cout << heap->getSum() << "\n";
            }
        } else if(s == "insert") {
            int x; cin >> x;
            heap->insert(x, k);
        }
    }

    return 0;
}
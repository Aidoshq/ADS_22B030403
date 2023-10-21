#include <iostream>
#include <vector>

using namespace std;

#define ll unsigned long long

struct MinHeap {
    vector <ll> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }

    void insert(ll value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    ll extractMin() {
        if(heap.size() == 0) return 0;
        if(heap.size() == 1) {
            ll root = heap[0];
            heap.pop_back();
            return root;
        }
        ll root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        } 
        if(r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    int getSize() {
        return heap.size();
    }
};

int main() {
    ll n; cin >> n;
    MinHeap *heap = new MinHeap();
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        heap->insert(x);
    }

    if(heap->getSize() == 1) {
        cout << heap->extractMin() << "\n";
        return 0;
    }

    ll sum = 0;
    while(heap->getSize() > 1) {
        ll first = heap->extractMin();
        ll second = heap->extractMin();
        ll result = first + second;
        sum += result;
        heap->insert(result);
    }
    cout << sum << "\n";

    return 0;
}
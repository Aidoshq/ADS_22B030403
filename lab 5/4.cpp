#include <iostream>
#include  <vector>

using namespace std;

struct MinHeap {
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
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMin() {
        if(heap.size() == 0) return (int)1e9;
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
    int n, m;
    cin >> n >> m;
    MinHeap *heap = new MinHeap();
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        heap->insert(x);
    }

    bool flag = false;
    int cnt = 0;
    while(heap->getSize() > 1) {
        int first = heap->extractMin();
        if(first >= m) {
            flag = true;
            break;
        }
        int second = heap->extractMin();
        int x = first + 2 * second;
        heap->insert(x);
        cnt++;
        if(x >= m) {
            flag = true;
        }
    }
    int result = (flag) ? cnt : -1;
    cout << result << "\n";

    return 0;
}
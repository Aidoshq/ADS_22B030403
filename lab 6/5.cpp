#include <iostream>

#include <algorithm>

using namespace std;

int partition(int **arr, int l, int r, int i) {
    int pivot = arr[r][i];
    int pIndex = l;
    for(int j = l; j < r; j++) {
        if(arr[j][i] >= pivot) {
            swap(arr[j][i], arr[pIndex][i]);
            pIndex++;
        }
    }
    swap(arr[pIndex][i], arr[r][i]);
    return pIndex;
}

void quickSort(int **arr, int l, int r, int i) {
    if(l < r) {
        int p = partition(arr, l, r, i);
        quickSort(arr, l, p - 1, i);
        quickSort(arr, p + 1, r, i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int **arr;
    arr = new int *[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        quickSort(arr, 0, n - 1, i);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(arr[i] < pivot) {
            swap(arr[pIndex], arr[i]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}


int main () {
    int n , m ;
    cin>>n>>m;

    if(n==0 || m==0) {
        return 0;
    }

    int a[n] , b[m];

    for (int i=0 ; i<n ; i++) {
        cin>>a[i];
    }
    for (int i =0 ; i<m ; i++) {
        cin>>b[i];
    }

    quickSort(a, 0, n - 1);
    quickSort(b, 0, m - 1);

    vector <int> ans;
    int l = 0, r = 0;
    while(l < n && r < m) {
        if(a[l] == b[r]) {
            ans.push_back(a[l]);
            l++;
            r++;
        } else if(a[l] < b[r]) {
            l++;
        } else if(a[l] > b[r]) {
            r++;
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
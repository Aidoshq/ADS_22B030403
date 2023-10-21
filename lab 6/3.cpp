#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int partition (int arr[] , int l , int r) {

    int pivot = arr[r];
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void  quickSort(int a[], int l, int r) {
    if(l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main () {
    int n;
    cin>>n;
    int a[n];
    for (int  i =0 ; i<n ; i++) {
        cin>>a[i];
    }

    quickSort(a,0,n-1);
int min = (int) 1e9;
    map <pair <int, int>, int> m;
    for(int i = 0; i < n - 1; i++) {
        if(min > abs(a[i] - a[i + 1])) {
            min = abs(a[i] - a[i + 1]);
        }
        m[make_pair(a[i], a[i + 1])] = abs(a[i] - a[i + 1]);
    }
    map <pair <int, int>, int> :: iterator it;
    vector <int> ans;
    for(it = m.begin(); it != m.end(); it++) {
        if((*it).second == min) {
            ans.push_back((*it).first.first);
            ans.push_back((*it).first.second);
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
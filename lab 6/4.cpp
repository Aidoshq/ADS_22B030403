#include <iostream>
#include <algorithm>

using namespace std;

int compare(string &s1, string &s2) {
    if(s1.substr(6, 4) < s2.substr(6, 4)) {
        return 1;
    } else if(s1.substr(6, 4) > s2.substr(6, 4)) {
        return 0;
    } else {
        if(s1.substr(3, 2) < s2.substr(3, 2)) {
            return 1;
        } else if(s1.substr(3, 2) > s2.substr(3, 2)) {
            return 0;
        } else {
            if(s1.substr(0, 2) <= s2.substr(0, 2)) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int partition(string arr[], int l, int r) {
    string pivot = arr[r];
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(compare(arr[i], pivot) == 1) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(string arr[], int l, int r) {
    if(l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main () {
    int n;
    cin>>n;
    string a[n];
    for (int i =0 ; i< n ; i++) {
        cin>>a[i];
    }

    quickSort(a, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }

    return 0;
}



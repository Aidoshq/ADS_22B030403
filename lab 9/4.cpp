#include <iostream>

#include <vector>

using namespace std;

vector <int> prefixFun(string s) {
    int n = (int) s.size();
    vector <int> pi(n);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s; cin >> s;
    s[0] = tolower(s[0]);
    int q; cin >> q;
    vector <string> v;
    int maxLen = 1;
    while(q--) {
        string city; cin >> city;
        city[0] = tolower(city[0]);
        string p = city + "#" + s;
        vector <int> pi = prefixFun(p);
        city[0] = toupper(city[0]);
        if(maxLen < pi.back()) {
            maxLen = pi.back();
            v.clear();
            v.push_back(city);
        } else if (pi.back() == maxLen) {
            v.push_back(city);
        }
    }
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int q = 1e9 + 7;
const int p = 31;

long long getHash(string s) {
    long long hash = 0;
    long long pow = 1;
    for(int i = 0; i < s.size(); i++) {
        long long curH = (s[i] - 'a' + 1) * pow % q;
        hash = (hash + curH) % q;
        pow = (pow * p) % q;
    }
    return hash;
}

vector <long long> prefHash(string s) {
    vector <long long> h(s.size());
    long long pow = 1;
    for(int i = 0; i < s.size(); i++) {
        h[i] = (s[i] - 'a' + 1) * pow % q;
        if(i) {
            h[i] = (h[i] + h[i - 1]) % q;
        }
        pow = (pow * p) % q;
    }
    return h;
}

vector<int> rabinKarp(string s, string t) {
    long long hash = getHash(t);
    vector<long long> pref = prefHash(s);
    vector<int> v;
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long diff = pref[i + t.size() - 1];
        if (i) {
            diff -= pref[i - 1];
        }
        if (diff < 0) {
            diff += q;
        }
        if (i) {
            hash = (hash * p) % q;
        }
        if (diff == hash) {
            v.push_back(i);
        }
    }
    return v;
}

int main() {
    string s; cin >> s;
    int q; cin >> q;
    vector <int> v(s.size());
    while(q--) {
        string sub; cin >> sub;
        vector <int> w = rabinKarp(s, sub);
        for(int i = 0; i < w.size(); i++) {
            fill(v.begin() + w[i], v.begin() + w[i] + sub.size(), 1);
        }
    }
    
    for(int i = 0; i < v.size(); i++) {
        // cout << v[i] << " ";
        if(!v[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
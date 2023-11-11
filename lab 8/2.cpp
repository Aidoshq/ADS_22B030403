#include <iostream>
#include <vector>

using namespace std;

long long q = 1e9 + 7;
long long p = 31;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curH = (s[i] - 'a' + 1) * curX % q;
        hash = (hash + curH) % q;
        curX = (curX * p) % q;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % q;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % q;
        }
        curX = (curX * p) % q;
    }
    return hashes;
}

vector<int> rabinKarp(string s, string t) {
    long long smallHash = getHash(t);
    vector<int> res;
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long diff = hashes[i + t.size() - 1];
        if (i != 0) diff -= hashes[i - 1];
        if (diff < 0) diff += q;
        if (i != 0) smallHash = (smallHash * p) % q;
        if (smallHash == diff) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    vector<int> v = rabinKarp(s1, t);
    vector<int> w = rabinKarp(s2, t);

    int i = 0, j = 0, cnt = 0;
    while(i < v.size() && j < w.size()) {
        if(v[i] == w[j]) {
            cnt++;
            i++;
            j++;
        } else if (v[i] < w[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
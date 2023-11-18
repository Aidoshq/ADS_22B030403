#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int q = 1e9 + 7;
const int p = 31;

vector<long long> getPrefixHashes(string s, vector <long long> p_pow) {
    vector <long long> hashes(s.size());
    for(int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i) {
            hashes[i] += hashes[i - 1];
        }
    }
    return hashes;
}

int main() {
    string s; cin >> s;

    vector <long long> p_pow(s.size());
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p);
    }

    vector <long long> pref_hashes = getPrefixHashes(s, p_pow);

    unordered_set <long long> st;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            long long cur_hash = pref_hashes[j];
            if(i) {
                cur_hash -= pref_hashes[i - 1];
            }
            cur_hash *= p_pow[s.size() - i - 1];
            st.insert(cur_hash);
        }
    }
    cout << st.size() << "\n";

    return 0;
}
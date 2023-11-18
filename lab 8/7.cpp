#include <iostream>
#include <vector>

using namespace std;

const int q = 1e9 + 7;
const int p = 31;

vector <long long> getAllHash(string s, vector <long long> p_pow) {
    vector <long long> h(s.size());
    for(int i = 0; i < s.size(); i++) {
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i) {
            h[i] += h[i - 1];
        }
    }
    return h;
}

int main() {
    string s; cin >> s;
    vector <long long> p_pow(s.size());
    p_pow[0] = 1;
    for(int i = 1; i < p_pow.size(); i++) {
        p_pow[i] = p_pow[i - 1] * p; 
    }
    vector <long long> h = getAllHash(s, p_pow);

    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        string sub = "";
        for(int i = l - 1; i < r; i++) {
            sub += s[i];
        }

        long long h_s = 0;
        for(int i = 0; i < sub.size(); i++) {
            h_s += (sub[i] - 'a' + 1) * p_pow[i];
        }

        int cnt = 0;
        for(int i = 0; i + sub.size() - 1 < s.size(); i++) {
            long long cur = h[i + sub.size() - 1];
            if(i) {
                cur -= h[i - 1];
            }
            if(cur == h_s * p_pow[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
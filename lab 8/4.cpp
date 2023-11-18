#include <iostream>
#include <vector>

using namespace std;

const int p = 31;
const int N = 1e5 + 5;
vector <long long> powers(N);

vector <long long> prefHash(string s) {
    vector <long long> hash(s.size());
    for(int i = 0; i < s.size(); i++) {
        hash[i] = (s[i] - 'a' + 1) * powers[i];
        if(i) {
            hash[i] += hash[i - 1];
        }
    }
    return hash;
}

int rabinKarp(string s, string t, vector <long long> h) {
    long long h_s = 0;
    for(int i = 0; i < s.size(); i++) {
        h_s += (s[i] - 'a' + 1) * powers[i];
    }
    int cnt = 0;
    for(int i = 0; i + s.size() - 1 < t.size(); i++) {
        long long cur = h[i + s.size() - 1];
        if(i) {
            cur -= h[i - 1];
        }
        if(cur == h_s * powers[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    powers[0] = 1;
    for(int i = 1; i < N; i++) {
        powers[i] = powers[i - 1] * p;
    }

    int n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        vector <string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        string s; cin >> s;
        
        vector <long long> pref = prefHash(s);
        vector <string> ans;
        int max = 0;
        for(int i = 0; i < v.size(); i++) {
            int f = rabinKarp(v[i], s, pref);
            if(max < f) {
                max = f;
                ans.clear();
                ans.push_back(v[i]);
            } else if (f == max) {
                ans.push_back(v[i]);
            }
        }
        cout << max << "\n";
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}
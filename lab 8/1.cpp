#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;


const int q = 1e9 + 7;
const int p = 11;

string getHash(string s) {
    unsigned long long hash = 0;
    unsigned long long pow = 1;
    for(int i = 0; i < s.size(); i++) {
        long long curH = (s[i] - 47) * pow % q;
        hash = (hash + curH) % q;
        pow = (pow * p) % q;
    }
    return to_string(hash);
}

int main() {
    int n; cin >> n;
    vector <string> v;
    map <string, bool> m;
    for(int i = 0; i < 2 * n; i++) {
        string s; cin >> s;
        v.push_back(s);
        m[s] = true;
    }

    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(cnt == n) {
            break;
        }
        string hash = getHash(v[i]);
        if(m[hash]) {
            cout << "Hash of string " << '"' << v[i] << '"' << " is " << hash << "\n";
            cnt++;
        }
    }

    return 0;
}

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

vector <int> KMP(string txt, string pat) {
    vector <int> res;
    string p = pat + '#' + txt;
    vector <int> pi = prefixFun(p);
    for(int i = pat.size() + 1; i < p.size(); i++) {
        if(pi[i] == pat.size()) {
            res.push_back(i - 2 * pat.size());
        }
    }
    return res;
}

int main () {
    string s1,s2;
    cin>>s1>>s2;

    vector<int> v= KMP(s1,s2);
    cout<<v.size() << "\n";

    for (int i=0 ; i<v.size() ; i++) {
        cout<<v[i] + 1<< " ";
    }
    return 0;
}
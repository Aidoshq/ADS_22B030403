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
    int q;
    cin>>q;
    while (q--)
    {
        string s;
        cin>>s;
        int k ;
        cin>>k;
        vector <int> pi = prefixFun(s);

        int len = s.size() - pi.back();
        cout<<len*(k-1) + s.size() << "\n";
    }
    return 0;
}

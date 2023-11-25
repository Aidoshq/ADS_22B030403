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

int main () {
    string s;
    cin>>s;
    int cnt = 0;
    vector <int> v = prefixFun(s);
    for (int i=1 ; i<v.size() ; i++) {
        if(i%2 == 0) {
            int k = i - v[i-1];
            if((i/k)%2 == 0) {
                cnt++;
            }
        }
    }
    cout<<cnt;
}
